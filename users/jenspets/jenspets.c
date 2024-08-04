/* -*- c-file-style: "qmk" -*- */
#include QMK_KEYBOARD_H
#include <jenspets.h>

#ifdef RGBLIGHT_ENABLE
static rgblight_config_t rgb_default;
#endif

void keyboard_post_init_user(void){
#ifdef RGBLIGHT_ENABLE
    rgb_default.raw = eeconfig_read_rgblight();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    if (rgblight_is_enabled()){
	uint8_t offset;
	uint8_t rgbbase = 0;
	switch (get_highest_layer(state)){
	case _RAISE:
	    offset = 32;
	    break;
	case _LOWER:
	    offset = -32;
	    break;
	case _ADJUST:
	    /* No offset for adjust layer, as the hue is difficult to adjust with an offset applied */
	    offset = 0;
	    break;
#ifdef USE_PLOVER
	case _PLOVER:
	    offset = 128;
	    rgbbase = 1;
	    break;
#endif
	case _NAV:
	    offset = 64;
	    break;
	case _NUM:
	    offset = -64;
	    break;
	default:
	    rgbbase = 1;
	    offset = 0;
	}
	if (rgbbase == 0){
	    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
	} else {
	    rgb_default.raw = eeconfig_read_rgblight();
	    rgblight_mode_noeeprom(rgb_default.mode);
	}
	rgblight_sethsv_noeeprom((rgb_default.hue + offset) % 255, rgb_default.sat, rgb_default.val);
    }
#endif
    
    //state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);    
    return state;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
#ifdef RGBLIGHT_ENABLE
    case RGB_HUD:
    case RGB_HUI:
    case RGB_SAD:
    case RGB_SAI:
    case RGB_VAD:
    case RGB_VAI:
	rgb_default.raw = eeconfig_read_rgblight();
	break;
#endif 
    default:
	break;
    }
}

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

#ifdef ENCODER_ENABLE
#define ENC_REVERSE 0x80

#ifndef ENC_VOLUME            // Volume 
#define ENC_VOLUME 255
#endif
#ifndef ENC_VOLUME_REV        // Volume, reverse direction
#define ENC_VOLUME_REV 255
#endif
#ifndef ENC_PAGE_UD           // Page up, page down
#define ENC_PAGE_UD 255
#endif
#ifndef ENC_PAGE_UD_REV       // Page up, down, reverse
#define ENC_PAGE_UD_REV 255
#endif
#ifndef ENC_LR                // Left and right arrows
#define ENC_LR 255
#endif
#ifndef ENC_LR_REV            // Left and right arrows, reversed
#define ENC_LR_REV 255
#endif
#ifndef ENC_UD                // Up and down arrows
#define ENC_UD 255
#endif
#ifndef ENC_UD_REV            // Up and down, reversed
#define ENC_UD_REV 255
#endif

bool encoder_update_user(uint8_t index, bool clockwise) {
    if ((index == ENC_VOLUME_REV) || (index == ENC_PAGE_UD_REV) || (index == ENC_LR_REV) || (index == ENC_UD_REV)) {
        clockwise = !clockwise;
    }
    if ((index == ENC_VOLUME) || (index == ENC_VOLUME_REV)) {
	// Volume control
        if (!clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if ((index == ENC_PAGE_UD) || (index == ENC_PAGE_UD_REV)) {
        // Page up/Page down
        if (!clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if ((index == ENC_LR) || (index == ENC_LR_REV)) {
      if (clockwise) {
	tap_code(KC_LEFT);
      } else {
	tap_code(KC_RIGHT);
      }
    } else if ((index == ENC_UD) || (index == ENC_UD_REV)) {
      if (!clockwise) {
	tap_code(KC_UP);
      } else {
	tap_code(KC_DOWN);
      }
    }
    return false;
}
#endif
