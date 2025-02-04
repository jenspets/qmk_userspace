/* -*- c-file-style: "mqk" -*- */
#pragma once
#include QMK_KEYBOARD_H   // In case we are loaded first

#ifndef SWAP_HANDS_ENABLE
#ifdef SH_T
#undef SH_T
#endif
#define SH_T(kc) kc
#endif

#ifndef NO_GAME
#define TO_GAME TO(_GAME)
#define TG_GAME TG(_GAME)
#else
#define TO_GAME KC_NO
#define TG_GAME KC_NO
#endif

#ifndef NO_QWERTY
#define DF_QWERTY DF(_QWERTY)
#else
#define DF_QWERTY KC_NO
#endif

#ifdef USE_PLOVER
#define TO_PLOVER TO(_PLOVER)
#else
#define TO_PLOVER KC_NO
#endif

#ifdef USE_NEWMODELF
#define TO_FN MO(_FN)
#define TO_FN2 MO(_FN2)
#else
#define TO_FN KC_NO
#define TO_FN2 KC_NO
#endif

#ifndef AUDIO_ENABLE
#undef MU_MOD
#undef AU_ON
#undef AU_OFF
#undef MUV_DE
#undef MUV_IN
#undef MU_ON
#undef MU_OFF
#undef MI_ON
#undef MI_OFF
#define MU_MOD KC_NO
#define AU_ON KC_NO
#define AU_OFF KC_NO
#define MUV_DE KC_NO
#define MUV_IN KC_NO
#define MU_ON KC_NO
#define MU_OFF KC_NO
#define MI_ON KC_NO
#define MI_OFF KC_NO
#endif


enum layers {
    _COLEMAK = 0,
#ifndef NO_GAME
    _GAME,
    _GAME2,
#endif
#ifndef NO_QWERTY
    _QWERTY,
#endif
#ifdef USE_PLOVER
    _PLOVER,
#endif
#ifdef USE_NEWMODELF
    _FN,
    _FN2,
#endif
    _LOWER,
    _RAISE,
    _AUDIO,
    _ADJUST,
    _NAV,
    _NUM,
};

#define BASE_R2_L KC_Q, KC_W, KC_F, KC_P, KC_B
#define BASE_R2_R KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define BASE_R3_L LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_G
#define BASE_R3_R KC_M, RSFT_T(KC_N), RCTL_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O)
#define BASE_R4_L LT(_NAV, KC_Z), KC_X, KC_C, RALT_T(KC_D), KC_V
#define BASE_R4_R KC_K, RALT_T(KC_H), KC_COMM, KC_DOT, LT(_AUDIO, KC_SLSH)
#define BASE_T_L  LT(_LOWER, KC_TAB), SH_T(KC_SPC)
#define BASE_T_R  SH_T(KC_BSPC), LT(_RAISE, KC_ESC)

#define QWR_R2_L KC_Q, KC_W, KC_E, KC_R, KC_T
#define QWR_R2_R KC_Y, KC_U, KC_I, KC_O, KC_P
#define QWR_R3_L LGUI_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define QWR_R3_R KC_H, RSFT_T(KC_J), RCTL_T(KC_K), LALT_T(KC_L), LGUI_T(KC_SCLN)
#define QWR_R4_L LT(_NAV, KC_Z), KC_X, KC_C, RALT_T(KC_V), KC_B
#define QWR_R4_R KC_N, RALT_T(KC_M), KC_COMM, KC_DOT, LT(_AUDIO, KC_SLSH)
#define QWR_T_L  LT(_LOWER, KC_TAB), SH_T(KC_SPC)
#define QWR_T_R  SH_T(KC_BSPC), LT(_RAISE, KC_ESC)

#define LOW_R2_L KC_GRV, KC_AT, KC_LCBR, KC_RCBR, KC_PERC
#define LOW_R2_R KC_CIRC, KC_AMPR, KC_PIPE, KC_BSLS, KC_TILD
#define LOW_R3_L KC_ESC, KC_EXLM, KC_LPRN, KC_RPRN, KC_QUOT
#define LOW_R3_R KC_ASTR, KC_MINS, KC_EQL, KC_NUHS, LSFT(KC_NUHS)
#define LOW_R4_L KC_CAPS, KC_DLR, KC_LBRC, KC_RBRC, LSFT(KC_QUOT)
#define LOW_R4_R KC_HASH, KC_UNDS, KC_PLUS, KC_NUBS, LSFT(KC_NUBS)
#define LOW_T_L  KC_TRNS, KC_TRNS
#define LOW_T_R  KC_DEL, MO(_ADJUST)

