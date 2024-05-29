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
#ifndef LLM_OS_ApplicationModel_SocialInfo_1_H
#define LLM_OS_ApplicationModel_SocialInfo_1_H
#include "llm/impl/Windows.ApplicationModel.SocialInfo.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo
{
    struct __declspec(empty_bases) ISocialFeedChildItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialFeedChildItem>
    {
        ISocialFeedChildItem(std::nullptr_t = nullptr) noexcept {}
        ISocialFeedChildItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialFeedContent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialFeedContent>
    {
        ISocialFeedContent(std::nullptr_t = nullptr) noexcept {}
        ISocialFeedContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialFeedItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialFeedItem>
    {
        ISocialFeedItem(std::nullptr_t = nullptr) noexcept {}
        ISocialFeedItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialFeedSharedItem :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialFeedSharedItem>
    {
        ISocialFeedSharedItem(std::nullptr_t = nullptr) noexcept {}
        ISocialFeedSharedItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialItemThumbnail :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialItemThumbnail>
    {
        ISocialItemThumbnail(std::nullptr_t = nullptr) noexcept {}
        ISocialItemThumbnail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocialUserInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISocialUserInfo>
    {
        ISocialUserInfo(std::nullptr_t = nullptr) noexcept {}
        ISocialUserInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
