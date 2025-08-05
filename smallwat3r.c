// smallwat3r's QMK keymap

#include QMK_KEYBOARD_H
#ifdef SELECT_WORD_ENABLE
#include "features/select_word.h"
#endif

enum layers {
    BASE,
    SYM,
    SYM2,
    NUM,
    NAV,
    NAV2,
    EDIT,
    FUN,
    SYS,
    ROS,  // ROS2 teleop
};

enum custom_keycodes {
    M_KC_ARROW = SAFE_RANGE,
    M_KC_000,
    M_KC_SCRN,  // take screenshot
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
    SELWBAK,
    SELWFWD,
    SELLINE,
};

// define one alias per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
#define  CK_1   KC_L
#define  CK_2   KC_D
#define  CK_3   KC_P
#define  CK_4   MT(MOD_LSFT,  KC_W)
#define  CK_5   LT(SYM2,      KC_R)
#define  CK_6   LT(NUM,       KC_T)
#define  CK_7   LT(NAV,       KC_S)
#define  CK_8   LT(ROS,       KC_G)
#define  CK_9   MT(MOD_LCTL,  KC_K)
#define  CK_10  MT(MOD_LALT,  KC_M)
#define  CK_11  MT(MOD_LGUI,  KC_C)
#define  CK_12  LT(EDIT,      KC_TAB)
#define  CK_13  LT(FUN,       KC_SPC)
#define  CK_14  KC_F
#define  CK_15  KC_O
#define  CK_16  KC_U
#define  CK_17  KC_Y
#define  CK_18  LT(SYS,       KC_N)
#define  CK_19  KC_A
#define  CK_20  LT(SYM2,      KC_E)
#define  CK_21  MT(MOD_LSFT,  KC_I)
#define  CK_22  MT(MOD_LGUI,  KC_H)
#define  CK_23  MT(MOD_LALT,  KC_COMMA)
#define  CK_24  MT(MOD_LCTL,  KC_DOT)
#define  CK_25  LT(SYS,       KC_BSPC)
#define  CK_26  LT(SYM,       KC_ENT)

#define KC_EURO LSFT(LALT(KC_2))

#ifdef COMBO_ENABLE
// need to be included after custom keycode definition in order to use the
// keycodes in combos.def
#include "g/keymap_combo.h"
#endif

// base
#define  ___BASE_L1___  CK_1,   CK_2,   CK_3
#define  ___BASE_L1_30  KC_Q,   CK_1,   CK_2,   CK_3,   KC_J
#define  ___BASE_R1___  CK_14,  CK_15,  CK_16
#define  ___BASE_R1_30  KC_B,   CK_14,  CK_15,  CK_16,  KC_QUOT
#define  ___BASE_L2___  CK_4,   CK_5,   CK_6,   CK_7,   CK_8
#define  ___BASE_R2___  CK_17,  CK_18,  CK_19,  CK_20,  CK_21
#define  ___BASE_L3___  CK_9,   CK_10,  CK_11
#define  ___BASE_R3___  CK_22,  CK_23,  CK_24
#define  ___BASE_L4___  CK_12,  CK_13
#define  ___BASE_R4___  CK_25,  CK_26

// num
#define  ___NUM__L1___  KC_TRNS,   KC_TRNS,  KC_TRNS
#define  ___NUM__L1_30  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___NUM__R1___  KC_7,      KC_8,     KC_9
#define  ___NUM__R1_30  KC_NO,     KC_7,     KC_8,     KC_9,     KC_TRNS
#define  ___NUM__L2___  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_DOT,   KC_TRNS
#define  ___NUM__R2___  M_KC_000,  KC_4,     KC_5,     KC_6,     KC_0
#define  ___NUM__L3___  KC_TRNS,   KC_TRNS,  KC_COMMA
#define  ___NUM__R3___  KC_1,      KC_2,     KC_3
#define  ___NUM__L4___  KC_TRNS,   KC_SPC
#define  ___NUM__R4___  KC_BSPC,   KC_DEL

// common SYM definitions
#define  ___SYM_COMMON_L1___  KC_AT,        S(KC_3),      S(KC_4)
#define  ___SYM_COMMON_L1_30  KC_NO,        KC_AT,        S(KC_3),     S(KC_4),      KC_EURO
#define  ___SYM_COMMON_R1___  KC_BSLS,      KC_SLASH,     S(KC_SLASH)
#define  ___SYM_COMMON_R1_30  KC_NO,        KC_BSLS,      KC_SLASH,    S(KC_SLASH),  KC_CIRC
#define  ___SYM_COMMON_L3___  S(KC_EQUAL),  S(KC_7),      KC_GRAVE
#define  ___SYM_COMMON_R3___  S(KC_COMMA),  S(KC_DOT),    M_KC_ARROW
#define  ___SYM_COMMON_L4___  KC_TRNS,      KC_TRNS
#define  ___SYM_COMMON_R4___  KC_TRNS,      KC_TRNS

