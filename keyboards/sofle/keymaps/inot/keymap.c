/* Copyright 2020 Josef Adamcik
 * Modification for VIA support and RGB underglow by Jens Bonk-Wiltfang
 * Modification for Vial support by Drew Petersen
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

// clang-format off

#include QMK_KEYBOARD_H
#include "oled.c"


#define _DEFAULT 0
#define _FPS 1
#define _LOWER 2
#define _RAISE 3
#define _WOW 4

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

// CS GO
enum custom_keycodes {
  A_D = SAFE_RANGE,
  D_A, 
  JUMP_SIT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case A_D :
      if (record->event.pressed) {
        register_code(KC_A);
      } else {
        unregister_code(KC_A);
        tap_code16_delay(KC_D, 25);
      }
      break;
    case D_A:
      if (record->event.pressed) {
        register_code(KC_D);
      } else {
        unregister_code(KC_D);
        tap_code16_delay(KC_A, 25);
      }
      break;
    case JUMP_SIT:
      if (record->event.pressed) {
          register_code(KC_SPC);
          register_code(KC_LCTL);
        } else {
          unregister_code(KC_SPC);
          unregister_code(KC_LCTL);
        }
  }
  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
[_DEFAULT] = LAYOUT(QK_GRAVE_ESCAPE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,  KC_7,      KC_8,     KC_9,    KC_0,     KC_BSPC, 
                    KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,  KC_U,      KC_I,     KC_O,    KC_P,     KC_LBRC, 
                    KC_LSFT,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,  KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOTE, 
                    KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  DF(0),    KC_N,  KC_M,      KC_COMMA, KC_DOT,  KC_SLASH, SC_SENT, 
                                               KC_LGUI, KC_LALT, KC_LCTL, MO(2), KC_SPACE, KC_ENTER, MO(3), KC_DELETE, KC_HOME,  KC_END),


[_FPS] = LAYOUT(KC_TRNS, KC_1,  KC_2,  KC_3,  KC_4,     KC_5,                         KC_6,    KC_7,  KC_8,     KC_9,   KC_0,       KC_BSPC, 
                KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,     KC_T,                         KC_Y,    KC_U,  KC_I,     KC_O,   KC_P,       KC_LBRC, 
                KC_LSFT, KC_A,  KC_S,  KC_D,  KC_F,     KC_G,                         KC_H,    KC_J,  KC_K,     KC_L,   KC_SCLN,    KC_QUOTE, 
                KC_LSFT, KC_Z,  KC_X,  KC_C,  KC_V,     KC_B,    KC_TRNS,   KC_TRNS,  KC_N,    KC_M,  KC_COMMA, KC_DOT, KC_SLASH,   KC_TRNS, 
                                KC_NO, KC_NO, JUMP_SIT, KC_LCTL, KC_SPACE,  KC_ENTER, KC_TRNS, KC_NO, KC_NO,    KC_NO),


[_LOWER] = LAYOUT(KC_TRNS , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   , KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11  , 
 KC_GRAVE            , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_F12  , KC_TRNS , 
 LSFT(KC_1)          , LSFT(KC_2)          , LSFT(KC_3)          , LSFT(KC_4)          , LSFT(KC_5)          , LSFT(KC_6)          , LSFT(KC_7)          , LSFT(KC_8)          , LSFT(KC_9)          , LSFT(KC_0)          , LSFT(KC_BSLS)     , KC_TRNS , 
 KC_EQUAL            , KC_MINUS            , LSFT(KC_EQUAL)      , LSFT(KC_LBRC)   , LSFT(KC_RBRC)   , KC_TRNS , KC_TRNS , KC_LBRC         , KC_RBRC         , KC_SCLN           , LSFT(KC_SCLN)     , KC_BSLS           , KC_TRNS , 
 KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ),


[_RAISE] = LAYOUT(KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_CALC , KC_TRNS , KC_TRNS , KC_TRNS , LGUI(KC_L)          , KC_DELETE           , 
 KC_TRNS , KC_INSERT           , KC_PSCR          , KC_APPLICATION      , KC_NO   , KC_NO   , KC_PGUP , KC_TRNS , KC_UP   , KC_TRNS , KC_TRNS , KC_BSPC           , KC_TRNS , 
 KC_LALT , KC_LCTL            , KC_LSFT           , KC_NO   , KC_CAPS         , KC_PGDN           , KC_LEFT , KC_DOWN , KC_RIGHT            , KC_DELETE           , KC_BSPC           , KC_TRNS , 
 LCTL(KC_Z)          , LCTL(KC_X)          , LCTL(KC_C)          , LCTL(KC_V)          , KC_NO   , KC_TRNS , KC_TRNS , KC_NO   , KC_HOME , KC_NO   , KC_END  , KC_NO   , KC_TRNS , 
 KC_LGUI , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS ),


[_WOW] = LAYOUT(KC_ESCAPE           , KC_1    , KC_2    , KC_3    , KC_4    , KC_5    , KC_6    , KC_7    , KC_8    , KC_9    , KC_0    , KC_BSPC           , 
 KC_TAB  , KC_Q    , KC_W    , KC_E    , KC_R    , KC_T    , KC_Y    , KC_U    , KC_I    , KC_O    , KC_P    , KC_LBRC         , KC_LSFT           , 
 KC_A    , KC_S    , KC_D    , KC_F    , KC_G    , KC_H    , KC_J    , KC_K    , KC_L    , KC_SCLN           , KC_QUOTE            , KC_LSFT           , 
 KC_Z    , KC_X    , KC_C    , KC_V    , KC_B    , KC_TRNS , KC_TRNS , KC_N    , KC_M    , KC_COMMA            , KC_DOT  , KC_SLASH            , SC_SENT           , 
 KC_NO   , KC_NO   , KC_9    , KC_7    , KC_SPACE            , KC_ENTER            , KC_TRNS , KC_NO   , KC_NO   , KC_RCTL            )
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [_FPS] =     {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [_LOWER] =   {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_UP, KC_DOWN)  },
    [_RAISE] =   {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(DF(1), DF(4)) },
    [_WOW] =     {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif