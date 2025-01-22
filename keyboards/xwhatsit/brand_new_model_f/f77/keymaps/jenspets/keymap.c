/* -*- c-file-style: "qmk" -*- */

#include QMK_KEYBOARD_H
#include <jenspets.h>

#define LAYOUT_wrap(...) LAYOUT_all(__VA_ARGS__)
#define AU_NEXT KC_MNXT
#define AU_PREV KC_MPRV
#define MU_NEXT KC_NO

//enum layers layer_names;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_wrap(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,    KC_P7,   KC_P8,   KC_P9,
			     KC_TAB, BASE_R2_L, BASE_R2_R, KC_LBRC, KC_RBRC, KC_BSPC,                                                 KC_P4,   KC_P5,   KC_P6,
			     MT(MOD_LCTL, KC_ESC), BASE_R3_L, BASE_R3_R, KC_QUOT, KC_NO, KC_ENT,                                      KC_P1,   KC_P2,   KC_P3,
			     KC_LSFT, BASE_R4_L, SH_T(KC_BSPC), BASE_R4_R, KC_RSFT, TO_FN,                                            KC_P0,   KC_UP,   KC_PDOT,
			     KC_CAPS, KC_LGUI, LT(_LOWER, KC_TAB),  SH_T(KC_SPC),  KC_NO, LT(_RAISE, KC_ESC), KC_NLCK, KC_RCTRL,      KC_LEFT, KC_DOWN, KC_RIGHT
			     ),
    [_QWERTY] = LAYOUT_wrap(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,    KC_P7,   KC_P8,   KC_P9,
			    KC_TAB, QWR_R2_L, QWR_R2_R, KC_LBRC, KC_RBRC, KC_BSPC,                                                   KC_P4,   KC_P5,   KC_P6,
			    MT(MOD_LCTL, KC_ESC), QWR_R3_L, QWR_R3_R, KC_QUOT, KC_NO, KC_ENT,                                        KC_P1,   KC_P2,   KC_P3,
			    KC_LSFT, QWR_R4_L, SH_T(KC_BSPC), QWR_R4_R, KC_RSFT, TO_FN,                                              KC_P0,   KC_UP,   KC_PDOT,
			    KC_CAPS, KC_LGUI, LT(_LOWER, KC_TAB),  SH_T(KC_SPC),  KC_NO, LT(_RAISE, KC_ESC), KC_NLCK, KC_RCTRL,      KC_LEFT, KC_DOWN, KC_RIGHT
			    ),
    [_GAME] = LAYOUT_wrap(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,    KC_P7,   KC_P8,   KC_P9,
			  KC_TAB, GAME_R2_L, GAME_R2_R, KC_LBRC, KC_RBRC, KC_BSPC,                                                 KC_P4,   KC_P5,   KC_P6,
			  MT(MOD_LCTL, KC_ESC), GAME_R3_L, GAME_R3_R, KC_QUOT, KC_NO, KC_ENT,                                      KC_P1,   KC_P2,   KC_P3,
			  KC_LSFT, GAME_R4_L, SH_T(KC_SPC), GAME_R4_R, KC_RSFT, TO_FN,                                             KC_P0,   KC_UP,   KC_PDOT,
			  KC_CAPS, KC_LGUI, MO(_GAME2),  KC_SPC,  KC_NO, KC_NO, KC_NLCK, KC_RCTRL,      KC_LEFT, KC_DOWN, KC_RIGHT
			  ),
    [_GAME2] = LAYOUT_wrap(KC_ESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRV,    KC_P7,   KC_P8,   KC_P9,
			   KC_TAB, GAME2_R2_L, GAME2_R2_R, KC_LBRC, KC_RBRC, KC_BSPC,                                               KC_P4,   KC_P5,   KC_P6,
			   MT(MOD_LCTL, KC_ESC), GAME2_R3_L, GAME2_R3_R, KC_QUOT, KC_NO, KC_ENT,                                    KC_P1,   KC_P2,   KC_P3,
			   KC_LSFT, GAME2_R4_L, SH_T(KC_SPC), GAME_R4_R, KC_RSFT, TO_FN,                                            KC_P0,   KC_UP,   KC_PDOT,
			   KC_CAPS, KC_LGUI, KC_TRNS,  KC_NO,  KC_NO, TG_GAME, KC_NLCK, KC_RCTRL,                                   KC_LEFT, KC_DOWN, KC_RIGHT
			   ),
    [_FN] = LAYOUT_all(KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8,   KC_F9, KC_F10,    KC_F11, KC_F12, KC_INS, KC_DEL,           KC_HOME,   KC_UP,   KC_PGUP,
		       KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_NO, KC_DEL,                 KC_LEFT,   KC_NO,   KC_RIGHT,
		       _______,     KC_VOLD, KC_VOLU, KC_MUTE, KC_EJCT, KC_NO, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RIGHT, KC_NO, KC_NO,  KC_END,    KC_DOWN, KC_PGDN,
		       _______, _______, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, _______, _______,            KC_INS,    KC_NO,   KC_DEL,
		       _______, KC_NO, _______,                             TO_FN2,                 _______,  _______, KC_NO, _______,             KC_NO,     KC_NO,   KC_NO
		       ),
    [_FN2] = LAYOUT_all(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			_______,     _______, _______, EEPROM_RESET, RESET, HPT_TOG, HPT_DWLI, HPT_DWLD, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			_______,         _______, _______, DEBUG, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,      _______, _______, _______,
			_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,            _______, _______, _______,
			_______, _______, _______,                             _______,                            _______,   _______, _______, _______,         _______, _______, _______
			),
    [_LOWER] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			   _______, LOW_R2_L, LOW_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, LOW_R3_L, LOW_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, LOW_R4_L, KC_DEL, LOW_R4_R, _______, _______,                                                                                   _______, _______, _______,
			   _______, _______, _______,                             _______,                         _______,  MO(_ADJUST), _______, _______,         _______, _______, _______
			   ),
    [_RAISE] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			   _______, RSE_R2_L, RSE_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, RSE_R3_L, RSE_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, RSE_R4_L, KC_INS, RSE_R4_R, _______, _______,                                                                                   _______, _______, _______,
			   _______, _______, MO(_ADJUST),                         KC_ENT,                              _______,  KC_TRNS, _______, _______,         _______, _______, _______
			   ),
    [_AUDIO] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			   _______, AUD_R2_L, AUD_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, AUD_R3_L, AUD_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			   _______, AUD_R4_L, KC_TRNS, AUD_R4_R, _______, _______,                                                                                  _______, _______, _______,
			   _______, _______, _______,                             KC_TRNS,                             _______,  KC_TRNS, _______, _______,         _______, _______, _______
			   ),
    [_ADJUST] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			    _______, ADJ_R2_L, ADJ_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			    _______, ADJ_R3_L, ADJ_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			    _______, ADJ_R4_L, KC_INS, ADJ_R4_R, _______, _______,                                                                                   _______, _______, _______,
			    _______, _______, _______,                             KC_PSCR,                             _______,  KC_TRNS, _______, _______,         _______, _______, _______
			    ),
    [_NAV] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			 _______, NAV_R2_L, NAV_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			 _______, NAV_R3_L, NAV_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			 _______, NAV_R4_L, KC_INS, NAV_R4_R, _______, _______,                                                                                   _______, _______, _______,
			 _______, _______, _______,                             KC_SPC,                             _______,  TG(_NAV), _______, _______,         _______, _______, _______			
			 ),
    [_NUM] = LAYOUT_wrap(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   _______, _______, _______,
			 _______, NUM_R2_L, NUM_R2_R, _______, _______, _______,                                                                                  _______, _______, _______,
			 _______, NUM_R3_L, NUM_R3_R, _______, _______, _______,                                                                                  _______, _______, _______,
			 _______, NUM_R4_L, KC_BSPC, NUM_R4_R, _______, _______,                                                                                  _______, _______, _______,
			 _______, _______, KC_NO,                             KC_PSCR,                              _______,  TG(_NUM), _______, _______,         _______, _______, _______
			 )
};
