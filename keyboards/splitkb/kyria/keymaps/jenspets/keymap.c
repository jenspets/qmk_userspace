/* Copyright 2021 Jens-Petter Sandvik <jens.petter.sandvik@gmail.com>
 * Based on the defaults by Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include <jenspets.h>
#include <stdio.h>

#define LAYOUT_wrap(...) LAYOUT(__VA_ARGS__)

/* #define CTL_ESC  MT(MOD_LCTL, KC_ESC) */
/* #define CTL_QUOT MT(MOD_RCTL, KC_QUOTE) */
/* #define CTL_MINS MT(MOD_RCTL, KC_MINUS) */
/* #define ALT_ENT  MT(MOD_LALT, KC_ENT) */

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

enum custom_keycodes {
    X_THE = SAFE_RANGE
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* /\* */

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  | [ {  |CapsLk|  |F-keys|  ] } |   K  |   H  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_COLEMAK] = LAYOUT_wrap(
			     KC_TAB  , BASE_R2_L,                                        BASE_R2_R, RALT(KC_W),
			     X_THE, BASE_R3_L,                                        BASE_R3_R , RALT(KC_L),
			     LSFT_T(KC_CAPS), BASE_R4_L, KC_NUBS, KC_MINS,     KC_ENT  , KC_NUHS, BASE_R4_R, RALT(KC_Z),
                                 KC_MPLY, KC_J, BASE_T_L, KC_QUOT   ,   KC_DEL    ,BASE_T_R, KC_APP, KC_APP),

    [_GAME] = LAYOUT_wrap(KC_TAB, GAME_R2_L,                                     GAME_R2_R, KC_BSPC,
			  KC_CAPS, GAME_R3_L,                                    GAME_R3_R, KC_PIPE,
			  KC_LSFT, GAME_R4_L, KC_NUBS, KC_MINS, KC_ENT, KC_NUHS, GAME_R4_R, KC_ENT,
			  KC_MPLY, KC_ESC, GAME_T_L, KC_SPC,    KC_DEL, GAME_T_R, KC_ESC, KC_APP),

    [_GAME2] = LAYOUT_wrap(KC_TAB, GAME2_R2_L,                                     GAME2_R2_R, KC_BSPC,
			   KC_CAPS, GAME2_R3_L,                                    GAME2_R3_R, KC_PIPE,
			   KC_LSFT, GAME2_R4_L, KC_NUBS, KC_MINS, KC_ENT, KC_NUHS, GAME2_R4_R, KC_ENT,
			   KC_MPLY, KC_ESC, GAME2_T_L, KC_SPC,    KC_DEL, GAME2_T_R, KC_ESC, KC_APP),
/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  | [ {  |CapsLk|  |F-keys|  ] } |   N  |   M  | ,  < | . >  | /  ? | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |Adjust| LGUI | LAlt/| Space| Nav  |  | Sym  | Space| AltGr| RGUI | Menu |
 *                        |      |      | Enter|      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_QWERTY] = LAYOUT_wrap(
			    KC_TAB          , QWR_R2_L ,                                        QWR_R2_R , RALT(KC_W),
			    X_THE           , QWR_R3_L ,                                        QWR_R3_R , RALT(KC_L),
			    LSFT_T(KC_CAPS) , QWR_R4_L, KC_NUBS, KC_MINS,     KC_ENT , KC_NUHS, QWR_R4_R, RALT(KC_Z),
                                     KC_MPLY , KC_LGUI, QWR_T_L, KC_QUOT ,    KC_DEL , QWR_T_R, KC_APP, KC_APP
    ),

     [_LOWER] = LAYOUT_wrap(
			   _______, LOW_R2_L,                                     LOW_R2_R, KC_NO,
			   _______, LOW_R3_L,                                     LOW_R3_R, KC_NO,
			   _______, LOW_R4_L, _______, _______, _______, _______, LOW_R4_R, KC_NO,
			   _______, _______, LOW_T_L, KC_EQL,  KC_EQL,  LOW_T_R, _______, _______
    ),
    
