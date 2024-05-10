#ifndef _CODE_PIPELINE
#define _CODE_PIPELINE

#include <CODE/std/detail/__config>

#if defined(_CODE_IMPLICIT_SYSTEM_HEADER_GCC)
#  pragma GCC system_header
#elif defined(_CODE_IMPLICIT_SYSTEM_HEADER_CLANG)
#  pragma clang system_header
#elif defined(_CODE_IMPLICIT_SYSTEM_HEADER_MSVC)
#  pragma system_header
#endif // no system header

#include <barrier>
#include <atomic>
#include <chrono>

_LIBCODECXX_BEGIN_NAMESPACE_CODE

    // Forward declaration in barrier of pipeline
    enum class pipeline_role {
        producer,
        consumer
    };

    template<thread_scope _Scope>
    struct __pipeline_stage {
        barrier<_Scope> __produced;
        barrier<_Scope> __consumed;
    };

    template<thread_scope _Scope, uint8_t _Stages_count>
    class pipeline_shared_state {
    public:
        pipeline_shared_state() = default;
        pipeline_shared_state(const pipeline_shared_state &) = delete;
        pipeline_shared_state(pipeline_shared_state &&) = delete;
        pipeline_shared_state & operator=(pipeline_shared_state &&) = delete;
        pipeline_shared_state & operator=(const pipeline_shared_state &) =  delete;

    private:
        __pipeline_stage<_Scope> __stages[_Stages_count];
        atomic<uint32_t, _Scope> __refcount;

        template<thread_scope _Pipeline_scope>
        friend class pipeline;

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state);

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state, size_t __producer_count);

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state, pipeline_role __role);
    };

    struct __pipeline_asm_helper {
        _CCCL_DEVICE
        static inline uint32_t __lane_id()
        {
            NV_IF_ELSE_TARGET(
                NV_IS_DEVICE,
                (
                    uint32_t __lane_id;
                    asm volatile ("mov.u32 %0, %%laneid;" : "=r"(__lane_id));
                    return __lane_id;
                ),
                (
                    return 0;
                )
            )
        }
    };

    template<thread_scope _Scope>
    class pipeline {
    public:
        pipeline(pipeline &&) = default;
        pipeline(const pipeline &) = delete;
        pipeline & operator=(pipeline &&) = delete;
        pipeline & operator=(const pipeline &) = delete;

        _LIBCODE_INLINE_VISIBILITY
        ~pipeline()
        {
            if (__active) {
                (void)quit();
            }
        }

        _LIBCODE_INLINE_VISIBILITY
        bool quit()
        {
            bool __elected;
            uint32_t __sub_count;
NV_IF_TARGET(NV_IS_DEVICE,
            const uint32_t __match_mask = __match_any_sync(__activemask(), reinterpret_cast<uintptr_t>(__shared_state_get_refcount()));
            const uint32_t __elected_id = __ffs(__match_mask) - 1;
            __elected = (__pipeline_asm_helper::__lane_id() == __elected_id);
            __sub_count = __popc(__match_mask);
,
            __elected = true;
            __sub_count = 1;
)
            bool __released = false;
            if (__elected) {
                const uint32_t __old = __shared_state_get_refcount()->fetch_sub(__sub_count);
                const bool __last = (__old == __sub_count);
                if (__last) {
                    for (uint8_t __stage = 0; __stage < __stages_count; ++__stage) {
                        __shared_state_get_stage(__stage)->__produced.~barrier();
                        __shared_state_get_stage(__stage)->__consumed.~barrier();
                    }
                    __released = true;
                }
            }
            __active = false;
            return __released;
        }

        _LIBCODE_INLINE_VISIBILITY
        void producer_acquire()
        {
            barrier<_Scope> & __stage_barrier = __shared_state_get_stage(__head)->__consumed;
            __stage_barrier.wait_parity(__consumed_phase_parity);
        }

        _LIBCODE_INLINE_VISIBILITY
        void producer_commit()
        {
            barrier<_Scope> & __stage_barrier = __shared_state_get_stage(__head)->__produced;
            (void)__memcpy_completion_impl::__defer(__completion_mechanism::__async_group, __single_thread_group{}, 0, __stage_barrier);
            (void)__stage_barrier.arrive();
            if (++__head == __stages_count) {
                __head = 0;
                __consumed_phase_parity = !__consumed_phase_parity;
            }
        }

        _LIBCODE_INLINE_VISIBILITY
        void consumer_wait()
        {
            barrier<_Scope> & __stage_barrier = __shared_state_get_stage(__tail)->__produced;
            __stage_barrier.wait_parity(__produced_phase_parity);
        }

        _LIBCODE_INLINE_VISIBILITY
        void consumer_release()
        {
            (void)__shared_state_get_stage(__tail)->__consumed.arrive();
            if (++__tail == __stages_count) {
                __tail = 0;
                __produced_phase_parity = !__produced_phase_parity;
            }
        }

        template<class _Rep, class _Period>
        _LIBCODE_INLINE_VISIBILITY
        bool consumer_wait_for(const _CODE_VSTD::chrono::duration<_Rep, _Period> & __duration)
        {
            barrier<_Scope> & __stage_barrier = __shared_state_get_stage(__tail)->__produced;
            return _CODE_VSTD::__libcpp_thread_poll_with_backoff(
                        _CODE_VSTD::__barrier_poll_tester_parity<barrier<_Scope>>(
                            &__stage_barrier,
                            __produced_phase_parity),
                        _CODE_VSTD::chrono::duration_cast<_CODE_VSTD::chrono::nanoseconds>(__duration)
            );
        }

        template<class _Clock, class _Duration>
        _LIBCODE_INLINE_VISIBILITY
        bool consumer_wait_until(const _CODE_VSTD::chrono::time_point<_Clock, _Duration> & __time_point)
        {
            return consumer_wait_for(__time_point - _Clock::now());
        }

    private:
        uint8_t __head               : 8;
        uint8_t __tail               : 8;
        const uint8_t __stages_count : 8;
        bool __consumed_phase_parity : 1;
        bool __produced_phase_parity : 1;
        bool __active                : 1;
        // TODO: Remove partitioned on next ABI break
        const bool __partitioned     : 1;
        char * const __shared_state;


        _LIBCODE_INLINE_VISIBILITY
        pipeline(char * __shared_state, uint8_t __stages_count, bool __partitioned)
            : __head(0)
            , __tail(0)
            , __stages_count(__stages_count)
            , __consumed_phase_parity(true)
            , __produced_phase_parity(false)
            , __active(true)
            , __partitioned(__partitioned)
            , __shared_state(__shared_state)
        {}

        _LIBCODE_INLINE_VISIBILITY
        __pipeline_stage<_Scope> * __shared_state_get_stage(uint8_t __stage)
        {
            ptrdiff_t __stage_offset = __stage * sizeof(__pipeline_stage<_Scope>);
            return reinterpret_cast<__pipeline_stage<_Scope>*>(__shared_state + __stage_offset);
        }

        _LIBCODE_INLINE_VISIBILITY
        atomic<uint32_t, _Scope> * __shared_state_get_refcount()
        {
            ptrdiff_t __refcount_offset = __stages_count * sizeof(__pipeline_stage<_Scope>);
            return reinterpret_cast<atomic<uint32_t, _Scope>*>(__shared_state + __refcount_offset);
        }

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state);

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state, size_t __producer_count);

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state, pipeline_role __role);
    };

    template<class _Group, thread_scope _Scope, uint8_t _Stages_count>
    _LIBCODE_INLINE_VISIBILITY
    pipeline<_Scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Scope, _Stages_count> * __shared_state)
    {
        const uint32_t __group_size = static_cast<uint32_t>(__group.size());
        const uint32_t __thread_rank = static_cast<uint32_t>(__group.thread_rank());

        if (__thread_rank == 0) {
            for (uint8_t __stage = 0; __stage < _Stages_count; ++__stage) {
                init(&__shared_state->__stages[__stage].__consumed, __group_size);
                init(&__shared_state->__stages[__stage].__produced, __group_size);
            }
            __shared_state->__refcount.store(__group_size, std::memory_order_relaxed);
        }
        __group.sync();

        return pipeline<_Scope>(reinterpret_cast<char*>(__shared_state->__stages), _Stages_count, false);
    }

    template<class _Group, thread_scope _Scope, uint8_t _Stages_count>
    _LIBCODE_INLINE_VISIBILITY
    pipeline<_Scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Scope, _Stages_count> * __shared_state, size_t __producer_count)
    {
        const uint32_t __group_size = static_cast<uint32_t>(__group.size());
        const uint32_t __thread_rank = static_cast<uint32_t>(__group.thread_rank());

        if (__thread_rank == 0) {
            const size_t __consumer_count = __group_size - __producer_count;
            for (uint8_t __stage = 0; __stage < _Stages_count; ++__stage) {
                init(&__shared_state->__stages[__stage].__consumed, __consumer_count);
                init(&__shared_state->__stages[__stage].__produced, __producer_count);
            }
            __shared_state->__refcount.store(__group_size, std::memory_order_relaxed);
        }
        __group.sync();

        return pipeline<_Scope>(reinterpret_cast<char*>(__shared_state->__stages), _Stages_count, true);
    }

    template<class _Group, thread_scope _Scope, uint8_t _Stages_count>
    _LIBCODE_INLINE_VISIBILITY
    pipeline<_Scope> make_pipeline(const _Group & __group, pipeline_shared_state<_Scope, _Stages_count> * __shared_state, pipeline_role __role)
    {
        const uint32_t __group_size = static_cast<uint32_t>(__group.size());
        const uint32_t __thread_rank = static_cast<uint32_t>(__group.thread_rank());

        if (__thread_rank == 0) {
            __shared_state->__refcount.store(0, std::memory_order_relaxed);
        }
        __group.sync();

        if (__role == pipeline_role::producer) {
            bool __elected;
            uint32_t __add_count;
NV_IF_TARGET(NV_IS_DEVICE,
            const uint32_t __match_mask = __match_any_sync(__activemask(), reinterpret_cast<uintptr_t>(&__shared_state->__refcount));
            const uint32_t __elected_id = __ffs(__match_mask) - 1;
            __elected = (__pipeline_asm_helper::__lane_id() == __elected_id);
            __add_count = __popc(__match_mask);
,
            __elected = true;
            __add_count = 1;
)
            if (__elected) {
                (void)__shared_state->__refcount.fetch_add(__add_count, std::memory_order_relaxed);
            }
        }
        __group.sync();

        if (__thread_rank == 0) {
            const uint32_t __producer_count = __shared_state->__refcount.load(std::memory_order_relaxed);
            const uint32_t __consumer_count = __group_size - __producer_count;
            for (uint8_t __stage = 0; __stage < _Stages_count; ++__stage) {
                init(&__shared_state->__stages[__stage].__consumed, __consumer_count);
                init(&__shared_state->__stages[__stage].__produced, __producer_count);
            }
            __shared_state->__refcount.store(__group_size, std::memory_order_relaxed);
        }
        __group.sync();

        return pipeline<_Scope>(reinterpret_cast<char*>(__shared_state->__stages), _Stages_count, true);
    }

