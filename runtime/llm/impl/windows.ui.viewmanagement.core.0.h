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
#ifndef LLM_OS_UI_ViewManagement_Core_0_H
#define LLM_OS_UI_ViewManagement_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct UIContext;
}
LLM_EXPORT namespace llm:OS::UI::ViewManagement::Core
{
    enum class CoreInputViewKind : int32_t
    {
        Default = 0,
        Keyboard = 1,
        Handwriting = 2,
        Emoji = 3,
        Symbols = 4,
        Clipboard = 5,
        Dictation = 6,
    };
    enum class CoreInputViewOcclusionKind : int32_t
    {
        Docked = 0,
        Floating = 1,
        Overlay = 2,
    };
    enum class CoreInputViewXYFocusTransferDirection : int32_t
    {
        Up = 0,
        Right = 1,
        Down = 2,
        Left = 3,
    };
    struct ICoreFrameworkInputView;
    struct ICoreFrameworkInputViewAnimationStartingEventArgs;
    struct ICoreFrameworkInputViewOcclusionsChangedEventArgs;
    struct ICoreFrameworkInputViewStatics;
    struct ICoreInputView;
    struct ICoreInputView2;
    struct ICoreInputView3;
    struct ICoreInputView4;
    struct ICoreInputView5;
    struct ICoreInputViewAnimationStartingEventArgs;
    struct ICoreInputViewHidingEventArgs;
    struct ICoreInputViewOcclusion;
    struct ICoreInputViewOcclusionsChangedEventArgs;
    struct ICoreInputViewShowingEventArgs;
    struct ICoreInputViewStatics;
    struct ICoreInputViewStatics2;
    struct ICoreInputViewTransferringXYFocusEventArgs;
    struct IUISettingsController;
    struct IUISettingsControllerStatics;
    struct CoreFrameworkInputView;
    struct CoreFrameworkInputViewAnimationStartingEventArgs;
    struct CoreFrameworkInputViewOcclusionsChangedEventArgs;
    struct CoreInputView;
    struct CoreInputViewAnimationStartingEventArgs;
    struct CoreInputViewHidingEventArgs;
    struct CoreInputViewOcclusion;
    struct CoreInputViewOcclusionsChangedEventArgs;
    struct CoreInputViewShowingEventArgs;
    struct CoreInputViewTransferringXYFocusEventArgs;
    struct UISettingsController;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputView>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputView2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputView3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputView4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputView5>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::IUISettingsController>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::IUISettingsControllerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputView>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::UISettingsController>{ using type = class_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewKind>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView> = L"Windows.UI.ViewManagement.Core.CoreFrameworkInputView";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> = L"Windows.UI.ViewManagement.Core.CoreFrameworkInputViewAnimationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> = L"Windows.UI.ViewManagement.Core.CoreFrameworkInputViewOcclusionsChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputView> = L"Windows.UI.ViewManagement.Core.CoreInputView";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> = L"Windows.UI.ViewManagement.Core.CoreInputViewAnimationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> = L"Windows.UI.ViewManagement.Core.CoreInputViewHidingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion> = L"Windows.UI.ViewManagement.Core.CoreInputViewOcclusion";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> = L"Windows.UI.ViewManagement.Core.CoreInputViewOcclusionsChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> = L"Windows.UI.ViewManagement.Core.CoreInputViewShowingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> = L"Windows.UI.ViewManagement.Core.CoreInputViewTransferringXYFocusEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::UISettingsController> = L"Windows.UI.ViewManagement.Core.UISettingsController";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewKind> = L"Windows.UI.ViewManagement.Core.CoreInputViewKind";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind> = L"Windows.UI.ViewManagement.Core.CoreInputViewOcclusionKind";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection> = L"Windows.UI.ViewManagement.Core.CoreInputViewXYFocusTransferDirection";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView> = L"Windows.UI.ViewManagement.Core.ICoreFrameworkInputView";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreFrameworkInputViewAnimationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreFrameworkInputViewOcclusionsChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics> = L"Windows.UI.ViewManagement.Core.ICoreFrameworkInputViewStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputView> = L"Windows.UI.ViewManagement.Core.ICoreInputView";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputView2> = L"Windows.UI.ViewManagement.Core.ICoreInputView2";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputView3> = L"Windows.UI.ViewManagement.Core.ICoreInputView3";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputView4> = L"Windows.UI.ViewManagement.Core.ICoreInputView4";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputView5> = L"Windows.UI.ViewManagement.Core.ICoreInputView5";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreInputViewAnimationStartingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreInputViewHidingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion> = L"Windows.UI.ViewManagement.Core.ICoreInputViewOcclusion";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreInputViewOcclusionsChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreInputViewShowingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics> = L"Windows.UI.ViewManagement.Core.ICoreInputViewStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics2> = L"Windows.UI.ViewManagement.Core.ICoreInputViewStatics2";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs> = L"Windows.UI.ViewManagement.Core.ICoreInputViewTransferringXYFocusEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::IUISettingsController> = L"Windows.UI.ViewManagement.Core.IUISettingsController";
    template <> inline constexpr auto& name_v<llm:OS::UI::ViewManagement::Core::IUISettingsControllerStatics> = L"Windows.UI.ViewManagement.Core.IUISettingsControllerStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>{ 0xD77C94AE,0x46B8,0x5D4A,{ 0x94,0x89,0x8D,0xDE,0xC3,0xD6,0x39,0xA6 } }; // D77C94AE-46B8-5D4A-9489-8DDEC3D639A6
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs>{ 0xC0EC901C,0xBBA4,0x501B,{ 0xAE,0x8B,0x65,0xC9,0xE7,0x56,0xA7,0x19 } }; // C0EC901C-BBA4-501B-AE8B-65C9E756A719
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs>{ 0xF36F4949,0xC82C,0x53D1,{ 0xA7,0x5D,0x2B,0x2B,0xAF,0x0D,0x9B,0x0D } }; // F36F4949-C82C-53D1-A75D-2B2BAF0D9B0D
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics>{ 0x6EEBD9B6,0xEAC2,0x5F8B,{ 0x97,0x5F,0x77,0x2E,0xE3,0xE4,0x2E,0xEB } }; // 6EEBD9B6-EAC2-5F8B-975F-772EE3E42EEB
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputView>{ 0xC770CD7A,0x7001,0x4C32,{ 0xBF,0x94,0x25,0xC1,0xF5,0x54,0xCB,0xF1 } }; // C770CD7A-7001-4C32-BF94-25C1F554CBF1
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputView2>{ 0x0ED726C1,0xE09A,0x4AE8,{ 0xAE,0xDF,0xDF,0xA4,0x85,0x7D,0x1A,0x01 } }; // 0ED726C1-E09A-4AE8-AEDF-DFA4857D1A01
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputView3>{ 0xBC941653,0x3AB9,0x4849,{ 0x8F,0x58,0x46,0xE7,0xF0,0x35,0x3C,0xFC } }; // BC941653-3AB9-4849-8F58-46E7F0353CFC
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputView4>{ 0x002863D6,0xD9EF,0x57EB,{ 0x8C,0xEF,0x77,0xF6,0xCE,0x1B,0x7E,0xE7 } }; // 002863D6-D9EF-57EB-8CEF-77F6CE1B7EE7
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputView5>{ 0x136316E0,0xC6D5,0x5C57,{ 0x81,0x1E,0x1A,0xD8,0xA9,0x9B,0xA6,0xAB } }; // 136316E0-C6D5-5C57-811E-1AD8A99BA6AB
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs>{ 0xA9144AF2,0xB55C,0x5EA1,{ 0xB8,0xAB,0x53,0x40,0xF3,0xE9,0x48,0x97 } }; // A9144AF2-B55C-5EA1-B8AB-5340F3E94897
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs>{ 0xEADA47BD,0xBAC5,0x5336,{ 0x84,0x8D,0x41,0x08,0x35,0x84,0xDA,0xAD } }; // EADA47BD-BAC5-5336-848D-41083584DAAD
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion>{ 0xCC36CE06,0x3865,0x4177,{ 0xB5,0xF5,0x8B,0x65,0xE0,0xB9,0xCE,0x84 } }; // CC36CE06-3865-4177-B5F5-8B65E0B9CE84
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs>{ 0xBE1027E8,0xB3EE,0x4DF7,{ 0x95,0x54,0x89,0xCD,0xC6,0x60,0x82,0xC2 } }; // BE1027E8-B3EE-4DF7-9554-89CDC66082C2
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs>{ 0xCA52261B,0xFB9E,0x5DAF,{ 0xA9,0x8C,0x26,0x2B,0x8B,0x76,0xAF,0x50 } }; // CA52261B-FB9E-5DAF-A98C-262B8B76AF50
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics>{ 0x7D9B97CD,0xEDBE,0x49CF,{ 0xA5,0x4F,0x33,0x7D,0xE0,0x52,0x90,0x7F } }; // 7D9B97CD-EDBE-49CF-A54F-337DE052907F
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics2>{ 0x7EBC0862,0xD049,0x4E52,{ 0x87,0xB0,0x1E,0x90,0xE9,0x8C,0x49,0xED } }; // 7EBC0862-D049-4E52-87B0-1E90E98C49ED
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs>{ 0x04DE169F,0xBA02,0x4850,{ 0x8B,0x55,0xD8,0x2D,0x03,0xBA,0x6D,0x7F } }; // 04DE169F-BA02-4850-8B55-D82D03BA6D7F
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::IUISettingsController>{ 0x78A51AC4,0x15C0,0x5A1B,{ 0xA7,0x5B,0xAC,0xBF,0x9C,0xB8,0xBB,0x9E } }; // 78A51AC4-15C0-5A1B-A75B-ACBF9CB8BB9E
    template <> inline constexpr guid guid_v<llm:OS::UI::ViewManagement::Core::IUISettingsControllerStatics>{ 0xEB3C68CC,0xC220,0x578C,{ 0x81,0x19,0x7D,0xB3,0x24,0xED,0x26,0xA6 } }; // EB3C68CC-C220-578C-8119-7DB324ED26A6
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView>{ using type = llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputView>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputView; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs>{ using type = llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs; };
    template <> struct default_interface<llm:OS::UI::ViewManagement::Core::UISettingsController>{ using type = llm:OS::UI::ViewManagement::Core::IUISettingsController; };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_PrimaryViewAnimationStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PrimaryViewAnimationStarting(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_OcclusionsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_OcclusionsChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Occlusions(void**) noexcept = 0;
            virtual int32_t __stdcall get_FrameworkAnimationRecommended(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AnimationDuration(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Occlusions(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUIContext(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_OcclusionsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_OcclusionsChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetCoreInputViewOcclusions(void**) noexcept = 0;
            virtual int32_t __stdcall TryShowPrimaryView(bool*) noexcept = 0;
            virtual int32_t __stdcall TryHidePrimaryView(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputView2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_XYFocusTransferringFromPrimaryView(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_XYFocusTransferringFromPrimaryView(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_XYFocusTransferredToPrimaryView(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_XYFocusTransferredToPrimaryView(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall TryTransferXYFocusToPrimaryView(llm:OS::Foundation::Rect, int32_t, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputView3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryShow(bool*) noexcept = 0;
            virtual int32_t __stdcall TryShowWithKind(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall TryHide(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputView4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_PrimaryViewShowing(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PrimaryViewShowing(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PrimaryViewHiding(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PrimaryViewHiding(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputView5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsKindSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall add_SupportedKindsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SupportedKindsChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PrimaryViewAnimationStarting(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PrimaryViewAnimationStarting(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Occlusions(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
            virtual int32_t __stdcall get_AnimationDuration(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCancel(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OccludingRect(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_OcclusionKind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Occlusions(void**) noexcept = 0;
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCancel(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForCurrentView(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUIContext(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Origin(llm:OS::Foundation::Rect*) noexcept = 0;
            virtual int32_t __stdcall get_Direction(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_TransferHandled(bool) noexcept = 0;
            virtual int32_t __stdcall get_TransferHandled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_KeepPrimaryViewVisible(bool) noexcept = 0;
            virtual int32_t __stdcall get_KeepPrimaryViewVisible(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::IUISettingsController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetAdvancedEffectsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall SetAnimationsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall SetAutoHideScrollBars(bool) noexcept = 0;
            virtual int32_t __stdcall SetMessageDuration(uint32_t) noexcept = 0;
            virtual int32_t __stdcall SetTextScaleFactor(double) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::ViewManagement::Core::IUISettingsControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestDefaultAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView
    {
        LLM_IMPL_AUTO(llm::event_token) PrimaryViewAnimationStarting(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> const& handler) const;
        using PrimaryViewAnimationStarting_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>::remove_PrimaryViewAnimationStarting>;
        [[nodiscard]] PrimaryViewAnimationStarting_revoker PrimaryViewAnimationStarting(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PrimaryViewAnimationStarting(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) OcclusionsChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> const& handler) const;
        using OcclusionsChanged_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>::remove_OcclusionsChanged>;
        [[nodiscard]] OcclusionsChanged_revoker OcclusionsChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm:OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) OcclusionsChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputView>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewAnimationStartingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) Occlusions() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) FrameworkAnimationRecommended() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) AnimationDuration() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewAnimationStartingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewOcclusionsChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) Occlusions() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewOcclusionsChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView) GetForUIContext(llm:OS::UI::UIContext const& context) const;
        LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreFrameworkInputView) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputView
    {
        LLM_IMPL_AUTO(llm::event_token) OcclusionsChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> const& handler) const;
        using OcclusionsChanged_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView>::remove_OcclusionsChanged>;
        [[nodiscard]] OcclusionsChanged_revoker OcclusionsChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) OcclusionsChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) GetCoreInputViewOcclusions() const;
        LLM_IMPL_AUTO(bool) TryShowPrimaryView() const;
        LLM_IMPL_AUTO(bool) TryHidePrimaryView() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputView>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputView2
    {
        LLM_IMPL_AUTO(llm::event_token) XYFocusTransferringFromPrimaryView(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> const& handler) const;
        using XYFocusTransferringFromPrimaryView_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView2, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView2>::remove_XYFocusTransferringFromPrimaryView>;
        [[nodiscard]] XYFocusTransferringFromPrimaryView_revoker XYFocusTransferringFromPrimaryView(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) XYFocusTransferringFromPrimaryView(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) XYFocusTransferredToPrimaryView(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::Foundation::IInspectable> const& handler) const;
        using XYFocusTransferredToPrimaryView_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView2, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView2>::remove_XYFocusTransferredToPrimaryView>;
        [[nodiscard]] XYFocusTransferredToPrimaryView_revoker XYFocusTransferredToPrimaryView(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) XYFocusTransferredToPrimaryView(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(bool) TryTransferXYFocusToPrimaryView(llm:OS::Foundation::Rect const& origin, llm:OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection const& direction) const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputView2>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputView3
    {
        LLM_IMPL_AUTO(bool) TryShow() const;
        LLM_IMPL_AUTO(bool) TryShow(llm:OS::UI::ViewManagement::Core::CoreInputViewKind const& type) const;
        LLM_IMPL_AUTO(bool) TryHide() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputView3>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputView3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputView4
    {
        LLM_IMPL_AUTO(llm::event_token) PrimaryViewShowing(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> const& handler) const;
        using PrimaryViewShowing_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView4, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView4>::remove_PrimaryViewShowing>;
        [[nodiscard]] PrimaryViewShowing_revoker PrimaryViewShowing(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PrimaryViewShowing(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PrimaryViewHiding(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> const& handler) const;
        using PrimaryViewHiding_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView4, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView4>::remove_PrimaryViewHiding>;
        [[nodiscard]] PrimaryViewHiding_revoker PrimaryViewHiding(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PrimaryViewHiding(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputView4>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputView5
    {
        LLM_IMPL_AUTO(bool) IsKindSupported(llm:OS::UI::ViewManagement::Core::CoreInputViewKind const& type) const;
        LLM_IMPL_AUTO(llm::event_token) SupportedKindsChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::Foundation::IInspectable> const& handler) const;
        using SupportedKindsChanged_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView5, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView5>::remove_SupportedKindsChanged>;
        [[nodiscard]] SupportedKindsChanged_revoker SupportedKindsChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) SupportedKindsChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PrimaryViewAnimationStarting(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> const& handler) const;
        using PrimaryViewAnimationStarting_revoker = impl::event_revoker<llm:OS::UI::ViewManagement::Core::ICoreInputView5, &impl::abi_t<llm:OS::UI::ViewManagement::Core::ICoreInputView5>::remove_PrimaryViewAnimationStarting>;
        [[nodiscard]] PrimaryViewAnimationStarting_revoker PrimaryViewAnimationStarting(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::ViewManagement::Core::CoreInputView, llm:OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PrimaryViewAnimationStarting(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputView5>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) Occlusions() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::TimeSpan) AnimationDuration() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewHidingEventArgs
    {
        LLM_IMPL_AUTO(bool) TryCancel() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewHidingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusion
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) OccludingRect() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind) OcclusionKind() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusion>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusion<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusionsChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) Occlusions() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusionsChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewShowingEventArgs
    {
        LLM_IMPL_AUTO(bool) TryCancel() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewShowingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreInputView) GetForCurrentView() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics2
    {
        LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreInputView) GetForUIContext(llm:OS::UI::UIContext const& context) const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewStatics2>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Rect) Origin() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection) Direction() const;
        LLM_IMPL_AUTO(void) TransferHandled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) TransferHandled() const;
        LLM_IMPL_AUTO(void) KeepPrimaryViewVisible(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) KeepPrimaryViewVisible() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_IUISettingsController
    {
        LLM_IMPL_AUTO(void) SetAdvancedEffectsEnabled(bool value) const;
        LLM_IMPL_AUTO(void) SetAnimationsEnabled(bool value) const;
        LLM_IMPL_AUTO(void) SetAutoHideScrollBars(bool value) const;
        LLM_IMPL_AUTO(void) SetMessageDuration(uint32_t value) const;
        LLM_IMPL_AUTO(void) SetTextScaleFactor(double value) const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::IUISettingsController>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>;
    };
    template <typename D>
    struct consume_Windows_UI_ViewManagement_Core_IUISettingsControllerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::ViewManagement::Core::UISettingsController>) RequestDefaultAsync() const;
    };
    template <> struct consume<llm:OS::UI::ViewManagement::Core::IUISettingsControllerStatics>
    {
        template <typename D> using type = consume_Windows_UI_ViewManagement_Core_IUISettingsControllerStatics<D>;
    };
}
#endif
