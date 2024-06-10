#include "quantum_keycodes.h"
#include "quantum.h"
#include "rbpatt2019.h"

static bool process_quopostrokey(uint16_t keycode, keyrecord_t* record) {
  static bool within_word = false;

  if (keycode == QUOP) {
    if (record->event.pressed) {
      if (within_word) {
        tap_code(KC_QUOT);
      } else {
        SEND_STRING("\"\"" SS_TAP(X_LEFT));
      }
    }
    return false;
  }

  switch (keycode) {  // Unpack tapping keycode for tap-hold keys.
#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0) { return true; }
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

  // Determine whether the key is a letter.
  switch (keycode) {
    case KC_A ... KC_Z:
      within_word = true;
      break;

    default:
      within_word = false;
  }

  return true;
}

