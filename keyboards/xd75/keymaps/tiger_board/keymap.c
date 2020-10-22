/* Copyright 2017 Wunder
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

// Layer shorthand
#define _QWERTY 0
#define _FUNCTION 1
#define _GAMING 2
#define _DVORAK 3

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  QMKBEST = SAFE_RANGE,
  QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY (Designed for the computer to switch to DVORAK)
 * 
 * Notice that left control and shift are not mirrored with right control and shift
 * 
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | ESC    | 1 -> 1 | 2 -> 2 | 3 -> 3 | 4 -> 4 | 5 -> 5 | - -> [ | \ -> \ | = -> ] | 6 -> 6 | 7 -> 7 | 8 -> 8 | 9 -> 9 | 0 -> 0 | BACKSP |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------|
 * | LCTRLa | Q -> ' | W -> , | E -> . | R -> p | T -> y | ' -> - | [ -> / | ] -> = | Y -> f | U -> g | I -> c | O -> r | P -> l | RCTRLv |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------+--------|
 * | TAB    | A -> a | S -> o | D -> e | F -> u | G -> i | ` -> ` | UP     | DELETE | H -> d | J -> h | K -> t | L -> n | ; -> s | ENTER  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------------------------+--------|
 * | LSHIFT | Z -> ; | X -> q | C -> j | V -> k | B -> x | LEFT   | DOWN   | RIGHT  | N -> b | M -> m | , -> w | . -> v | / -> z | RCTRL  |
 * |--------+--------+--------+--------+--------+-----------------+--------+--------+--------+--------+-----------------+--------+--------|
 * | LCTRLz | LCTRLy | LGUI   | LALT   | LCTRL  | SPACE  | TO QWE | TO FUN | TO GAM | SPACE  | RSHIFT | RALT   | RGUI   | RCTRLx | RCTRLc |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_QWERTY] = LAYOUT_ortho_5x15( /* QWERTY */
	KC_ESC,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_MINS,	KC_BSLS,	KC_EQL,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BSPC,
	LCTL(KC_A),	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_QUOT,	KC_LBRC,	KC_RBRC,	KC_Y,	KC_U,	KC_I,	KC_O,	KC_P,	RCTL(KC_V),
	KC_TAB,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_GRV,	KC_UP,	KC_DEL,	KC_H,	KC_J,	KC_K,	KC_L,	KC_SCLN,	KC_ENT,
	KC_LSFT,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_N,	KC_M,	KC_COMM,	KC_DOT,	KC_SLSH,	KC_RCTL,
	LCTL(KC_Z),	LCTL(KC_Y),	KC_LGUI,	KC_LALT,	KC_LCTL,	KC_SPC,	TO(_QWERTY),	TO(_FUNCTION),	TO(_GAMING),	KC_SPC,	KC_RSFT,	KC_RALT,	KC_RGUI,	RCTL(KC_X),	RCTL(KC_C)
  ),

/* FUNCTION
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_FUNCTION] = LAYOUT_ortho_5x15( /* FUNCTION */
	KC_TRNS,	KC_F1,	KC_F2,	KC_F3,	KC_F4,	KC_F5,	KC_F6,	KC_NO,	KC_NO,	KC_NO,	BL_TOGG,	BL_INC,	RGB_VAI,	RGB_SPI,	KC_TRNS,
	KC_TRNS,	KC_F7,	KC_F8,	KC_F9,	KC_F10,	KC_F11,	KC_F12,	KC_NO,	KC_NO,	KC_NO,	RGB_TOG,	BL_DEC,	RGB_VAD,	RGB_SPD,	KC_TRNS,
	KC_TRNS,	KC_F13,	KC_F14,	KC_F15,	KC_F16,	KC_F17,	KC_F18,	RESET,	KC_MPRV,	KC_MNXT,	KC_MPLY,	KC_PSCR,	KC_SLCK,	KC_PAUS,	KC_TRNS,
	KC_TRNS,	KC_F19,	KC_F20,	KC_F21,	KC_F22,	KC_F23,	KC_F24,	TO(_DVORAK),	KC_VOLD,	KC_VOLU,	KC_MUTE,	KC_CAPS,	KC_NLCK,	KC_INS,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
  ),

