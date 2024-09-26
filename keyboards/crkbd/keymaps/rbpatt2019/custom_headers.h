#include <stdbool.h>
#include "quantum_keycodes.h"

enum user_layer {
    _COLEMAK,
    _LOWER,
    _UPPER,
    _ADJUST
};

// Custom keycodes shared across maps
// use KEYMAP_SAFE_RANGE for local functions
enum user_keycodes {
    SPC_DOT,
    PARENS = SAFE_RANGE,
    BRACES,
    CBRACES,
    GRAVES
};

// OSM abbrevs.
#define OSMLGUI OSM(MOD_LGUI)
#define OSMLCTL OSM(MOD_LCTL)
#define OSMLALT OSM(MOD_LALT)
#define OSMLSFT OSM(MOD_LSFT)

// Term shortcuts
#define LCTL_C LCTL(KC_C)
#define LCTL_R LCTL(KC_R)
#define LCTL_L LCTL(KC_L)
#define LCTLT LCTL(KC_T) // no underscore to avoid conflict
#define LALT_C A(KC_C)

// Mac uk awkward keys
#define MAC_HSH LALT(KC_3)
#define MAC_DLR LSFT(KC_3)

// Mac navigation...
#define APPS LGUI(KC_SPC)
#define FIND LGUI(KC_F)
#define MAC_APP LCTL(KC_UP)
#define SETTING LGUI(KC_COMM)

// Trilayer hacks for main board
#define ENT_RAI LT(_UPPER, KC_ENT) // LT trilayer
#define ESC_LOW LT(_LOWER, KC_ESC) // LT trilayer
