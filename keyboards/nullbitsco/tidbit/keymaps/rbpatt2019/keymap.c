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
#include "rbpatt2019.h"

enum layers {
    _SYSTEM = 0,
    _APPS,
    _CHROME
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_SYSTEM] = LAYOUT(
//     |-------|--------|--------|
           FULL, SETTING,TG(_APPS),
//     |-------|--------|--------|--------|
           LEFT,    DOWN,      UP,   RIGHT,
//     |-------|--------|--------|--------|
        MAC_ALL, MAC_CUT, MAC_CPY, MAC_PST,
//     |-------|--------|--------|--------|
        CMD_TAB, XXXXXXX, XXXXXXX, XXXXXXX,
//     |-------|--------|--------|--------|
        MAC_APP,    QUIT, KIL_APP, KIL_WIN
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
        CHR_HST,   TG(2), CHR_BKM, CHR_DWN,
//     |-------|--------|--------|--------|
         KC_ESC, SLK_STS, MAC_NEW, SLK_SCH
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

#ifdef ENCODERS_PAD_A
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_SYSTEM] =  { ENCODER_CCW_CW(NXT_DSK, PRV_DSK), ENCODER_CCW_CW(KC_TAB, LSFT(KC_TAB)), ENCODER_CCW_CW(NXT_SPC, PRV_SPC) },
    [_APPS] = { ENCODER_CCW_CW(ZM_IN, ZM_OUT), ENCODER_CCW_CW(CHR_RPG, CHR_LPG), ENCODER_CCW_CW(SLK_NXT, SLK_PRV) },
    [_CHROME] = { ENCODER_CCW_CW(ZM_IN, ZM_OUT), ENCODER_CCW_CW(CHR_RTB, CHR_LTB), ENCODER_CCW_CW(SLK_NXT, SLK_PRV) }
};
#endif /* ifdef ENCODERS_PAD_A */

#ifdef RGBLIGHT_LAYERS
#include "features/rgb_layers.c"
#endif /* ifdef RGBLIGHT_LAYERS */

// set up for cmd tab
bool is_cmd_tab_on = false;
uint16_t cmd_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t spd_esc_timer;
    static uint16_t spd_all_timer;

    switch (keycode) {
        case SPD_ESC:
            if (record->event.pressed) {
              spd_esc_timer = timer_read();
              register_code(KC_ACL1);
            } else {
              unregister_code(KC_ACL1);
              if (timer_elapsed(spd_esc_timer) < TAPPING_TERM) {
                tap_code16(KC_ESC);
              }
            }
            return false;
        case SPD_ALL:
            if (record->event.pressed) {
              spd_all_timer = timer_read();
              register_code(KC_ACL2);
            } else {
              unregister_code(KC_ACL2);
              if (timer_elapsed(spd_all_timer) < TAPPING_TERM) {
                tap_code16(LGUI(KC_A));
              }
            }
            return false;
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
    if (timer_elapsed(cmd_tab_timer) > 1500) {
      unregister_code(KC_LGUI);
      is_cmd_tab_on = false;
    }
  }
}
