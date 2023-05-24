#include QMK_KEYBOARD_H

enum layer_names {
  _DEFAULT, 
  _RAISE, 
  _LOWER, 
  _RESET,
  _CS
};

// CS GO
enum custom_keycodes {
  A_D = SAFE_RANGE,
  D_A,
  JUMP_SIT
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case A_D:
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
  [_DEFAULT] = LAYOUT( /* qwerty */
    KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,        KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPACE ,
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRACKET ,
    KC_CAPSLOCK,    KC_A,    KC_S,    KC_D,    KC_F,        KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT ,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_SFTENT, 
    RGUI(KC_SPACE), KC_NO,   KC_LGUI, KC_LALT, KC_LCTL,     OSL(1),   KC_SPC,   KC_ENT,  OSL(2),  KC_NO,   KC_NO,   KC_NO,   KC_NO,    TG(4)
  ),

  [_RAISE] = LAYOUT(
    KC_TRNS,  KC_F1,      KC_F2,      KC_F3,            KC_F4,             KC_F5,                                 KC_F6,       KC_F7,       KC_F8,      KC_F9,           KC_F10,     KC_F11,
    KC_GRAVE, KC_1,       KC_2,       KC_3,             KC_4,              KC_5,                                  KC_6,        KC_7,        KC_8,       KC_9,            KC_0,       KC_F12,
    KC_TRNS,  LSFT(KC_1), LSFT(KC_2), LSFT(KC_3),       LSFT(KC_4),        LSFT(KC_5),                            LSFT(KC_6),  LSFT(KC_7),  LSFT(KC_8), LSFT(KC_9),      LSFT(KC_0), LSFT(KC_BSLASH),
    KC_TRNS,  KC_EQUAL,   KC_MINUS,   LSFT(KC_EQUAL),   LSFT(KC_LBRACKET), LSFT(KC_RBRACKET),                     KC_LBRACKET, KC_RBRACKET, KC_SCOLON,  LSFT(KC_SCOLON), KC_BSLASH,  KC_TRNS,
    KC_TRNS,  KC_TRNS,    KC_TRNS,    KC_TRNS,          KC_TRNS,           KC_TRNS,           KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,         KC_TRNS,    KC_TRNS
  ),

  [_LOWER] = LAYOUT(
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,                       KC_CALC,   KC_TRNS, KC_TRNS, KC_TRNS,  LGUI(KC_L), KC_DELETE,
    KC_TRNS, KC_INSERT,  KC_PSCREEN, KC_APPLICATION, KC_NO,      KC_NO,                         KC_PGUP,   KC_TRNS, KC_UP,   KC_TRNS,  KC_TRNS,    KC_BSPACE,
    KC_TRNS, KC_LALT,    KC_LCTRL,   KC_LSHIFT,      KC_NO,      KC_CAPSLOCK,                   KC_PGDOWN, KC_LEFT, KC_DOWN, KC_RIGHT, KC_DELETE,  KC_BSPACE,
    KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C),     LCTL(KC_V), KC_NO,                         KC_NO,     KC_HOME, KC_NO,   KC_END,   KC_NO,      KC_TRNS,
    KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,        KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,    KC_TRNS
  ),

  [_RESET] = LAYOUT(
    KC_TRNS,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,                     KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO   ,
    KC_NO,    KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  ,  KC_NO  ,  KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , QK_BOOT
  ),

  [_CS] = LAYOUT( /* FPS */
    KC_GESC,        KC_1,    KC_2,    KC_3,    KC_4,        KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_BSPACE ,
    KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,        KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRACKET ,
    KC_LCTL,        KC_A,    KC_S,    KC_D,    KC_F,        KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT ,
    KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,        KC_B,                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_SFTENT, 
    RGUI(KC_SPACE), KC_LGUI, KC_NO,   KC_NO,   JUMP_SIT,    KC_LCTL,  KC_SPC,  KC_ENT,   KC_NO,   KC_NO,   KC_NO,   KC_1,    KC_NO,    TG(4)
  ),

  /*
  [_TRNS] = LAYOUT(
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS ,
    KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  */
};