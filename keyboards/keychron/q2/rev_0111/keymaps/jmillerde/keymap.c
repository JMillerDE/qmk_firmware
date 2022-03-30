/* Copyright 2022 @ Jeremy MIller(https://github.com/jmillerde/qmk_firmware)
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
#include "keymap_user.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

// clang-format off
typedef union {
	uint32_t raw;
	struct {
		bool caps_lock_light_tab :1;
		bool caps_lock_light_alphas :1;
		bool caps_lock_light_home_row :1;
		bool fn_layer_enable :1;
		bool rgb_layer_enable :1;
		bool numpad_layer_enable :1;
		bool transparent_keys_off :1;
		bool unmapped_keys_off :1;
	};
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
	#ifdef VIA_ENABLE
		KC_MISSION_CONTROL = USER00,
	#else
		KC_MISSION_CONTROL = SAFE_RANGE,
	#endif
	
	KC_LAUNCHPAD,
	KC_LIGHT_TAB_TOGGLE,
    KC_LIGHT_ALPHAS_TOGGLE,
	KC_LIGHT_HOME_ROW_TOGGLE,
    KC_FN_LAYER_COLOR_TOGGLE,
	KC_RGB_LAYER_COLOR_TOGGLE,
	KC_NUMPAD_LAYER_COLOR_TOGGLE,
	KC_TRANSPARENT_KEYS_TOGGLE,
	KC_UNMAPPED_KEYS_TOGGLE
};

#define KC_MCTL  KC_MISSION_CONTROL
#define KC_LPAD  KC_LAUNCHPAD
#define KC_LTTOG KC_LIGHT_TAB_TOGGLE
#define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
#define KC_LHTOG KC_LIGHT_HOME_ROW_TOGGLE
#define KC_FNTOG KC_FN_LAYER_COLOR_TOGGLE
#define KC_RGBTG KC_RGB_LAYER_COLOR_TOGGLE
#define KC_NPTOG KC_NUMPAD_LAYER_COLOR_TOGGLE
#define KC_TKTOG KC_TRANSPARENT_KEYS_TOGGLE
#define KC_UMTOG KC_UNMAPPED_KEYS_TOGGLE
#define KC_TASK  LGUI(KC_TAB)
#define KC_WAVE  S(KC_GRV)
#define KC_FLXP  LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[MAC_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
		KC_LCTL, KC_LOPT, KC_LCMD,                            KC_SPC,                             KC_RCMD, MO(_ML1), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT
	),
	
	[WIN_BASE] = LAYOUT_ansi_67(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,  KC_EQL,   KC_BSPC,          KC_MUTE,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_HOME,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,            KC_ENT,           KC_END,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(_WL1), KC_RCTL,  KC_LEFT, KC_DOWN, KC_RGHT
	),
	
	[_ML1] = LAYOUT_ansi_67(
        KC_GRV,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO,   KC_NO,    KC_DEL,         KC_SLEP,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   KC_NO,          KC_PGUP,
        KC_LCAP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_NO,          KC_PGDN,
        KC_TRNS,          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,             KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS,                            KC_TRNS, KC_TRNS, MO(_RGB), KC_NO,   KC_NO, KC_NO
	),
	
	[_WL1] = LAYOUT_ansi_67(
        KC_GRV,    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,  KC_F12,   KC_DEL,          KC_SLEP,
        KC_WFAV,   KC_WHOM,  KC_WBAK, KC_WFWD, KC_WREF, KC_WSCH, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,    KC_NO,           KC_PGUP,
        KC_LCAP,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,             KC_NO,           KC_PGDN,
        KC_TRNS,             KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   		   KC_TRNS, KC_NO,
        KC_TRNS,  KC_TRNS,   KC_TRNS,                            KC_TRNS,                      KC_TRNS, KC_TRNS, MO(_RGB), KC_NO,   KC_NO,  KC_NO
	),
	
	[_RGB] = LAYOUT_ansi_67(
        KC_TILD, KC_F13,   KC_F14,  KC_F15,  KC_F16,  KC_F17,   KC_F18,   KC_F19,   KC_F20,   KC_F21,   KC_F22,   KC_F23,   KC_F24,   KC_NO,              KC_PWR,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,  KC_NO,    KC_LTTOG, KC_LATOG, KC_LHTOG, KC_NO,    KC_NO,    KC_NO,    KC_NO,              KC_INS,
        KC_LCAP, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,  KC_NO,    KC_FNTOG, KC_RGBTG, KC_NPTOG, KC_TKTOG, KC_UMTOG,           KC_NO,              KC_PSCR,
        KC_TRNS,           RGB_M_P, RGB_M_B, RGB_M_R, RGB_M_SW, RGB_M_SN, RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  KC_NO,   			  KC_TRNS,    KC_NO,
        KC_TRNS, KC_TRNS,  KC_TRNS,                             KC_TRNS,                                MO(_NP),  KC_TRNS,  KC_TRNS,  KC_NO,      KC_NO,  KC_NO
	),
	
	[_NP] = LAYOUT_ansi_67(
        KC_LPRN,   KC_RPRN,  KC_CIRC, KC_PAST, KC_PSLS,  KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,     KC_NO,      KC_NO,          KC_CALC,
        KC_PMNS,   KC_P6,    KC_P7,   KC_P8,   KC_P9,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,     KC_NO,      KC_NO,          KC_NLCK,
        KC_PPLS,   KC_P2,    KC_P3,   KC_P4,   KC_P5,    KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,                 KC_NO,		   KC_SLCK,
        KC_PEQL,             KC_P0,   KC_P1,   KC_PDOT,  KC_PCMM,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   			   KC_NO,  KC_NO,
        KC_LT,     KC_GT,    KC_PENT,                              KC_NO,                               KC_TRNS,    KC_TRNS,   KC_TRNS,    KC_NO,  KC_NO,  KC_NO
	)
};

void matrix_init_user(void) {
	#ifdef RGB_MATRIX_ENABLE
		rgb_matrix_init_user();
	#endif
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.caps_lock_light_tab = 0;
    user_config.caps_lock_light_alphas = 0;
	user_config.caps_lock_light_home_row = 1;
	
    user_config.fn_layer_enable = 0;
	user_config.rgb_layer_enable = 0;
	user_config.numpad_layer_enable = 0;
	
	user_config.transparent_keys_off = 0;
	user_config.unmapped_keys_off = 1;
	
    eeconfig_update_user(user_config.raw);
}

void keyboard_post_init_user(void) {
	// Set initalized user settings
    user_config.raw = eeconfig_read_user();
	
	// Set the intial RGB color
	rgb_matrix_sethsv(80, 207, 111);
}

bool get_caps_lock_light_tab(void) {
    return user_config.caps_lock_light_tab;
}

bool get_caps_lock_light_alphas(void) {
    return user_config.caps_lock_light_alphas;
}

bool get_caps_lock_light_home_row(void) {
    return user_config.caps_lock_light_home_row;
}

bool get_fn_layer_enable(void) {
    return user_config.fn_layer_enable;
}

bool get_rgb_layer_enable(void) {
    return user_config.rgb_layer_enable;
}

bool get_numpad_layer_enable(void) {
    return user_config.numpad_layer_enable;
}

bool get_transparent_keys_off(void) {
    return user_config.transparent_keys_off;
}

bool get_unmapped_keys_off(void) {
    return user_config.unmapped_keys_off;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
		case KC_LIGHT_TAB_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_tab ^= 1; // bitwise xor to toggle status bit
                eeconfig_update_user(user_config.raw);
            } 
            return false;  // Skip all further processing of this key
        case KC_LIGHT_ALPHAS_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_alphas ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
		case KC_LIGHT_HOME_ROW_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_home_row ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config.fn_layer_enable ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
		case KC_RGB_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config.rgb_layer_enable ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
		case KC_NUMPAD_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config.numpad_layer_enable ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
		case KC_TRANSPARENT_KEYS_TOGGLE:
            if (record->event.pressed) {
                user_config.transparent_keys_off ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
		case KC_UNMAPPED_KEYS_TOGGLE:
			if (record->event.pressed) {
                user_config.unmapped_keys_off ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}