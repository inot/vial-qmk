# Build Options
#   change yes to no to disable
#

OLED_DRIVER = ssd1306

HAPTIC_DRIVER += solenoid

# Release some space
LTO_ENABLE = yes

# Disabled Features
MOUSEKEY_ENABLE = no
SWAP_HANDS_ENABLE = no
COMBO_ENABLE = no
MAGIC_ENABLE = no
BOOTMAGIC_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
QMK_SETTINGS = no # 3000 bytes
KEY_OVERRIDE_ENABLE = no