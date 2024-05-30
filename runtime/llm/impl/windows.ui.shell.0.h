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
#ifndef LLM_OS_UI_Shell_0_H
#define LLM_OS_UI_Shell_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel::Core
{
    struct AppListEntry;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Graphics::Imaging
{
    struct BitmapSize;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct WindowId;
}
LLM_EXPORT namespace llm:OS::UI::StartScreen
{
    struct SecondaryTile;
}
LLM_EXPORT namespace llm:OS::UI::Shell
{
    enum class SecurityAppKind : int32_t
    {
        WebProtection = 0,
    };
    enum class SecurityAppState : int32_t
    {
        Disabled = 0,
        Enabled = 1,
    };
    enum class SecurityAppSubstatus : int32_t
    {
        Undetermined = 0,
        NoActionNeeded = 1,
        ActionRecommended = 2,
        ActionNeeded = 3,
    };
    enum class ShareWindowCommand : int32_t
    {
        None = 0,
        StartSharing = 1,
        StopSharing = 2,
    };
    struct IAdaptiveCard;
    struct IAdaptiveCardBuilderStatics;
    struct IFocusSession;
    struct IFocusSessionManager;
    struct IFocusSessionManagerStatics;
    struct ISecurityAppManager;
    struct IShareWindowCommandEventArgs;
    struct IShareWindowCommandSource;
    struct IShareWindowCommandSourceStatics;
    struct ITaskbarManager;
    struct ITaskbarManager2;
    struct ITaskbarManagerDesktopAppSupportStatics;
    struct ITaskbarManagerStatics;
    struct IWindowTab;
    struct IWindowTabCloseRequestedEventArgs;
    struct IWindowTabCollection;
    struct IWindowTabGroup;
    struct IWindowTabIcon;
    struct IWindowTabIconStatics;
    struct IWindowTabManager;
    struct IWindowTabManagerStatics;
    struct IWindowTabSwitchRequestedEventArgs;
    struct IWindowTabTearOutRequestedEventArgs;
    struct IWindowTabThumbnailRequestedEventArgs;
    struct AdaptiveCardBuilder;
    struct FocusSession;
    struct FocusSessionManager;
    struct SecurityAppManager;
    struct ShareWindowCommandEventArgs;
    struct ShareWindowCommandSource;
    struct TaskbarManager;
    struct WindowTab;
    struct WindowTabCloseRequestedEventArgs;
    struct WindowTabCollection;
    struct WindowTabGroup;
    struct WindowTabIcon;
    struct WindowTabManager;
    struct WindowTabSwitchRequestedEventArgs;
    struct WindowTabTearOutRequestedEventArgs;
    struct WindowTabThumbnailRequestedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Shell::IAdaptiveCard>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IAdaptiveCardBuilderStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IFocusSession>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IFocusSessionManager>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IFocusSessionManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::ISecurityAppManager>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IShareWindowCommandEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IShareWindowCommandSource>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IShareWindowCommandSourceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::ITaskbarManager>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::ITaskbarManager2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::ITaskbarManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTab>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabCollection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabGroup>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabIcon>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabIconStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabManager>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Shell::AdaptiveCardBuilder>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::FocusSession>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::FocusSessionManager>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::SecurityAppManager>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::ShareWindowCommandEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::ShareWindowCommandSource>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::TaskbarManager>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTab>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabCloseRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabCollection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabGroup>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabIcon>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabManager>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabSwitchRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabTearOutRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::WindowTabThumbnailRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Shell::SecurityAppKind>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Shell::SecurityAppState>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Shell::SecurityAppSubstatus>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Shell::ShareWindowCommand>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::AdaptiveCardBuilder> = L"Windows.UI.Shell.AdaptiveCardBuilder";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::FocusSession> = L"Windows.UI.Shell.FocusSession";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::FocusSessionManager> = L"Windows.UI.Shell.FocusSessionManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::SecurityAppManager> = L"Windows.UI.Shell.SecurityAppManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ShareWindowCommandEventArgs> = L"Windows.UI.Shell.ShareWindowCommandEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ShareWindowCommandSource> = L"Windows.UI.Shell.ShareWindowCommandSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::TaskbarManager> = L"Windows.UI.Shell.TaskbarManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTab> = L"Windows.UI.Shell.WindowTab";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabCloseRequestedEventArgs> = L"Windows.UI.Shell.WindowTabCloseRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabCollection> = L"Windows.UI.Shell.WindowTabCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabGroup> = L"Windows.UI.Shell.WindowTabGroup";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabIcon> = L"Windows.UI.Shell.WindowTabIcon";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabManager> = L"Windows.UI.Shell.WindowTabManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabSwitchRequestedEventArgs> = L"Windows.UI.Shell.WindowTabSwitchRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabTearOutRequestedEventArgs> = L"Windows.UI.Shell.WindowTabTearOutRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> = L"Windows.UI.Shell.WindowTabThumbnailRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::SecurityAppKind> = L"Windows.UI.Shell.SecurityAppKind";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::SecurityAppState> = L"Windows.UI.Shell.SecurityAppState";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::SecurityAppSubstatus> = L"Windows.UI.Shell.SecurityAppSubstatus";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ShareWindowCommand> = L"Windows.UI.Shell.ShareWindowCommand";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IAdaptiveCard> = L"Windows.UI.Shell.IAdaptiveCard";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IAdaptiveCardBuilderStatics> = L"Windows.UI.Shell.IAdaptiveCardBuilderStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IFocusSession> = L"Windows.UI.Shell.IFocusSession";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IFocusSessionManager> = L"Windows.UI.Shell.IFocusSessionManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IFocusSessionManagerStatics> = L"Windows.UI.Shell.IFocusSessionManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ISecurityAppManager> = L"Windows.UI.Shell.ISecurityAppManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IShareWindowCommandEventArgs> = L"Windows.UI.Shell.IShareWindowCommandEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IShareWindowCommandSource> = L"Windows.UI.Shell.IShareWindowCommandSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IShareWindowCommandSourceStatics> = L"Windows.UI.Shell.IShareWindowCommandSourceStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ITaskbarManager> = L"Windows.UI.Shell.ITaskbarManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ITaskbarManager2> = L"Windows.UI.Shell.ITaskbarManager2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics> = L"Windows.UI.Shell.ITaskbarManagerDesktopAppSupportStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::ITaskbarManagerStatics> = L"Windows.UI.Shell.ITaskbarManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTab> = L"Windows.UI.Shell.IWindowTab";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs> = L"Windows.UI.Shell.IWindowTabCloseRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabCollection> = L"Windows.UI.Shell.IWindowTabCollection";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabGroup> = L"Windows.UI.Shell.IWindowTabGroup";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabIcon> = L"Windows.UI.Shell.IWindowTabIcon";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabIconStatics> = L"Windows.UI.Shell.IWindowTabIconStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabManager> = L"Windows.UI.Shell.IWindowTabManager";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabManagerStatics> = L"Windows.UI.Shell.IWindowTabManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs> = L"Windows.UI.Shell.IWindowTabSwitchRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs> = L"Windows.UI.Shell.IWindowTabTearOutRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs> = L"Windows.UI.Shell.IWindowTabThumbnailRequestedEventArgs";
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IAdaptiveCard>{ 0x72D0568C,0xA274,0x41CD,{ 0x82,0xA8,0x98,0x9D,0x40,0xB9,0xB0,0x5E } }; // 72D0568C-A274-41CD-82A8-989D40B9B05E
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IAdaptiveCardBuilderStatics>{ 0x766D8F08,0xD3FE,0x4347,{ 0xA0,0xBC,0xB9,0xEA,0x9A,0x6D,0xC2,0x8E } }; // 766D8F08-D3FE-4347-A0BC-B9EA9A6DC28E
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IFocusSession>{ 0x069FBAB8,0x0E84,0x5F2F,{ 0x86,0x14,0x9B,0x65,0x44,0x32,0x62,0x77 } }; // 069FBAB8-0E84-5F2F-8614-9B6544326277
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IFocusSessionManager>{ 0xE7FFBAA9,0xD8BE,0x5DBF,{ 0xBA,0xC6,0x49,0x36,0x48,0x42,0xE3,0x7E } }; // E7FFBAA9-D8BE-5DBF-BAC6-49364842E37E
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IFocusSessionManagerStatics>{ 0x834DF764,0xCB9A,0x5D0A,{ 0xAA,0x9F,0x73,0xDF,0x4F,0x24,0x93,0x95 } }; // 834DF764-CB9A-5D0A-AA9F-73DF4F249395
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::ISecurityAppManager>{ 0x96AC500C,0xAED4,0x561D,{ 0xBD,0xE8,0x95,0x35,0x20,0x34,0x3A,0x2D } }; // 96AC500C-AED4-561D-BDE8-953520343A2D
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IShareWindowCommandEventArgs>{ 0x4578DC09,0xA523,0x5756,{ 0xA9,0x95,0xE4,0xFE,0xB9,0x91,0xFF,0xF0 } }; // 4578DC09-A523-5756-A995-E4FEB991FFF0
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IShareWindowCommandSource>{ 0xCB3B7AE3,0x6B9C,0x561E,{ 0xBC,0xCC,0x61,0xE6,0x8E,0x0A,0xBF,0xEF } }; // CB3B7AE3-6B9C-561E-BCCC-61E68E0ABFEF
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IShareWindowCommandSourceStatics>{ 0xB0EB6656,0x9CAC,0x517C,{ 0xB6,0xC7,0x8E,0xF7,0x15,0x08,0x42,0x95 } }; // B0EB6656-9CAC-517C-B6C7-8EF715084295
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::ITaskbarManager>{ 0x87490A19,0x1AD9,0x49F4,{ 0xB2,0xE8,0x86,0x73,0x8D,0xC5,0xAC,0x40 } }; // 87490A19-1AD9-49F4-B2E8-86738DC5AC40
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::ITaskbarManager2>{ 0x79F0A06E,0x7B02,0x4911,{ 0x91,0x8C,0xDE,0xE0,0xBB,0xD2,0x0B,0xA4 } }; // 79F0A06E-7B02-4911-918C-DEE0BBD20BA4
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics>{ 0xCDFEFD63,0xE879,0x4134,{ 0xB9,0xA7,0x82,0x83,0xF0,0x5F,0x94,0x80 } }; // CDFEFD63-E879-4134-B9A7-8283F05F9480
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::ITaskbarManagerStatics>{ 0xDB32AB74,0xDE52,0x4FE6,{ 0xB7,0xB6,0x95,0xFF,0x9F,0x83,0x95,0xDF } }; // DB32AB74-DE52-4FE6-B7B6-95FF9F8395DF
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTab>{ 0x551E776A,0x7928,0x4D60,{ 0xBD,0xD9,0x67,0x2B,0x5A,0x57,0x58,0xEB } }; // 551E776A-7928-4D60-BDD9-672B5A5758EB
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs>{ 0x477282E9,0xEEC4,0x5882,{ 0x98,0x89,0x2D,0xD6,0x4D,0x0F,0x9F,0xB6 } }; // 477282E9-EEC4-5882-9889-2DD64D0F9FB6
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabCollection>{ 0xACCD0D6C,0xED07,0x519A,{ 0x8C,0x33,0x17,0xE0,0x2E,0x7E,0x9B,0x0F } }; // ACCD0D6C-ED07-519A-8C33-17E02E7E9B0F
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabGroup>{ 0xA9C2C4FE,0x6CFE,0x449C,{ 0x8B,0x57,0x57,0x56,0x77,0x1A,0xBE,0x56 } }; // A9C2C4FE-6CFE-449C-8B57-5756771ABE56
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabIcon>{ 0xF92F398F,0x3669,0x4D0C,{ 0xA1,0x83,0x14,0xDD,0xAE,0x6F,0x65,0x38 } }; // F92F398F-3669-4D0C-A183-14DDAE6F6538
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabIconStatics>{ 0x2E18D95E,0x2CBB,0x4084,{ 0xAF,0x0C,0x36,0xEE,0x1C,0x2D,0x54,0xB1 } }; // 2E18D95E-2CBB-4084-AF0C-36EE1C2D54B1
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabManager>{ 0x97B3C697,0xF43A,0x43E7,{ 0xB3,0xA2,0xE8,0x89,0xA9,0x83,0x55,0x99 } }; // 97B3C697-F43A-43E7-B3A2-E889A9835599
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabManagerStatics>{ 0x76755668,0x45F0,0x4E0B,{ 0x81,0x72,0x4E,0x6D,0x9D,0x0F,0x87,0xBD } }; // 76755668-45F0-4E0B-8172-4E6D9D0F87BD
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs>{ 0x7CBC421A,0x58A4,0x568B,{ 0xA3,0x51,0xF8,0xA9,0x47,0xA5,0xAA,0xD8 } }; // 7CBC421A-58A4-568B-A351-F8A947A5AAD8
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs>{ 0x17D66659,0x5005,0x5ECE,{ 0x99,0xAF,0x56,0x63,0x06,0xE7,0x36,0x42 } }; // 17D66659-5005-5ECE-99AF-566306E73642
    template <> inline constexpr guid guid_v<llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs>{ 0x2D558E54,0x9C4E,0x5ABC,{ 0xAB,0x72,0x33,0x50,0xFB,0x49,0x37,0xA0 } }; // 2D558E54-9C4E-5ABC-AB72-3350FB4937A0
    template <> struct default_interface<llm:OS::UI::Shell::FocusSession>{ using type = llm:OS::UI::Shell::IFocusSession; };
    template <> struct default_interface<llm:OS::UI::Shell::FocusSessionManager>{ using type = llm:OS::UI::Shell::IFocusSessionManager; };
    template <> struct default_interface<llm:OS::UI::Shell::SecurityAppManager>{ using type = llm:OS::UI::Shell::ISecurityAppManager; };
    template <> struct default_interface<llm:OS::UI::Shell::ShareWindowCommandEventArgs>{ using type = llm:OS::UI::Shell::IShareWindowCommandEventArgs; };
    template <> struct default_interface<llm:OS::UI::Shell::ShareWindowCommandSource>{ using type = llm:OS::UI::Shell::IShareWindowCommandSource; };
    template <> struct default_interface<llm:OS::UI::Shell::TaskbarManager>{ using type = llm:OS::UI::Shell::ITaskbarManager; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTab>{ using type = llm:OS::UI::Shell::IWindowTab; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabCloseRequestedEventArgs>{ using type = llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabCollection>{ using type = llm:OS::UI::Shell::IWindowTabCollection; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabGroup>{ using type = llm:OS::UI::Shell::IWindowTabGroup; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabIcon>{ using type = llm:OS::UI::Shell::IWindowTabIcon; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabManager>{ using type = llm:OS::UI::Shell::IWindowTabManager; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabSwitchRequestedEventArgs>{ using type = llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabTearOutRequestedEventArgs>{ using type = llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs; };
    template <> struct default_interface<llm:OS::UI::Shell::WindowTabThumbnailRequestedEventArgs>{ using type = llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs; };
    template <> struct abi<llm:OS::UI::Shell::IAdaptiveCard>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ToJson(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IAdaptiveCardBuilderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAdaptiveCardFromJson(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IFocusSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall End() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IFocusSessionManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsFocusActive(bool*) noexcept = 0;
            virtual int32_t __stdcall GetSession(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryStartFocusSession(void**) noexcept = 0;
            virtual int32_t __stdcall TryStartFocusSession2(int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall DeactivateFocus() noexcept = 0;
            virtual int32_t __stdcall add_IsFocusActiveChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_IsFocusActiveChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IFocusSessionManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::ISecurityAppManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Register(int32_t, void*, void*, bool, llm::guid*) noexcept = 0;
            virtual int32_t __stdcall Unregister(int32_t, llm::guid) noexcept = 0;
            virtual int32_t __stdcall UpdateState(int32_t, llm::guid, int32_t, int32_t, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IShareWindowCommandEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WindowId(struct struct_Windows_UI_WindowId*) noexcept = 0;
            virtual int32_t __stdcall get_Command(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Command(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IShareWindowCommandSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall ReportCommandChanged() noexcept = 0;
            virtual int32_t __stdcall add_CommandRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CommandRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_CommandInvoked(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CommandInvoked(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IShareWindowCommandSourceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::ITaskbarManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsPinningAllowed(bool*) noexcept = 0;
            virtual int32_t __stdcall IsCurrentAppPinnedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall IsAppListEntryPinnedAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinCurrentAppAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinAppListEntryAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::ITaskbarManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSecondaryTilePinnedAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinSecondaryTileAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryUnpinSecondaryTileAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Shell::ITaskbarManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTab>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tag(void**) noexcept = 0;
            virtual int32_t __stdcall put_Tag(void*) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Icon(void**) noexcept = 0;
            virtual int32_t __stdcall put_Icon(void*) noexcept = 0;
            virtual int32_t __stdcall get_TreatAsSecondaryTileId(void**) noexcept = 0;
            virtual int32_t __stdcall put_TreatAsSecondaryTileId(void*) noexcept = 0;
            virtual int32_t __stdcall get_Group(void**) noexcept = 0;
            virtual int32_t __stdcall put_Group(void*) noexcept = 0;
            virtual int32_t __stdcall ReportThumbnailAvailable() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tab(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabCollection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall MoveTab(void*, uint32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Icon(void**) noexcept = 0;
            virtual int32_t __stdcall put_Icon(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabIcon>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabIconStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateFromFontGlyph(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromFontGlyphWithUri(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromImage(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tabs(void**) noexcept = 0;
            virtual int32_t __stdcall SetActiveTab(void*) noexcept = 0;
            virtual int32_t __stdcall add_TabSwitchRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TabSwitchRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_TabCloseRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TabCloseRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_TabTearOutRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TabTearOutRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_TabThumbnailRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_TabThumbnailRequested(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForWindow(struct struct_Windows_UI_WindowId, void**) noexcept = 0;
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall IsTabTearOutSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tab(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tab(void**) noexcept = 0;
            virtual int32_t __stdcall get_WindowId(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall put_WindowId(uint64_t) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Tab(void**) noexcept = 0;
            virtual int32_t __stdcall get_RequestedSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall get_Image(void**) noexcept = 0;
            virtual int32_t __stdcall put_Image(void*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsCompositedOnWindow(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IAdaptiveCard
    {
        LLM_IMPL_AUTO(hstring) ToJson() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IAdaptiveCard>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IAdaptiveCard<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IAdaptiveCardBuilderStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::IAdaptiveCard) CreateAdaptiveCardFromJson(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::UI::Shell::IAdaptiveCardBuilderStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IAdaptiveCardBuilderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IFocusSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        LLM_IMPL_AUTO(void) End() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IFocusSession>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IFocusSession<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IFocusSessionManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFocusActive() const;
        LLM_IMPL_AUTO(llm:OS::UI::Shell::FocusSession) GetSession(param::hstring const& id) const;
        LLM_IMPL_AUTO(llm:OS::UI::Shell::FocusSession) TryStartFocusSession() const;
        LLM_IMPL_AUTO(llm:OS::UI::Shell::FocusSession) TryStartFocusSession(llm:OS::Foundation::DateTime const& endTime) const;
        LLM_IMPL_AUTO(void) DeactivateFocus() const;
        LLM_IMPL_AUTO(llm::event_token) IsFocusActiveChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::FocusSessionManager, llm:OS::Foundation::IInspectable> const& handler) const;
        using IsFocusActiveChanged_revoker = impl::event_revoker<llm:OS::UI::Shell::IFocusSessionManager, &impl::abi_t<llm:OS::UI::Shell::IFocusSessionManager>::remove_IsFocusActiveChanged>;
        [[nodiscard]] IsFocusActiveChanged_revoker IsFocusActiveChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::FocusSessionManager, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) IsFocusActiveChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Shell::IFocusSessionManager>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IFocusSessionManager<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IFocusSessionManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::FocusSessionManager) GetDefault() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IFocusSessionManagerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IFocusSessionManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_ISecurityAppManager
    {
        LLM_IMPL_AUTO(llm::guid) Register(llm:OS::UI::Shell::SecurityAppKind const& kind, param::hstring const& displayName, llm:OS::Foundation::Uri const& detailsUri, bool registerPerUser) const;
        LLM_IMPL_AUTO(void) Unregister(llm:OS::UI::Shell::SecurityAppKind const& kind, llm::guid const& guidRegistration) const;
        LLM_IMPL_AUTO(void) UpdateState(llm:OS::UI::Shell::SecurityAppKind const& kind, llm::guid const& guidRegistration, llm:OS::UI::Shell::SecurityAppState const& state, llm:OS::UI::Shell::SecurityAppSubstatus const& substatus, llm:OS::Foundation::Uri const& detailsUri) const;
    };
    template <> struct consume<llm:OS::UI::Shell::ISecurityAppManager>
    {
        template <typename D> using type = consume_Windows_UI_Shell_ISecurityAppManager<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IShareWindowCommandEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WindowId) WindowId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::ShareWindowCommand) Command() const;
        LLM_IMPL_AUTO(void) Command(llm:OS::UI::Shell::ShareWindowCommand const& value) const;
    };
    template <> struct consume<llm:OS::UI::Shell::IShareWindowCommandEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IShareWindowCommandEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IShareWindowCommandSource
    {
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
        LLM_IMPL_AUTO(void) ReportCommandChanged() const;
        LLM_IMPL_AUTO(llm::event_token) CommandRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::ShareWindowCommandSource, llm:OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const;
        using CommandRequested_revoker = impl::event_revoker<llm:OS::UI::Shell::IShareWindowCommandSource, &impl::abi_t<llm:OS::UI::Shell::IShareWindowCommandSource>::remove_CommandRequested>;
        [[nodiscard]] CommandRequested_revoker CommandRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::ShareWindowCommandSource, llm:OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CommandRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) CommandInvoked(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::ShareWindowCommandSource, llm:OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const;
        using CommandInvoked_revoker = impl::event_revoker<llm:OS::UI::Shell::IShareWindowCommandSource, &impl::abi_t<llm:OS::UI::Shell::IShareWindowCommandSource>::remove_CommandInvoked>;
        [[nodiscard]] CommandInvoked_revoker CommandInvoked(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::ShareWindowCommandSource, llm:OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CommandInvoked(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Shell::IShareWindowCommandSource>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IShareWindowCommandSource<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IShareWindowCommandSourceStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::ShareWindowCommandSource) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IShareWindowCommandSourceStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IShareWindowCommandSourceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_ITaskbarManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsPinningAllowed() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) IsCurrentAppPinnedAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) IsAppListEntryPinnedAsync(llm:OS::ApplicationModel::Core::AppListEntry const& appListEntry) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestPinCurrentAppAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestPinAppListEntryAsync(llm:OS::ApplicationModel::Core::AppListEntry const& appListEntry) const;
    };
    template <> struct consume<llm:OS::UI::Shell::ITaskbarManager>
    {
        template <typename D> using type = consume_Windows_UI_Shell_ITaskbarManager<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_ITaskbarManager2
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) IsSecondaryTilePinnedAsync(param::hstring const& tileId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestPinSecondaryTileAsync(llm:OS::UI::StartScreen::SecondaryTile const& secondaryTile) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) TryUnpinSecondaryTileAsync(param::hstring const& tileId) const;
    };
    template <> struct consume<llm:OS::UI::Shell::ITaskbarManager2>
    {
        template <typename D> using type = consume_Windows_UI_Shell_ITaskbarManager2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_ITaskbarManagerDesktopAppSupportStatics
    {
    };
    template <> struct consume<llm:OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_ITaskbarManagerDesktopAppSupportStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_ITaskbarManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::TaskbarManager) GetDefault() const;
    };
    template <> struct consume<llm:OS::UI::Shell::ITaskbarManagerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_ITaskbarManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTab
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) Tag() const;
        LLM_IMPL_AUTO(void) Tag(llm:OS::Foundation::IInspectable const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabIcon) Icon() const;
        LLM_IMPL_AUTO(void) Icon(llm:OS::UI::Shell::WindowTabIcon const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TreatAsSecondaryTileId() const;
        LLM_IMPL_AUTO(void) TreatAsSecondaryTileId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabGroup) Group() const;
        LLM_IMPL_AUTO(void) Group(llm:OS::UI::Shell::WindowTabGroup const& value) const;
        LLM_IMPL_AUTO(void) ReportThumbnailAvailable() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTab>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTab<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabCloseRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTab) Tab() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabCloseRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabCollection
    {
        LLM_IMPL_AUTO(void) MoveTab(llm:OS::UI::Shell::WindowTab const& tab, uint32_t index) const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabCollection>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabCollection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabIcon) Icon() const;
        LLM_IMPL_AUTO(void) Icon(llm:OS::UI::Shell::WindowTabIcon const& value) const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabGroup>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabGroup<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabIcon
    {
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabIcon>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabIcon<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabIconStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabIcon) CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily) const;
        LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabIcon) CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily, llm:OS::Foundation::Uri const& fontUri) const;
        LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabIcon) CreateFromImage(llm:OS::Storage::Streams::IRandomAccessStreamReference const& image) const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabIconStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabIconStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabCollection) Tabs() const;
        LLM_IMPL_AUTO(void) SetActiveTab(llm:OS::UI::Shell::WindowTab const& tab) const;
        LLM_IMPL_AUTO(llm::event_token) TabSwitchRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabSwitchRequestedEventArgs> const& handler) const;
        using TabSwitchRequested_revoker = impl::event_revoker<llm:OS::UI::Shell::IWindowTabManager, &impl::abi_t<llm:OS::UI::Shell::IWindowTabManager>::remove_TabSwitchRequested>;
        [[nodiscard]] TabSwitchRequested_revoker TabSwitchRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabSwitchRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TabSwitchRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) TabCloseRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabCloseRequestedEventArgs> const& handler) const;
        using TabCloseRequested_revoker = impl::event_revoker<llm:OS::UI::Shell::IWindowTabManager, &impl::abi_t<llm:OS::UI::Shell::IWindowTabManager>::remove_TabCloseRequested>;
        [[nodiscard]] TabCloseRequested_revoker TabCloseRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabCloseRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TabCloseRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) TabTearOutRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabTearOutRequestedEventArgs> const& handler) const;
        using TabTearOutRequested_revoker = impl::event_revoker<llm:OS::UI::Shell::IWindowTabManager, &impl::abi_t<llm:OS::UI::Shell::IWindowTabManager>::remove_TabTearOutRequested>;
        [[nodiscard]] TabTearOutRequested_revoker TabTearOutRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabTearOutRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TabTearOutRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) TabThumbnailRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> const& handler) const;
        using TabThumbnailRequested_revoker = impl::event_revoker<llm:OS::UI::Shell::IWindowTabManager, &impl::abi_t<llm:OS::UI::Shell::IWindowTabManager>::remove_TabThumbnailRequested>;
        [[nodiscard]] TabThumbnailRequested_revoker TabThumbnailRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::Shell::WindowTabManager, llm:OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) TabThumbnailRequested(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabManager>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabManager<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTabManager) GetForWindow(llm:OS::UI::WindowId const& id) const;
        LLM_IMPL_AUTO(bool) IsSupported() const;
        LLM_IMPL_AUTO(bool) IsTabTearOutSupported() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabManagerStatics>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabSwitchRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTab) Tab() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabSwitchRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTab) Tab() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) WindowId() const;
        LLM_IMPL_AUTO(void) WindowId(uint64_t value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Shell::WindowTab) Tab() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Imaging::BitmapSize) RequestedSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamReference) Image() const;
        LLM_IMPL_AUTO(void) Image(llm:OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCompositedOnWindow() const;
    };
    template <> struct consume<llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>;
    };
}
#endif
