LTO_ENABLE = yes

AUTOCORRECT_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
CAPS_WORD_ENABLE = yes
OS_DETECTION_ENABLE = yes
UNICODE_COMMON = yes
UNICODEMAP_ENABLE = yes
VPATH += keyboards/gboards/

COMMAND_ENABLE = no

EXTRAFLAGS += -flto

SELECT_WORD_ENABLE ?= yes
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
	SRC += features/external/select_word.c
endif

LED_INDICATOR_ENABLE ?= no
ifeq ($(strip $(LED_INDICATOR_ENABLE)), yes)
	DEFERRED_EXEC_ENABLE = yes
	OPT_DEFS += -DLED_INDICATOR_ENABLE
	SRC += features/led_indicator.c
endif
