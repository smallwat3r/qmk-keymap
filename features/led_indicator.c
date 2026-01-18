// LED indicator
// Caps Word: solid on
// OSM Shift: slow blink
// Autocorrect applied: double flash
// Toggle ON: single flash
// Toggle OFF: double flash

#include QMK_KEYBOARD_H

#define LED_BLINK_INTERVAL_MS 150
#define LED_FLASH_INTERVAL_MS 60

static bool           osm_active       = false;
static bool           caps_word_active = false;
static bool           blink_state      = false;
static uint8_t        flash_count      = 0;
static uint8_t        flash_target     = 0;
static deferred_token blink_token      = INVALID_DEFERRED_TOKEN;
static deferred_token flash_token      = INVALID_DEFERRED_TOKEN;

static uint32_t blink_callback(uint32_t trigger_time, void *cb_arg);

static void cancel_blink(void) {
    if (blink_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(blink_token);
        blink_token = INVALID_DEFERRED_TOKEN;
    }
}

static void cancel_flash(void) {
    if (flash_token != INVALID_DEFERRED_TOKEN) {
        cancel_deferred_exec(flash_token);
        flash_token  = INVALID_DEFERRED_TOKEN;
        flash_count  = 0;
        flash_target = 0;
    }
}

static void indicator_set(bool on) {
    gpio_write_pin(LED_INDICATOR_PIN, on ? LED_INDICATOR_ON_STATE : !LED_INDICATOR_ON_STATE);
}

static void restore_indicator_state(void) {
    if (caps_word_active) {
        indicator_set(true);
    } else if (osm_active) {
        blink_state = false;
        if (blink_token == INVALID_DEFERRED_TOKEN) {
            blink_token = defer_exec(1, blink_callback, NULL);
        }
    } else {
        indicator_set(false);
    }
}

static uint32_t blink_callback(uint32_t trigger_time, void *cb_arg) {
    if (osm_active && !caps_word_active && flash_token == INVALID_DEFERRED_TOKEN) {
        blink_state = !blink_state;
        indicator_set(blink_state);
        return LED_BLINK_INTERVAL_MS;
    }
    blink_token = INVALID_DEFERRED_TOKEN;
    return 0;
}

static uint32_t flash_callback(uint32_t trigger_time, void *cb_arg) {
    flash_count++;
    if (flash_count <= flash_target) {
        indicator_set(flash_count % 2 == 1);
        return LED_FLASH_INTERVAL_MS;
    }
    flash_count  = 0;
    flash_target = 0;
    flash_token  = INVALID_DEFERRED_TOKEN;
    restore_indicator_state();
    return 0;
}

static void start_flash(uint8_t count) {
    if (count == 0) return;
    cancel_blink();
    cancel_flash();
    flash_target = count * 2; // each flash = on + off
    flash_token  = defer_exec(1, flash_callback, NULL);
}

void led_indicator_flash(uint8_t count) {
    start_flash(count);
}

#if defined(AUTOCORRECT_ENABLE) && !defined(RGBLIGHT_ENABLE)
bool apply_autocorrect(uint8_t backspaces, const char *str, char *typo, char *correct) {
    start_flash(2);
    return true;
}
#endif

void led_indicator_init(void) {
    gpio_set_pin_output(LED_INDICATOR_PIN);
    indicator_set(false);
}

#if defined(CAPS_WORD_ENABLE) && !defined(RGBLIGHT_ENABLE)
void caps_word_set_user(bool active) {
    caps_word_active = active;
    if (active) {
        cancel_blink();
        cancel_flash();
        indicator_set(true);
    } else {
        restore_indicator_state();
    }
}
#endif

void led_indicator_oneshot_mods(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        osm_active = true;
        if (!caps_word_active && blink_token == INVALID_DEFERRED_TOKEN && flash_token == INVALID_DEFERRED_TOKEN) {
            blink_token = defer_exec(1, blink_callback, NULL);
        }
    } else if (!mods) {
        osm_active = false;
        cancel_blink();
        if (!caps_word_active && flash_token == INVALID_DEFERRED_TOKEN) {
            indicator_set(false);
        }
    }
}
