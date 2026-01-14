// smallwat3r's QMK keymap

#include QMK_KEYBOARD_H
#ifdef SELECT_WORD_ENABLE
#    include "features/select_word.h"
#endif

enum layers {
    BASE,
    SYM,
    SYM2, // lighter symbol layer for home row rolls
    NUM,
    NAV,
    NAV2,
    EDIT,
    FUN,
    SYS,
    ROS, // ROS2 teleop
    UNI, // unicode
};

enum custom_keycodes {
    M_KC_ARROW = SAFE_RANGE,
    M_KC_000,
    M_KC_SCRN, // take screenshot
    M_KC_COPY,
    M_KC_CUT,
    M_KC_PASTE,
    M_KC_UNDO,
    M_KC_REDO,
    M_KC_FIND,
    M_KC_F_NEXT, // find next
    M_KC_F_PREV, // find prev
    M_KC_ALL,    // select all
    M_KC_BSPC_W, // backspace whole word
    M_KC_DEL_W,  // delete whole word
    M_KC_R_W,    // move right whole word
    M_KC_L_W,    // move left whole word
    M_KC_SEL_BACK,
    M_KC_SEL_FWD,
    M_KC_SEL_LINE,
    M_KC_EURO,
    M_KC_POUND,
    M_KC_HASH,
};

enum unicode_names {
    UC_A_GRAVE,      // à
    UC_A_CIRCUMFLEX, // â
    UC_C_CEDILLA,    // ç
    UC_E_ACUTE,      // é
    UC_E_GRAVE,      // è
    UC_E_CIRCUMFLEX, // ê
    UC_U_CIRCUMFLEX, // û
    UC_EURO,         // €
    UC_POUND,        // £
    UC_HASH,         // #
};

const uint32_t PROGMEM unicode_map[] = {
    [UC_A_GRAVE]      = 0x00E0, // à
    [UC_A_CIRCUMFLEX] = 0x00E2, // â
    [UC_C_CEDILLA]    = 0x00E7, // ç
    [UC_E_ACUTE]      = 0x00E9, // é
    [UC_E_GRAVE]      = 0x00E8, // è
    [UC_E_CIRCUMFLEX] = 0x00EA, // ê
    [UC_U_CIRCUMFLEX] = 0x00FB, // û
    [UC_EURO]         = 0x20AC, // €
    [UC_POUND]        = 0x00A3, // £
    [UC_HASH]         = 0x0023, // #
};

// define one alias per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
// naming: K_<side><row><position> (L/R, T/H/B/TH, 1-5)
#define K_LT1  KC_L
#define K_LT2  KC_D
#define K_LT3  LT(UNI, KC_P)
#define K_LH1  MT(MOD_LSFT, KC_W)
#define K_LH2  LT(SYM2, KC_R)
#define K_LH3  LT(NUM, KC_T)
#define K_LH4  LT(NAV, KC_S)
#define K_LH5  LT(ROS, KC_G)
#define K_LB1  MT(MOD_LCTL, KC_K)
#define K_LB2  MT(MOD_LALT, KC_M)
#define K_LB3  MT(MOD_LGUI, KC_C)
#define K_LTH1 LT(EDIT, KC_TAB)
#define K_LTH2 LT(FUN, KC_SPC)
#define K_RT1  KC_F
#define K_RT2  KC_O
#define K_RT3  KC_U
#define K_RH1  KC_Y
#define K_RH2  LT(SYS, KC_N)
#define K_RH3  KC_A
#define K_RH4  LT(SYM2, KC_E)
#define K_RH5  MT(MOD_LSFT, KC_I)
#define K_RB1  MT(MOD_LGUI, KC_H)
#define K_RB2  MT(MOD_LALT, KC_COMMA)
#define K_RB3  MT(MOD_LCTL, KC_DOT)
#define K_RTH1 LT(SYS, KC_BSPC)
#define K_RTH2 LT(SYM, KC_ENT)

#ifdef COMBO_ENABLE
// need to be included after custom keycode definition in order to use the
// keycodes in combos.def
#    include "g/keymap_combo.h"
#endif

// base
#define BASE_L_TOP K_LT1, K_LT2, K_LT3
#define BASE_R_TOP K_RT1, K_RT2, K_RT3
#define BASE_L_HOME K_LH1, K_LH2, K_LH3, K_LH4, K_LH5
#define BASE_R_HOME K_RH1, K_RH2, K_RH3, K_RH4, K_RH5
#define BASE_L_BOT K_LB1, K_LB2, K_LB3
#define BASE_R_BOT K_RB1, K_RB2, K_RB3
#define BASE_L_THUMB K_LTH1, K_LTH2
#define BASE_R_THUMB K_RTH1, K_RTH2

// num
#define NUM_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NUM_R_TOP KC_7, KC_8, KC_9
#define NUM_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_TRNS
#define NUM_R_HOME M_KC_000, KC_4, KC_5, KC_6, KC_0
#define NUM_L_BOT KC_TRNS, KC_TRNS, KC_COMMA
#define NUM_R_BOT KC_1, KC_2, KC_3
#define NUM_L_THUMB KC_TRNS, KC_SPC
#define NUM_R_THUMB KC_BSPC, KC_DEL

