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

// ----------------------------------------------------------------
// Unshifted symbols that differ between US and JIS
// ----------------------------------------------------------------
//
//  JA macro     Send keycode   US result   JIS result
//  ----------   ------------   ---------   ----------
#define JA_CARET  EQUAL       //    =           ^
#define JA_AT     LBKT        //    [           @
#define JA_LBKT   RBKT        //    ]           [
#define JA_RBKT   BSLH        //    \           ]
#define JA_YEN    INT_YEN     //    (none)      ¥
#define JA_COLON  APOS        //    '           :

// ----------------------------------------------------------------
// Shifted symbols that differ between US and JIS
// ----------------------------------------------------------------
//
//  JA macro     Send keycode   US result   JIS result
//  ----------   ------------   ---------   ----------
#define JA_DQT    LS(N2)      // Shift+2  :  @  →  "
#define JA_AMPS   LS(N6)      // Shift+6  :  ^  →  &
#define JA_SQT    LS(N7)      // Shift+7  :  &  →  '
#define JA_LPAR   LS(N8)      // Shift+8  :  *  →  (
#define JA_RPAR   LS(N9)      // Shift+9  :  (  →  )
#define JA_EQUAL  LS(MINUS)   // Shift+-  :  _  →  =
#define JA_UNDER  LS(INT_RO)  // Shift+ろ :  (none) →  _
#define JA_TILDE  LS(EQUAL)   // Shift+=  :  +  →  ~
#define JA_GRAVE  LS(LBKT)    // Shift+[  :  {  →  `
#define JA_LBRC   LS(RBKT)    // Shift+]  :  }  →  {
#define JA_RBRC   LS(BSLH)    // Shift+\  :  |  →  }
#define JA_PIPE   LS(INT_YEN) // Shift+¥  :  (none) →  |
#define JA_PLUS   LS(SEMI)    // Shift+;  :  :  →  +
#define JA_STAR   LS(APOS)    // Shift+'  :  "  →  *

// ----------------------------------------------------------------
// Japanese IME keys
// ----------------------------------------------------------------
#define JA_ZENKAKU   GRAVE         // 半角/全角 (GRAVE key position on JIS)
#define JA_HENKAN    INT_HENKAN    // 変換
#define JA_MUHENKAN  INT_MUHENKAN  // 無変換
#define JA_KANA      INT_KANA      // カタカナ/ひらがな