_LIBCODECXX_END_NAMESPACE_CODE

_LIBCODECXX_BEGIN_NAMESPACE_CODE_DEVICE

    template<uint8_t _Prior>
    _CCCL_DEVICE
    void __pipeline_consumer_wait(pipeline<thread_scope_thread> & __pipeline);

    _CCCL_DEVICE
    inline void __pipeline_consumer_wait(pipeline<thread_scope_thread> & __pipeline, uint8_t __prior);

_LIBCODECXX_END_NAMESPACE_CODE_DEVICE

_LIBCODECXX_BEGIN_NAMESPACE_CODE

    template<>
    class pipeline<thread_scope_thread> {
    public:
        pipeline(pipeline &&) = default;
        pipeline(const pipeline &) = delete;
        pipeline & operator=(pipeline &&) = delete;
        pipeline & operator=(const pipeline &) = delete;

        _LIBCODE_INLINE_VISIBILITY
        ~pipeline() {}

        _LIBCODE_INLINE_VISIBILITY
        bool quit()
        {
            return true;
        }

        _LIBCODE_INLINE_VISIBILITY
        void producer_acquire() {}

        _LIBCODE_INLINE_VISIBILITY
        void producer_commit()
        {
NV_IF_TARGET(NV_PROVIDES_SM_80,
            asm volatile ("cp.async.commit_group;");
            ++__head;
)
        }

        _LIBCODE_INLINE_VISIBILITY
        void consumer_wait()
        {
NV_IF_TARGET(NV_PROVIDES_SM_80,
            if (__head == __tail) {
                return;
            }

            const uint8_t __prior = __head - __tail - 1;
            device::__pipeline_consumer_wait(*this, __prior);
            ++__tail;
)
        }

        _LIBCODE_INLINE_VISIBILITY
        void consumer_release() {}

        template<class _Rep, class _Period>
        _LIBCODE_INLINE_VISIBILITY
        bool consumer_wait_for(const _CODE_VSTD::chrono::duration<_Rep, _Period> & __duration)
        {
            (void)__duration;
            consumer_wait();
            return true;
        }

        template<class _Clock, class _Duration>
        _LIBCODE_INLINE_VISIBILITY
        bool consumer_wait_until(const _CODE_VSTD::chrono::time_point<_Clock, _Duration> & __time_point)
        {
            (void)__time_point;
            consumer_wait();
            return true;
        }

    private:
        uint8_t __head;
        uint8_t __tail;

        _LIBCODE_INLINE_VISIBILITY
        pipeline()
            : __head(0)
            , __tail(0)
        {}

        friend _LIBCODE_INLINE_VISIBILITY inline pipeline<thread_scope_thread> make_pipeline();

        template<uint8_t _Prior>
        friend _LIBCODE_INLINE_VISIBILITY
        void pipeline_consumer_wait_prior(pipeline<thread_scope_thread> & __pipeline);

        template<class _Group, thread_scope _Pipeline_scope, uint8_t _Pipeline_stages_count>
        friend _LIBCODE_INLINE_VISIBILITY
        pipeline<_Pipeline_scope> __make_pipeline(const _Group & __group, pipeline_shared_state<_Pipeline_scope, _Pipeline_stages_count> * __shared_state);
    };

_LIBCODECXX_END_NAMESPACE_CODE

_LIBCODECXX_BEGIN_NAMESPACE_CODE_DEVICE

    template<uint8_t _Prior>
    _CCCL_DEVICE
    void __pipeline_consumer_wait(pipeline<thread_scope_thread> & __pipeline)
    {
        (void)__pipeline;
NV_IF_TARGET(NV_PROVIDES_SM_80,
        constexpr uint8_t __max_prior = 8;

        asm volatile ("cp.async.wait_group %0;"
            :
            : "n"(_Prior < __max_prior ? _Prior : __max_prior));
)
    }

    _CCCL_DEVICE
    inline void __pipeline_consumer_wait(pipeline<thread_scope_thread> & __pipeline, uint8_t __prior)
    {
        switch (__prior) {
        case 0:  device::__pipeline_consumer_wait<0>(__pipeline); break;
        case 1:  device::__pipeline_consumer_wait<1>(__pipeline); break;
        case 2:  device::__pipeline_consumer_wait<2>(__pipeline); break;
        case 3:  device::__pipeline_consumer_wait<3>(__pipeline); break;
        case 4:  device::__pipeline_consumer_wait<4>(__pipeline); break;
        case 5:  device::__pipeline_consumer_wait<5>(__pipeline); break;
        case 6:  device::__pipeline_consumer_wait<6>(__pipeline); break;
        case 7:  device::__pipeline_consumer_wait<7>(__pipeline); break;
        default: device::__pipeline_consumer_wait<8>(__pipeline); break;
        }
    }

