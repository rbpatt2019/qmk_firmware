#include <stdbool.h>
#include "quantum_keycodes.h"

//Layers used in all keymaps
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
    GRAVES,
    KEYMAP_SAFE_RANGE
};

// Keycode aliases shared on all boards
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
#define PRV_SPC LCTL(KC_LEFT)
#define NXT_SPC LCTL(KC_RIGHT)
#define NXT_DSK RCS(KC_RIGHT)
#define PRV_DSK RCS(KC_LEFT)
#define SETTING LGUI(KC_COMM)

// Rectangle shortcuts
#define TOP LCA(KC_UP)
#define BOT LCA(KC_DOWN)
#define LEFT LCA(KC_LEFT)
#define RIGHT LCA(KC_RIGHT)
#define FULL G(C(KC_ENT))

// Trilayer hacks for main board
#define ENT_RAI LT(_UPPER, KC_ENT) // LT trilayer
#define ESC_LOW LT(_LOWER, KC_ESC) // LT trilayer

// Mac Paste/copy keys
#define MAC_ALL LGUI(KC_A)
#define MAC_CUT LGUI(KC_X)
#define MAC_CPY LGUI(KC_C)
#define MAC_PST LGUI(KC_V)

// Zoom shortcuts
#define ZM_TOGG LAG(KC_8)
#define ZM_IN LAG(KC_EQL)
#define ZM_OUT LAG(KC_MINS)

// Close things
#define KIL_APP LGUI(KC_Q)
#define KIL_WIN LGUI(KC_W)

// Slack
#define SLK_NXT LSA(KC_DOWN)
#define SLK_PRV LSA(KC_UP)
#define SLK_STS LSG(KC_Y)
#define MAC_NEW LGUI(KC_N)
#define SLK_SCH LGUI(KC_G)

// Chrome
#define CHR_TAB LSG(KC_T)
#define CHR_LTB LAG(KC_LEFT)
#define CHR_RTB LAG(KC_RIGHT)
#define CHR_HST LGUI(KC_Y)
#define CHR_LPG LGUI(KC_LBRC)
#define CHR_RPG LGUI(KC_RBRC)
#define CHR_BKM LSG(KC_B)
#define CHR_DWN LAG(KC_L)
