#pragma once
#define VIAL_KEYBOARD_UID {0x25, 0xAF, 0x45, 0xDA, 0x52, 0xE7, 0x36, 0xF9}

// USB: 1000Hz 
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// For ctrl+shift+esc at windows
#define GRAVE_ESC_CTRL_OVERRIDE


// Five Layers
#define DYNAMIC_KEYMAP_LAYER_COUNT 5

// Backlight
// #define BACKLIGHT_PIN B7
// #define RGBLED_NUM 8
// #define RGB_DI_PIN E2