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
#ifndef LLM_OS_UI_Input_Inking_Preview_0_H
#define LLM_OS_UI_Input_Inking_Preview_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Rect;
}
LLM_EXPORT namespace llm:OS::UI::Composition
{
    struct Visual;
}
LLM_EXPORT namespace llm:OS::UI::Input::Inking::Preview
{
    struct IPalmRejectionDelayZonePreview;
    struct IPalmRejectionDelayZonePreviewStatics;
    struct PalmRejectionDelayZonePreview;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview> = L"Windows.UI.Input.Inking.Preview.PalmRejectionDelayZonePreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview> = L"Windows.UI.Input.Inking.Preview.IPalmRejectionDelayZonePreview";
    template <> inline constexpr auto& name_v<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics> = L"Windows.UI.Input.Inking.Preview.IPalmRejectionDelayZonePreviewStatics";
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview>{ 0x62B496CB,0x539D,0x5343,{ 0xA6,0x5F,0x41,0xF5,0x30,0x0E,0xC7,0x0C } }; // 62B496CB-539D-5343-A65F-41F5300EC70C
    template <> inline constexpr guid guid_v<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics>{ 0xCDEF5EE0,0x93D0,0x53A9,{ 0x8F,0x0E,0x9A,0x37,0x9F,0x8F,0x75,0x30 } }; // CDEF5EE0-93D0-53A9-8F0E-9A379F8F7530
    template <> struct default_interface<llm:OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview>{ using type = llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview; };
    template <> struct abi<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateForVisual(void*, llm:OS::Foundation::Rect, void**) noexcept = 0;
            virtual int32_t __stdcall CreateForVisualWithViewportClip(void*, llm:OS::Foundation::Rect, void*, llm:OS::Foundation::Rect, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreview
    {
    };
    template <> struct consume<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview>
    {
        template <typename D> using type = consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreview<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreviewStatics
    {
        LLM_IMPL_AUTO(llm:OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview) CreateForVisual(llm:OS::UI::Composition::Visual const& inputPanelVisual, llm:OS::Foundation::Rect const& inputPanelRect) const;
        LLM_IMPL_AUTO(llm:OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview) CreateForVisual(llm:OS::UI::Composition::Visual const& inputPanelVisual, llm:OS::Foundation::Rect const& inputPanelRect, llm:OS::UI::Composition::Visual const& viewportVisual, llm:OS::Foundation::Rect const& viewportRect) const;
    };
    template <> struct consume<llm:OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics>
    {
        template <typename D> using type = consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreviewStatics<D>;
    };
}
#endif
