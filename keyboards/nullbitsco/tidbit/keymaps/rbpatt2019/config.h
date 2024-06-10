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
#pragma once


// Workaround for freezing after MacOS sleep
#define USB_SUSPEND_WAKEUP_DELAY 200

// Encoder setup
#define ENCODERS_PAD_A { B2, D0, D3 }
#define ENCODERS_PAD_B { B3, D1, D2 }

// tap term
#define ONESHOT_TAP_TOGGLE 2
#define ONESHOT_TIMEOUT 1000
#define TAP_TERM 200

// Mouse keys - constant momentary
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_OFFSET_1 6
#define MK_C_INTERVAL_1 16
#define MC_C_OFFSET_UNMOD 24
#define MK_C_INTERVAL_UNMOD 16
#define MK_C_OFFSET_2 36
#define MK_C_INTERVAL_2 16
#define MK_W_OFFSET_1 1
#define MK_W_INTERVAL_1 115
#define MK_W_OFFSET_UNMOD 1
#define MK_W_INTERVAL_UNMOD 85

// RGB SETUP
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_DEFAULT_HUE 21
#define RGBLIGHT_SLEEP
#undef RGBLIGHT_EFFECT_ALTERNATING
#undef RGBLIGHT_EFFECT_CHRISTMAS
#undef RGBLIGHT_EFFECT_KNIGHT
#undef RGBLIGHT_EFFECT_RAINBOW_MOOD
#undef RGBLIGHT_EFFECT_STATIC_GRADIENT
#undef RGBLIGHT_EFFECT_TWINKLE
#undef RGBLIGHT_EFFECT_BREATHING
#undef RGBLIGHT_EFFECT_RAINBOW_SWIRL
#undef RGBLIGHT_EFFECT_SNAKE
#undef RGBLIGHT_EFFECT_RGB_TEST
