# This is loaded after the keyboard rules.mk
# So we disable things that we don't want on any keyboard
# And load things we want on everything
# And conditionally load things dependent on keyboard settings, such as RGBs

LTO_ENABLE = yes  # Makes hex file smaller
SPLIT_KEYBOARD = yes

# Include common to all
# And activate features required in main file
MOUSE_ENABLE = yes # for jiggle
DEFERRED_EXEC_ENABLE = yes # for jiggle
DYNAMIC_MACRO_ENABLE = yes # for jiggle
SRC += rbpatt2019.c

# Enable on all for required functionality
KEY_OVERRIDE_ENABLE = yes
SRC += feature_overrides.c

TAP_DANCE_ENABLE = yes
SRC += feature_tapdance.c

TRI_LAYER_ENABLE = yes

# Optional per board functionality
ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += feature_oled.c
endif

#Disable on all to save space
AUTO_SHIFT_ENABLE = no
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = no
COMBO_ENABLE = no
COMMAND_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
MAGIC_ENABLE = no
MIDI_ENABLE = no
NKRO_ENABLE = no
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = np