#define RSE_R2_L KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define RSE_R2_R KC_F6, KC_F7, KC_F8, KC_F9, KC_F10
#define RSE_R3_L KC_9, KC_7, KC_3, KC_1, KC_HOME
#define RSE_R3_R KC_PGUP, KC_0, KC_2, KC_6, KC_8
#define RSE_R4_L KC_F11, KC_F12, KC_INS, KC_5, KC_END
#define RSE_R4_R KC_PGDN, KC_4, TG(_NAV), TG(_NUM), KC_PSCR
#define RSE_T_L  MO(_ADJUST), KC_ENT
#define RSE_T_R  KC_TRNS, KC_TRNS

#define AUD_R2_L KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define AUD_R2_R KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define AUD_R3_L KC_NO, MU_NEXT, AU_ON, AU_OFF, KC_NO
#define AUD_R3_R KC_NO, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO
#define AUD_R4_L AU_PREV, AU_NEXT, MU_ON, MU_OFF, MI_ON
#define AUD_R4_R MI_OFF, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS
#define AUD_T_L  KC_TRNS, KC_TRNS
#define AUD_T_R  KC_TRNS, KC_TRNS

#define ADJ_R2_L QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI
#define ADJ_R2_R RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD
#define ADJ_R3_L KC_SYRQ, KC_NO, KC_NO, KC_NO, KC_NO
#define ADJ_R3_R KC_NO, DF(_COLEMAK), TO_GAME, DF_QWERTY, TO_PLOVER
#define ADJ_R4_L KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define ADJ_R4_R KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ADJ_T_L  KC_TRNS, KC_PSCR
#define ADJ_T_R  KC_INS, KC_TRNS

#define NAV_R2_L KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U
#define NAV_R2_R KC_BTN4, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN5
#define NAV_R3_L KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D
#define NAV_R3_R KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define NAV_R4_L KC_TRNS, KC_LALT, KC_LCTL, KC_LSFT, KC_LGUI
#define NAV_R4_R KC_TAB, KC_HOME, KC_PGDN, KC_PGUP, KC_END
#define NAV_T_L  KC_TRNS, KC_SPC
#define NAV_T_R  KC_TRNS, TG(_NAV)

#define NUM_R2_L KC_NUM, KC_HOME, KC_UP, KC_END, KC_PGUP
#define NUM_R2_R KC_PEQL, KC_P7, KC_P8, KC_P9, KC_PENT
#define NUM_R3_L KC_NO, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN
#define NUM_R3_R KC_PDOT, KC_P4, KC_P5, KC_P6, KC_TAB
#define NUM_R4_L KC_KP_SLASH, KC_KP_ASTERISK, KC_KP_MINUS, KC_KP_PLUS, KC_COMM
#define NUM_R4_R KC_P0, KC_P1, KC_P2, KC_P3, KC_DEL
#define NUM_T_L  KC_NO, KC_SPC
#define NUM_T_R  KC_BSPC, TG(_NUM)

#define GAME_R2_L KC_TAB, KC_Q, KC_W, KC_E, KC_R
#define GAME_R2_R KC_ESC, KC_NO, KC_UP, KC_NO, KC_DEL
#define GAME_R3_L KC_LCTL, KC_A, KC_S, KC_D, KC_F
#define GAME_R3_R KC_P0, KC_LEFT, KC_DOWN, KC_RIGHT, KC_BSPC
#define GAME_R4_L KC_LSFT, KC_Z, KC_X, KC_C, KC_V
#define GAME_R4_R KC_NO, KC_NO, KC_NO, KC_NO, KC_ENT
#define GAME_T_L  MO(_GAME2), KC_SPC
#define GAME_T_R  KC_SPC, KC_NO

#define GAME2_R2_L KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define GAME2_R2_R KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define GAME2_R3_L KC_1, KC_2, KC_3, KC_4, KC_5
#define GAME2_R3_R KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define GAME2_R4_L KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO
#define GAME2_R4_R KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
#define GAME2_T_L  KC_TRNS, KC_NO
#define GAME2_T_R  KC_NO, TG_GAME

enum custom_keycodes {
  X_THE = SAFE_RANGE
};
