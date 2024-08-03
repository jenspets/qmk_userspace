/* -*- c-file-style: "qmk" -*- */
/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

#include QMK_KEYBOARD_H
#include <jenspets.h>

#define LAYOUT_wrap(...) LAYOUT(__VA_ARGS__)

enum custom_keycodes {
    X_THE = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* COLEMAK
   *
   * ,----------------------------------.                      ,----------------------------------.
   * |   Q  |   W  |   F  |   P  |   B  |                      |   J  |   L  |   U  |   Y  |   ;  |
   * |------+------+------+------+------|                      |------+------+------+------+------|
   * |   A  |   R  |   S  |   T  |   G  |                      |   M  |   N  |   E  |   I  |   O  |
   * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
   * |   Z  |   X  |   C  |   D  |   V  |  | SPC |    | ENT |  |   H  |   H  |   ,  |   .  |   /  |
   * `----------------------------------'  `-----'    `-----'  `----------------------------------'
   *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
   *          |  1  |   | LWR | SPACE | The  |            |   J  |  BS |  RSE  |   |  4  |
   *          `-----'   `--------------------'            `--------------------'   `-----'
   */
  [_COLEMAK] = LAYOUT_wrap(BASE_R2_L, BASE_R2_R,
			   BASE_R3_L, BASE_R3_R,
			   BASE_R4_L, BASE_R4_R,
			   KC_1, BASE_T_L, X_THE, KC_SPC, KC_ENT, KC_J, BASE_T_R, KC_4),
  [_GAME] = LAYOUT_wrap(GAME_R2_L, GAME_R2_R,
			GAME_R3_L, GAME_R3_R,
			GAME_R4_L, GAME_R4_R,
			KC_TRNS, GAME_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GAME_T_R, KC_TRNS),
  [_GAME2] = LAYOUT_wrap(GAME2_R2_L, GAME2_R2_R,
			 GAME2_R3_L, GAME2_R3_R,
			 GAME2_R4_L, GAME2_R4_R,
			 KC_TRNS, GAME2_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, GAME2_T_R, KC_TRNS),
  [_LOWER] = LAYOUT_wrap(LOW_R2_L, LOW_R2_R,
			 LOW_R3_L, LOW_R3_R,
			 LOW_R4_L, LOW_R4_R,
			 KC_TRNS, LOW_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LOW_T_R, KC_TRNS),
  [_RAISE] = LAYOUT_wrap(RSE_R2_L, RSE_R2_R,
			 RSE_R3_L, RSE_R3_R,
			 RSE_R4_L, RSE_R4_R,
			 KC_TRNS, RSE_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RSE_T_R, KC_TRNS),
  [_ADJUST] = LAYOUT_wrap(ADJ_R2_L, ADJ_R2_R,
			  ADJ_R3_L, ADJ_R3_R,
			  ADJ_R4_L, ADJ_R4_R,
			  KC_TRNS, ADJ_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, ADJ_T_R, KC_TRNS),
  [_NAV] = LAYOUT_wrap(NAV_R2_L, NAV_R2_R,
		       NAV_R3_L, NAV_R3_R,
		       NAV_R4_L, NAV_R4_R,
		       KC_TRNS, NAV_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NAV_T_R, KC_TRNS),
  [_NUM] = LAYOUT_wrap(NUM_R2_L, NUM_R2_R,
		       NUM_R3_L, NUM_R3_R,
		       NUM_R4_L, NUM_R4_R,
		       KC_TRNS, NUM_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NUM_T_R, KC_TRNS),
  [_AUDIO] = LAYOUT_wrap(AUD_R2_L, AUD_R2_R,
			 AUD_R3_L, AUD_R3_R,
			 AUD_R4_L, AUD_R4_R,
			 KC_TRNS, AUD_T_L, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, AUD_T_R, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record){
  switch (keycode) {
  case X_THE: {
    if  (record->event.pressed) {
      uint16_t mods = get_mods() & MOD_MASK_SHIFT;
      if (mods & MOD_MASK_SHIFT) {
	uint16_t lsft = mods & MOD_BIT(KC_LSFT);
	uint16_t rsft = mods & MOD_BIT(KC_RSFT);
	unregister_code(KC_LSFT);
	unregister_code(KC_RSFT);
	SEND_STRING("The");
	if (lsft) register_code(KC_LSFT);
	if (rsft) register_code(KC_RSFT);
      } else {
	SEND_STRING("the");
      }
    }
    break;
  }
  }
  return true;
};
