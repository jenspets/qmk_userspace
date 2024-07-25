#include QMK_KEYBOARD_H
#include <jenspets.h>

#define LAG_NRM KC_NO
#define LAG_SWP KC_NO

enum combos {
  COMBO_SPC,
  COMBO_BSP,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL,
  COMBO_ENT,
  COMBO_LWR,
  COMBO_RSE,
  COMBO_ADJ
};

const uint16_t PROGMEM space_combo[]  = {LCTL_T(KC_S), RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM bspace_combo[] = {LGUI_T(KC_A), LGUI_T(KC_O), COMBO_END};
const uint16_t PROGMEM tab_combo[]    = {KC_G, KC_M, COMBO_END};
const uint16_t PROGMEM esc_combo[]    = {LALT_T(KC_R), LALT_T(KC_I), COMBO_END};
const uint16_t PROGMEM del_combo[]    = {KC_Q, KC_SCLN, COMBO_END};
const uint16_t PROGMEM ent_combo[]    = {KC_V, KC_K, COMBO_END};
const uint16_t PROGMEM lwr_combo[]    = {KC_P, KC_L, COMBO_END};
const uint16_t PROGMEM rse_combo[]    = {KC_B, KC_J, COMBO_END};
const uint16_t PROGMEM adj_combo[]    = {KC_P, KC_B, KC_J, KC_L, COMBO_END};

combo_t key_combos[] = {
  [COMBO_SPC] = COMBO(space_combo, KC_SPC),
  [COMBO_BSP] = COMBO(bspace_combo, KC_BSPC),
  [COMBO_TAB] = COMBO(tab_combo, KC_TAB),
  [COMBO_ESC] = COMBO(esc_combo, KC_ESC),
  [COMBO_DEL] = COMBO(del_combo, KC_DEL),
  [COMBO_ENT] = COMBO(ent_combo, KC_ENT),
  [COMBO_LWR] = COMBO(lwr_combo, MO(_LOWER)),
  [COMBO_RSE] = COMBO(rse_combo, MO(_RAISE)),
  [COMBO_ADJ] = COMBO(adj_combo, MO(_ADJUST))
};

#define LAYOUT_ortho_3x10_wrap(...) LAYOUT_ortho_3x10(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_ortho_3x10_wrap(BASE_R2_L, BASE_R2_R,
				      BASE_R3_L, BASE_R3_R,
				      BASE_R4_L, BASE_R4_R),
  [_LOWER] = LAYOUT_ortho_3x10_wrap(LOW_R2_L, LOW_R2_R,
				    LOW_R3_L, LOW_R3_R,
				    LOW_R4_L, LOW_R4_R),
  [_RAISE] = LAYOUT_ortho_3x10_wrap(RSE_R2_L, RSE_R2_R,
				    RSE_R3_L, RSE_R3_R,
				    RSE_R4_L, RSE_R4_R),
  [_AUDIO] = LAYOUT_ortho_3x10_wrap(AUD_R2_L, AUD_R2_R,
				    AUD_R3_L, AUD_R3_R,
				    AUD_R4_L, AUD_R4_R),
  [_ADJUST] = LAYOUT_ortho_3x10_wrap(ADJ_R2_L, ADJ_R2_R,
				     ADJ_R3_L, ADJ_R3_R,
				     ADJ_R4_L, ADJ_R4_R),
  [_NAV] = LAYOUT_ortho_3x10_wrap(NAV_R2_L, NAV_R2_R,
				  NAV_R3_L, NAV_R3_R,
				  NAV_R4_L, NAV_R4_R),
  [_NUM] = LAYOUT_ortho_3x10_wrap(NUM_R2_L, NUM_R2_R,
				  NUM_R3_L, NUM_R3_R,
				  NUM_R4_L, NUM_R4_R)
};
