// RGB indicator
// Base layer: white
// Caps Word/Caps Lock: red
// OSM Shift: green
// Toggle flash: blue

#include QMK_KEYBOARD_H

const rgblight_segment_t PROGMEM default_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});
const rgblight_segment_t PROGMEM flash_layer[]     = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_BLUE});

const rgblight_segment_t *const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(default_layer, capslock_layer, osm_shift_layer, flash_layer);

#define RGB_FLASH_LAYER 3
#define RGB_FLASH_INTERVAL_MS 100

static void rgb_set_caps_lock(bool enabled) {
    rgblight_set_layer_state(1, enabled);
}

void rgb_indicator_init(void) {
    rgblight_layers = rgb_layers;
}

void rgb_indicator_set_base_layer(bool is_base) {
    rgblight_set_layer_state(0, is_base);
}

void rgb_indicator_oneshot_mods(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        rgblight_set_layer_state(2, true);
    }
    if (!mods) {
        rgblight_set_layer_state(2, false);
    }
}

void rgb_indicator_flash(uint8_t count) {
    if (count == 0) return;
    rgblight_blink_layer_repeat(RGB_FLASH_LAYER, RGB_FLASH_INTERVAL_MS, count);
}

bool led_update_user(led_t led_state) {
    rgb_set_caps_lock(led_state.caps_lock);
    return true;
}

#ifdef CAPS_WORD_ENABLE
void caps_word_set_user(bool active) {
    rgb_set_caps_lock(active);
}
#endif
