#include <stdbool.h>
#include "quantum_keycodes.h"

//Layers used in all keymaps
enum user_layer {
    _VOL,
    _APPS,
    _BRIGHT,
    _CHROME
};

// Custom keycodes shared across maps
// use KEYMAP_SAFE_RANGE for local functions
enum user_keycodes {
    CMD_TAB = SAFE_RANGE
};

#define SETTING LGUI(KC_COMM)

// Navigate desktops
#define MAC_APP LCTL(KC_UP)
#define PRV_SPC LCTL(KC_LEFT)
#define NXT_SPC LCTL(KC_RIGHT)

// Move between desktops
#define FULL G(C(KC_F))
#define NXT_DSK RCS(KC_RIGHT)
#define PRV_DSK RCS(KC_LEFT)

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
#define QUIT G(A(KC_ESC))
#define HIDE G(KC_H)

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
