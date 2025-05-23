#include QMK_KEYBOARD_H

// custom type to store stuff in EEPROM
typedef union {
  uint32_t raw;
} user_config_t;

user_config_t user_config;

// Layer definitions
#define _BL 0
#define _DL 1
#define _UL 2
#define _GL 3
#define _GLV 4
#define _MSL 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
                   KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
                   KC_P, KC_BSPC, KC_TAB, LGUI_T(KC_A), LALT_T(KC_S),
                   LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, RCTL_T(KC_J),
                   RSFT_T(KC_K), LALT_T(KC_L), RGUI_T(KC_SCLN), TT(_GL),
                   KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_QUOT,
                   KC_SLSH, KC_ENT, KC_LCTL, KC_LALT, KC_COMMA, LT(_DL, KC_SPC),
                   LT(_UL, KC_SPC), KC_DOT, KC_LGUI),

    [_DL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7,
        KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_1, KC_2, KC_3, KC_4,
        KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, TG(_GLV), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, TG(_MSL), KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, QK_BOOT, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS),

    [_UL] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_GRV, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_PIPE,
        KC_BSLS, KC_PLUS, KC_UNDS, KC_MINS, KC_EQL, KC_DEL, KC_TRNS, KC_EXLM,
        KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,
        KC_RPRN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_GL] =
        LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
               KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_UP,
               KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,
               KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_C,
               KC_V, KC_B, KC_N, KC_M, KC_QUOT, KC_SLSH, KC_ENT, KC_LCTL,
               KC_LALT, KC_COMMA, KC_SPC, KC_SPC, KC_DOT, KC_LGUI),

    [_GLV] =
        LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
               KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O,
               KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,
               KC_K, KC_L, KC_SCLN, KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_C, KC_V,
               KC_B, KC_N, KC_M, KC_QUOT, KC_SLSH, KC_ENT, KC_COMMA, KC_LALT,
               KC_LCTL, KC_SPC, KC_SPC, KC_DOT, KC_LGUI),

    [_MSL] =
        LAYOUT(KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
               KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_UP,
               KC_P, KC_BSPC, KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J,
               KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_LSFT, KC_Z, KC_X, KC_C,
               KC_V, KC_B, KC_N, KC_M, KC_QUOT, KC_SLSH, KC_ENT, KC_LCTL,
               KC_LALT, KC_COMMA, KC_LALT, KC_SPC, KC_DOT, KC_LGUI)};

void keyboard_post_init_user(void) { user_config.raw = eeconfig_read_user(); }

void eeconfig_init_user(void) {
  user_config.raw = 0;
  eeconfig_update_user(user_config.raw);
}
