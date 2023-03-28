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

// Default keymap. This can be changed in Vial. Use oled.c to change beavior that Vial cannot change.

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPACE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, DF(0), KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_SFTENT, KC_LGUI, KC_LALT, KC_LCTRL, MO(2), KC_SPACE, KC_ENTER, MO(3), KC_DELETE, KC_HOME, KC_END), 


[1] = LAYOUT(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPACE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_LCTRL, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO), 


[2] = LAYOUT(KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_F12, KC_TRNS, LSFT(KC_1), LSFT(KC_2), LSFT(KC_3), LSFT(KC_4), LSFT(KC_5), LSFT(KC_6), LSFT(KC_7), LSFT(KC_8), LSFT(KC_9), LSFT(KC_0), LSFT(KC_BSLASH), KC_TRNS, KC_EQUAL, KC_MINUS, LSFT(KC_EQUAL), LSFT(KC_LBRACKET), LSFT(KC_RBRACKET), KC_TRNS, KC_TRNS, KC_LBRACKET, KC_RBRACKET, KC_SCOLON, LSFT(KC_SCOLON), KC_BSLASH, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS), 


[3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_L), KC_DELETE, KC_TRNS, KC_INSERT, KC_PSCREEN, KC_APPLICATION, KC_NO, KC_NO, KC_PGUP, KC_TRNS, KC_UP, KC_TRNS, KC_TRNS, KC_BSPACE, KC_TRNS, KC_LALT, KC_LCTRL, KC_LSHIFT, KC_NO, KC_CAPSLOCK, KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE, KC_BSPACE, KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_NO, KC_END, KC_NO, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS), 


[4] = LAYOUT(KC_ESCAPE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPACE, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRACKET, KC_LSHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCOLON, KC_QUOTE, KC_LSHIFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMMA, KC_DOT, KC_SLASH, KC_SFTENT, KC_NO, KC_NO, KC_9, KC_7, KC_SPACE, KC_ENTER, KC_TRNS, KC_NO, KC_NO, KC_RCTRL), 
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] = {  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),           ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [1] = {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [2] = {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS, KC_TRNS)  },
    [3] = {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(DF(1), DF(4)) },
    [4] = {  ENCODER_CCW_CW(KC_TRNS, KC_TRNS),           ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif