#include <stddef.h>
#include "quantum_keycodes.h"
#include "quantum.h"

// Control backspace sends delete
const key_override_t delete_key_override = ko_make_basic(MOD_MASK_CTRL, KC_BSPC, KC_DEL);
// Shift space sends tab
const key_override_t space_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPC, KC_TAB);

const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    &space_key_override,
    NULL // Null terminate the array of overrides!
};