// sym (common)
#define SYM_L_TOP KC_AT, M_KC_POUND, S(KC_4)
#define SYM_R_TOP KC_BSLS, KC_SLASH, S(KC_SLASH)
#define SYM_L_HOME S(KC_8), KC_MINUS, KC_EQUAL, S(KC_QUOTE), S(KC_5)
#define SYM_R_HOME S(KC_1), S(KC_SCLN), M_KC_HASH, S(KC_GRAVE), S(KC_BSLS)
#define SYM_L_BOT S(KC_EQUAL), S(KC_7), KC_GRAVE
#define SYM_R_BOT S(KC_COMMA), S(KC_DOT), M_KC_ARROW
#define SYM_L_THUMB KC_TRNS, KC_SPC
#define SYM_R_THUMB KC_TRNS, KC_TRNS

// sym2 (lighter layer that eases rolls for home row)
#define SYM2_L_TOP SYM_L_TOP
#define SYM2_R_TOP SYM_R_TOP
#define SYM2_L_HOME S(KC_8), KC_R, KC_EQUAL, S(KC_QUOTE), S(KC_5)
#define SYM2_R_HOME S(KC_1), S(KC_SCLN), CK_19, KC_E, S(KC_BSLS)
#define SYM2_L_BOT SYM_L_BOT
#define SYM2_R_BOT SYM_R_BOT
#define SYM2_L_THUMB SYM_L_THUMB
#define SYM2_R_THUMB SYM_R_THUMB

// nav
#define NAV_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV_R_TOP S(KC_LBRC), S(KC_RBRC), KC_TRNS
#define NAV_L_HOME KC_END, KC_TRNS, MO(NAV2), KC_TRNS, KC_TRNS
#define NAV_R_HOME KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_HOME
#define NAV_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define NAV_R_BOT KC_LBRC, KC_RBRC, KC_TRNS
#define NAV_L_THUMB KC_BTN2, KC_BTN1
#define NAV_R_THUMB KC_BSPC, KC_DEL

// nav2
#define NAV2_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_R_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_R_HOME M_KC_L_W, M_KC_SEL_BACK, M_KC_SEL_FWD, M_KC_R_W, KC_TRNS
#define NAV2_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_R_BOT M_KC_SEL_LINE, KC_TRNS, KC_TRNS
#define NAV2_L_THUMB KC_TRNS, KC_TRNS
#define NAV2_R_THUMB M_KC_BSPC_W, M_KC_DEL_W

// edit
#define EDIT_L_TOP M_KC_F_PREV, M_KC_FIND, M_KC_F_NEXT
#define EDIT_R_TOP S(KC_LBRC), S(KC_RBRC), KC_TRNS
#define EDIT_L_HOME M_KC_ALL, M_KC_CUT, M_KC_COPY, M_KC_PASTE, KC_TRNS
#define EDIT_R_HOME KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS
#define EDIT_L_BOT KC_TRNS, M_KC_UNDO, M_KC_REDO
#define EDIT_R_BOT KC_LBRC, KC_RBRC, KC_TRNS
#define EDIT_L_THUMB KC_TRNS, KC_TRNS
#define EDIT_R_THUMB KC_BSPC, KC_DEL

// fun
#define FUN_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_R_TOP KC_F7, KC_F8, KC_F9
#define FUN_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_R_HOME KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS
#define FUN_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_R_BOT KC_F1, KC_F2, KC_F3
#define FUN_L_THUMB KC_TRNS, KC_TRNS
#define FUN_R_THUMB M_KC_BSPC_W, M_KC_DEL_W

// sys
#define SYS_L_TOP KC_MPLY, KC_BTN4, KC_BTN5
#define SYS_R_TOP KC_MUTE, KC_VOLD, KC_VOLU
#define SYS_L_HOME KC_END, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L
#define SYS_R_HOME KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_HOME
#define SYS_L_BOT KC_MCTL, KC_BRID, KC_BRIU
#define SYS_R_BOT RGB_TOG, G(KC_KP_MINUS), G(KC_KP_PLUS)
#define SYS_L_THUMB KC_BTN2, KC_BTN1
#define SYS_R_THUMB KC_TRNS, KC_TRNS

// ros (ros2 teleop)
#define ROS_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_R_TOP KC_U, KC_I, KC_O
#define ROS_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_R_HOME KC_TRNS, KC_J, KC_K, KC_L, KC_TRNS
#define ROS_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_R_BOT KC_M, KC_COMM, KC_DOT
#define ROS_L_THUMB KC_TRNS, KC_TRNS
#define ROS_R_THUMB KC_TRNS, KC_TRNS

