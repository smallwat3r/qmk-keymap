LTO_ENABLE = yes

MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
REPEAT_KEY_ENABLE = yes
COMBO_ENABLE = yes
VPATH += keyboards/gboards/
SRC += features/select_word.c

COMMAND_ENABLE = no
UNICODE_ENABLE = no

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor

EXTRAFLAGS += -flto
