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
#ifndef LLM_OS_UI_Text_0_H
#define LLM_OS_UI_Text_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Point;
    struct Rect;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm:OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm:OS::UI::Text
{
    enum class CaretType : int32_t
    {
        Normal = 0,
        Null = 1,
    };
    enum class FindOptions : uint32_t
    {
        None = 0,
        Word = 0x2,
        Case = 0x4,
    };
    enum class FontStretch : int32_t
    {
        Undefined = 0,
        UltraCondensed = 1,
        ExtraCondensed = 2,
        Condensed = 3,
        SemiCondensed = 4,
        Normal = 5,
        SemiExpanded = 6,
        Expanded = 7,
        ExtraExpanded = 8,
        UltraExpanded = 9,
    };
    enum class FontStyle : int32_t
    {
        Normal = 0,
        Oblique = 1,
        Italic = 2,
    };
    enum class FormatEffect : int32_t
    {
        Off = 0,
        On = 1,
        Toggle = 2,
        Undefined = 3,
    };
    enum class HorizontalCharacterAlignment : int32_t
    {
        Left = 0,
        Right = 1,
        Center = 2,
    };
    enum class LetterCase : int32_t
    {
        Lower = 0,
        Upper = 1,
    };
    enum class LineSpacingRule : int32_t
    {
        Undefined = 0,
        Single = 1,
        OneAndHalf = 2,
        Double = 3,
        AtLeast = 4,
        Exactly = 5,
        Multiple = 6,
        Percent = 7,
    };
    enum class LinkType : int32_t
    {
        Undefined = 0,
        NotALink = 1,
        ClientLink = 2,
        FriendlyLinkName = 3,
        FriendlyLinkAddress = 4,
        AutoLink = 5,
        AutoLinkEmail = 6,
        AutoLinkPhone = 7,
        AutoLinkPath = 8,
    };
    enum class MarkerAlignment : int32_t
    {
        Undefined = 0,
        Left = 1,
        Center = 2,
        Right = 3,
    };
    enum class MarkerStyle : int32_t
    {
        Undefined = 0,
        Parenthesis = 1,
        Parentheses = 2,
        Period = 3,
        Plain = 4,
        Minus = 5,
        NoNumber = 6,
    };
    enum class MarkerType : int32_t
    {
        Undefined = 0,
        None = 1,
        Bullet = 2,
        Arabic = 3,
        LowercaseEnglishLetter = 4,
        UppercaseEnglishLetter = 5,
        LowercaseRoman = 6,
        UppercaseRoman = 7,
        UnicodeSequence = 8,
        CircledNumber = 9,
        BlackCircleWingding = 10,
        WhiteCircleWingding = 11,
        ArabicWide = 12,
        SimplifiedChinese = 13,
        TraditionalChinese = 14,
        JapanSimplifiedChinese = 15,
        JapanKorea = 16,
        ArabicDictionary = 17,
        ArabicAbjad = 18,
        Hebrew = 19,
        ThaiAlphabetic = 20,
        ThaiNumeric = 21,
        DevanagariVowel = 22,
        DevanagariConsonant = 23,
        DevanagariNumeric = 24,
    };
    enum class ParagraphAlignment : int32_t
    {
        Undefined = 0,
        Left = 1,
        Center = 2,
        Right = 3,
        Justify = 4,
    };
    enum class ParagraphStyle : int32_t
    {
        Undefined = 0,
        None = 1,
        Normal = 2,
        Heading1 = 3,
        Heading2 = 4,
        Heading3 = 5,
        Heading4 = 6,
        Heading5 = 7,
        Heading6 = 8,
        Heading7 = 9,
        Heading8 = 10,
        Heading9 = 11,
    };
    enum class PointOptions : uint32_t
    {
        None = 0,
        IncludeInset = 0x1,
        Start = 0x20,
        ClientCoordinates = 0x100,
        AllowOffClient = 0x200,
        Transform = 0x400,
        NoHorizontalScroll = 0x10000,
        NoVerticalScroll = 0x40000,
    };
    enum class RangeGravity : int32_t
    {
        UIBehavior = 0,
        Backward = 1,
        Forward = 2,
        Inward = 3,
        Outward = 4,
    };
    enum class RichEditMathMode : int32_t
    {
        NoMath = 0,
        MathOnly = 1,
    };
    enum class SelectionOptions : uint32_t
    {
        StartActive = 0x1,
        AtEndOfLine = 0x2,
        Overtype = 0x4,
        Active = 0x8,
        Replace = 0x10,
    };
    enum class SelectionType : int32_t
    {
        None = 0,
        InsertionPoint = 1,
        Normal = 2,
        InlineShape = 7,
        Shape = 8,
    };
    enum class TabAlignment : int32_t
    {
        Left = 0,
        Center = 1,
        Right = 2,
        Decimal = 3,
        Bar = 4,
    };
    enum class TabLeader : int32_t
    {
        Spaces = 0,
        Dots = 1,
        Dashes = 2,
        Lines = 3,
        ThickLines = 4,
        Equals = 5,
    };
    enum class TextDecorations : uint32_t
    {
        None = 0,
        Underline = 0x1,
        Strikethrough = 0x2,
    };
    enum class TextGetOptions : uint32_t
    {
        None = 0,
        AdjustCrlf = 0x1,
        UseCrlf = 0x2,
        UseObjectText = 0x4,
        AllowFinalEop = 0x8,
        NoHidden = 0x20,
        IncludeNumbering = 0x40,
        FormatRtf = 0x2000,
        UseLf = 0x1000000,
    };
    enum class TextRangeUnit : int32_t
    {
        Character = 0,
        Word = 1,
        Sentence = 2,
        Paragraph = 3,
        Line = 4,
        Story = 5,
        Screen = 6,
        Section = 7,
        Window = 8,
        CharacterFormat = 9,
        ParagraphFormat = 10,
        Object = 11,
        HardParagraph = 12,
        Cluster = 13,
        Bold = 14,
        Italic = 15,
        Underline = 16,
        Strikethrough = 17,
        ProtectedText = 18,
        Link = 19,
        SmallCaps = 20,
        AllCaps = 21,
        Hidden = 22,
        Outline = 23,
        Shadow = 24,
        Imprint = 25,
        Disabled = 26,
        Revised = 27,
        Subscript = 28,
        Superscript = 29,
        FontBound = 30,
        LinkProtected = 31,
        ContentLink = 32,
    };
    enum class TextScript : int32_t
    {
        Undefined = 0,
        Ansi = 1,
        EastEurope = 2,
        Cyrillic = 3,
        Greek = 4,
        Turkish = 5,
        Hebrew = 6,
        Arabic = 7,
        Baltic = 8,
        Vietnamese = 9,
        Default = 10,
        Symbol = 11,
        Thai = 12,
        ShiftJis = 13,
        GB2312 = 14,
        Hangul = 15,
        Big5 = 16,
        PC437 = 17,
        Oem = 18,
        Mac = 19,
        Armenian = 20,
        Syriac = 21,
        Thaana = 22,
        Devanagari = 23,
        Bengali = 24,
        Gurmukhi = 25,
        Gujarati = 26,
        Oriya = 27,
        Tamil = 28,
        Telugu = 29,
        Kannada = 30,
        Malayalam = 31,
        Sinhala = 32,
        Lao = 33,
        Tibetan = 34,
        Myanmar = 35,
        Georgian = 36,
        Jamo = 37,
        Ethiopic = 38,
        Cherokee = 39,
        Aboriginal = 40,
        Ogham = 41,
        Runic = 42,
        Khmer = 43,
        Mongolian = 44,
        Braille = 45,
        Yi = 46,
        Limbu = 47,
        TaiLe = 48,
        NewTaiLue = 49,
        SylotiNagri = 50,
        Kharoshthi = 51,
        Kayahli = 52,
        UnicodeSymbol = 53,
        Emoji = 54,
        Glagolitic = 55,
        Lisu = 56,
        Vai = 57,
        NKo = 58,
        Osmanya = 59,
        PhagsPa = 60,
        Gothic = 61,
        Deseret = 62,
        Tifinagh = 63,
    };
    enum class TextSetOptions : uint32_t
    {
        None = 0,
        UnicodeBidi = 0x1,
        Unlink = 0x8,
        Unhide = 0x10,
        CheckTextLimit = 0x20,
        FormatRtf = 0x2000,
        ApplyRtfDocumentDefaults = 0x4000,
    };
    enum class UnderlineType : int32_t
    {
        Undefined = 0,
        None = 1,
        Single = 2,
        Words = 3,
        Double = 4,
        Dotted = 5,
        Dash = 6,
        DashDot = 7,
        DashDotDot = 8,
        Wave = 9,
        Thick = 10,
        Thin = 11,
        DoubleWave = 12,
        HeavyWave = 13,
        LongDash = 14,
        ThickDash = 15,
        ThickDashDot = 16,
        ThickDashDotDot = 17,
        ThickDotted = 18,
        ThickLongDash = 19,
    };
    enum class VerticalCharacterAlignment : int32_t
    {
        Top = 0,
        Baseline = 1,
        Bottom = 2,
    };
    struct IContentLinkInfo;
    struct IFontWeights;
    struct IFontWeightsStatics;
    struct IRichEditTextRange;
    struct ITextCharacterFormat;
    struct ITextConstantsStatics;
    struct ITextDocument;
    struct ITextDocument2;
    struct ITextDocument3;
    struct ITextDocument4;
    struct ITextParagraphFormat;
    struct ITextRange;
    struct ITextSelection;
    struct ContentLinkInfo;
    struct FontWeights;
    struct RichEditTextDocument;
    struct RichEditTextRange;
    struct TextConstants;
    struct FontWeight;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::Text::IContentLinkInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::IFontWeights>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::IFontWeightsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::IRichEditTextRange>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextCharacterFormat>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextConstantsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextDocument>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextDocument2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextDocument3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextDocument4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextParagraphFormat>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextRange>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ITextSelection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::Text::ContentLinkInfo>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Text::FontWeights>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Text::RichEditTextDocument>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Text::RichEditTextRange>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Text::TextConstants>{ using type = class_category; };
    template <> struct category<llm:OS::UI::Text::CaretType>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::FindOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::FontStretch>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::FontStyle>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::FormatEffect>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::HorizontalCharacterAlignment>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::LetterCase>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::LineSpacingRule>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::LinkType>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::MarkerAlignment>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::MarkerStyle>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::MarkerType>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::ParagraphAlignment>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::ParagraphStyle>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::PointOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::RangeGravity>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::RichEditMathMode>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::SelectionOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::SelectionType>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TabAlignment>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TabLeader>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TextDecorations>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TextGetOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TextRangeUnit>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TextScript>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::TextSetOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::UnderlineType>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::VerticalCharacterAlignment>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::Text::FontWeight>{ using type = struct_category<uint16_t>; };
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ContentLinkInfo> = L"Windows.UI.Text.ContentLinkInfo";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FontWeights> = L"Windows.UI.Text.FontWeights";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::RichEditTextDocument> = L"Windows.UI.Text.RichEditTextDocument";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::RichEditTextRange> = L"Windows.UI.Text.RichEditTextRange";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextConstants> = L"Windows.UI.Text.TextConstants";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::CaretType> = L"Windows.UI.Text.CaretType";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FindOptions> = L"Windows.UI.Text.FindOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FontStretch> = L"Windows.UI.Text.FontStretch";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FontStyle> = L"Windows.UI.Text.FontStyle";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FormatEffect> = L"Windows.UI.Text.FormatEffect";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::HorizontalCharacterAlignment> = L"Windows.UI.Text.HorizontalCharacterAlignment";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::LetterCase> = L"Windows.UI.Text.LetterCase";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::LineSpacingRule> = L"Windows.UI.Text.LineSpacingRule";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::LinkType> = L"Windows.UI.Text.LinkType";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::MarkerAlignment> = L"Windows.UI.Text.MarkerAlignment";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::MarkerStyle> = L"Windows.UI.Text.MarkerStyle";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::MarkerType> = L"Windows.UI.Text.MarkerType";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ParagraphAlignment> = L"Windows.UI.Text.ParagraphAlignment";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ParagraphStyle> = L"Windows.UI.Text.ParagraphStyle";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::PointOptions> = L"Windows.UI.Text.PointOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::RangeGravity> = L"Windows.UI.Text.RangeGravity";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::RichEditMathMode> = L"Windows.UI.Text.RichEditMathMode";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::SelectionOptions> = L"Windows.UI.Text.SelectionOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::SelectionType> = L"Windows.UI.Text.SelectionType";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TabAlignment> = L"Windows.UI.Text.TabAlignment";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TabLeader> = L"Windows.UI.Text.TabLeader";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextDecorations> = L"Windows.UI.Text.TextDecorations";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextGetOptions> = L"Windows.UI.Text.TextGetOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextRangeUnit> = L"Windows.UI.Text.TextRangeUnit";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextScript> = L"Windows.UI.Text.TextScript";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::TextSetOptions> = L"Windows.UI.Text.TextSetOptions";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::UnderlineType> = L"Windows.UI.Text.UnderlineType";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::VerticalCharacterAlignment> = L"Windows.UI.Text.VerticalCharacterAlignment";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::FontWeight> = L"Windows.UI.Text.FontWeight";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::IContentLinkInfo> = L"Windows.UI.Text.IContentLinkInfo";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::IFontWeights> = L"Windows.UI.Text.IFontWeights";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::IFontWeightsStatics> = L"Windows.UI.Text.IFontWeightsStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::IRichEditTextRange> = L"Windows.UI.Text.IRichEditTextRange";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextCharacterFormat> = L"Windows.UI.Text.ITextCharacterFormat";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextConstantsStatics> = L"Windows.UI.Text.ITextConstantsStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextDocument> = L"Windows.UI.Text.ITextDocument";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextDocument2> = L"Windows.UI.Text.ITextDocument2";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextDocument3> = L"Windows.UI.Text.ITextDocument3";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextDocument4> = L"Windows.UI.Text.ITextDocument4";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextParagraphFormat> = L"Windows.UI.Text.ITextParagraphFormat";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextRange> = L"Windows.UI.Text.ITextRange";
    template <> inline constexpr auto& name_v<llm:OS::UI::Text::ITextSelection> = L"Windows.UI.Text.ITextSelection";
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::IContentLinkInfo>{ 0x1ED52525,0x1C5F,0x48CB,{ 0xB3,0x35,0x78,0xB5,0x0A,0x2E,0xE6,0x42 } }; // 1ED52525-1C5F-48CB-B335-78B50A2EE642
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::IFontWeights>{ 0x7880A444,0x01AB,0x4997,{ 0x85,0x17,0xDF,0x82,0x2A,0x0C,0x45,0xF1 } }; // 7880A444-01AB-4997-8517-DF822A0C45F1
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::IFontWeightsStatics>{ 0xB3B579D5,0x1BA9,0x48EB,{ 0x9D,0xAD,0xC0,0x95,0xE8,0xC2,0x3B,0xA3 } }; // B3B579D5-1BA9-48EB-9DAD-C095E8C23BA3
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::IRichEditTextRange>{ 0x374E3515,0xBA8A,0x4A6E,{ 0x8C,0x59,0x0D,0xDE,0x3D,0x0C,0xF5,0xCD } }; // 374E3515-BA8A-4A6E-8C59-0DDE3D0CF5CD
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextCharacterFormat>{ 0x5ADEF3DB,0x05FB,0x442D,{ 0x80,0x65,0x64,0x2A,0xFE,0xA0,0x2C,0xED } }; // 5ADEF3DB-05FB-442D-8065-642AFEA02CED
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextConstantsStatics>{ 0x779E7C33,0x189D,0x4BFA,{ 0x97,0xC8,0x10,0xDB,0x13,0x5D,0x97,0x6E } }; // 779E7C33-189D-4BFA-97C8-10DB135D976E
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextDocument>{ 0xBEEE4DDB,0x90B2,0x408C,{ 0xA2,0xF6,0x0A,0x0A,0xC3,0x1E,0x33,0xE4 } }; // BEEE4DDB-90B2-408C-A2F6-0A0AC31E33E4
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextDocument2>{ 0xF2311112,0x8C89,0x49C9,{ 0x91,0x18,0xF0,0x57,0xCB,0xB8,0x14,0xEE } }; // F2311112-8C89-49C9-9118-F057CBB814EE
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextDocument3>{ 0x75AB03A1,0xA6F8,0x441D,{ 0xAA,0x18,0x0A,0x85,0x1D,0x6E,0x5E,0x3C } }; // 75AB03A1-A6F8-441D-AA18-0A851D6E5E3C
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextDocument4>{ 0x619C20F2,0xCB3B,0x4521,{ 0x98,0x1F,0x28,0x65,0xB1,0xB9,0x3F,0x04 } }; // 619C20F2-CB3B-4521-981F-2865B1B93F04
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextParagraphFormat>{ 0x2CF8CFA6,0x4676,0x498A,{ 0x93,0xF5,0xBB,0xDB,0xFC,0x0B,0xD8,0x83 } }; // 2CF8CFA6-4676-498A-93F5-BBDBFC0BD883
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextRange>{ 0x5B9E4E57,0xC072,0x42A0,{ 0x89,0x45,0xAF,0x50,0x3E,0xE5,0x47,0x68 } }; // 5B9E4E57-C072-42A0-8945-AF503EE54768
    template <> inline constexpr guid guid_v<llm:OS::UI::Text::ITextSelection>{ 0xA6D36724,0xF28F,0x430A,{ 0xB2,0xCF,0xC3,0x43,0x67,0x1E,0xC0,0xE9 } }; // A6D36724-F28F-430A-B2CF-C343671EC0E9
    template <> struct default_interface<llm:OS::UI::Text::ContentLinkInfo>{ using type = llm:OS::UI::Text::IContentLinkInfo; };
    template <> struct default_interface<llm:OS::UI::Text::FontWeights>{ using type = llm:OS::UI::Text::IFontWeights; };
    template <> struct default_interface<llm:OS::UI::Text::RichEditTextDocument>{ using type = llm:OS::UI::Text::ITextDocument; };
    template <> struct default_interface<llm:OS::UI::Text::RichEditTextRange>{ using type = llm:OS::UI::Text::ITextRange; };
    template <> struct abi<llm:OS::UI::Text::IContentLinkInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Id(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_DisplayText(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayText(void*) noexcept = 0;
            virtual int32_t __stdcall get_SecondaryText(void**) noexcept = 0;
            virtual int32_t __stdcall put_SecondaryText(void*) noexcept = 0;
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall put_Uri(void*) noexcept = 0;
            virtual int32_t __stdcall get_LinkContentKind(void**) noexcept = 0;
            virtual int32_t __stdcall put_LinkContentKind(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::IFontWeights>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::UI::Text::IFontWeightsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Black(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_Bold(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_ExtraBlack(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_ExtraBold(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_ExtraLight(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_Light(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_Medium(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_Normal(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_SemiBold(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_SemiLight(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
            virtual int32_t __stdcall get_Thin(struct struct_Windows_UI_Text_FontWeight*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::IRichEditTextRange>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentLinkInfo(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentLinkInfo(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextCharacterFormat>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllCaps(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AllCaps(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_Bold(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Bold(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_FontStretch(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FontStretch(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_FontStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_FontStyle(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ForegroundColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_ForegroundColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_Hidden(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Hidden(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Italic(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Italic(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Kerning(float*) noexcept = 0;
            virtual int32_t __stdcall put_Kerning(float) noexcept = 0;
            virtual int32_t __stdcall get_LanguageTag(void**) noexcept = 0;
            virtual int32_t __stdcall put_LanguageTag(void*) noexcept = 0;
            virtual int32_t __stdcall get_LinkType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Outline(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Outline(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Position(float*) noexcept = 0;
            virtual int32_t __stdcall put_Position(float) noexcept = 0;
            virtual int32_t __stdcall get_ProtectedText(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ProtectedText(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Size(float*) noexcept = 0;
            virtual int32_t __stdcall put_Size(float) noexcept = 0;
            virtual int32_t __stdcall get_SmallCaps(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SmallCaps(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Spacing(float*) noexcept = 0;
            virtual int32_t __stdcall put_Spacing(float) noexcept = 0;
            virtual int32_t __stdcall get_Strikethrough(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Strikethrough(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Subscript(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Subscript(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Superscript(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Superscript(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_TextScript(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_TextScript(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Underline(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Underline(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Weight(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Weight(int32_t) noexcept = 0;
            virtual int32_t __stdcall SetClone(void*) noexcept = 0;
            virtual int32_t __stdcall GetClone(void**) noexcept = 0;
            virtual int32_t __stdcall IsEqual(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextConstantsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AutoColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_MinUnitCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaxUnitCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UndefinedColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_UndefinedFloatValue(float*) noexcept = 0;
            virtual int32_t __stdcall get_UndefinedInt32Value(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UndefinedFontStretch(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UndefinedFontStyle(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextDocument>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CaretType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CaretType(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DefaultTabStop(float*) noexcept = 0;
            virtual int32_t __stdcall put_DefaultTabStop(float) noexcept = 0;
            virtual int32_t __stdcall get_Selection(void**) noexcept = 0;
            virtual int32_t __stdcall get_UndoLimit(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_UndoLimit(uint32_t) noexcept = 0;
            virtual int32_t __stdcall CanCopy(bool*) noexcept = 0;
            virtual int32_t __stdcall CanPaste(bool*) noexcept = 0;
            virtual int32_t __stdcall CanRedo(bool*) noexcept = 0;
            virtual int32_t __stdcall CanUndo(bool*) noexcept = 0;
            virtual int32_t __stdcall ApplyDisplayUpdates(int32_t*) noexcept = 0;
            virtual int32_t __stdcall BatchDisplayUpdates(int32_t*) noexcept = 0;
            virtual int32_t __stdcall BeginUndoGroup() noexcept = 0;
            virtual int32_t __stdcall EndUndoGroup() noexcept = 0;
            virtual int32_t __stdcall GetDefaultCharacterFormat(void**) noexcept = 0;
            virtual int32_t __stdcall GetDefaultParagraphFormat(void**) noexcept = 0;
            virtual int32_t __stdcall GetRange(int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetRangeFromPoint(llm:OS::Foundation::Point, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetText(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall LoadFromStream(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall Redo() noexcept = 0;
            virtual int32_t __stdcall SaveToStream(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall SetDefaultCharacterFormat(void*) noexcept = 0;
            virtual int32_t __stdcall SetDefaultParagraphFormat(void*) noexcept = 0;
            virtual int32_t __stdcall SetText(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall Undo() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextDocument2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AlignmentIncludesTrailingWhitespace(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AlignmentIncludesTrailingWhitespace(bool) noexcept = 0;
            virtual int32_t __stdcall get_IgnoreTrailingCharacterSpacing(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IgnoreTrailingCharacterSpacing(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextDocument3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ClearUndoRedoHistory() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextDocument4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetMath(void*) noexcept = 0;
            virtual int32_t __stdcall GetMath(void**) noexcept = 0;
            virtual int32_t __stdcall SetMathMode(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextParagraphFormat>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Alignment(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Alignment(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_FirstLineIndent(float*) noexcept = 0;
            virtual int32_t __stdcall get_KeepTogether(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_KeepTogether(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_KeepWithNext(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_KeepWithNext(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_LeftIndent(float*) noexcept = 0;
            virtual int32_t __stdcall get_LineSpacing(float*) noexcept = 0;
            virtual int32_t __stdcall get_LineSpacingRule(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ListAlignment(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ListAlignment(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ListLevelIndex(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ListLevelIndex(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ListStart(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ListStart(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ListStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ListStyle(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ListTab(float*) noexcept = 0;
            virtual int32_t __stdcall put_ListTab(float) noexcept = 0;
            virtual int32_t __stdcall get_ListType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ListType(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_NoLineNumber(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_NoLineNumber(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_PageBreakBefore(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_PageBreakBefore(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RightIndent(float*) noexcept = 0;
            virtual int32_t __stdcall put_RightIndent(float) noexcept = 0;
            virtual int32_t __stdcall get_RightToLeft(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RightToLeft(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Style(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Style(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SpaceAfter(float*) noexcept = 0;
            virtual int32_t __stdcall put_SpaceAfter(float) noexcept = 0;
            virtual int32_t __stdcall get_SpaceBefore(float*) noexcept = 0;
            virtual int32_t __stdcall put_SpaceBefore(float) noexcept = 0;
            virtual int32_t __stdcall get_WidowControl(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_WidowControl(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_TabCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall AddTab(float, int32_t, int32_t) noexcept = 0;
            virtual int32_t __stdcall ClearAllTabs() noexcept = 0;
            virtual int32_t __stdcall DeleteTab(float) noexcept = 0;
            virtual int32_t __stdcall GetClone(void**) noexcept = 0;
            virtual int32_t __stdcall GetTab(int32_t, float*, int32_t*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall IsEqual(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall SetClone(void*) noexcept = 0;
            virtual int32_t __stdcall SetIndents(float, float, float) noexcept = 0;
            virtual int32_t __stdcall SetLineSpacing(int32_t, float) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextRange>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Character(char16_t*) noexcept = 0;
            virtual int32_t __stdcall put_Character(char16_t) noexcept = 0;
            virtual int32_t __stdcall get_CharacterFormat(void**) noexcept = 0;
            virtual int32_t __stdcall put_CharacterFormat(void*) noexcept = 0;
            virtual int32_t __stdcall get_FormattedText(void**) noexcept = 0;
            virtual int32_t __stdcall put_FormattedText(void*) noexcept = 0;
            virtual int32_t __stdcall get_EndPosition(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_EndPosition(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Gravity(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Gravity(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Length(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Link(void**) noexcept = 0;
            virtual int32_t __stdcall put_Link(void*) noexcept = 0;
            virtual int32_t __stdcall get_ParagraphFormat(void**) noexcept = 0;
            virtual int32_t __stdcall put_ParagraphFormat(void*) noexcept = 0;
            virtual int32_t __stdcall get_StartPosition(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_StartPosition(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StoryLength(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
            virtual int32_t __stdcall put_Text(void*) noexcept = 0;
            virtual int32_t __stdcall CanPaste(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall ChangeCase(int32_t) noexcept = 0;
            virtual int32_t __stdcall Collapse(bool) noexcept = 0;
            virtual int32_t __stdcall Copy() noexcept = 0;
            virtual int32_t __stdcall Cut() noexcept = 0;
            virtual int32_t __stdcall Delete(int32_t, int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall EndOf(int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall Expand(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall FindText(void*, int32_t, uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetCharacterUtf32(uint32_t*, int32_t) noexcept = 0;
            virtual int32_t __stdcall GetClone(void**) noexcept = 0;
            virtual int32_t __stdcall GetIndex(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetPoint(int32_t, int32_t, uint32_t, llm:OS::Foundation::Point*) noexcept = 0;
            virtual int32_t __stdcall GetRect(uint32_t, llm:OS::Foundation::Rect*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetText(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetTextViaStream(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall InRange(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall InsertImage(int32_t, int32_t, int32_t, int32_t, void*, void*) noexcept = 0;
            virtual int32_t __stdcall InStory(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsEqual(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall Move(int32_t, int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveEnd(int32_t, int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveStart(int32_t, int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall Paste(int32_t) noexcept = 0;
            virtual int32_t __stdcall ScrollIntoView(uint32_t) noexcept = 0;
            virtual int32_t __stdcall MatchSelection() noexcept = 0;
            virtual int32_t __stdcall SetIndex(int32_t, int32_t, bool) noexcept = 0;
            virtual int32_t __stdcall SetPoint(llm:OS::Foundation::Point, uint32_t, bool) noexcept = 0;
            virtual int32_t __stdcall SetRange(int32_t, int32_t) noexcept = 0;
            virtual int32_t __stdcall SetText(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall SetTextViaStream(uint32_t, void*) noexcept = 0;
            virtual int32_t __stdcall StartOf(int32_t, bool, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::Text::ITextSelection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Options(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Options(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall EndKey(int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall HomeKey(int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveDown(int32_t, int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveLeft(int32_t, int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveRight(int32_t, int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall MoveUp(int32_t, int32_t, bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall TypeText(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Text_IContentLinkInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) Id() const;
        LLM_IMPL_AUTO(void) Id(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayText() const;
        LLM_IMPL_AUTO(void) DisplayText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SecondaryText() const;
        LLM_IMPL_AUTO(void) SecondaryText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) Uri() const;
        LLM_IMPL_AUTO(void) Uri(llm:OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LinkContentKind() const;
        LLM_IMPL_AUTO(void) LinkContentKind(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::UI::Text::IContentLinkInfo>
    {
        template <typename D> using type = consume_Windows_UI_Text_IContentLinkInfo<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_IFontWeights
    {
    };
    template <> struct consume<llm:OS::UI::Text::IFontWeights>
    {
        template <typename D> using type = consume_Windows_UI_Text_IFontWeights<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_IFontWeightsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Black() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Bold() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) ExtraBlack() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) ExtraBold() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) ExtraLight() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Light() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Medium() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Normal() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) SemiBold() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) SemiLight() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontWeight) Thin() const;
    };
    template <> struct consume<llm:OS::UI::Text::IFontWeightsStatics>
    {
        template <typename D> using type = consume_Windows_UI_Text_IFontWeightsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_IRichEditTextRange
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ContentLinkInfo) ContentLinkInfo() const;
        LLM_IMPL_AUTO(void) ContentLinkInfo(llm:OS::UI::Text::ContentLinkInfo const& value) const;
    };
    template <> struct consume<llm:OS::UI::Text::IRichEditTextRange>
    {
        template <typename D> using type = consume_Windows_UI_Text_IRichEditTextRange<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextCharacterFormat
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) AllCaps() const;
        LLM_IMPL_AUTO(void) AllCaps(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) BackgroundColor() const;
        LLM_IMPL_AUTO(void) BackgroundColor(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Bold() const;
        LLM_IMPL_AUTO(void) Bold(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStretch) FontStretch() const;
        LLM_IMPL_AUTO(void) FontStretch(llm:OS::UI::Text::FontStretch const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStyle) FontStyle() const;
        LLM_IMPL_AUTO(void) FontStyle(llm:OS::UI::Text::FontStyle const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) ForegroundColor() const;
        LLM_IMPL_AUTO(void) ForegroundColor(llm:OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Hidden() const;
        LLM_IMPL_AUTO(void) Hidden(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Italic() const;
        LLM_IMPL_AUTO(void) Italic(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Kerning() const;
        LLM_IMPL_AUTO(void) Kerning(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LanguageTag() const;
        LLM_IMPL_AUTO(void) LanguageTag(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::LinkType) LinkType() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Outline() const;
        LLM_IMPL_AUTO(void) Outline(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Position() const;
        LLM_IMPL_AUTO(void) Position(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) ProtectedText() const;
        LLM_IMPL_AUTO(void) ProtectedText(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Size() const;
        LLM_IMPL_AUTO(void) Size(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) SmallCaps() const;
        LLM_IMPL_AUTO(void) SmallCaps(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) Spacing() const;
        LLM_IMPL_AUTO(void) Spacing(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Strikethrough() const;
        LLM_IMPL_AUTO(void) Strikethrough(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Subscript() const;
        LLM_IMPL_AUTO(void) Subscript(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) Superscript() const;
        LLM_IMPL_AUTO(void) Superscript(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::TextScript) TextScript() const;
        LLM_IMPL_AUTO(void) TextScript(llm:OS::UI::Text::TextScript const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::UnderlineType) Underline() const;
        LLM_IMPL_AUTO(void) Underline(llm:OS::UI::Text::UnderlineType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Weight() const;
        LLM_IMPL_AUTO(void) Weight(int32_t value) const;
        LLM_IMPL_AUTO(void) SetClone(llm:OS::UI::Text::ITextCharacterFormat const& value) const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextCharacterFormat) GetClone() const;
        LLM_IMPL_AUTO(bool) IsEqual(llm:OS::UI::Text::ITextCharacterFormat const& format) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextCharacterFormat>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextCharacterFormat<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextConstantsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) AutoColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MinUnitCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxUnitCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Color) UndefinedColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) UndefinedFloatValue() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) UndefinedInt32Value() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStretch) UndefinedFontStretch() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FontStyle) UndefinedFontStyle() const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextConstantsStatics>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextConstantsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextDocument
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::CaretType) CaretType() const;
        LLM_IMPL_AUTO(void) CaretType(llm:OS::UI::Text::CaretType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) DefaultTabStop() const;
        LLM_IMPL_AUTO(void) DefaultTabStop(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ITextSelection) Selection() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) UndoLimit() const;
        LLM_IMPL_AUTO(void) UndoLimit(uint32_t value) const;
        LLM_IMPL_AUTO(bool) CanCopy() const;
        LLM_IMPL_AUTO(bool) CanPaste() const;
        LLM_IMPL_AUTO(bool) CanRedo() const;
        LLM_IMPL_AUTO(bool) CanUndo() const;
        LLM_IMPL_AUTO(int32_t) ApplyDisplayUpdates() const;
        LLM_IMPL_AUTO(int32_t) BatchDisplayUpdates() const;
        LLM_IMPL_AUTO(void) BeginUndoGroup() const;
        LLM_IMPL_AUTO(void) EndUndoGroup() const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextCharacterFormat) GetDefaultCharacterFormat() const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextParagraphFormat) GetDefaultParagraphFormat() const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextRange) GetRange(int32_t startPosition, int32_t endPosition) const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextRange) GetRangeFromPoint(llm:OS::Foundation::Point const& point, llm:OS::UI::Text::PointOptions const& options) const;
        LLM_IMPL_AUTO(void) GetText(llm:OS::UI::Text::TextGetOptions const& options, hstring& value) const;
        LLM_IMPL_AUTO(void) LoadFromStream(llm:OS::UI::Text::TextSetOptions const& options, llm:OS::Storage::Streams::IRandomAccessStream const& value) const;
        LLM_IMPL_AUTO(void) Redo() const;
        LLM_IMPL_AUTO(void) SaveToStream(llm:OS::UI::Text::TextGetOptions const& options, llm:OS::Storage::Streams::IRandomAccessStream const& value) const;
        LLM_IMPL_AUTO(void) SetDefaultCharacterFormat(llm:OS::UI::Text::ITextCharacterFormat const& value) const;
        LLM_IMPL_AUTO(void) SetDefaultParagraphFormat(llm:OS::UI::Text::ITextParagraphFormat const& value) const;
        LLM_IMPL_AUTO(void) SetText(llm:OS::UI::Text::TextSetOptions const& options, param::hstring const& value) const;
        LLM_IMPL_AUTO(void) Undo() const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextDocument>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextDocument<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextDocument2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AlignmentIncludesTrailingWhitespace() const;
        LLM_IMPL_AUTO(void) AlignmentIncludesTrailingWhitespace(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IgnoreTrailingCharacterSpacing() const;
        LLM_IMPL_AUTO(void) IgnoreTrailingCharacterSpacing(bool value) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextDocument2>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextDocument2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextDocument3
    {
        LLM_IMPL_AUTO(void) ClearUndoRedoHistory() const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextDocument3>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextDocument3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextDocument4
    {
        LLM_IMPL_AUTO(void) SetMath(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) GetMath(hstring& value) const;
        LLM_IMPL_AUTO(void) SetMathMode(llm:OS::UI::Text::RichEditMathMode const& mode) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextDocument4>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextDocument4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextParagraphFormat
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ParagraphAlignment) Alignment() const;
        LLM_IMPL_AUTO(void) Alignment(llm:OS::UI::Text::ParagraphAlignment const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) FirstLineIndent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) KeepTogether() const;
        LLM_IMPL_AUTO(void) KeepTogether(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) KeepWithNext() const;
        LLM_IMPL_AUTO(void) KeepWithNext(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LeftIndent() const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LineSpacing() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::LineSpacingRule) LineSpacingRule() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::MarkerAlignment) ListAlignment() const;
        LLM_IMPL_AUTO(void) ListAlignment(llm:OS::UI::Text::MarkerAlignment const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ListLevelIndex() const;
        LLM_IMPL_AUTO(void) ListLevelIndex(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ListStart() const;
        LLM_IMPL_AUTO(void) ListStart(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::MarkerStyle) ListStyle() const;
        LLM_IMPL_AUTO(void) ListStyle(llm:OS::UI::Text::MarkerStyle const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) ListTab() const;
        LLM_IMPL_AUTO(void) ListTab(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::MarkerType) ListType() const;
        LLM_IMPL_AUTO(void) ListType(llm:OS::UI::Text::MarkerType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) NoLineNumber() const;
        LLM_IMPL_AUTO(void) NoLineNumber(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) PageBreakBefore() const;
        LLM_IMPL_AUTO(void) PageBreakBefore(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RightIndent() const;
        LLM_IMPL_AUTO(void) RightIndent(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) RightToLeft() const;
        LLM_IMPL_AUTO(void) RightToLeft(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ParagraphStyle) Style() const;
        LLM_IMPL_AUTO(void) Style(llm:OS::UI::Text::ParagraphStyle const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) SpaceAfter() const;
        LLM_IMPL_AUTO(void) SpaceAfter(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) SpaceBefore() const;
        LLM_IMPL_AUTO(void) SpaceBefore(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::FormatEffect) WidowControl() const;
        LLM_IMPL_AUTO(void) WidowControl(llm:OS::UI::Text::FormatEffect const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) TabCount() const;
        LLM_IMPL_AUTO(void) AddTab(float position, llm:OS::UI::Text::TabAlignment const& align, llm:OS::UI::Text::TabLeader const& leader) const;
        LLM_IMPL_AUTO(void) ClearAllTabs() const;
        LLM_IMPL_AUTO(void) DeleteTab(float position) const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextParagraphFormat) GetClone() const;
        LLM_IMPL_AUTO(void) GetTab(int32_t index, float& position, llm:OS::UI::Text::TabAlignment& align, llm:OS::UI::Text::TabLeader& leader) const;
        LLM_IMPL_AUTO(bool) IsEqual(llm:OS::UI::Text::ITextParagraphFormat const& format) const;
        LLM_IMPL_AUTO(void) SetClone(llm:OS::UI::Text::ITextParagraphFormat const& format) const;
        LLM_IMPL_AUTO(void) SetIndents(float start, float left, float right) const;
        LLM_IMPL_AUTO(void) SetLineSpacing(llm:OS::UI::Text::LineSpacingRule const& rule, float spacing) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextParagraphFormat>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextParagraphFormat<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextRange
    {
        [[nodiscard]] LLM_IMPL_AUTO(char16_t) Character() const;
        LLM_IMPL_AUTO(void) Character(char16_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ITextCharacterFormat) CharacterFormat() const;
        LLM_IMPL_AUTO(void) CharacterFormat(llm:OS::UI::Text::ITextCharacterFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ITextRange) FormattedText() const;
        LLM_IMPL_AUTO(void) FormattedText(llm:OS::UI::Text::ITextRange const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) EndPosition() const;
        LLM_IMPL_AUTO(void) EndPosition(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::RangeGravity) Gravity() const;
        LLM_IMPL_AUTO(void) Gravity(llm:OS::UI::Text::RangeGravity const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Length() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Link() const;
        LLM_IMPL_AUTO(void) Link(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::ITextParagraphFormat) ParagraphFormat() const;
        LLM_IMPL_AUTO(void) ParagraphFormat(llm:OS::UI::Text::ITextParagraphFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) StartPosition() const;
        LLM_IMPL_AUTO(void) StartPosition(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) StoryLength() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
        LLM_IMPL_AUTO(void) Text(param::hstring const& value) const;
        LLM_IMPL_AUTO(bool) CanPaste(int32_t format) const;
        LLM_IMPL_AUTO(void) ChangeCase(llm:OS::UI::Text::LetterCase const& value) const;
        LLM_IMPL_AUTO(void) Collapse(bool value) const;
        LLM_IMPL_AUTO(void) Copy() const;
        LLM_IMPL_AUTO(void) Cut() const;
        LLM_IMPL_AUTO(int32_t) Delete(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count) const;
        LLM_IMPL_AUTO(int32_t) EndOf(llm:OS::UI::Text::TextRangeUnit const& unit, bool extend) const;
        LLM_IMPL_AUTO(int32_t) Expand(llm:OS::UI::Text::TextRangeUnit const& unit) const;
        LLM_IMPL_AUTO(int32_t) FindText(param::hstring const& value, int32_t scanLength, llm:OS::UI::Text::FindOptions const& options) const;
        LLM_IMPL_AUTO(void) GetCharacterUtf32(uint32_t& value, int32_t offset) const;
        LLM_IMPL_AUTO(llm:OS::UI::Text::ITextRange) GetClone() const;
        LLM_IMPL_AUTO(int32_t) GetIndex(llm:OS::UI::Text::TextRangeUnit const& unit) const;
        LLM_IMPL_AUTO(void) GetPoint(llm:OS::UI::Text::HorizontalCharacterAlignment const& horizontalAlign, llm:OS::UI::Text::VerticalCharacterAlignment const& verticalAlign, llm:OS::UI::Text::PointOptions const& options, llm:OS::Foundation::Point& point) const;
        LLM_IMPL_AUTO(void) GetRect(llm:OS::UI::Text::PointOptions const& options, llm:OS::Foundation::Rect& rect, int32_t& hit) const;
        LLM_IMPL_AUTO(void) GetText(llm:OS::UI::Text::TextGetOptions const& options, hstring& value) const;
        LLM_IMPL_AUTO(void) GetTextViaStream(llm:OS::UI::Text::TextGetOptions const& options, llm:OS::Storage::Streams::IRandomAccessStream const& value) const;
        LLM_IMPL_AUTO(bool) InRange(llm:OS::UI::Text::ITextRange const& range) const;
        LLM_IMPL_AUTO(void) InsertImage(int32_t width, int32_t height, int32_t ascent, llm:OS::UI::Text::VerticalCharacterAlignment const& verticalAlign, param::hstring const& alternateText, llm:OS::Storage::Streams::IRandomAccessStream const& value) const;
        LLM_IMPL_AUTO(bool) InStory(llm:OS::UI::Text::ITextRange const& range) const;
        LLM_IMPL_AUTO(bool) IsEqual(llm:OS::UI::Text::ITextRange const& range) const;
        LLM_IMPL_AUTO(int32_t) Move(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count) const;
        LLM_IMPL_AUTO(int32_t) MoveEnd(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count) const;
        LLM_IMPL_AUTO(int32_t) MoveStart(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count) const;
        LLM_IMPL_AUTO(void) Paste(int32_t format) const;
        LLM_IMPL_AUTO(void) ScrollIntoView(llm:OS::UI::Text::PointOptions const& value) const;
        LLM_IMPL_AUTO(void) MatchSelection() const;
        LLM_IMPL_AUTO(void) SetIndex(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t index, bool extend) const;
        LLM_IMPL_AUTO(void) SetPoint(llm:OS::Foundation::Point const& point, llm:OS::UI::Text::PointOptions const& options, bool extend) const;
        LLM_IMPL_AUTO(void) SetRange(int32_t startPosition, int32_t endPosition) const;
        LLM_IMPL_AUTO(void) SetText(llm:OS::UI::Text::TextSetOptions const& options, param::hstring const& value) const;
        LLM_IMPL_AUTO(void) SetTextViaStream(llm:OS::UI::Text::TextSetOptions const& options, llm:OS::Storage::Streams::IRandomAccessStream const& value) const;
        LLM_IMPL_AUTO(int32_t) StartOf(llm:OS::UI::Text::TextRangeUnit const& unit, bool extend) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextRange>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextRange<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Text_ITextSelection
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::SelectionOptions) Options() const;
        LLM_IMPL_AUTO(void) Options(llm:OS::UI::Text::SelectionOptions const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::Text::SelectionType) Type() const;
        LLM_IMPL_AUTO(int32_t) EndKey(llm:OS::UI::Text::TextRangeUnit const& unit, bool extend) const;
        LLM_IMPL_AUTO(int32_t) HomeKey(llm:OS::UI::Text::TextRangeUnit const& unit, bool extend) const;
        LLM_IMPL_AUTO(int32_t) MoveDown(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
        LLM_IMPL_AUTO(int32_t) MoveLeft(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
        LLM_IMPL_AUTO(int32_t) MoveRight(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
        LLM_IMPL_AUTO(int32_t) MoveUp(llm:OS::UI::Text::TextRangeUnit const& unit, int32_t count, bool extend) const;
        LLM_IMPL_AUTO(void) TypeText(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::UI::Text::ITextSelection>
    {
        template <typename D> using type = consume_Windows_UI_Text_ITextSelection<D>;
    };
    struct struct_Windows_UI_Text_FontWeight
    {
        uint16_t Weight;
    };
    template <> struct abi<Windows::UI::Text::FontWeight>
    {
        using type = struct_Windows_UI_Text_FontWeight;
    };
}
#endif