/* GAMING
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_GAMING] = LAYOUT_ortho_5x15( /* GAMING */
	KC_TRNS,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_BTN4,	KC_BTN3,	KC_BTN5,	KC_TRNS,
	KC_TRNS,	KC_Q,	KC_W,	KC_E,	KC_R,	KC_T,	KC_P1,	KC_P2,	KC_P3,	KC_P4,	KC_P7,	KC_BTN1,	KC_MS_U,	KC_BTN2,	KC_TRNS,
	KC_TRNS,	KC_A,	KC_S,	KC_D,	KC_F,	KC_G,	KC_WH_D,	KC_UP,	KC_WH_U,	KC_P5,	KC_P8,	KC_MS_L,	KC_MS_D,	KC_MS_R,	KC_TRNS,
	KC_TRNS,	KC_Z,	KC_X,	KC_C,	KC_V,	KC_B,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_P6,	KC_P9,	KC_ACL0,	KC_ACL1,	KC_ACL2,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
  ),

/* DVORAK
 * .--------------------------------------------------------------------------------------------------------------------------------------.
 * | F1     | F2     | F3     | F4     | F5     | F6     | NUM LK | P/     | P*     | F7     | F8     | F9     | F10    | F11    | F12    |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | SELECT | CALC   | MYCOMP | MAIL   | RGB HD | RGB HI | P7     | P8     | P9     | -      |        |        | PR SCR | SCR LK | PAUSE  |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | PREV   | PLAY   | NEXT   | STOP   | RGB SD | RGB SI | P4     | P5     | P6     | +      |        | RESET  |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * | VOL-   | MUTE   | VOL+   | APP    | RGB VD | RGB VI | P1     | P2     | P3     | PENT   |        |        |        |        |        |
 * |--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------+--------|
 * |        |        | RGB TG | FN     | RGB RMD| RGB MD | P0     |        | P.     | PENT   | PENT   | FN     |        |        |        |
 * '--------------------------------------------------------------------------------------------------------------------------------------'
 */

  [_DVORAK] = LAYOUT_ortho_5x15( /* DVORAK */
	KC_TRNS,	KC_1,	KC_2,	KC_3,	KC_4,	KC_5,	KC_LBRC,	KC_BSLS,	KC_RBRC,	KC_6,	KC_7,	KC_8,	KC_9,	KC_0,	KC_TRNS,
	KC_TRNS,	KC_QUOT,	KC_COMM,	KC_DOT,	KC_P,	KC_Y,	KC_MINS,	KC_SLSH,	KC_EQL,	KC_F,	KC_G,	KC_C,	KC_R,	KC_L,	KC_TRNS,
	KC_TRNS,	KC_A,	KC_O,	KC_E,	KC_U,	KC_I,	KC_GRV,	KC_UP,	KC_DEL,	KC_D,	KC_H,	KC_T,	KC_N,	KC_S,	KC_TRNS,
	KC_TRNS,	KC_SCLN,	KC_Q,	KC_J,	KC_K,	KC_X,	KC_LEFT,	KC_DOWN,	KC_RGHT,	KC_B,	KC_M,	KC_W,	KC_V,	KC_Z,	KC_TRNS,
	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS,	KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _QWERTY:
        backlight_level(12);
        //breathing_enable();
        rgblight_sethsv_noeeprom(HSV_CORAL);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    case _FUNCTION:
        backlight_level(10);
        //breathing_disable();
        rgblight_sethsv_noeeprom(HSV_CORAL);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        break;
    case _GAMING:
        backlight_level(14);
        //breathing_enable();
        rgblight_sethsv_noeeprom(HSV_RED);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
        break;
    default: 
        backlight_level(10);
        //breathing_disable();
        rgblight_sethsv_noeeprom(HSV_WHITE);
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        break;
    }
  return state;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
  keycaps_led_on();
}

void keyboard_pre_init_user(void) {
  backlight_enable();
  backlight_level(12);
  breathing_disable();
  rgblight_sethsv_noeeprom(HSV_CORAL);
  rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
}