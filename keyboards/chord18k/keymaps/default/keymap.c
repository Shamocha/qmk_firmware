// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define LD   TG(_RAISE)
#define LD2  TG(_LOWER)
#define FUNC MO(_FN)

enum layer_number {
  _BASE = 0,
  _RAISE,
  _LOWER,
  _FN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_ESC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LD,      FUNC   ,
        KC_LSFT, KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_RSFT,
                                   KC_C,    KC_M
    ),

    [_RAISE] = LAYOUT(
        KC_ESC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LD,      FUNC   ,
        KC_LSFT, KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_RSFT,
                                   KC_C,    KC_M
    ),

    [_LOWER] = LAYOUT(
        KC_ESC,  KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, LD2,     FUNC   ,
        KC_LSFT, KC_S,    KC_D,    KC_F,    KC_J,    KC_K,    KC_L,    KC_RSFT,
                                   KC_C,    KC_M
    ),

    [_FN] = LAYOUT(
        KC_F5,   KC_TAB,  KC_HOME, KC_PGDN, KC_PGUP, KC_END, LD2,     FUNC   ,
        UG_VALD, UG_TOGG, KC_D,    KC_F,    KC_J,    KC_K,   KC_L,    UG_VALU,
                                   KC_SPC,  KC_ENT
    )

};


const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_CYAN}
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_GREEN}
);

const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_PURPLE}
);

const rgblight_segment_t PROGMEM fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    base_layer,
    raise_layer,
    lower_layer,
    fn_layer
);

void keyboard_post_init_user(void) {
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, _BASE));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN));
    return state;
}
