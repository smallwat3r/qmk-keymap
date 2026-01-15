#pragma once

#include <stdbool.h>
#include <stdint.h>

void rgb_indicator_init(void);
void rgb_indicator_set_base_layer(bool is_base);
void rgb_indicator_oneshot_mods(uint8_t mods);
