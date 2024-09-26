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
      XXXXXXX,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y, KC_QUOT, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       GRAVES,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      OSMLALT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, OSMLGUI,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ESC_LOW, OSMLSFT, KC_BSPC,     KC_SPC, ENT_RAI, OSMLCTL
                                      //`--------------------------'  `--------------------------'

  ),

    [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_P1,   KC_P2,   KC_P3,   KC_P4, XXXXXXX,                      XXXXXXX,   KC_P7,   KC_P8,   KC_P9,   KC_P0, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, XXXXXXX, XXXXXXX,   KC_P5, XXXXXXX,                      XXXXXXX,   KC_P6, _______, _______, KC_BSLS, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_UPPER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, XXXXXXX, XXXXXXX, KC_AMPR, CBRACES, XXXXXXX,                      XXXXXXX, KC_RCBR, KC_PIPE, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_ASTR,   KC_AT, MAC_HSH,  PARENS, XXXXXXX,                      XXXXXXX, KC_RPRN, KC_MINS, KC_UNDS,  KC_EQL, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, MAC_DLR, KC_DLR, KC_PERC,  BRACES, XXXXXXX,                      XXXXXXX, KC_RBRC, KC_PLUS, KC_CIRC, KC_EXLM, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, LALT_C,    LCTLT,  LCTL_R,    APPS, XXXXXXX,                      XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_MAKE, SETTING,  LCTL_L,    FIND,  LCTL_C, XXXXXXX,                      XXXXXXX, DM_PLY1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();

  switch (keycode) {
    case PARENS:
      if (record->event.pressed) {
        // if shift, type single
        if (mods & MOD_MASK_SHIFT) {
            tap_code16(KC_LPRN);
        } else {
            tap_code16(KC_LPRN);
            tap_code16(KC_RPRN);
            tap_code16(KC_LEFT);
        }
      }
      return false;
    case BRACES:
      if (record->event.pressed) {
        // if shift, type single
        if (mods & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            tap_code16(KC_LBRC);
            set_mods(mods);
        } else {
            tap_code16(KC_LBRC);
            tap_code16(KC_RBRC);
            tap_code16(KC_LEFT);
        }
      }
      return false;
    case CBRACES:
      if (record->event.pressed) {
        // if shift, type single
        if (mods & MOD_MASK_SHIFT) {
            tap_code16(KC_LCBR);
        } else {
            tap_code16(KC_LCBR);
            tap_code16(KC_RCBR);
            tap_code16(KC_LEFT);
        }
      }
      return false;
    case GRAVES:
      if (record->event.pressed) {
        if (mods & MOD_MASK_SHIFT) {
          SEND_STRING("~");
        } else if (mods & MOD_MASK_CTRL) {
          // capacity to send single
          SEND_STRING("`");
        } else {
          SEND_STRING("``");
          tap_code(KC_LEFT);
        }
      }
      return false;
    case ESC_LOW: // modified trilayer for LT - yes I know it's ugly
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _UPPER, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _UPPER, _ADJUST);
      }
      break;
    case ENT_RAI: // modified trilayer for LT - yes I know it's ugly
      if (record->event.pressed) {
        layer_on(_UPPER);
        update_tri_layer(_LOWER, _UPPER, _ADJUST);
      } else {
        layer_off(_UPPER);
        update_tri_layer(_LOWER, _UPPER, _ADJUST);
      }
      break;
  }
  return true;
}

// Overrides
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);
const key_override_t shift_space_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_TAB);
const key_override_t ctrl_space_key_override = ko_make_basic(MOD_MASK_CTRL, KC_SPC, S(KC_TAB));

const key_override_t *key_overrides[] = {
    &delete_key_override,
    &shift_space_key_override,
    &ctrl_space_key_override
};
