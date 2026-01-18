#pragma once

#include <stdint.h>

void led_indicator_init(void);
void led_indicator_oneshot_mods(uint8_t mods);
void led_indicator_flash(uint8_t count);