// sym
#define  ___SYM__L1___  ___SYM_COMMON_L1___
#define  ___SYM__L1_30  ___SYM_COMMON_L1_30
#define  ___SYM__R1___  ___SYM_COMMON_R1___
#define  ___SYM__R1_30  ___SYM_COMMON_R1_30
#define  ___SYM__L2___  S(KC_8),      KC_MINUS,     KC_EQUAL,    S(KC_QUOTE),  S(KC_5)
#define  ___SYM__R2___  S(KC_1),      S(KC_SCLN),   RALT(KC_3),  S(KC_GRAVE),  S(KC_BSLS)
#define  ___SYM__L3___  ___SYM_COMMON_L3___
#define  ___SYM__R3___  ___SYM_COMMON_R3___
#define  ___SYM__L4___  ___SYM_COMMON_L4___
#define  ___SYM__R4___  ___SYM_COMMON_R4___

// sym2 (lighter layer that ease rolls for home row)
#define  ___SYM2_L1___  ___SYM_COMMON_L1___
#define  ___SYM2_L1_30  ___SYM_COMMON_L1_30
#define  ___SYM2_R1___  ___SYM_COMMON_R1___
#define  ___SYM2_R1_30  ___SYM_COMMON_R1_30
#define  ___SYM2_L2___  S(KC_8),      KC_R,         KC_EQUAL,    S(KC_QUOTE),  S(KC_5)
#define  ___SYM2_R2___  S(KC_1),      S(KC_SCLN),   CK_19,       KC_E,         S(KC_BSLS)
#define  ___SYM2_L3___  ___SYM_COMMON_L3___
#define  ___SYM2_R3___  ___SYM_COMMON_R3___
#define  ___SYM2_L4___  ___SYM_COMMON_L4___
#define  ___SYM2_R4___  ___SYM_COMMON_R4___

// nav
#define  ___NAV__L1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__L1_30  KC_NO,       KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_NO
#define  ___NAV__R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___NAV__R1_30  KC_NO,       S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,      KC_TRNS
#define  ___NAV__L2___  KC_END,      KC_TRNS,     MO(NAV2),    KC_TRNS,      KC_TRNS
#define  ___NAV__R2___  KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,     KC_HOME
#define  ___NAV__L3___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__R3___  KC_LBRC,     KC_RBRC,     KC_TRNS
#define  ___NAV__L4___  KC_BTN2,     KC_BTN1
#define  ___NAV__R4___  KC_BSPC,     KC_DEL

// nav2
#define  ___NAV2_L1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_L1_30  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_R1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_R1_30  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_L2___  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_R2___  M_KC_L_W,    SELWBAK,     SELWFWD,     M_KC_R_W,     KC_TRNS
#define  ___NAV2_L3___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_R3___  SELLINE,     KC_TRNS,     KC_TRNS
#define  ___NAV2_L4___  KC_TRNS,     KC_TRNS
#define  ___NAV2_R4___  M_KC_BSPC_W, M_KC_DEL_W

// edit
#define  ___EDIT_L1___  M_KC_F_PREV, M_KC_FIND,   M_KC_F_NEXT
#define  ___EDIT_L1_30  KC_NO,       M_KC_F_PREV, M_KC_FIND,   M_KC_F_NEXT, KC_NO
#define  ___EDIT_R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___EDIT_R1_30  KC_NO,       S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,     KC_TRNS
#define  ___EDIT_L2___  M_KC_ALL,    M_KC_CUT,    M_KC_COPY,   M_KC_PASTE,  KC_TRNS
#define  ___EDIT_R2___  KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,    KC_TRNS
#define  ___EDIT_L3___  KC_TRNS,     M_KC_UNDO,   M_KC_REDO
#define  ___EDIT_R3___  KC_LBRC,     KC_RBRC,     KC_TRNS
#define  ___EDIT_L4___  KC_TRNS,     KC_TRNS
#define  ___EDIT_R4___  KC_BSPC,     KC_DEL

// fun
#define  ___FUN__L1___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___FUN__L1_30  KC_NO,       KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_NO
#define  ___FUN__R1___  KC_F7,       KC_F8,     KC_F9
#define  ___FUN__R1_30  KC_NO,       KC_F7,     KC_F8,    KC_F9,    KC_TRNS
#define  ___FUN__L2___  KC_TRNS,     KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___FUN__R2___  KC_TRNS,     KC_F4,     KC_F5,    KC_F6,    KC_TRNS
#define  ___FUN__L3___  KC_TRNS,     KC_TRNS,   KC_TRNS
#define  ___FUN__R3___  KC_F1,       KC_F2,     KC_F3
#define  ___FUN__L4___  KC_TRNS,     KC_TRNS
#define  ___FUN__R4___  M_KC_BSPC_W, M_KC_DEL_W

