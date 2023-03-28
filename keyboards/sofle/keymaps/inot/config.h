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

#pragma once

// Vial Support
#define VIAL_KEYBOARD_UID { 0x05, 0xCD, 0x9F, 0x8A, 0xF4, 0xDF, 0xDE, 0xB2 }
#define VIAL_UNLOCK_COMBO_ROWS { 0, 2 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

// USB: 1000Hz 
#define USB_POLLING_INTERVAL_MS 1

#define QMK_KEYS_PER_SCAN 12
#undef ENCODER_RESOLUTION
#define ENCODER_RESOLUTION 4
// For ctrl+shift+esc at windows
#define GRAVE_ESC_CTRL_OVERRIDE

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// Five Layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// For Refresh both screens
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE

#ifdef RGBLIGHT_ENABLE
    #define RGB_DI_PIN D3
    #undef RGBLED_NUM
    #define RGBLED_NUM 14
	#define RGBLED_SPLIT { RGBLED_NUM/2, RGBLED_NUM/2 }

    #undef RGBLIGHT_ANIMATIONS
    #undef RGBLIGHT_EFFECT_BREATHING
    #undef RGBLIGHT_EFFECT_RAINBOW_MOOD
    #undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #undef RGBLIGHT_EFFECT_SNAKE
    #undef RGBLIGHT_EFFECT_KNIGHT
    #undef RGBLIGHT_EFFECT_CHRISTMAS
    #undef RGBLIGHT_EFFECT_STATIC_GRADIENT
    #undef RGBLIGHT_EFFECT_ALTERNATING
    #undef RGBLIGHT_EFFECT_TWINKLE
	#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL

    #define RGBLIGHT_LIMIT_VAL 100
    #define RGBLIGHT_DEFAULT_VAL RGBLIGHT_LIMIT_VAL
    // #undef RGBLIGHT_DEFAULT_MODE RGBLIGHT_MODE_RAINBOW_SWIRL+0
#endif