_LIBCODECXX_END_NAMESPACE_CODE_DEVICE

_LIBCODECXX_BEGIN_NAMESPACE_CODE

    _LIBCODE_INLINE_VISIBILITY
    inline pipeline<thread_scope_thread> make_pipeline()
    {
        return pipeline<thread_scope_thread>();
    }

    template<uint8_t _Prior>
    _LIBCODE_INLINE_VISIBILITY
    void pipeline_consumer_wait_prior(pipeline<thread_scope_thread> & __pipeline)
    {
        NV_IF_TARGET(NV_PROVIDES_SM_80,
            device::__pipeline_consumer_wait<_Prior>(__pipeline);
            __pipeline.__tail = __pipeline.__head - _Prior;
        )
    }

    template<thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    void pipeline_producer_commit(pipeline<thread_scope_thread> & __pipeline, barrier<_Scope> & __barrier)
    {
        (void)__pipeline;
        NV_IF_TARGET(NV_PROVIDES_SM_80,(
            (void)__memcpy_completion_impl::__defer(__completion_mechanism::__async_group, __single_thread_group{}, 0, __barrier);
        ));
    }

    template<typename _Group, class _Tp, typename _Size, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment __memcpy_async_pipeline(_Group const & __group, _Tp * __destination, _Tp const * __source, _Size __size, pipeline<_Scope> & __pipeline) {
        // 1. Set the completion mechanisms that can be used.
        //
        //    Do not (yet) allow async_bulk_group completion. Do not allow
        //    mbarrier_complete_tx completion, even though it may be possible if
        //    the pipeline has stage barriers in shared memory.
        _CODE_VSTD::uint32_t __allowed_completions = _CODE_VSTD::uint32_t(__completion_mechanism::__async_group);

        // Alignment: Use the maximum of the alignment of _Tp and that of a possible CODE::aligned_size_t.
        constexpr _CODE_VSTD::size_t __size_align = __get_size_align<_Size>::align;
        constexpr _CODE_VSTD::size_t __align = (alignof(_Tp) < __size_align) ? __size_align : alignof(_Tp);
        // Cast to char pointers. We don't need the type for alignment anymore and
        // erasing the types reduces the number of instantiations of down-stream
        // functions.
        char * __dest_char = reinterpret_cast<char*>(__destination);
        char const * __src_char = reinterpret_cast<char const *>(__source);

        // 2. Issue actual copy instructions.
        auto __cm =  __dispatch_memcpy_async<__align>(__group, __dest_char, __src_char, __size, __allowed_completions);

        // 3. No need to synchronize with copy instructions.
        return __memcpy_completion_impl::__defer(__cm, __group, __size, __pipeline);
    }

    template<typename _Group, class _Type, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(_Group const & __group, _Type * __destination, _Type const * __source, std::size_t __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__group, __destination, __source, __size, __pipeline);
    }

    template<typename _Group, class _Type, std::size_t _Alignment, thread_scope _Scope, std::size_t _Larger_alignment = (alignof(_Type) > _Alignment) ? alignof(_Type) : _Alignment>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(_Group const & __group, _Type * __destination, _Type const * __source, aligned_size_t<_Alignment> __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__group, __destination, __source, __size, __pipeline);
    }

    template<class _Type, typename _Size, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(_Type * __destination, _Type const * __source, _Size __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__single_thread_group{}, __destination, __source, __size, __pipeline);
    }

    template<typename _Group, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(_Group const & __group, void * __destination, void const * __source, std::size_t __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__group, reinterpret_cast<char *>(__destination), reinterpret_cast<char const *>(__source), __size, __pipeline);
    }

    template<typename _Group, std::size_t _Alignment, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(_Group const & __group, void * __destination, void const * __source, aligned_size_t<_Alignment> __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__group, reinterpret_cast<char*>(__destination), reinterpret_cast<char const *>(__source), __size, __pipeline);
    }

    template<typename _Size, thread_scope _Scope>
    _LIBCODE_INLINE_VISIBILITY
    async_contract_fulfillment memcpy_async(void * __destination, void const * __source, _Size __size, pipeline<_Scope> & __pipeline) {
        return __memcpy_async_pipeline(__single_thread_group{}, reinterpret_cast<char*>(__destination), reinterpret_cast<char const *>(__source), __size, __pipeline);
    }

_LIBCODECXX_END_NAMESPACE_CODE

#endif //_CODE_PIPELINE
