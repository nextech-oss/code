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
#ifndef LLM_OS_System_Diagnostics_Telemetry_0_H
#define LLM_OS_System_Diagnostics_Telemetry_0_H
LLM_EXPORT namespace llm:OS::System::Diagnostics::Telemetry
{
    enum class PlatformTelemetryRegistrationStatus : int32_t
    {
        Success = 0,
        SettingsOutOfRange = 1,
        UnknownFailure = 2,
    };
    struct IPlatformTelemetryClientStatics;
    struct IPlatformTelemetryRegistrationResult;
    struct IPlatformTelemetryRegistrationSettings;
    struct PlatformTelemetryClient;
    struct PlatformTelemetryRegistrationResult;
    struct PlatformTelemetryRegistrationSettings;
}
namespace llm::impl
{
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryClient>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings>{ using type = class_category; };
    template <> struct category<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryClient> = L"Windows.System.Diagnostics.Telemetry.PlatformTelemetryClient";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult> = L"Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings> = L"Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationSettings";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus> = L"Windows.System.Diagnostics.Telemetry.PlatformTelemetryRegistrationStatus";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics> = L"Windows.System.Diagnostics.Telemetry.IPlatformTelemetryClientStatics";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult> = L"Windows.System.Diagnostics.Telemetry.IPlatformTelemetryRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings> = L"Windows.System.Diagnostics.Telemetry.IPlatformTelemetryRegistrationSettings";
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics>{ 0x9BF3F25D,0xD5C3,0x4EEA,{ 0x8D,0xBE,0x9C,0x8D,0xBB,0x0D,0x9D,0x8F } }; // 9BF3F25D-D5C3-4EEA-8DBE-9C8DBB0D9D8F
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult>{ 0x4D8518AB,0x2292,0x49BD,{ 0xA1,0x5A,0x3D,0x71,0xD2,0x14,0x51,0x12 } }; // 4D8518AB-2292-49BD-A15A-3D71D2145112
    template <> inline constexpr guid guid_v<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings>{ 0x819A8582,0xCA19,0x415E,{ 0xBB,0x79,0x9C,0x22,0x4B,0xFA,0x3A,0x73 } }; // 819A8582-CA19-415E-BB79-9C224BFA3A73
    template <> struct default_interface<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult>{ using type = llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult; };
    template <> struct default_interface<llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings>{ using type = llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings; };
    template <> struct abi<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Register(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterWithSettings(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StorageSize(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StorageSize(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_UploadQuotaSize(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_UploadQuotaSize(uint32_t) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryClientStatics
    {
        LLM_IMPL_AUTO(llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult) Register(param::hstring const& id) const;
        LLM_IMPL_AUTO(llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationResult) Register(param::hstring const& id, llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationSettings const& settings) const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryClientStatics>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryClientStatics<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::Diagnostics::Telemetry::PlatformTelemetryRegistrationStatus) Status() const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationResult>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationResult<D>;
    };
    template <typename D>
    struct consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) StorageSize() const;
        LLM_IMPL_AUTO(void) StorageSize(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) UploadQuotaSize() const;
        LLM_IMPL_AUTO(void) UploadQuotaSize(uint32_t value) const;
    };
    template <> struct consume<llm:OS::System::Diagnostics::Telemetry::IPlatformTelemetryRegistrationSettings>
    {
        template <typename D> using type = consume_Windows_System_Diagnostics_Telemetry_IPlatformTelemetryRegistrationSettings<D>;
    };
}
#endif
