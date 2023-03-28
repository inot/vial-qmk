/* Copyright 2021 Jordan Duabe
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
// https://joric.github.io/qle/ 126x24
#ifdef OLED_ENABLE
#    include QMK_KEYBOARD_H

static void print_status_narrow(void) {
    oled_write_P(PSTR("inot"), false);
    oled_write_P(PSTR("\n\n\n"), false);
    // Print current mode
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        default:
            oled_write_P(PSTR("Mod\n"), false);
            break;
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            oled_write_P(PSTR("Base\n"), false);
            rgblight_setrgb(0, 20, 20);
            break;
        case 1:
            oled_write_P(PSTR("FPS"), false);
            rgblight_setrgb(20, 0, 35);
            break;
        case 2:
            oled_write_P(PSTR("Lower"), false);
            rgblight_setrgb(0, 20, 0);
            break;
        case 3:
            oled_write_P(PSTR("Raise"), false);
            rgblight_setrgb(20, 0, 0);
            break;
        case 4:
            oled_write_P(PSTR("WoW"), false);
            rgblight_setrgb(25, 20, 0);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_P(PSTR("\n\n"), false);
    if (led_usb_state.caps_lock) { 
        oled_write_P(PSTR("CAPS"), false);
    } else {
        oled_write_P(PSTR("    "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    print_status_narrow();
    return false;
}

#endif
