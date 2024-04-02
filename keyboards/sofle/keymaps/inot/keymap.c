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
#define _WOW 2
#define _LOWER 3
#define _RAISE 4


// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(0,KC_NO):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS); 
            } else if (record->event.pressed) {
                tap_code16(LSFT(KC_MINS)); 
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 
[_DEFAULT] = LAYOUT(KC_NO,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                               KC_NO,      KC_NO,     KC_NO,    KC_NO,   KC_NO,    LALT(KC_C), 
                    KC_NO,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,       KC_U,      KC_I,     KC_O,    KC_P,     KC_NO, 
                    LSFT_T(KC_ESCAPE), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                KC_H,       KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_LBRC, 
                    LGUI_T(KC_TAB),    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_MUTE,  DF(_DEFAULT),  KC_N,       KC_M,      KC_COMMA, KC_DOT,  KC_SLASH, KC_QUOTE, 
                                                KC_NO,   KC_NO,   KC_LCTL, MO(_LOWER), KC_SPACE, SC_SENT,       MO(_RAISE), KC_BSPC,   KC_NO,    KC_NO),

// [_DEFAULT] = LAYOUT(QK_GRAVE_ESCAPE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,  KC_7,      KC_8,     KC_9,    KC_0,     KC_BSPC, 
//                     KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,  KC_U,      KC_I,     KC_O,    KC_P,     KC_LBRC, 
//                     KC_LSFT,          KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,  KC_J,      KC_K,     KC_L,    KC_SCLN,  KC_QUOTE, 
//                     KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,  DF(0),    KC_N,  KC_M,      KC_COMMA, KC_DOT,  KC_SLASH, SC_SENT, 
//                                                KC_LGUI, KC_LALT, KC_LCTL, MO(3), KC_SPACE, KC_ENTER, MO(4), KC_DELETE, KC_HOME,  KC_END),

[_FPS] = LAYOUT(KC_ESCAPE, KC_1,  KC_2,    KC_3,  KC_4,     KC_5,                         KC_6,    KC_7,    KC_8,     KC_9,   KC_0,       KC_BSPC, 
                KC_TAB,    KC_Q,  KC_W,    KC_E,  KC_R,     KC_T,                         KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,       KC_LBRC, 
                KC_LSFT,   KC_A,  KC_S,    KC_D,  KC_F,     KC_G,                         KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,    KC_QUOTE, 
                KC_LSFT,   KC_Z,  KC_X,    KC_C,  KC_V,     KC_B,    KC_TRNS,   KC_TRNS,  KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLASH,   SC_SENT, 
                                  KC_LGUI, KC_M,  KC_LALT,  KC_LCTL, KC_SPACE,  KC_ENTER, KC_TRNS, KC_LALT, KC_F1,    KC_GRAVE),

[_WOW] = LAYOUT(KC_ESCAPE, KC_1,  KC_2,  KC_3,   KC_4,     KC_5,                                   KC_6,    KC_7,    KC_8,     KC_9,   KC_0,     KC_BSPC, 
                KC_TAB,    KC_Q,  KC_W,  KC_E,   KC_R,     KC_T,                                   KC_Y,    KC_U,    KC_I,     KC_O,   KC_P,     KC_LBRC,
                KC_LSFT,   KC_A,  KC_S,  KC_D,   KC_F,     KC_G,                                   KC_H,    KC_J,    KC_K,     KC_L,   KC_SCLN,  KC_QUOTE,
                KC_LSFT,   KC_Z,  KC_X,  KC_C,   KC_V,     KC_B,  KC_TRNS,              KC_TRNS,   KC_N,    KC_M,    KC_COMMA, KC_DOT, KC_SLASH, SC_SENT, 
                                  KC_NO, KC_M,   KC_9,     KC_7,  KC_SPACE,             SC_SENT,   KC_TRNS, KC_BSPC, KC_LGUI,  KC_RCTL ),

[_LOWER] = LAYOUT(KC_NO,    KC_NO,      KC_NO,       KC_NO,          KC_NO,         KC_NO,                              KC_NO,      KC_NO,      KC_NO,      KC_NO,         KC_NO,      KC_NO, 
                  KC_NO,    KC_F1,      KC_F2,       KC_F3,          KC_F4,         KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,         KC_F10,     KC_NO, 
                  KC_TRNS,  KC_1,       KC_2,        KC_3,           KC_4,          KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,          KC_0,       KC_F11, 
                  KC_TRNS,  KC_EQUAL,   LT(0,KC_NO), LSFT(KC_EQUAL), LSFT(KC_LBRC), LSFT(KC_RBRC),   KC_TRNS, KC_TRNS,  KC_LBRC,    KC_RBRC,    KC_SCLN,    LSFT(KC_SCLN), KC_BSLS,    KC_GRAVE, 
                                        KC_TRNS,     KC_TRNS,        KC_LALT,       KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS ),

// [_LOWER] = LAYOUT(KC_TRNS,  KC_F1,      KC_F2,       KC_F3,          KC_F4,         KC_F5,                              KC_F6,      KC_F7,      KC_F8,      KC_F9,         KC_F10,     KC_F11, 
//                   KC_GRAVE, KC_1,       KC_2,        KC_3,           KC_4,          KC_5,                               KC_6,       KC_7,       KC_8,       KC_9,          KC_0,       KC_F12, 
//                   KC_TRNS,  LSFT(KC_1), LSFT(KC_2),  LSFT(KC_3),     LSFT(KC_4),    LSFT(KC_5),                         LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9),    LSFT(KC_0), LSFT(KC_BSLS), 
//                   KC_TRNS,  KC_EQUAL,   LT(0,KC_NO), LSFT(KC_EQUAL), LSFT(KC_LBRC), LSFT(KC_RBRC),   KC_TRNS, KC_TRNS,  KC_LBRC,    KC_RBRC,    KC_SCLN,    LSFT(KC_SCLN), KC_BSLS,    KC_TRNS , 
//                                         KC_TRNS,     KC_TRNS,        KC_TRNS,       KC_TRNS,         KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS ),


[_RAISE] = LAYOUT(KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,                   KC_CALC, KC_TRNS,   KC_TRNS, KC_TRNS,  LGUI(KC_L), KC_DELETE, 
                  KC_TRNS, KC_INSERT,  KC_PSCR,    KC_APPLICATION, KC_NO,      KC_NO,                     KC_PGUP, KC_TRNS,   KC_UP,   KC_TRNS,  KC_TRNS,    KC_BSPC, 
                  KC_TRNS, KC_LALT,    KC_LCTL,    KC_LSFT,        KC_NO,      KC_CAPS,                   KC_PGDN, KC_LEFT,   KC_DOWN, KC_RIGHT, KC_DELETE,  KC_BSPC, 
                  KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),     LCTL(KC_V), KC_NO,   KC_TRNS, KC_TRNS, KC_NO,   KC_HOME,   KC_NO,   KC_END,   KC_NO,      KC_TRNS, 
                                       KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DELETE, KC_TRNS, KC_TRNS )
 };



#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_DEFAULT] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_LEFT,  KC_RIGHT)},
    [_FPS] =     {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS,  KC_TRNS)  },
    [_LOWER] =   {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_UP,    KC_DOWN)  },
    [_RAISE] =   {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(DF(_FPS), DF(_WOW)) },
    [_WOW] =     {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS,  KC_TRNS) },
};
#endif