/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    `   |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |   =    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ~   |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |   +    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |    |   |   \  |  :   |  ;   |  -   |  [   |  {   |      |  |      |   }  |   ]  |  _   |  ,   |  .   |  /   |   ?    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    /* [_RAISE] = LAYOUT_wrap( */
    /*   KC_GRV ,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , KC_EQL , */
    /*  KC_TILD , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PLUS, */
    /*  KC_PIPE , KC_BSLS, KC_COLN, KC_SCLN, KC_MINS, KC_LBRC, KC_LCBR, _______, _______, KC_RCBR, KC_RBRC, KC_UNDS, KC_COMM,  KC_DOT, KC_SLSH, KC_QUES, */
    /*                              _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ */
    /* ), */

     [_RAISE] = LAYOUT_wrap(
			   _______, RSE_R2_L,                                      RSE_R2_R, _______,
			   _______, RSE_R3_L,                                      RSE_R3_R, _______,
			   _______,  RSE_R4_L, _______, _______, _______, _______, RSE_R4_R, _______,
			   _______, _______,RSE_T_L, _______, _______, RSE_T_R, _______, _______
			   ),
     
     [_AUDIO] = LAYOUT_wrap(
			    _______, AUD_R2_L,                                       AUD_R2_R,  _______,
			     _______, AUD_R3_L,                                     AUD_R3_R,  _______,
			     _______, AUD_R4_L,_______, _______, _______, _______, AUD_R4_R, _______,
			     _______, _______, AUD_T_L, _______, _______, AUD_T_R, _______, _______
			    ),

     [_ADJUST] = LAYOUT_wrap(
			     _______, ADJ_R2_L,                                       ADJ_R2_R,  _______,
			     _______, ADJ_R3_L,                                     ADJ_R3_R,  _______,
			     _______, ADJ_R4_L,_______, _______, _______, _______, ADJ_R4_R, _______,
			     _______, _______, ADJ_T_L, _______, _______, ADJ_T_R, _______, _______
			     ),

#ifdef USE_PLOVER
     [_PLOVER] = LAYOUT_wrap(
			     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
			     _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
			     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
			     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
			     ),
#endif 
     [_NAV] = LAYOUT_wrap(
			  _______,  NAV_R2_L,                                    NAV_R2_R, _______,
			  _______,  NAV_R3_L,                                     NAV_R3_R, _______,
			  _______, NAV_R4_L, _______, _______, _______, _______, NAV_R4_R, _______,
			  _______, _______,  NAV_T_L, _______, _______, NAV_T_R, _______, _______
			  ),
     
     [_NUM] = LAYOUT_wrap(
			  _______, NUM_R2_L,                                     NUM_R2_R, _______,
			 _______, NUM_R3_L,                                     NUM_R3_R, _______,
			  _______, NUM_R4_L, _______, _______, _______, _______, NUM_R4_R, _______,
			  _______, _______, NUM_T_L, _______, _______, NUM_T_R, _______, _______
			  ),

 
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */


#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on
	//char wpmstr[10];
	
        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);


	// WPM
	// Remove to save space
	// sprintf(wpmstr, "WPM: %3d\n", get_current_wpm());
	//oled_write_P(PSTR("      "), false);
	//oled_write(wpmstr, false);
	
        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
	case _QWERTY:
	    oled_write_P(PSTR("QWERTY\n"), false);
	    break;
	case _COLEMAK:
	    oled_write_P(PSTR("Colemak-DH\n"), false);
	    break;
	case _NAV:
	    oled_write_P(PSTR("Nav\n"), false);
	    break;
	case _LOWER:
	    oled_write_P(PSTR("Lower\n"), false);
	    break;
	case _RAISE:
	    oled_write_P(PSTR("Raise\n"), false);
	    break;
	case _ADJUST:
	    oled_write_P(PSTR("Adjust\n"), false);
	    break;
	case _NUM:
	    oled_write_P(PSTR("Number\n"), false);
	    break;
	case _AUDIO:
	    oled_write_P(PSTR("Audio\n"), false);
	    break;
	case _GAME:
	    oled_write_P(PSTR("Game\n"), false);
	    break;
	case _GAME2:
	    oled_write_P(PSTR("Game 2\n"), false);
	    break;
	default:
	    oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
	// Volume control
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (!clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif

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
}
