/* Copyright 2019 Ryota Goto
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

// Layer declarations
enum {
    DEF_LAYER,
    MOD_LAYER,
};

// Tap Dance declarations
enum {
    TD_CAR,
    TD_PRINT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CAR] = ACTION_TAP_DANCE_DOUBLE( LSFT(KC_V), LCTL(KC_V)),
    [TD_PRINT] = ACTION_TAP_DANCE_DOUBLE(
        LCTL(LALT(LSFT(KC_S))),
        LGUI(KC_PSCR)  // print screen
    ),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [DEF_LAYER] = LAYOUT_ortho_6x4( /* Base */

    KC_C,           // next cam
    KC_V,           // next car
    LSFT(KC_P3),    // next lap
    LCTL(KC_P3),    // next inc

    LSFT(KC_C),     // prev cam
    TD(TD_CAR),     // prev car, double tap for my car
	LSFT(KC_P1),    // prev lap
    LCTL(KC_P1),    // prev inc

	LSFT(KC_P4),    // rewind
    KC_P5,          // play/pause
    LSFT(KC_P6),    // fast forward
    KC_P8,          // slow mo

	KC_P4,          // prev frame
    KC_W,           // up
    KC_P6,          // next frame
    TD(TD_PRINT),   // print screen

	KC_A,           // left
    KC_S,           // down
    KC_D,           // right
    KC_NO,          // ran out of things to assign

	KC_LCTL,        // ctrl 
    KC_LALT,        // alt
    LCTL(KC_F12),   // camera tool
    LT(MOD_LAYER, KC_SPACE)        // UI
  ),

  [MOD_LAYER] = LAYOUT_ortho_6x4( /* Base */

    KC_B,           // next sub cam
    KC_PGUP,        // next driver cam
    LCTL(KC_P6),    // next session
    KC_P7,          // start

    LSFT(KC_B),     // prev sub cam
    KC_PGDOWN,      // prev driver cam
	LCTL(KC_P4),    // prev session
    KC_P1,          // end

	KC_RBRC,
    KC_EQL,
    _______,
    _______,

	KC_LBRC,
    KC_MINS,
    _______,
    _______,

	_______,
    _______,
    _______,
    _______,

	_______,
    LALT(KC_M),  // cycle aim
    RALT(KC_ENTER), // fullscreen.  Doesn't work reliably
    _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
