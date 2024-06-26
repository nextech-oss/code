/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_Web_Http_Diagnostics_H
#define LLM_OS_Web_Http_Diagnostics_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Web.Http.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.Diagnostics.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
#include "llm/impl/Windows.Web.Http.Diagnostics.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestSent(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->add_RequestSent(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestSent_revoker consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestSent(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RequestSent_revoker>(this, RequestSent(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestSent(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->remove_RequestSent(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::ResponseReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->add_ResponseReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::ResponseReceived_revoker consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::ResponseReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ResponseReceived_revoker>(this, ResponseReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::ResponseReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->remove_ResponseReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestResponseCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->add_RequestResponseCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestResponseCompleted_revoker consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestResponseCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RequestResponseCompleted_revoker>(this, RequestResponseCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProvider<D>::RequestResponseCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider)->remove_RequestResponseCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::Timestamps() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_Timestamps(&value));
        return llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::RequestedUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_RequestedUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ProcessId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ProcessId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::ThreadId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_ThreadId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::Initiator() const
    {
        llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_Initiator(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseCompletedEventArgs<D>::SourceLocations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs)->get_SourceLocations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::CacheCheckedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_CacheCheckedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ConnectionInitiatedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_ConnectionInitiatedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::NameResolvedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_NameResolvedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::SslNegotiatedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_SslNegotiatedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ConnectionCompletedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_ConnectionCompletedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::RequestSentTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_RequestSentTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::RequestCompletedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_RequestCompletedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ResponseReceivedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_ResponseReceivedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestResponseTimestamps<D>::ResponseCompletedTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps)->get_ResponseCompletedTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_Message(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::ProcessId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_ProcessId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::ThreadId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_ThreadId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::Initiator() const
    {
        llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_Initiator(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderRequestSentEventArgs<D>::SourceLocations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs)->get_SourceLocations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::ActivityId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs)->get_ActivityId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderResponseReceivedEventArgs<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs)->get_Message(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticProviderStatics<D>::CreateFromProcessDiagnosticInfo(llm::OS::System::Diagnostics::ProcessDiagnosticInfo const& processDiagnosticInfo) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics)->CreateFromProcessDiagnosticInfo(*(void**)(&processDiagnosticInfo), &value));
        return llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticSourceLocation<D>::SourceUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation)->get_SourceUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticSourceLocation<D>::LineNumber() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation)->get_LineNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Web_Http_Diagnostics_IHttpDiagnosticSourceLocation<D>::ColumnNumber() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation)->get_ColumnNumber(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider>
    {
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RequestSent(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RequestSent(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RequestSent(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestSent(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ResponseReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ResponseReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ResponseReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResponseReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RequestResponseCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RequestResponseCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider, llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RequestResponseCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestResponseCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs>
    {
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamps(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps>(this->shim().Timestamps());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestedUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().RequestedUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ProcessId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ThreadId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ThreadId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Initiator(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator>(this->shim().Initiator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceLocations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>>(this->shim().SourceLocations());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps>
    {
        int32_t __stdcall get_CacheCheckedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().CacheCheckedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionInitiatedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().ConnectionInitiatedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NameResolvedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().NameResolvedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SslNegotiatedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().SslNegotiatedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionCompletedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().ConnectionCompletedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestSentTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().RequestSentTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestCompletedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().RequestCompletedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseReceivedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().ResponseReceivedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseCompletedTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().ResponseCompletedTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProcessId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ProcessId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ThreadId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ThreadId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Initiator(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Diagnostics::HttpDiagnosticRequestInitiator>(this->shim().Initiator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceLocations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation>>(this->shim().SourceLocations());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivityId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ActivityId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics>
    {
        int32_t __stdcall CreateFromProcessDiagnosticInfo(void* processDiagnosticInfo, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider>(this->shim().CreateFromProcessDiagnosticInfo(*reinterpret_cast<llm::OS::System::Diagnostics::ProcessDiagnosticInfo const*>(&processDiagnosticInfo)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation> : produce_base<D, llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation>
    {
        int32_t __stdcall get_SourceUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().SourceUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LineNumber(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().LineNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColumnNumber(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().ColumnNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Web::Http::Diagnostics
{
    inline auto HttpDiagnosticProvider::CreateFromProcessDiagnosticInfo(llm::OS::System::Diagnostics::ProcessDiagnosticInfo const& processDiagnosticInfo)
    {
        return impl::call_factory<HttpDiagnosticProvider, IHttpDiagnosticProviderStatics>([&](IHttpDiagnosticProviderStatics const& f) { return f.CreateFromProcessDiagnosticInfo(processDiagnosticInfo); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestResponseTimestamps> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderRequestSentEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderResponseReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticProviderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::IHttpDiagnosticSourceLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestResponseTimestamps> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderRequestSentEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticProviderResponseReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::Diagnostics::HttpDiagnosticSourceLocation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
