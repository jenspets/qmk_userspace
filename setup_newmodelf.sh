#!/usr/bin/bash
# As the firmware for the model f labs qmk needs qmk version 0.18.17, we need to copy the user keymap to the qmk keyboard folder

MODELF_QMK_SRC=~/qmk_firmware_modelf

cp -r ./users/jenspets $MODELF_QMK_SRC/users/
cp -r ./keyboards/xwhatsit/brand_new_model_f/f77/keymaps/jenspets $MODELF_QMK_SRC/keyboards/xwhatsit/brand_new_model_f/f77/keymaps