// uni (unicode)
#define UNI_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_R_TOP UM(UC_E_CIRCUMFLEX), UM(UC_A_CIRCUMFLEX), UM(UC_U_CIRCUMFLEX)
#define UNI_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_R_HOME KC_TRNS, UM(UC_E_GRAVE), UM(UC_A_GRAVE), UM(UC_E_ACUTE), UM(UC_C_CEDILLA)
#define UNI_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_R_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_L_THUMB KC_TRNS, KC_TRNS
#define UNI_R_THUMB KC_TRNS, KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

#ifdef OS_DETECTION_ENABLE
bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
            set_unicode_input_mode(UNICODE_MODE_MACOS);
            break;
        case OS_LINUX:
            set_unicode_input_mode(UNICODE_MODE_LINUX);
            break;
        default:
            break;
    }
    return true;
}
#endif

#ifdef COMBO_TERM_PER_COMBO
uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case C_LB_SH:
        case C_LB_WH:
        case C_RB_UNDS:
        case C_RB_DASH:
        case C_LB_B:
            return 50;
        case C_LB_LBRC:
            return 20;
    }
    return COMBO_TERM; // 35
}
#endif

#define OS_TAP(mac_key, other_key) tap_code16(detected_host_os() == OS_MACOS ? (mac_key) : (other_key))

#define OS_TAP_UNICODE(mac_key, unicode_name)  \
    do {                                       \
        if (detected_host_os() == OS_MACOS) {  \
            tap_code16(mac_key);               \
        } else {                               \
            register_unicodemap(unicode_name); \
        }                                      \
    } while (0)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record)) {
        return false;
    }
#endif

    if (!record->event.pressed) {
#ifdef SELECT_WORD_ENABLE
        switch (keycode) {
            case M_KC_SEL_BACK:
            case M_KC_SEL_FWD:
            case M_KC_SEL_LINE:
                select_word_unregister();
                return false;
        }
#endif
        return true;
    }

    switch (keycode) {
#ifdef SELECT_WORD_ENABLE
        case M_KC_SEL_BACK:
            select_word_register('B');
            return false;
        case M_KC_SEL_FWD:
            select_word_register('W');
            return false;
        case M_KC_SEL_LINE:
            select_word_register('L');
            return false;
#endif
        case M_KC_ARROW:
            SEND_STRING("->");
            return false;
        case M_KC_000:
            SEND_STRING("000");
            return false;
        case M_KC_COPY:
            OS_TAP(G(KC_C), KC_COPY);
            return false;
        case M_KC_CUT:
            OS_TAP(G(KC_X), KC_CUT);
            return false;
        case M_KC_PASTE:
            OS_TAP(G(KC_V), KC_PASTE);
            return false;
        case M_KC_UNDO:
            OS_TAP(G(KC_Z), C(KC_Z));
            return false;
        case M_KC_REDO:
            OS_TAP(SGUI(KC_Z), C(S(KC_Z)));
            return false;
        case M_KC_FIND:
            OS_TAP(G(KC_F), C(KC_F));
            return false;
        case M_KC_F_NEXT:
            OS_TAP(G(KC_G), C(KC_G));
            return false;
        case M_KC_F_PREV:
            OS_TAP(SGUI(KC_G), C(S(KC_G)));
            return false;
        case M_KC_ALL:
            OS_TAP(G(KC_A), C(KC_A));
            return false;
        case M_KC_BSPC_W:
            OS_TAP(A(KC_BSPC), C(KC_BSPC));
            return false;
        case M_KC_DEL_W:
            OS_TAP(A(KC_DEL), C(KC_DEL));
            return false;
        case M_KC_R_W:
            OS_TAP(A(KC_RIGHT), C(KC_RIGHT));
            return false;
        case M_KC_L_W:
            OS_TAP(A(KC_LEFT), C(KC_LEFT));
            return false;
        case M_KC_SCRN:
            OS_TAP(SGUI(KC_4), KC_PSCR);
            return false;
        case M_KC_EURO:
            OS_TAP_UNICODE(A(S(KC_2)), UC_EURO);
            return false;
        case M_KC_POUND:
            OS_TAP_UNICODE(S(KC_3), UC_POUND);
            return false;
        case M_KC_HASH:
            OS_TAP_UNICODE(RALT(KC_3), UC_HASH);
            return false;
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM default_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});

const rgblight_segment_t *const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(default_layer, capslock_layer, osm_shift_layer);
#endif

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    // light default layer in white
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
#endif
    return state;
}

#ifdef RGBLIGHT_ENABLE
bool led_update_user(led_t led_state) {
    // light up led in red when caps lock in on
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}
#endif

void oneshot_mods_changed_user(uint8_t mods) {
#ifdef RGBLIGHT_ENABLE
    // light up led in yellow when sticky shift is activated
    if (mods & MOD_MASK_SHIFT) {
        rgblight_set_layer_state(2, true);
    }
    if (!mods) {
        rgblight_set_layer_state(2, false);
    }
#endif
}

void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_ENABLE
    rgblight_layers = rgb_layers;
#endif
#ifdef AUTOCORRECT_ENABLE
    // ensure autocorrect is on by default
    if (!autocorrect_is_enabled()) autocorrect_enable();
#endif
}
