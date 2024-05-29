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
#ifndef LLM_OS_Gaming_Input_0_H
#define LLM_OS_Gaming_Input_0_H
LLM_EXPORT namespace llm::OS::Devices::Haptics
{
    struct SimpleHapticsController;
}
LLM_EXPORT namespace llm::OS::Devices::Power
{
    struct BatteryReport;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Gaming::Input::ForceFeedback
{
    struct ForceFeedbackMotor;
}
LLM_EXPORT namespace llm::OS::System
{
    struct User;
    struct UserChangedEventArgs;
}
LLM_EXPORT namespace llm::OS::Gaming::Input
{
    enum class ArcadeStickButtons : uint32_t
    {
        None = 0,
        StickUp = 0x1,
        StickDown = 0x2,
        StickLeft = 0x4,
        StickRight = 0x8,
        Action1 = 0x10,
        Action2 = 0x20,
        Action3 = 0x40,
        Action4 = 0x80,
        Action5 = 0x100,
        Action6 = 0x200,
        Special1 = 0x400,
        Special2 = 0x800,
    };
    enum class FlightStickButtons : uint32_t
    {
        None = 0,
        FirePrimary = 0x1,
        FireSecondary = 0x2,
    };
    enum class GameControllerButtonLabel : int32_t
    {
        None = 0,
        XboxBack = 1,
        XboxStart = 2,
        XboxMenu = 3,
        XboxView = 4,
        XboxUp = 5,
        XboxDown = 6,
        XboxLeft = 7,
        XboxRight = 8,
        XboxA = 9,
        XboxB = 10,
        XboxX = 11,
        XboxY = 12,
        XboxLeftBumper = 13,
        XboxLeftTrigger = 14,
        XboxLeftStickButton = 15,
        XboxRightBumper = 16,
        XboxRightTrigger = 17,
        XboxRightStickButton = 18,
        XboxPaddle1 = 19,
        XboxPaddle2 = 20,
        XboxPaddle3 = 21,
        XboxPaddle4 = 22,
        Mode = 23,
        Select = 24,
        Menu = 25,
        View = 26,
        Back = 27,
        Start = 28,
        Options = 29,
        Share = 30,
        Up = 31,
        Down = 32,
        Left = 33,
        Right = 34,
        LetterA = 35,
        LetterB = 36,
        LetterC = 37,
        LetterL = 38,
        LetterR = 39,
        LetterX = 40,
        LetterY = 41,
        LetterZ = 42,
        Cross = 43,
        Circle = 44,
        Square = 45,
        Triangle = 46,
        LeftBumper = 47,
        LeftTrigger = 48,
        LeftStickButton = 49,
        Left1 = 50,
        Left2 = 51,
        Left3 = 52,
        RightBumper = 53,
        RightTrigger = 54,
        RightStickButton = 55,
        Right1 = 56,
        Right2 = 57,
        Right3 = 58,
        Paddle1 = 59,
        Paddle2 = 60,
        Paddle3 = 61,
        Paddle4 = 62,
        Plus = 63,
        Minus = 64,
        DownLeftArrow = 65,
        DialLeft = 66,
        DialRight = 67,
        Suspension = 68,
    };
    enum class GameControllerSwitchKind : int32_t
    {
        TwoWay = 0,
        FourWay = 1,
        EightWay = 2,
    };
    enum class GameControllerSwitchPosition : int32_t
    {
        Center = 0,
        Up = 1,
        UpRight = 2,
        Right = 3,
        DownRight = 4,
        Down = 5,
        DownLeft = 6,
        Left = 7,
        UpLeft = 8,
    };
    enum class GamepadButtons : uint32_t
    {
        None = 0,
        Menu = 0x1,
        View = 0x2,
        A = 0x4,
        B = 0x8,
        X = 0x10,
        Y = 0x20,
        DPadUp = 0x40,
        DPadDown = 0x80,
        DPadLeft = 0x100,
        DPadRight = 0x200,
        LeftShoulder = 0x400,
        RightShoulder = 0x800,
        LeftThumbstick = 0x1000,
        RightThumbstick = 0x2000,
        Paddle1 = 0x4000,
        Paddle2 = 0x8000,
        Paddle3 = 0x10000,
        Paddle4 = 0x20000,
    };
    enum class OptionalUINavigationButtons : uint32_t
    {
        None = 0,
        Context1 = 0x1,
        Context2 = 0x2,
        Context3 = 0x4,
        Context4 = 0x8,
        PageUp = 0x10,
        PageDown = 0x20,
        PageLeft = 0x40,
        PageRight = 0x80,
        ScrollUp = 0x100,
        ScrollDown = 0x200,
        ScrollLeft = 0x400,
        ScrollRight = 0x800,
    };
    enum class RacingWheelButtons : uint32_t
    {
        None = 0,
        PreviousGear = 0x1,
        NextGear = 0x2,
        DPadUp = 0x4,
        DPadDown = 0x8,
        DPadLeft = 0x10,
        DPadRight = 0x20,
        Button1 = 0x40,
        Button2 = 0x80,
        Button3 = 0x100,
        Button4 = 0x200,
        Button5 = 0x400,
        Button6 = 0x800,
        Button7 = 0x1000,
        Button8 = 0x2000,
        Button9 = 0x4000,
        Button10 = 0x8000,
        Button11 = 0x10000,
        Button12 = 0x20000,
        Button13 = 0x40000,
        Button14 = 0x80000,
        Button15 = 0x100000,
        Button16 = 0x200000,
    };
    enum class RequiredUINavigationButtons : uint32_t
    {
        None = 0,
        Menu = 0x1,
        View = 0x2,
        Accept = 0x4,
        Cancel = 0x8,
        Up = 0x10,
        Down = 0x20,
        Left = 0x40,
        Right = 0x80,
    };
    struct IArcadeStick;
    struct IArcadeStickStatics;
    struct IArcadeStickStatics2;
    struct IFlightStick;
    struct IFlightStickStatics;
    struct IGameController;
    struct IGameControllerBatteryInfo;
    struct IGamepad;
    struct IGamepad2;
    struct IGamepadStatics;
    struct IGamepadStatics2;
    struct IHeadset;
    struct IRacingWheel;
    struct IRacingWheelStatics;
    struct IRacingWheelStatics2;
    struct IRawGameController;
    struct IRawGameController2;
    struct IRawGameControllerStatics;
    struct IUINavigationController;
    struct IUINavigationControllerStatics;
    struct IUINavigationControllerStatics2;
    struct ArcadeStick;
    struct FlightStick;
    struct Gamepad;
    struct Headset;
    struct RacingWheel;
    struct RawGameController;
    struct UINavigationController;
    struct ArcadeStickReading;
    struct FlightStickReading;
    struct GamepadReading;
    struct GamepadVibration;
    struct RacingWheelReading;
    struct UINavigationReading;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Gaming::Input::IArcadeStick>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IArcadeStickStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IArcadeStickStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IFlightStick>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IFlightStickStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGameController>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGameControllerBatteryInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGamepad>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGamepad2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGamepadStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IGamepadStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IHeadset>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRacingWheel>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRacingWheelStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRacingWheelStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRawGameController>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRawGameController2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IRawGameControllerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IUINavigationController>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IUINavigationControllerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::IUINavigationControllerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Gaming::Input::ArcadeStick>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::FlightStick>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Gamepad>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::Headset>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::RacingWheel>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::RawGameController>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::UINavigationController>{ using type = class_category; };
    template <> struct category<llm::OS::Gaming::Input::ArcadeStickButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::FlightStickButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::GameControllerButtonLabel>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::GameControllerSwitchKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::GameControllerSwitchPosition>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::GamepadButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::OptionalUINavigationButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::RacingWheelButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::RequiredUINavigationButtons>{ using type = enum_category; };
    template <> struct category<llm::OS::Gaming::Input::ArcadeStickReading>{ using type = struct_category<uint64_t, llm::OS::Gaming::Input::ArcadeStickButtons>; };
    template <> struct category<llm::OS::Gaming::Input::FlightStickReading>{ using type = struct_category<uint64_t, llm::OS::Gaming::Input::FlightStickButtons, llm::OS::Gaming::Input::GameControllerSwitchPosition, double, double, double, double>; };
    template <> struct category<llm::OS::Gaming::Input::GamepadReading>{ using type = struct_category<uint64_t, llm::OS::Gaming::Input::GamepadButtons, double, double, double, double, double, double>; };
    template <> struct category<llm::OS::Gaming::Input::GamepadVibration>{ using type = struct_category<double, double, double, double>; };
    template <> struct category<llm::OS::Gaming::Input::RacingWheelReading>{ using type = struct_category<uint64_t, llm::OS::Gaming::Input::RacingWheelButtons, int32_t, double, double, double, double, double>; };
    template <> struct category<llm::OS::Gaming::Input::UINavigationReading>{ using type = struct_category<uint64_t, llm::OS::Gaming::Input::RequiredUINavigationButtons, llm::OS::Gaming::Input::OptionalUINavigationButtons>; };
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ArcadeStick> = L"Windows.Gaming.Input.ArcadeStick";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::FlightStick> = L"Windows.Gaming.Input.FlightStick";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Gamepad> = L"Windows.Gaming.Input.Gamepad";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::Headset> = L"Windows.Gaming.Input.Headset";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::RacingWheel> = L"Windows.Gaming.Input.RacingWheel";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::RawGameController> = L"Windows.Gaming.Input.RawGameController";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::UINavigationController> = L"Windows.Gaming.Input.UINavigationController";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ArcadeStickButtons> = L"Windows.Gaming.Input.ArcadeStickButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::FlightStickButtons> = L"Windows.Gaming.Input.FlightStickButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GameControllerButtonLabel> = L"Windows.Gaming.Input.GameControllerButtonLabel";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GameControllerSwitchKind> = L"Windows.Gaming.Input.GameControllerSwitchKind";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GameControllerSwitchPosition> = L"Windows.Gaming.Input.GameControllerSwitchPosition";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GamepadButtons> = L"Windows.Gaming.Input.GamepadButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::OptionalUINavigationButtons> = L"Windows.Gaming.Input.OptionalUINavigationButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::RacingWheelButtons> = L"Windows.Gaming.Input.RacingWheelButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::RequiredUINavigationButtons> = L"Windows.Gaming.Input.RequiredUINavigationButtons";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::ArcadeStickReading> = L"Windows.Gaming.Input.ArcadeStickReading";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::FlightStickReading> = L"Windows.Gaming.Input.FlightStickReading";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GamepadReading> = L"Windows.Gaming.Input.GamepadReading";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::GamepadVibration> = L"Windows.Gaming.Input.GamepadVibration";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::RacingWheelReading> = L"Windows.Gaming.Input.RacingWheelReading";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::UINavigationReading> = L"Windows.Gaming.Input.UINavigationReading";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IArcadeStick> = L"Windows.Gaming.Input.IArcadeStick";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IArcadeStickStatics> = L"Windows.Gaming.Input.IArcadeStickStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IArcadeStickStatics2> = L"Windows.Gaming.Input.IArcadeStickStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IFlightStick> = L"Windows.Gaming.Input.IFlightStick";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IFlightStickStatics> = L"Windows.Gaming.Input.IFlightStickStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGameController> = L"Windows.Gaming.Input.IGameController";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGameControllerBatteryInfo> = L"Windows.Gaming.Input.IGameControllerBatteryInfo";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGamepad> = L"Windows.Gaming.Input.IGamepad";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGamepad2> = L"Windows.Gaming.Input.IGamepad2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGamepadStatics> = L"Windows.Gaming.Input.IGamepadStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IGamepadStatics2> = L"Windows.Gaming.Input.IGamepadStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IHeadset> = L"Windows.Gaming.Input.IHeadset";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRacingWheel> = L"Windows.Gaming.Input.IRacingWheel";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRacingWheelStatics> = L"Windows.Gaming.Input.IRacingWheelStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRacingWheelStatics2> = L"Windows.Gaming.Input.IRacingWheelStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRawGameController> = L"Windows.Gaming.Input.IRawGameController";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRawGameController2> = L"Windows.Gaming.Input.IRawGameController2";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IRawGameControllerStatics> = L"Windows.Gaming.Input.IRawGameControllerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IUINavigationController> = L"Windows.Gaming.Input.IUINavigationController";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IUINavigationControllerStatics> = L"Windows.Gaming.Input.IUINavigationControllerStatics";
    template <> inline constexpr auto& name_v<llm::OS::Gaming::Input::IUINavigationControllerStatics2> = L"Windows.Gaming.Input.IUINavigationControllerStatics2";
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IArcadeStick>{ 0xB14A539D,0xBEFB,0x4C81,{ 0x80,0x51,0x15,0xEC,0xF3,0xB1,0x30,0x36 } }; // B14A539D-BEFB-4C81-8051-15ECF3B13036
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IArcadeStickStatics>{ 0x5C37B8C8,0x37B1,0x4AD8,{ 0x94,0x58,0x20,0x0F,0x1A,0x30,0x01,0x8E } }; // 5C37B8C8-37B1-4AD8-9458-200F1A30018E
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IArcadeStickStatics2>{ 0x52B5D744,0xBB86,0x445A,{ 0xB5,0x9C,0x59,0x6F,0x0E,0x2A,0x49,0xDF } }; // 52B5D744-BB86-445A-B59C-596F0E2A49DF
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IFlightStick>{ 0xB4A2C01C,0xB83B,0x4459,{ 0xA1,0xA9,0x97,0xB0,0x3C,0x33,0xDA,0x7C } }; // B4A2C01C-B83B-4459-A1A9-97B03C33DA7C
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IFlightStickStatics>{ 0x5514924A,0xFECC,0x435E,{ 0x83,0xDC,0x5C,0xEC,0x8A,0x18,0xA5,0x20 } }; // 5514924A-FECC-435E-83DC-5CEC8A18A520
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGameController>{ 0x1BAF6522,0x5F64,0x42C5,{ 0x82,0x67,0xB9,0xFE,0x22,0x15,0xBF,0xBD } }; // 1BAF6522-5F64-42C5-8267-B9FE2215BFBD
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGameControllerBatteryInfo>{ 0xDCECC681,0x3963,0x4DA6,{ 0x95,0x5D,0x55,0x3F,0x3B,0x6F,0x61,0x61 } }; // DCECC681-3963-4DA6-955D-553F3B6F6161
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGamepad>{ 0xBC7BB43C,0x0A69,0x3903,{ 0x9E,0x9D,0xA5,0x0F,0x86,0xA4,0x5D,0xE5 } }; // BC7BB43C-0A69-3903-9E9D-A50F86A45DE5
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGamepad2>{ 0x3C1689BD,0x5915,0x4245,{ 0xB0,0xC0,0xC8,0x9F,0xAE,0x03,0x08,0xFF } }; // 3C1689BD-5915-4245-B0C0-C89FAE0308FF
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGamepadStatics>{ 0x8BBCE529,0xD49C,0x39E9,{ 0x95,0x60,0xE4,0x7D,0xDE,0x96,0xB7,0xC8 } }; // 8BBCE529-D49C-39E9-9560-E47DDE96B7C8
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IGamepadStatics2>{ 0x42676DC5,0x0856,0x47C4,{ 0x92,0x13,0xB3,0x95,0x50,0x4C,0x3A,0x3C } }; // 42676DC5-0856-47C4-9213-B395504C3A3C
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IHeadset>{ 0x3FD156EF,0x6925,0x3FA8,{ 0x91,0x81,0x02,0x9C,0x52,0x23,0xAE,0x3B } }; // 3FD156EF-6925-3FA8-9181-029C5223AE3B
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRacingWheel>{ 0xF546656F,0xE106,0x4C82,{ 0xA9,0x0F,0x55,0x40,0x12,0x90,0x4B,0x85 } }; // F546656F-E106-4C82-A90F-554012904B85
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRacingWheelStatics>{ 0x3AC12CD5,0x581B,0x4936,{ 0x9F,0x94,0x69,0xF1,0xE6,0x51,0x4C,0x7D } }; // 3AC12CD5-581B-4936-9F94-69F1E6514C7D
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRacingWheelStatics2>{ 0xE666BCAA,0xEDFD,0x4323,{ 0xA9,0xF6,0x3C,0x38,0x40,0x48,0xD1,0xED } }; // E666BCAA-EDFD-4323-A9F6-3C384048D1ED
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRawGameController>{ 0x7CAD6D91,0xA7E1,0x4F71,{ 0x9A,0x78,0x33,0xE9,0xC5,0xDF,0xEA,0x62 } }; // 7CAD6D91-A7E1-4F71-9A78-33E9C5DFEA62
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRawGameController2>{ 0x43C0C035,0xBB73,0x4756,{ 0xA7,0x87,0x3E,0xD6,0xBE,0xA6,0x17,0xBD } }; // 43C0C035-BB73-4756-A787-3ED6BEA617BD
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IRawGameControllerStatics>{ 0xEB8D0792,0xE95A,0x4B19,{ 0xAF,0xC7,0x0A,0x59,0xF8,0xBF,0x75,0x9E } }; // EB8D0792-E95A-4B19-AFC7-0A59F8BF759E
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IUINavigationController>{ 0xE5AEEFDD,0xF50E,0x4A55,{ 0x8C,0xDC,0xD3,0x32,0x29,0x54,0x81,0x75 } }; // E5AEEFDD-F50E-4A55-8CDC-D33229548175
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IUINavigationControllerStatics>{ 0x2F14930A,0xF6F8,0x4A48,{ 0x8D,0x89,0x94,0x78,0x6C,0xCA,0x0C,0x2E } }; // 2F14930A-F6F8-4A48-8D89-94786CCA0C2E
    template <> inline constexpr guid guid_v<llm::OS::Gaming::Input::IUINavigationControllerStatics2>{ 0xE0CB28E3,0xB20B,0x4B0B,{ 0x9E,0xD4,0xF3,0xD5,0x3C,0xEC,0x0D,0xE4 } }; // E0CB28E3-B20B-4B0B-9ED4-F3D53CEC0DE4
    template <> struct default_interface<llm::OS::Gaming::Input::ArcadeStick>{ using type = llm::OS::Gaming::Input::IArcadeStick; };
    template <> struct default_interface<llm::OS::Gaming::Input::FlightStick>{ using type = llm::OS::Gaming::Input::IFlightStick; };
    template <> struct default_interface<llm::OS::Gaming::Input::Gamepad>{ using type = llm::OS::Gaming::Input::IGamepad; };
    template <> struct default_interface<llm::OS::Gaming::Input::Headset>{ using type = llm::OS::Gaming::Input::IHeadset; };
    template <> struct default_interface<llm::OS::Gaming::Input::RacingWheel>{ using type = llm::OS::Gaming::Input::IRacingWheel; };
    template <> struct default_interface<llm::OS::Gaming::Input::RawGameController>{ using type = llm::OS::Gaming::Input::IRawGameController; };
    template <> struct default_interface<llm::OS::Gaming::Input::UINavigationController>{ using type = llm::OS::Gaming::Input::IUINavigationController; };
    template <> struct abi<llm::OS::Gaming::Input::IArcadeStick>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetButtonLabel(uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetCurrentReading(struct struct_Windows_Gaming_Input_ArcadeStickReading*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IArcadeStickStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ArcadeStickAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ArcadeStickAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ArcadeStickRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ArcadeStickRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_ArcadeSticks(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IArcadeStickStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IFlightStick>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HatSwitchKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetButtonLabel(uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetCurrentReading(struct struct_Windows_Gaming_Input_FlightStickReading*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IFlightStickStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_FlightStickAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FlightStickAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_FlightStickRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_FlightStickRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_FlightSticks(void**) noexcept = 0;
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGameController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_HeadsetConnected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HeadsetConnected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_HeadsetDisconnected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HeadsetDisconnected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_UserChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UserChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Headset(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsWireless(bool*) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryGetBatteryReport(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGamepad>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Vibration(struct struct_Windows_Gaming_Input_GamepadVibration*) noexcept = 0;
            virtual int32_t __stdcall put_Vibration(struct struct_Windows_Gaming_Input_GamepadVibration) noexcept = 0;
            virtual int32_t __stdcall GetCurrentReading(struct struct_Windows_Gaming_Input_GamepadReading*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGamepad2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetButtonLabel(uint32_t, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGamepadStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_GamepadAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GamepadAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_GamepadRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_GamepadRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Gamepads(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IGamepadStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IHeadset>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CaptureDeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_RenderDeviceId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRacingWheel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HasClutch(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HasHandbrake(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HasPatternShifter(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPatternShifterGear(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxWheelAngle(double*) noexcept = 0;
            virtual int32_t __stdcall get_WheelMotor(void**) noexcept = 0;
            virtual int32_t __stdcall GetButtonLabel(uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetCurrentReading(struct struct_Windows_Gaming_Input_RacingWheelReading*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRacingWheelStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_RacingWheelAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RacingWheelAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RacingWheelRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RacingWheelRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_RacingWheels(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRacingWheelStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRawGameController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AxisCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ButtonCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ForceFeedbackMotors(void**) noexcept = 0;
            virtual int32_t __stdcall get_HardwareProductId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_HardwareVendorId(uint16_t*) noexcept = 0;
            virtual int32_t __stdcall get_SwitchCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetButtonLabel(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetCurrentReading(uint32_t, bool*, uint32_t, int32_t*, uint32_t, double*, uint64_t*) noexcept = 0;
            virtual int32_t __stdcall GetSwitchKind(int32_t, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRawGameController2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SimpleHapticsControllers(void**) noexcept = 0;
            virtual int32_t __stdcall get_NonRoamableId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IRawGameControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_RawGameControllerAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RawGameControllerAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RawGameControllerRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RawGameControllerRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_RawGameControllers(void**) noexcept = 0;
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IUINavigationController>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCurrentReading(struct struct_Windows_Gaming_Input_UINavigationReading*) noexcept = 0;
            virtual int32_t __stdcall GetOptionalButtonLabel(uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetRequiredButtonLabel(uint32_t, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IUINavigationControllerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_UINavigationControllerAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UINavigationControllerAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_UINavigationControllerRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_UINavigationControllerRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_UINavigationControllers(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Gaming::Input::IUINavigationControllerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromGameController(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IArcadeStick
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetButtonLabel(llm::OS::Gaming::Input::ArcadeStickButtons const& button) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::ArcadeStickReading) GetCurrentReading() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IArcadeStick>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IArcadeStick<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IArcadeStickStatics
    {
        LLM_IMPL_AUTO(llm::event_token) ArcadeStickAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value) const;
        using ArcadeStickAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IArcadeStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IArcadeStickStatics>::remove_ArcadeStickAdded>;
        [[nodiscard]] ArcadeStickAdded_revoker ArcadeStickAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value) const;
        LLM_IMPL_AUTO(void) ArcadeStickAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ArcadeStickRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value) const;
        using ArcadeStickRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IArcadeStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IArcadeStickStatics>::remove_ArcadeStickRemoved>;
        [[nodiscard]] ArcadeStickRemoved_revoker ArcadeStickRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::ArcadeStick> const& value) const;
        LLM_IMPL_AUTO(void) ArcadeStickRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::ArcadeStick>) ArcadeSticks() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IArcadeStickStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IArcadeStickStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IArcadeStickStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::ArcadeStick) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IArcadeStickStatics2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IArcadeStickStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IFlightStick
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerSwitchKind) HatSwitchKind() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetButtonLabel(llm::OS::Gaming::Input::FlightStickButtons const& button) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::FlightStickReading) GetCurrentReading() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IFlightStick>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IFlightStick<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IFlightStickStatics
    {
        LLM_IMPL_AUTO(llm::event_token) FlightStickAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value) const;
        using FlightStickAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IFlightStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IFlightStickStatics>::remove_FlightStickAdded>;
        [[nodiscard]] FlightStickAdded_revoker FlightStickAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value) const;
        LLM_IMPL_AUTO(void) FlightStickAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) FlightStickRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value) const;
        using FlightStickRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IFlightStickStatics, &impl::abi_t<llm::OS::Gaming::Input::IFlightStickStatics>::remove_FlightStickRemoved>;
        [[nodiscard]] FlightStickRemoved_revoker FlightStickRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::FlightStick> const& value) const;
        LLM_IMPL_AUTO(void) FlightStickRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::FlightStick>) FlightSticks() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::FlightStick) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IFlightStickStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IFlightStickStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGameController
    {
        LLM_IMPL_AUTO(llm::event_token) HeadsetConnected(llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::Headset> const& value) const;
        using HeadsetConnected_revoker = impl::event_revoker<llm::OS::Gaming::Input::IGameController, &impl::abi_t<llm::OS::Gaming::Input::IGameController>::remove_HeadsetConnected>;
        [[nodiscard]] HeadsetConnected_revoker HeadsetConnected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::Headset> const& value) const;
        LLM_IMPL_AUTO(void) HeadsetConnected(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) HeadsetDisconnected(llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::Headset> const& value) const;
        using HeadsetDisconnected_revoker = impl::event_revoker<llm::OS::Gaming::Input::IGameController, &impl::abi_t<llm::OS::Gaming::Input::IGameController>::remove_HeadsetDisconnected>;
        [[nodiscard]] HeadsetDisconnected_revoker HeadsetDisconnected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::Gaming::Input::Headset> const& value) const;
        LLM_IMPL_AUTO(void) HeadsetDisconnected(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) UserChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::System::UserChangedEventArgs> const& value) const;
        using UserChanged_revoker = impl::event_revoker<llm::OS::Gaming::Input::IGameController, &impl::abi_t<llm::OS::Gaming::Input::IGameController>::remove_UserChanged>;
        [[nodiscard]] UserChanged_revoker UserChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Gaming::Input::IGameController, llm::OS::System::UserChangedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) UserChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::Headset) Headset() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsWireless() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::User) User() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGameController>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGameController<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGameControllerBatteryInfo
    {
        LLM_IMPL_AUTO(llm::OS::Devices::Power::BatteryReport) TryGetBatteryReport() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGameControllerBatteryInfo>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGameControllerBatteryInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGamepad
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::GamepadVibration) Vibration() const;
        LLM_IMPL_AUTO(void) Vibration(llm::OS::Gaming::Input::GamepadVibration const& value) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GamepadReading) GetCurrentReading() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGamepad>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGamepad<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGamepad2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetButtonLabel(llm::OS::Gaming::Input::GamepadButtons const& button) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGamepad2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGamepad2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGamepadStatics
    {
        LLM_IMPL_AUTO(llm::event_token) GamepadAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value) const;
        using GamepadAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IGamepadStatics, &impl::abi_t<llm::OS::Gaming::Input::IGamepadStatics>::remove_GamepadAdded>;
        [[nodiscard]] GamepadAdded_revoker GamepadAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value) const;
        LLM_IMPL_AUTO(void) GamepadAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) GamepadRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value) const;
        using GamepadRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IGamepadStatics, &impl::abi_t<llm::OS::Gaming::Input::IGamepadStatics>::remove_GamepadRemoved>;
        [[nodiscard]] GamepadRemoved_revoker GamepadRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::Gamepad> const& value) const;
        LLM_IMPL_AUTO(void) GamepadRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::Gamepad>) Gamepads() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGamepadStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGamepadStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IGamepadStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::Gamepad) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IGamepadStatics2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IGamepadStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IHeadset
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CaptureDeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RenderDeviceId() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IHeadset>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IHeadset<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRacingWheel
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasClutch() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasHandbrake() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasPatternShifter() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxPatternShifterGear() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) MaxWheelAngle() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackMotor) WheelMotor() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetButtonLabel(llm::OS::Gaming::Input::RacingWheelButtons const& button) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::RacingWheelReading) GetCurrentReading() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRacingWheel>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRacingWheel<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRacingWheelStatics
    {
        LLM_IMPL_AUTO(llm::event_token) RacingWheelAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value) const;
        using RacingWheelAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IRacingWheelStatics, &impl::abi_t<llm::OS::Gaming::Input::IRacingWheelStatics>::remove_RacingWheelAdded>;
        [[nodiscard]] RacingWheelAdded_revoker RacingWheelAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value) const;
        LLM_IMPL_AUTO(void) RacingWheelAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RacingWheelRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value) const;
        using RacingWheelRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IRacingWheelStatics, &impl::abi_t<llm::OS::Gaming::Input::IRacingWheelStatics>::remove_RacingWheelRemoved>;
        [[nodiscard]] RacingWheelRemoved_revoker RacingWheelRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RacingWheel> const& value) const;
        LLM_IMPL_AUTO(void) RacingWheelRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::RacingWheel>) RacingWheels() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRacingWheelStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRacingWheelStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRacingWheelStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::RacingWheel) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRacingWheelStatics2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRacingWheelStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRawGameController
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) AxisCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ButtonCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::ForceFeedback::ForceFeedbackMotor>) ForceFeedbackMotors() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) HardwareProductId() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) HardwareVendorId() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) SwitchCount() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetButtonLabel(int32_t buttonIndex) const;
        LLM_IMPL_AUTO(uint64_t) GetCurrentReading(array_view<bool> buttonArray, array_view<llm::OS::Gaming::Input::GameControllerSwitchPosition> switchArray, array_view<double> axisArray) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerSwitchKind) GetSwitchKind(int32_t switchIndex) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRawGameController>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRawGameController<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRawGameController2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Haptics::SimpleHapticsController>) SimpleHapticsControllers() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NonRoamableId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRawGameController2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRawGameController2<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IRawGameControllerStatics
    {
        LLM_IMPL_AUTO(llm::event_token) RawGameControllerAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value) const;
        using RawGameControllerAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IRawGameControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IRawGameControllerStatics>::remove_RawGameControllerAdded>;
        [[nodiscard]] RawGameControllerAdded_revoker RawGameControllerAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value) const;
        LLM_IMPL_AUTO(void) RawGameControllerAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RawGameControllerRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value) const;
        using RawGameControllerRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IRawGameControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IRawGameControllerStatics>::remove_RawGameControllerRemoved>;
        [[nodiscard]] RawGameControllerRemoved_revoker RawGameControllerRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::RawGameController> const& value) const;
        LLM_IMPL_AUTO(void) RawGameControllerRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::RawGameController>) RawGameControllers() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::RawGameController) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IRawGameControllerStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IRawGameControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IUINavigationController
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::UINavigationReading) GetCurrentReading() const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetOptionalButtonLabel(llm::OS::Gaming::Input::OptionalUINavigationButtons const& button) const;
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::GameControllerButtonLabel) GetRequiredButtonLabel(llm::OS::Gaming::Input::RequiredUINavigationButtons const& button) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IUINavigationController>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IUINavigationController<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IUINavigationControllerStatics
    {
        LLM_IMPL_AUTO(llm::event_token) UINavigationControllerAdded(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value) const;
        using UINavigationControllerAdded_revoker = impl::event_revoker<llm::OS::Gaming::Input::IUINavigationControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IUINavigationControllerStatics>::remove_UINavigationControllerAdded>;
        [[nodiscard]] UINavigationControllerAdded_revoker UINavigationControllerAdded(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value) const;
        LLM_IMPL_AUTO(void) UINavigationControllerAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) UINavigationControllerRemoved(llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value) const;
        using UINavigationControllerRemoved_revoker = impl::event_revoker<llm::OS::Gaming::Input::IUINavigationControllerStatics, &impl::abi_t<llm::OS::Gaming::Input::IUINavigationControllerStatics>::remove_UINavigationControllerRemoved>;
        [[nodiscard]] UINavigationControllerRemoved_revoker UINavigationControllerRemoved(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Gaming::Input::UINavigationController> const& value) const;
        LLM_IMPL_AUTO(void) UINavigationControllerRemoved(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Gaming::Input::UINavigationController>) UINavigationControllers() const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IUINavigationControllerStatics>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IUINavigationControllerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Gaming_Input_IUINavigationControllerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Gaming::Input::UINavigationController) FromGameController(llm::OS::Gaming::Input::IGameController const& gameController) const;
    };
    template <> struct consume<llm::OS::Gaming::Input::IUINavigationControllerStatics2>
    {
        template <typename D> using type = consume_Windows_Gaming_Input_IUINavigationControllerStatics2<D>;
    };
    struct struct_Windows_Gaming_Input_ArcadeStickReading
    {
        uint64_t Timestamp;
        uint32_t Buttons;
    };
    template <> struct abi<Windows::Gaming::Input::ArcadeStickReading>
    {
        using type = struct_Windows_Gaming_Input_ArcadeStickReading;
    };
    struct struct_Windows_Gaming_Input_FlightStickReading
    {
        uint64_t Timestamp;
        uint32_t Buttons;
        int32_t HatSwitch;
        double Roll;
        double Pitch;
        double Yaw;
        double Throttle;
    };
    template <> struct abi<Windows::Gaming::Input::FlightStickReading>
    {
        using type = struct_Windows_Gaming_Input_FlightStickReading;
    };
    struct struct_Windows_Gaming_Input_GamepadReading
    {
        uint64_t Timestamp;
        uint32_t Buttons;
        double LeftTrigger;
        double RightTrigger;
        double LeftThumbstickX;
        double LeftThumbstickY;
        double RightThumbstickX;
        double RightThumbstickY;
    };
    template <> struct abi<Windows::Gaming::Input::GamepadReading>
    {
        using type = struct_Windows_Gaming_Input_GamepadReading;
    };
    struct struct_Windows_Gaming_Input_GamepadVibration
    {
        double LeftMotor;
        double RightMotor;
        double LeftTrigger;
        double RightTrigger;
    };
    template <> struct abi<Windows::Gaming::Input::GamepadVibration>
    {
        using type = struct_Windows_Gaming_Input_GamepadVibration;
    };
    struct struct_Windows_Gaming_Input_RacingWheelReading
    {
        uint64_t Timestamp;
        uint32_t Buttons;
        int32_t PatternShifterGear;
        double Wheel;
        double Throttle;
        double Brake;
        double Clutch;
        double Handbrake;
    };
    template <> struct abi<Windows::Gaming::Input::RacingWheelReading>
    {
        using type = struct_Windows_Gaming_Input_RacingWheelReading;
    };
    struct struct_Windows_Gaming_Input_UINavigationReading
    {
        uint64_t Timestamp;
        uint32_t RequiredButtons;
        uint32_t OptionalButtons;
    };
    template <> struct abi<Windows::Gaming::Input::UINavigationReading>
    {
        using type = struct_Windows_Gaming_Input_UINavigationReading;
    };
}
#endif
