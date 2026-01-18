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
MAGIC_ENABLE = no
CONSOLE_ENABLE = no
GRAVE_ESC_ENABLE = no
SPACE_CADET_ENABLE = no

SELECT_WORD_ENABLE ?= yes
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
	SRC += features/external/select_word.c
endif

SENTENCE_CASE_ENABLE ?= yes
ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
	SRC += features/external/sentence_case.c
endif

LED_INDICATOR_ENABLE ?= no
ifeq ($(strip $(LED_INDICATOR_ENABLE)), yes)
	DEFERRED_EXEC_ENABLE = yes
	OPT_DEFS += -DLED_INDICATOR_ENABLE
	SRC += features/led_indicator.c
endif

RGB_INDICATOR_ENABLE ?= no
ifeq ($(strip $(RGB_INDICATOR_ENABLE)), yes)
	OPT_DEFS += -DRGB_INDICATOR_ENABLE
	SRC += features/rgb_indicator.c
endif

OS_KEYS_ENABLE ?= yes
ifeq ($(strip $(OS_KEYS_ENABLE)), yes)
	OPT_DEFS += -DOS_KEYS_ENABLE
	SRC += features/os_keys.c
endif
