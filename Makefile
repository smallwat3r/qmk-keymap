.SILENT:
.PHONY: help all 26 uni flash-26 flash-uni clean format autocorrect
.DEFAULT_GOAL := help

QMK_USERSPACE := $(patsubst %/,%,$(dir $(shell realpath "$(lastword $(MAKEFILE_LIST))")))
UF2_DIR := $(QMK_USERSPACE)/uf2

KEYMAP := default
QMK_COMPILE := QMK_USERSPACE=$(QMK_USERSPACE) qmk compile
QMK_FLASH := QMK_USERSPACE=$(QMK_USERSPACE) qmk flash

all: 26 uni

26:
	$(QMK_COMPILE) -kb smallcat/26 -km $(KEYMAP)
	@mv $(QMK_USERSPACE)/smallcat_26_$(KEYMAP).uf2 $(UF2_DIR)/

uni:
	$(QMK_COMPILE) -kb smallcat/uni -km $(KEYMAP)
	@mv $(QMK_USERSPACE)/smallcat_uni_$(KEYMAP).uf2 $(UF2_DIR)/

flash-26:
	$(QMK_FLASH) -kb smallcat/26 -km $(KEYMAP)

flash-uni:
	$(QMK_FLASH) -kb smallcat/uni -km $(KEYMAP)

clean:
	qmk clean

format:
	find . -maxdepth 1 \( -name '*.c' -o -name '*.h' \) ! -name 'autocorrect_data.h' -exec clang-format -i {} +
	find features -maxdepth 1 \( -name '*.c' -o -name '*.h' \) -exec clang-format -i {} +
	clang-format -i keyboards/smallcat/*/keymaps/default/*.c
	clang-format -i keyboards/smallcat/*/keymaps/default/*.h 2>/dev/null || true

autocorrect:
	qmk generate-autocorrect-data $(QMK_USERSPACE)/autocorrection_dict.txt -o $(QMK_USERSPACE)/autocorrect_data.h

help:
	@echo "Usage: make [target]"
	@echo ""
	@echo "Build targets:"
	@echo "  all        Build all keyboards (26, uni)"
	@echo "  26         Build smallcat/26"
	@echo "  uni        Build smallcat/uni"
	@echo ""
	@echo "Flash targets:"
	@echo "  flash-26   Flash smallcat/26"
	@echo "  flash-uni  Flash smallcat/uni"
	@echo ""
	@echo "Other targets:"
	@echo "  clean         Clean build artifacts"
	@echo "  format        Format C code with clang-format"
	@echo "  autocorrect   Generate autocorrect data from dictionary"
	@echo "  help          Show this help message"
