#include "rbpatt2019.h"
#include "quantum.h"

// use process_record_keymap for keyboard specific functions
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }

#include "feature_quopostrokey.c"
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

  // jiggler
  if (record->event.pressed) {
    static deferred_token token = INVALID_DEFERRED_TOKEN;
    static report_mouse_t report = {0};
    if (token) {
      // If jiggler is currently running, stop when any key is pressed.
      cancel_deferred_exec(token);
      token = INVALID_DEFERRED_TOKEN;
      report = (report_mouse_t){};  // Clear the mouse.
      host_mouse_send(&report);
    } else if (keycode == JIGGLE) {

      uint32_t jiggler_callback(uint32_t trigger_time, void* cb_arg) {
        // Deltas to move in a circle of radius 20 pixels over 32 frames.
        static const int8_t deltas[32] = {
            0, -1, -2, -2, -3, -3, -4, -4, -4, -4, -3, -3, -2, -2, -1, 0,
            0, 1, 2, 2, 3, 3, 4, 4, 4, 4, 3, 3, 2, 2, 1, 0};
        static uint8_t phase = 0;
        // Get x delta from table and y delta by rotating a quarter cycle.
        report.x = deltas[phase];
        report.y = deltas[(phase + 8) & 31];
        phase = (phase + 1) & 31;
        host_mouse_send(&report);
        return 16;  // Call the callback every 16 ms.
      }

      token = defer_exec(1, jiggler_callback, NULL);  // Schedule callback
    }
  }

  // quopostrokey
  if (!process_quopostrokey(keycode, record)) { return false; }
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
