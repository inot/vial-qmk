# BM43a

## Making steps

* Hardware Supported: bm43a PCB
* Hardware Availability: [KPRepublic](https://kprepublic.com/products/bm43a-bm43-43-keys-40-custom-mechanical-keyboard-pcb-programmed-numpad-layouts-qmk-firmware-with-rgb-bottom-underglow-alps-mx)

Make example for this keyboard (after setting up your build environment):

    make kprepublic/bm43a:inot

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Layout

![title](https://i.imgur.com/KDd0MzE.png)

## Rules

* Via and Vial enabled.
* Backlight enabled with all effects
* Grave ESC enabled and fix for ctrl-shift-esc at Windows.
* Tap Dance enabled.

## Keymap creation steps

* Upload *kprepublic_bm43a_layout_inot.json* to [QMK Configurator](https://config.qmk.fm/)
* Change keymap and download json.
* Copy content of downloaded json file to *kprepublic_bm43a_layout_inot.json*.
* Execute command `qmk json2c keyboards/kprepublic/bm43a/keymaps/inot/kprepublic_bm43a_layout_inot.json`
* Copy result of command to *keymap.c* file.

## About

* [Telegram](https://t.me/inotka)
