/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "custom_headers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_BSPC,   LOWER, OSMLSFT,     KC_SPC,   UPPER, QK_LEAD
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX,   KC_P7,   KC_P8,   KC_P9, XXXXXXX,                      XXXXXXX, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,   KC_P0,   KC_P4,   KC_P5,   KC_P6, XXXXXXX,                      XXXXXXX,  KC_ESC,  KC_TAB, SFT_TAB,  KC_ENT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX,  KC_NUM,   KC_P1,   KC_P2,   KC_P3, XXXXXXX,                      XXXXXXX,  KC_DEL, _______, _______, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   LOWER, _______,    _______,  ADJUST, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, MAC_GBP, KC_AMPR, KC_LCBR, KC_RCBR,                      XXXXXXX,  KC_GRV, KC_PIPE,  KC_DLR, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_EXLM,   KC_AT, MAC_HSH, KC_LPRN, KC_RPRN,                      XXXXXXX,  KC_EQL, KC_MINS, KC_UNDS, KC_ASTR, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_QUES, KC_PERC, KC_TILD, KC_LBRC, KC_RBRC,                      XXXXXXX, KC_PLUS, KC_SLSH, KC_BSLS, KC_CIRC, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  ADJUST, _______,    _______,   UPPER, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LALT_C,    LCTLT,  LCTL_R,    APPS, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, QK_MAKE,  LCTL_L,    FIND,  LCTL_C, XXXXXXX,                      XXXXXXX, KC_PGUP, KC_PGDN, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  ADJUST, _______,    _______,  ADJUST, _______
                                      //`--------------------------'  `--------------------------'
  )
};

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_G)) {
        set_oneshot_mods(MOD_BIT(KC_LGUI));
    } else if (leader_sequence_one_key(KC_S)) {
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    } else if (leader_sequence_one_key(KC_A)) {
        set_oneshot_mods(MOD_BIT(KC_LALT));
    } else if (leader_sequence_one_key(KC_C)) {
        set_oneshot_mods(MOD_BIT(KC_LCTL));
    } else if (leader_sequence_one_key(KC_T)) {
        tap_code16(C(KC_A));
    }
}
