/* Copyright 2021 Jay Greco
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
#include "custom_headers.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_VOL] = LAYOUT(
//     |-------|--------|--------|
        KC_MUTE, TG(_BRIGHT), TG(_APPS),
//     |-------|--------|--------|--------|
        SETTING,    QUIT, KIL_APP, KIL_WIN,
//     |-------|--------|--------|--------|
        MAC_ALL, MAC_CUT, MAC_CPY, MAC_PST,
//     |-------|--------|--------|--------|
        CMD_TAB, PRV_DSK,    FULL, NXT_DSK,
//     |-------|--------|--------|--------|
        MAC_APP,    HIDE,  KC_ESC,  KC_ENT
//     |-------|--------|--------|--------|
    ),
    [_APPS] = LAYOUT(
//     |-------|--------|--------|
        ZM_TOGG, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        CHR_HST, TG(_CHROME), CHR_BKM, CHR_DWN,
//     |-------|--------|--------|--------|
         KC_ESC, SLK_STS, MAC_NEW, SLK_SCH
//     |-------|--------|--------|--------|
    ),
    [_BRIGHT] = LAYOUT(
//     |-------|--------|--------|
        KC_SLEP, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______
//     |-------|--------|--------|--------|
    ),
    [_CHROME] = LAYOUT(
//     |-------|--------|--------|
        _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______,
//     |-------|--------|--------|--------|
        CHR_TAB, _______, _______, _______,
//     |-------|--------|--------|--------|
        _______, _______, _______, _______
//     |-------|--------|--------|--------|
    )
};

// Encoder maps
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_VOL] =  { ENCODER_CCW_CW(KC_VOLU, KC_VOLD), ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)), ENCODER_CCW_CW(NXT_SPC, PRV_SPC) },
    [_BRIGHT] =  { ENCODER_CCW_CW(KC_BRIU, KC_BRID), ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)), ENCODER_CCW_CW(NXT_SPC, PRV_SPC) },
    [_APPS] = { ENCODER_CCW_CW(ZM_IN, ZM_OUT), ENCODER_CCW_CW(CHR_RPG, CHR_LPG), ENCODER_CCW_CW(SLK_NXT, SLK_PRV) },
    [_CHROME] = { ENCODER_CCW_CW(ZM_IN, ZM_OUT), ENCODER_CCW_CW(CHR_RTB, CHR_LTB), ENCODER_CCW_CW(SLK_NXT, SLK_PRV) }
};

// RGB Code
#include "features/rgb_layers.c"

// set up for cmd tab
bool is_cmd_tab_on = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CMD_TAB:
          if (record->event.pressed) {
            if (!is_cmd_tab_on) {
              is_cmd_tab_on = true;
              register_code(KC_LGUI);
            }
            cmd_tab_timer = timer_read();
            tap_code16(KC_TAB);
          }
          break;
        case KC_TAB:
          if (record->event.pressed) {
            cmd_tab_timer = timer_read();
          }
          break;
        case LSFT(KC_TAB):
          if (record->event.pressed) {
            cmd_tab_timer = timer_read();
          }
          break;
    }
    return true;
};

// Runs the timer necessary for the cmd tab set up
void matrix_scan_user(void) {
  if (cmd_tab_timer) {
    if (timer_elapsed(cmd_tab_timer) > 1000) {
      unregister_code(KC_LGUI);
      is_cmd_tab_on = false;
    }
  }
}
