#include <stdbool.h>
#include "quantum_keycodes.h"

enum user_layer {
    _COLEMAK,
    _LOWER,
    _UPPER,
    _ADJUST
};

// OSM abbrevs.
#define OSMLGUI OSM(MOD_LGUI)
#define OSMLCTL OSM(MOD_LCTL)
#define OSMLALT OSM(MOD_LALT)
#define OSMLSFT OSM(MOD_LSFT)

// Custom Trilayer// Custom Trilayer// Custom Trilayer
#define UPPER OSL(_UPPER)
#define LOWER OSL(_LOWER)
#define ADJUST OSL(_ADJUST)


// Term shortcuts
#define LCTL_C LCTL(KC_C)
#define LCTL_R LCTL(KC_R)
#define LCTL_L LCTL(KC_L)
#define LCTLT LCTL(KC_T) // no underscore to avoid conflict
#define LALT_C A(KC_C)

// Mac uk awkward keys
#define MAC_HSH RALT(KC_3) // we need left option as lalt in alacritty
#define MAC_GBP LSFT(KC_3)

// Mac navigation...
#define APPS LGUI(KC_SPC)
#define FIND LGUI(KC_F)
