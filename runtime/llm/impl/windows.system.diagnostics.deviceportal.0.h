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
#ifndef LLM_OS_System_Diagnostics_DevicePortal_0_H
#define LLM_OS_System_Diagnostics_DevicePortal_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel::AppService
{
    struct AppServiceConnection;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Networking::Sockets
{
    enum class MessageWebSocketReceiveMode : int32_t;
    struct ServerMessageWebSocket;
    struct ServerStreamWebSocket;
    enum class SocketMessageType : int32_t;
}
LLM_EXPORT namespace llm:OS::Web::Http
{
    struct HttpRequestMessage;
    struct HttpResponseMessage;
}
LLM_EXPORT namespace llm:OS::System::Diagnostics::DevicePortal
{
    enum class DevicePortalConnectionClosedReason : int32_t
    {
        Unknown = 0,
        ResourceLimitsExceeded = 1,
        ProtocolError = 2,
        NotAuthorized = 3,
        UserNotPresent = 4,
        ServiceTerminated = 5,
    };
    struct IDevicePortalConnection;
    struct IDevicePortalConnectionClosedEventArgs;
    struct IDevicePortalConnectionRequestReceivedEventArgs;
    struct IDevicePortalConnectionStatics;
    struct IDevicePortalWebSocketConnection;
    struct IDevicePortalWebSocketConnectionRequestReceivedEventArgs;
    struct DevicePortalConnection;
    struct DevicePortalConnectionClosedEventArgs;
    struct DevicePortalConnectionRequestReceivedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection> = L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnection";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> = L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> = L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionRequestReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason> = L"Windows.System.Diagnostics.DevicePortal.DevicePortalConnectionClosedReason";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnection";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionClosedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionRequestReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalConnectionStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalWebSocketConnection";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs> = L"Windows.System.Diagnostics.DevicePortal.IDevicePortalWebSocketConnectionRequestReceivedEventArgs";
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>{ 0x0F447F51,0x1198,0x4DA1,{ 0x8D,0x54,0xBD,0xEF,0x39,0x3E,0x09,0xB6 } }; // 0F447F51-1198-4DA1-8D54-BDEF393E09B6
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>{ 0xFCF70E38,0x7032,0x428C,{ 0x9F,0x50,0x94,0x5C,0x15,0xA9,0xF0,0xCB } }; // FCF70E38-7032-428C-9F50-945C15A9F0CB
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>{ 0x64DAE045,0x6FDA,0x4459,{ 0x9E,0xBD,0xEC,0xCE,0x22,0xE3,0x85,0x59 } }; // 64DAE045-6FDA-4459-9EBD-ECCE22E38559
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>{ 0x4BBE31E7,0xE9B9,0x4645,{ 0x8F,0xED,0xA5,0x3E,0xEA,0x0E,0xDB,0xD6 } }; // 4BBE31E7-E9B9-4645-8FED-A53EEA0EDBD6
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>{ 0x67657920,0xD65A,0x42F0,{ 0xAE,0xF4,0x78,0x78,0x08,0x09,0x8B,0x7B } }; // 67657920-D65A-42F0-AEF4-787808098B7B
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>{ 0x79FDCABA,0x175C,0x4739,{ 0x9F,0x74,0xDD,0xA7,0x97,0xC3,0x5B,0x3F } }; // 79FDCABA-175C-4739-9F74-DDA797C35B3F
    template <> struct default_interface<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection>{ using type = llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection; };
    template <> struct default_interface<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs>{ using type = llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs; };
    template <> struct default_interface<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs>{ using type = llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs; };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RequestReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RequestReceived(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RequestMessage(void**) noexcept = 0;
            virtual int32_t __stdcall get_ResponseMessage(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForAppServiceConnection(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest2(void*, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerMessageWebSocketForRequest3(void*, int32_t, void*, uint32_t, uint32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerStreamWebSocketForRequest(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetServerStreamWebSocketForRequest2(void*, void*, uint32_t, bool, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsWebSocketUpgradeRequest(bool*) noexcept = 0;
            virtual int32_t __stdcall get_WebSocketProtocolsRequested(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection
    {
        LLM_IMPL_AUTO(llm::event_token) Closed(llm:OS::Foundation::TypedEventHandler<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const;
        using Closed_revoker = impl::event_revoker<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection, &impl::abi_t<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RequestReceived(llm:OS::Foundation::TypedEventHandler<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const;
        using RequestReceived_revoker = impl::event_revoker<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection, &impl::abi_t<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>::remove_RequestReceived>;
        [[nodiscard]] RequestReceived_revoker RequestReceived(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) RequestReceived(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionClosedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason) Reason() const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionClosedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Web::Http::HttpRequestMessage) RequestMessage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Web::Http::HttpResponseMessage) ResponseMessage() const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::Diagnostics::DevicePortal::DevicePortalConnection) GetForAppServiceConnection(llm:OS::ApplicationModel::AppService::AppServiceConnection const& appServiceConnection) const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection
    {
        LLM_IMPL_AUTO(llm:OS::Networking::Sockets::ServerMessageWebSocket) GetServerMessageWebSocketForRequest(llm:OS::Web::Http::HttpRequestMessage const& request) const;
        LLM_IMPL_AUTO(llm:OS::Networking::Sockets::ServerMessageWebSocket) GetServerMessageWebSocketForRequest(llm:OS::Web::Http::HttpRequestMessage const& request, llm:OS::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol) const;
        LLM_IMPL_AUTO(llm:OS::Networking::Sockets::ServerMessageWebSocket) GetServerMessageWebSocketForRequest(llm:OS::Web::Http::HttpRequestMessage const& request, llm:OS::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, uint32_t maxMessageSize, llm:OS::Networking::Sockets::MessageWebSocketReceiveMode const& receiveMode) const;
        LLM_IMPL_AUTO(llm:OS::Networking::Sockets::ServerStreamWebSocket) GetServerStreamWebSocketForRequest(llm:OS::Web::Http::HttpRequestMessage const& request) const;
        LLM_IMPL_AUTO(llm:OS::Networking::Sockets::ServerStreamWebSocket) GetServerStreamWebSocketForRequest(llm:OS::Web::Http::HttpRequestMessage const& request, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, bool noDelay) const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsWebSocketUpgradeRequest() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) WebSocketProtocolsRequested() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs<D>;
    };
}
#endif
