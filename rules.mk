LTO_ENABLE = yes

AUTOCORRECT_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
LEADER_ENABLE = yes
COMBO_ENABLE = yes
VPATH += keyboards/gboards/

COMMAND_ENABLE = no
UNICODE_ENABLE = no

#added by maicon
OS_DETECTION_ENABLE = yes

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor

EXTRAFLAGS += -flto

SELECT_WORD_ENABLE ?= yes
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
	SRC += features/select_word.c
endif
