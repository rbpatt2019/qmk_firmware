#include "rbpatt2019.h"
#include "quantum.h"

void space_dot(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code(KC_SPC);
        reset_tap_dance(state);
    } else if (state->count == 2) {
        SEND_STRING(". ");
        add_oneshot_mods(MOD_BIT(KC_LSFT));
        reset_tap_dance(state);
    } else {
        tap_code(KC_SPC);
        reset_tap_dance(state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [SPC_DOT] = ACTION_TAP_DANCE_FN(space_dot),
};
