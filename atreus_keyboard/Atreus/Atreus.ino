 /* -*- mode: c++ -*-
 * Atreus -- Chrysalis-enabled Sketch for the Keyboardio Atreus
 * Copyright (C) 2018, 2019  Keyboard.io, Inc
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"



#define MO(n) ShiftToLayer(n)
#define TG(n) LockLayer(n)

enum {
  MACRO_QWERTY,
  MACRO_VERSION_INFO
};

#define Key_Exclamation LSHIFT(Key_1)
#define Key_At LSHIFT(Key_2)
#define Key_Hash LSHIFT(Key_3)
#define Key_Dollar LSHIFT(Key_4)
#define Key_Percent LSHIFT(Key_5)
#define Key_Caret LSHIFT(Key_6)
#define Key_And LSHIFT(Key_7)
#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

enum {
  QWERTY,
  FUN,
  UPPER
};

/* *INDENT-OFF* */
KEYMAPS(
  [QWERTY] = KEYMAP_STACKED
  (
       Key_Q         ,Key_W         ,Key_E       ,Key_R          ,Key_T
      ,Key_A         ,Key_S         ,Key_D       ,Key_F          ,Key_G
      ,Key_Z         ,Key_X         ,Key_C       ,Key_V          ,Key_B ,Key_Esc
      ,Key_LeftArrow ,Key_RightArrow ,MO(UPPER) ,Key_Backspace ,MO(FUN) ,Key_Tab

                     ,Key_Y     ,Key_U      ,Key_I     ,Key_O         ,Key_P
                     ,Key_H     ,Key_J      ,Key_K     ,Key_L         ,Key_Semicolon
       ,Key_Quote    ,Key_N     ,Key_M      ,Key_Comma ,Key_Period    ,Key_Slash
       ,Key_Enter    ,MO(FUN)   ,Key_Space  ,MO(UPPER) ,Key_DownArrow ,Key_UpArrow   
  ),

  [FUN] = KEYMAP_STACKED
  (
       Key_Exclamation ,Key_At           ,Key_LeftCurlyBracket ,Key_RightCurlyBracket, LSHIFT(Key_Minus)
      ,Key_Hash        ,Key_Dollar       ,Key_LeftParen        ,Key_RightParen      ,Key_Minus
      ,Key_Percent     ,Key_Caret        ,Key_LeftBracket      ,Key_RightBracket     ,Key_Plus ,___
      ,Key_Home        ,Key_End          ,___       ,Key_Delete ,___ ,___   

           ,LSHIFT(Key_7) /* & */          ,Key_7 ,Key_8 ,Key_9      ,Key_0
           ,Key_KeypadMultiply             ,Key_4 ,Key_5 ,Key_6      ,Key_Equals
      ,Key_Backtick  ,LSHIFT(Key_Backslash) /*pipe*/ ,Key_1 ,Key_2 ,Key_3      ,Key_Backslash
      ,___ ,___                            ,___   ,___   ,Key_PageDown     ,Key_PageUp
   ),

  [UPPER] = KEYMAP_STACKED
  (
       Key_Insert            ,Key_Home                 ,Key_UpArrow   ,Key_End        ,Key_PageUp
      ,Key_Delete            ,Key_LeftArrow            ,Key_DownArrow ,Key_RightArrow ,Key_PageDown
      ,M(MACRO_VERSION_INFO) ,Consumer_VolumeIncrement ,XXX           ,XXX            ,___ ,___
      ,MoveToLayer(QWERTY)   ,Consumer_VolumeDecrement ,___           ,___            ,___ ,___

                ,Key_UpArrow   ,Key_F7              ,Key_F8          ,Key_F9         ,Key_F10
                ,Key_DownArrow ,Key_F4              ,Key_F5          ,Key_F6         ,Key_F11
      ,___      ,XXX           ,Key_F1              ,Key_F2          ,Key_F3         ,Key_F12
      ,___      ,___           ,MoveToLayer(QWERTY) ,Key_PrintScreen ,Key_ScrollLock ,Consumer_PlaySlashPause
   )
)
/* *INDENT-ON* */

KALEIDOSCOPE_INIT_PLUGINS(
  EEPROMSettings,
//  EEPROMKeymap,
  Focus,
  FocusEEPROMCommand,
  FocusSettingsCommand,
  Qukeys,
  SpaceCadet,
  OneShot,
  Macros,
  MouseKeys
);

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
  case MACRO_QWERTY:
    // This macro is currently unused, but is kept around for compatibility
    // reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
    // longer do. We keep it so that if someone still has the old layout with
    // the macro in EEPROM, it will keep working after a firmware update.
    Layer.move(QWERTY);
    break;
  case MACRO_VERSION_INFO:
    if (keyToggledOn(keyState)) {
      Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
      Macros.type(PSTR(BUILD_INFORMATION));
    }
    break;
  default:
    break;
  }

  return MACRO_NONE;
}

void setup() {
  Kaleidoscope.setup();
  SpaceCadet.disable();

  //QuKeys - tap/hold modifiers
  QUKEYS(
    // Layer 0
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 0), Key_LeftShift),        // A/shift
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 1), Key_LeftControl),      // S/control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 2), Key_LeftAlt),          // D/option
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 3), Key_LeftGui),          // F/cmd
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 8), Key_RightGui),         // J/cmd
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 9), Key_RightAlt),         // K/option
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 10), Key_RightControl),     // L/control
    kaleidoscope::plugin::Qukey(0, KeyAddr(1, 11), Key_RightShift),       // ;/shift

    // Layer 1
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 0), Key_LeftShift),        // A/shift
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 1), Key_LeftControl),      // S/control
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 2), Key_LeftAlt),          // D/option
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 3), Key_LeftGui),          // F/cmd
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 8), Key_RightGui),         // J/cmd
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 9), Key_RightAlt),         // K/option
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 10), Key_RightControl),     // L/control
    kaleidoscope::plugin::Qukey(1, KeyAddr(1, 11), Key_RightShift),       // ;/shift

    // Layer 2
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 0), Key_LeftShift),        // A/shift
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 1), Key_LeftControl),      // S/control
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 2), Key_LeftAlt),          // D/option
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 3), Key_LeftGui),          // F/cmd
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 8), Key_RightGui),         // J/cmd
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 9), Key_RightAlt),         // K/option
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 10), Key_RightControl),     // L/control
    kaleidoscope::plugin::Qukey(2, KeyAddr(1, 11), Key_RightShift),       // ;/shift
  )
//  Qukeys.setHoldTimeout(1000); // 1 second time out for
  Qukeys.setOverlapThreshold(75); // roll-over - allow modifier key to be released before the modified key
  
//  EEPROMKeymap.setup(10);
}

void loop() {
  Kaleidoscope.loop();
}
