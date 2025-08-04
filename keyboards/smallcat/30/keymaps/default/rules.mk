ROOT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))
include ${ROOT_DIR}../../../../../rules.mk

RGBLIGHT_ENABLE = yes
WS2812_DRIVER = vendor
