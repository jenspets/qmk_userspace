/* -*- c-file-style: "qmk" -*- */

#include QMK_KEYBOARD_H
#include <jenspets.h>

#define LAYOUT_wrap(...) LAYOUT(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_wrap(BASE_R2_L, BASE_R2_R,
			   BASE_R3_L, BASE_R3_R,
			   BASE_R4_L, BASE_R4_R,
			   BASE_T_L, BASE_T_R),
  [_GAME] = LAYOUT_wrap(GAME_R2_L, GAME_R2_R,
			GAME_R3_L, GAME_R3_R,
			GAME_R4_L, GAME_R4_R,
			GAME_T_L, GAME_T_R),
  [_GAME2] = LAYOUT_wrap(GAME2_R2_L, GAME2_R2_R,
			 GAME2_R3_L, GAME2_R3_R,
			 GAME2_R4_L, GAME2_R4_R,
			 GAME2_T_L, GAME2_T_R),
  [_LOWER] = LAYOUT_wrap(LOW_R2_L, LOW_R2_R,
			 LOW_R3_L, LOW_R3_R,
			 LOW_R4_L, LOW_R4_R,
			 LOW_T_L, LOW_T_R),
  [_RAISE] = LAYOUT_wrap(RSE_R2_L, RSE_R2_R,
			 RSE_R3_L, RSE_R3_R,
			 RSE_R4_L, RSE_R4_R,
			 RSE_T_L, RSE_T_R),
  [_ADJUST] = LAYOUT_wrap(ADJ_R2_L, ADJ_R2_R,
			 ADJ_R3_L, ADJ_R3_R,
			 ADJ_R4_L, ADJ_R4_R,
			 ADJ_T_L, ADJ_T_R),
  [_NAV] = LAYOUT_wrap(NAV_R2_L, NAV_R2_R,
		       NAV_R3_L, NAV_R3_R,
		       NAV_R4_L, NAV_R4_R,
		       NAV_T_L, NAV_T_R),
  [_NUM] = LAYOUT_wrap(NUM_R2_L, NUM_R2_R,
		       NUM_R3_L, NUM_R3_R,
		       NUM_R4_L, NUM_R4_R,
		       NUM_T_L, NUM_T_R),
  [_AUDIO] = LAYOUT_wrap(AUD_R2_L, AUD_R2_R,
			 AUD_R3_L, AUD_R3_R,
			 AUD_R4_L, AUD_R4_R,
			 AUD_T_L, AUD_T_R)
};


