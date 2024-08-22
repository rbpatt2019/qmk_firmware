#include "rbpatt2019.h"
#include "quantum.h"

// use process_record_keymap for keyboard specific functions
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  switch (keycode) {
    case PARENS:
      if (record->event.pressed) {
        SEND_STRING("()");
        tap_code(KC_LEFT);
      }
      return false;
    case BRACES:
      if (record->event.pressed) {
        SEND_STRING("[]");
        tap_code(KC_LEFT);
      }
      return false;
    case CBRACES:
      if (record->event.pressed) {
        SEND_STRING("{}");
        tap_code(KC_LEFT);
      }
      return false;
    case GRAVES:
      if (record->event.pressed) {
        if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
          SEND_STRING("~");
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

// These feature turned on by default in userpsace rules.mk
__attribute__((weak)) void leader_start_keymap(void) { }
__attribute__((weak)) void leader_end_keymap(void) { }

// Keyboard specific - enable with rules.mk in local keymap
#ifdef OLED_ENABLE
__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) { return OLED_ROTATION_0; }
__attribute__((weak)) bool oled_task_keymap(void) { return false; }
#endif
