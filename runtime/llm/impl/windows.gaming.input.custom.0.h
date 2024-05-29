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
#ifndef LLM_OS_Gaming_Input_Custom_0_H
#define LLM_OS_Gaming_Input_Custom_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
}
LLM_EXPORT namespace llm::OS::Gaming::Input
{
    struct IGameController;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IInputStream;
}
LLM_EXPORT namespace llm::OS::Gaming::Input::Custom
{
    enum class GipFirmwareUpdateStatus : int32_t
    {
        Completed = 0,
        UpToDate = 1,
        Failed = 2,
    };
    enum class GipMessageClass : int32_t
    {
        Command = 0,
        LowLatency = 1,
        StandardLatency = 2,
    };
    enum class XusbDeviceSubtype : int32_t
    {
        Unknown = 0,
        Gamepad = 1,
        ArcadePad = 2,
        ArcadeStick = 3,
        FlightStick = 4,
        Wheel = 5,
        Guitar = 6,
        GuitarAlternate = 7,
        GuitarBass = 8,
        DrumKit = 9,
        DancePad = 10,
    };
    enum class XusbDeviceType : int32_t
    {
        Unknown = 0,
        Gamepad = 1,
    };
    struct ICustomGameControllerFactory;
    struct IGameControllerFactoryManagerStatics;
    struct IGameControllerFactoryManagerStatics2;
    struct IGameControllerInputSink;
    struct IGameControllerProvider;
    struct IGipFirmwareUpdateResult;
    struct IGipGameControllerInputSink;
    struct IGipGameControllerProvider;
    struct IHidGameControllerInputSink;
    struct IHidGameControllerProvider;
    struct IXusbGameControllerInputSink;
    struct IXusbGameControllerProvider;
    struct GameControllerFactoryManager;
    struct GipFirmwareUpdateResult;
    struct GipGameControllerProvider;
    struct HidGameControllerProvider;
    struct XusbGameControllerProvider;
    struct GameControllerVersionInfo;
    struct GipFirmwareUpdateProgress;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGameControllerInputSink>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGameControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GameControllerFactoryManager>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GipGameControllerProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::HidGameControllerProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::XusbGameControllerProvider>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GipMessageClass>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::XusbDeviceSubtype>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::XusbDeviceType>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo>{ using type = struct_category<uint16_t, uint16_t, uint16_t, uint16_t>; };
    template <> struct category<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress>{ using type = struct_category<double, uint32_t>; };
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GameControllerFactoryManager> = L"Windows.Gaming.Input.Custom.GameControllerFactoryManager";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult> = L"Windows.Gaming.Input.Custom.GipFirmwareUpdateResult";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GipGameControllerProvider> = L"Windows.Gaming.Input.Custom.GipGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::HidGameControllerProvider> = L"Windows.Gaming.Input.Custom.HidGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::XusbGameControllerProvider> = L"Windows.Gaming.Input.Custom.XusbGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus> = L"Windows.Gaming.Input.Custom.GipFirmwareUpdateStatus";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GipMessageClass> = L"Windows.Gaming.Input.Custom.GipMessageClass";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::XusbDeviceSubtype> = L"Windows.Gaming.Input.Custom.XusbDeviceSubtype";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::XusbDeviceType> = L"Windows.Gaming.Input.Custom.XusbDeviceType";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GameControllerVersionInfo> = L"Windows.Gaming.Input.Custom.GameControllerVersionInfo";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress> = L"Windows.Gaming.Input.Custom.GipFirmwareUpdateProgress";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory> = L"Windows.Gaming.Input.Custom.ICustomGameControllerFactory";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics> = L"Windows.Gaming.Input.Custom.IGameControllerFactoryManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2> = L"Windows.Gaming.Input.Custom.IGameControllerFactoryManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGameControllerInputSink> = L"Windows.Gaming.Input.Custom.IGameControllerInputSink";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGameControllerProvider> = L"Windows.Gaming.Input.Custom.IGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult> = L"Windows.Gaming.Input.Custom.IGipFirmwareUpdateResult";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink> = L"Windows.Gaming.Input.Custom.IGipGameControllerInputSink";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider> = L"Windows.Gaming.Input.Custom.IGipGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink> = L"Windows.Gaming.Input.Custom.IHidGameControllerInputSink";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider> = L"Windows.Gaming.Input.Custom.IHidGameControllerProvider";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink> = L"Windows.Gaming.Input.Custom.IXusbGameControllerInputSink";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider> = L"Windows.Gaming.Input.Custom.IXusbGameControllerProvider";
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory>{ 0x69A0AE5E,0x758E,0x4CBE,{ 0xAC,0xE6,0x62,0x15,0x5F,0xE9,0x12,0x6F } }; // 69A0AE5E-758E-4CBE-ACE6-62155FE9126F
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>{ 0x36CB66E3,0xD0A1,0x4986,{ 0xA2,0x4C,0x40,0xB1,0x37,0xDE,0xBA,0x9E } }; // 36CB66E3-D0A1-4986-A24C-40B137DEBA9E
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2>{ 0xEACE5644,0x19DF,0x4115,{ 0xB3,0x2A,0x27,0x93,0xE2,0xAE,0xA3,0xBB } }; // EACE5644-19DF-4115-B32A-2793E2AEA3BB
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGameControllerInputSink>{ 0x1FF6F922,0xC640,0x4C78,{ 0xA8,0x20,0x9A,0x71,0x5C,0x55,0x8B,0xCB } }; // 1FF6F922-C640-4C78-A820-9A715C558BCB
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGameControllerProvider>{ 0xE6D73982,0x2996,0x4559,{ 0xB1,0x6C,0x3E,0x57,0xD4,0x6E,0x58,0xD6 } }; // E6D73982-2996-4559-B16C-3E57D46E58D6
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult>{ 0x6B794D32,0x8553,0x4292,{ 0x8E,0x03,0xE1,0x66,0x51,0xA2,0xF8,0xBC } }; // 6B794D32-8553-4292-8E03-E16651A2F8BC
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink>{ 0xA2108ABF,0x09F1,0x43BC,{ 0xA1,0x40,0x80,0xF8,0x99,0xEC,0x36,0xFB } }; // A2108ABF-09F1-43BC-A140-80F899EC36FB
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider>{ 0xDBCF1E19,0x1AF5,0x45A8,{ 0xBF,0x02,0xA0,0xEE,0x50,0xC8,0x23,0xFC } }; // DBCF1E19-1AF5-45A8-BF02-A0EE50C823FC
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink>{ 0xF754C322,0x182D,0x40E4,{ 0xA1,0x26,0xFC,0xEE,0x4F,0xFA,0x1E,0x31 } }; // F754C322-182D-40E4-A126-FCEE4FFA1E31
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider>{ 0x95CE3AF4,0xABF0,0x4B68,{ 0xA0,0x81,0x3B,0x7D,0xE7,0x3F,0xF0,0xE7 } }; // 95CE3AF4-ABF0-4B68-A081-3B7DE73FF0E7
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink>{ 0xB2AC1D95,0x6ECB,0x42B3,{ 0x8A,0xAB,0x02,0x54,0x01,0xCA,0x47,0x12 } }; // B2AC1D95-6ECB-42B3-8AAB-025401CA4712
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider>{ 0x6E2971EB,0x0EFB,0x48B4,{ 0x80,0x8B,0x83,0x76,0x43,0xB2,0xF2,0x16 } }; // 6E2971EB-0EFB-48B4-808B-837643B2F216
    template <> struct default_interface<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult>{ using type = llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult; };
    template <> struct default_interface<llm::OS::Gaming::Input::Custom::GipGameControllerProvider>{ using type = llm::OS::Gaming::Input::Custom::IGipGameControllerProvider; };
    template <> struct default_interface<llm::OS::Gaming::Input::Custom::HidGameControllerProvider>{ using type = llm::OS::Gaming::Input::Custom::IHidGameControllerProvider; };
    template <> struct default_interface<llm::OS::Gaming::Input::Custom::XusbGameControllerProvider>{ using type = llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider; };
    template <> struct abi<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateGameController(void*, void**) noexcept = 0;
            virtual int32_t __stdcall OnGameControllerAdded(void*) noexcept = 0;
            virtual int32_t __stdcall OnGameControllerRemoved(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RegisterCustomFactoryForGipInterface(void*, llm::guid) noexcept = 0;
            virtual int32_t __stdcall RegisterCustomFactoryForHardwareId(void*, uint16_t, uint16_t) noexcept = 0;
            virtual int32_t __stdcall RegisterCustomFactoryForXusbType(void*, int32_t, int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetFactoryControllerFromGameController(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnInputResumed(uint64_t) noexcept = 0;
            virtual int32_t __stdcall OnInputSuspended(uint64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FirmwareVersionInfo(struct struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo*) noexcept = 0;
            virtual int32_t __stdcall get_HardwareProductId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_HardwareVendorId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_HardwareVersionInfo(struct struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo*) noexcept = 0;
            virtual int32_t __stdcall get_IsConnected(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ExtendedErrorCode(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_FinalComponentId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnKeyReceived(uint64_t, uint8_t, bool) noexcept = 0;
            virtual int32_t __stdcall OnMessageReceived(uint64_t, int32_t, uint8_t, uint8_t, uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SendMessage(int32_t, uint8_t, uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall SendReceiveMessage(int32_t, uint8_t, uint32_t, uint8_t*, uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall UpdateFirmwareAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnInputReportReceived(uint64_t, uint8_t, uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UsageId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_UsagePage(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall GetFeatureReport(uint8_t, uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall SendFeatureReport(uint8_t, uint32_t, uint8_t*) noexcept = 0;
            virtual int32_t __stdcall SendOutputReport(uint8_t, uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall OnInputReceived(uint64_t, uint8_t, uint32_t, uint8_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetVibration(double, double) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_ICustomGameControllerFactory
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateGameController(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const;
        LLM_IMPL_AUTO(void) OnGameControllerAdded(llm::OS::Gaming::Input::IGameController const& value) const;
        LLM_IMPL_AUTO(void) OnGameControllerRemoved(llm::OS::Gaming::Input::IGameController const& value) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_ICustomGameControllerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics
    {
        LLM_IMPL_AUTO(void) RegisterCustomFactoryForGipInterface(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::guid const& interfaceId) const;
        LLM_IMPL_AUTO(void) RegisterCustomFactoryForHardwareId(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, uint16_t hardwareVendorId, uint16_t hardwareProductId) const;
        LLM_IMPL_AUTO(void) RegisterCustomFactoryForXusbType(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::Custom::XusbDeviceType const& xusbType, llm::OS::Gaming::Input::Custom::XusbDeviceSubtype const& xusbSubtype) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::IGameController) TryGetFactoryControllerFromGameController(llm::OS::Gaming::Input::Custom::ICustomGameControllerFactory const& factory, llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGameControllerFactoryManagerStatics2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGameControllerFactoryManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGameControllerInputSink
    {
        LLM_IMPL_AUTO(void) OnInputResumed(uint64_t timestamp) const;
        LLM_IMPL_AUTO(void) OnInputSuspended(uint64_t timestamp) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGameControllerInputSink>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGameControllerInputSink<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGameControllerProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GameControllerVersionInfo) FirmwareVersionInfo() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) HardwareProductId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) HardwareVendorId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GameControllerVersionInfo) HardwareVersionInfo() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsConnected() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGameControllerProvider>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGameControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGipFirmwareUpdateResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) ExtendedErrorCode() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) FinalComponentId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::Custom::GipFirmwareUpdateStatus) Status() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGipFirmwareUpdateResult>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGipFirmwareUpdateResult<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGipGameControllerInputSink
    {
        LLM_IMPL_AUTO(void) OnKeyReceived(uint64_t timestamp, uint8_t keyCode, bool isPressed) const;
        LLM_IMPL_AUTO(void) OnMessageReceived(uint64_t timestamp, llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, uint8_t sequenceId, array_view<uint8_t const> messageBuffer) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGipGameControllerInputSink>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGipGameControllerInputSink<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IGipGameControllerProvider
    {
        LLM_IMPL_AUTO(void) SendMessage(llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, array_view<uint8_t const> messageBuffer) const;
        LLM_IMPL_AUTO(void) SendReceiveMessage(llm::OS::Gaming::Input::Custom::GipMessageClass const& messageClass, uint8_t messageId, array_view<uint8_t const> requestMessageBuffer, array_view<uint8_t> responseMessageBuffer) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Gaming::Input::Custom::GipFirmwareUpdateResult, llm::OS::Gaming::Input::Custom::GipFirmwareUpdateProgress>) UpdateFirmwareAsync(llm::OS::Storage::Streams::IInputStream const& firmwareImage) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IGipGameControllerProvider>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IGipGameControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IHidGameControllerInputSink
    {
        LLM_IMPL_AUTO(void) OnInputReportReceived(uint64_t timestamp, uint8_t reportId, array_view<uint8_t const> reportBuffer) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IHidGameControllerInputSink>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IHidGameControllerInputSink<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) UsageId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) UsagePage() const;
        LLM_IMPL_AUTO(void) GetFeatureReport(uint8_t reportId, array_view<uint8_t> reportBuffer) const;
        LLM_IMPL_AUTO(void) SendFeatureReport(uint8_t reportId, array_view<uint8_t const> reportBuffer) const;
        LLM_IMPL_AUTO(void) SendOutputReport(uint8_t reportId, array_view<uint8_t const> reportBuffer) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IHidGameControllerProvider>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IHidGameControllerProvider<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IXusbGameControllerInputSink
    {
        LLM_IMPL_AUTO(void) OnInputReceived(uint64_t timestamp, uint8_t reportId, array_view<uint8_t const> inputBuffer) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IXusbGameControllerInputSink>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IXusbGameControllerInputSink<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_Custom_IXusbGameControllerProvider
    {
        LLM_IMPL_AUTO(void) SetVibration(double lowFrequencyMotorSpeed, double highFrequencyMotorSpeed) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::Custom::IXusbGameControllerProvider>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_Custom_IXusbGameControllerProvider<D>;
    };
    struct struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo
    {
        uint16_t Major;
        uint16_t Minor;
        uint16_t Build;
        uint16_t Revision;
    };
    template <> struct abi<Windows::Gaming::Input::Custom::GameControllerVersionInfo>
    {
        using type = struct_Windows_Gaming_Input_Custom_GameControllerVersionInfo;
    };
    struct struct_Windows_Gaming_Input_Custom_GipFirmwareUpdateProgress
    {
        double PercentCompleted;
        uint32_t CurrentComponentId;
    };
    template <> struct abi<Windows::Gaming::Input::Custom::GipFirmwareUpdateProgress>
    {
        using type = struct_Windows_Gaming_Input_Custom_GipFirmwareUpdateProgress;
    };
}
#endif