// sys
#define  ___SYS__L1___  KC_MPLY,  KC_BTN4,         KC_BTN5
#define  ___SYS__L1_30  KC_NO,    MS_ACL0,         KC_BTN4,       KC_BTN5,  KC_NO
#define  ___SYS__R1___  KC_MUTE,  KC_VOLD,         KC_VOLU
#define  ___SYS__R1_30  KC_NO,    KC_VOLD,         KC_VOLU,       KC_MUTE,  KC_TRNS
#define  ___SYS__L2___  KC_END,   KC_WH_R,         KC_WH_U,       KC_WH_D,  KC_WH_L
#define  ___SYS__R2___  KC_MS_L,  KC_MS_D,         KC_MS_U,       KC_MS_R,  KC_HOME
#define  ___SYS__L3___  KC_MCTL,  KC_BRID,         KC_BRIU
#define  ___SYS__R3___  RGB_TOG,  G(KC_KP_MINUS),  G(KC_KP_PLUS)
#define  ___SYS__L4___  KC_BTN2,  KC_BTN1
#define  ___SYS__R4___  KC_TRNS,  KC_TRNS

// ros2 teleop
#define  ___ROS__L1___  KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___ROS__L1_30  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___ROS__R1___  KC_U,     KC_I,     KC_O
#define  ___ROS__R1_30  KC_TRNS,  KC_U,     KC_I,     KC_O,     KC_TRNS
#define  ___ROS__L2___  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___ROS__R2___  KC_TRNS,  KC_J,     KC_K,     KC_L,     KC_TRNS
#define  ___ROS__L3___  KC_TRNS,  KC_TRNS,  KC_TRNS
#define  ___ROS__R3___  KC_M,     KC_COMM,  KC_DOT
#define  ___ROS__L4___  KC_TRNS,  KC_TRNS
#define  ___ROS__R4___  KC_TRNS,  KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record)) {
        return false;
    }
#endif

    switch (keycode) {
#ifdef SELECT_WORD_ENABLE
        case SELWBAK: // backward word selection.
            if (record->event.pressed) {
                select_word_register('B');
            } else {
                select_word_unregister();
            }
            return false;
        case SELWFWD: // forward word selection.
            if (record->event.pressed) {
                select_word_register('W');
            } else {
                select_word_unregister();
            }
            return false;
        case SELLINE: // line selection.
            if (record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            return false;
#endif
        case M_KC_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
        case M_KC_000:
            if (record->event.pressed) {
                SEND_STRING("000");
            }
            return false;
        case M_KC_SCRN:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(SGUI(KC_4));
                } else {
                    tap_code(KC_PSCR);
                }
            }
            return false;
        case M_KC_COPY:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code(KC_COPY);
                }
            }
            return false;
        case M_KC_CUT:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_X));
                } else {
                    tap_code(KC_CUT);
                }
            }
            return false;
        case M_KC_PASTE:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_V));
                } else {
                    tap_code(KC_PASTE);
                }
            }
            return false;
        case M_KC_UNDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_Z));
                } else {
                    tap_code(KC_UNDO);
                }
            }
            return false;
        case M_KC_REDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(SGUI(KC_Z));
                } else {
                    tap_code16(LCS(KC_Z));
                }
            }
            return false;
        case M_KC_FIND:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_F));
                } else {
                    tap_code(KC_FIND);
                }
            }
            return false;
        case M_KC_F_NEXT:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_G));
                } else {
                    tap_code16(C(KC_G));
                }
            }
            return false;
        case M_KC_F_PREV:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(SGUI(KC_G));
                } else {
                    tap_code16(LCS(KC_G));
                }
            }
            return false;
        case M_KC_ALL:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(G(KC_A));
                } else {
                    tap_code16(C(KC_A));
                }
            }
            return false;
        case M_KC_BSPC_W:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(A(KC_BSPC));
                } else {
                    tap_code16(C(KC_BSPC));
                }
            }
            return false;
        case M_KC_DEL_W:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(A(KC_DEL));
                } else {
                    tap_code16(C(KC_DEL));
                }
            }
            return false;
        case M_KC_R_W:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(A(KC_RIGHT));
                } else {
                    tap_code16(C(KC_RIGHT));
                }
            }
            return false;
        case M_KC_L_W:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    tap_code16(A(KC_LEFT));
                } else {
                    tap_code16(C(KC_LEFT));
                }
            }
            return false;
    }
    return true;
}

#ifdef RGBLIGHT_ENABLE
const rgblight_segment_t PROGMEM default_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(default_layer, capslock_layer, osm_shift_layer);
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
