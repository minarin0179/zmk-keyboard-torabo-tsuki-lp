// Japanese (JIS) keyboard layout compensation for ZMK
//
// ZMK sends USB HID keycodes based on the US layout.
// When the OS keyboard setting is Japanese (JIS), the OS remaps
// these keycodes using the JIS layout table, causing many symbols
// to produce the wrong characters.
//
// Use JA_* macros instead of the standard US keycodes so that the
// intended character is produced when the OS is set to JIS.
//
// Symbols not listed here (!, #, $, %, -, ;, /, ?, <, >, etc.)
// are the same on US and JIS — use the standard ZMK names directly.

#pragma once

#include <dt-bindings/zmk/hid_usage.h>
#include <dt-bindings/zmk/hid_usage_pages.h>
#include <dt-bindings/zmk/modifiers.h>

// ----------------------------------------------------------------
// Unshifted symbols that differ between US and JIS
// ----------------------------------------------------------------

/* ^ */
#define JA_CARET (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_EQUAL_AND_PLUS))

/* @ */
#define JA_AT (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_LEFT_BRACKET_AND_LEFT_BRACE))

/* [ */
#define JA_LBKT (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_BRACE))

/* ] */
#define JA_RBKT (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_BACKSLASH_AND_PIPE))

/* ¥ */
#define JA_YEN (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL3))

/* : */
#define JA_COLON (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_APOSTROPHE_AND_QUOTE))

// ----------------------------------------------------------------
// Shifted symbols that differ between US and JIS
// ----------------------------------------------------------------

/* " */
#define JA_DQT (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_2_AND_AT)))

/* & */
#define JA_AMPS (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_6_AND_CARET)))

/* ' */
#define JA_SQT (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_7_AND_AMPERSAND)))

/* ( */
#define JA_LPAR (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_8_AND_ASTERISK)))

/* ) */
#define JA_RPAR (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_9_AND_LEFT_PARENTHESIS)))

/* = */
#define JA_EQUAL (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_MINUS_AND_UNDERSCORE)))

/* _ */
#define JA_UNDER (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL1)))

/* ~ */
#define JA_TILDE (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_EQUAL_AND_PLUS)))

/* ` */
#define JA_GRAVE (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_LEFT_BRACKET_AND_LEFT_BRACE)))

/* { */
#define JA_LBRC (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_RIGHT_BRACKET_AND_RIGHT_BRACE)))

/* } */
#define JA_RBRC (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_BACKSLASH_AND_PIPE)))

/* | */
#define JA_PIPE (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL3)))

/* + */
#define JA_PLUS (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_SEMICOLON_AND_COLON)))

/* * */
#define JA_STAR (LS(ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_APOSTROPHE_AND_QUOTE)))

// ----------------------------------------------------------------
// Japanese IME keys
// ----------------------------------------------------------------

/* 半角/全角 */
#define JA_ZENKAKU (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_GRAVE_ACCENT_AND_TILDE))

/* 変換 */
#define JA_HENKAN (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL4))

/* 無変換 */
#define JA_MUHENKAN (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL5))

/* カタカナ/ひらがな */
#define JA_KANA (ZMK_HID_USAGE(HID_USAGE_KEY, HID_USAGE_KEY_KEYBOARD_INTERNATIONAL2))
