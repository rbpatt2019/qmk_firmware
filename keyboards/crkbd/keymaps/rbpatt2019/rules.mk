# This is loaded after the keyboard rules.mk
# So we disable things that we don't want on any keyboard
# And load things we want on everything
# And conditionally load things dependent on keyboard settings, such as RGBs

LTO_ENABLE = yes  # Makes hex file smaller
SPLIT_KEYBOARD = yes

KEY_OVERRIDE_ENABLE = yes
OLED_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
    SRC += features/oled.c
endif

#Disable on all to save space
AUTOCORRECT_ENABLE = no
AUDIO_ENABLE = no
AUTO_SHIFT_ENABLE = no
BACKLIGHT_ENABLE = no
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = no
COMBO_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = no
DEFERRED_EXEC_ENABLE = no
GRAVE_ESC_ENABLE = no
KEY_LOCK_ENABLE = no
LEADER_ENABLE = no
MAGIC_ENABLE = no
MIDI_ENABLE = no
MOUSEKEY_ENABLE = no
NKRO_ENABLE = no
SLEEP_LED_ENABLE = no
SPACE_CADET_ENABLE = no
SWAP_HANDS_ENABLE = no
TAP_DANCE_ENABLE = no
TRI_LAYER_ENABLE = no
UCIS_ENABLE = no
UNICODEMAP_ENABLE = no
UNICODE_ENABLE = np
