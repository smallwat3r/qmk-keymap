// smallwat3r's QMK keymap

#include QMK_KEYBOARD_H
#include "features/select_word.h"
#include "features/autocorrect_data.h"

enum layers {
    BASE,
    SYM,
    NUM,
    NAV,
    NAV2,
    EDIT,
    FUN,
    SYS,
};

enum custom_keycodes {
    C_KC_ARROW = SAFE_RANGE,
    C_KC_TZERO,
    SELWBAK,
    SELWFWD,
    SELLINE,
    // macros invoked from magic key
    M_POST_DOT,
    M_POST_COMMA,
    M_POST_A,
    M_POST_B,
    M_POST_C,
    M_POST_D,
    M_POST_E,
    M_POST_I,
    M_POST_I_UP,
    M_POST_J,
    M_POST_M,
    M_POST_N,
    M_POST_O,
    M_POST_Q,
    M_POST_R,
    M_POST_S,
    M_POST_T,
    M_POST_U,
    M_POST_V,
    M_POST_W,
    M_POST_Y,
    M_POST_Z,
};

// define one alias per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
#define  CK_1   KC_L
#define  CK_2   KC_D
#define  CK_3   KC_P
#define  CK_4   MT(MOD_LSFT,  KC_M)
#define  CK_5   LT(SYM,       KC_R)
#define  CK_6   LT(NUM,       KC_T)
#define  CK_7   LT(NAV,       KC_S)
#define  CK_8   KC_G
#define  CK_9   MT(MOD_LCTL,  KC_TAB)
#define  CK_10  MT(MOD_LALT,  KC_QUOT)
#define  CK_11  MT(MOD_LGUI,  KC_C)
#define  CK_12  LT(EDIT,      QK_AREP)
#define  CK_13  LT(FUN,       KC_SPC)
#define  CK_14  KC_F
#define  CK_15  KC_O
#define  CK_16  KC_U
#define  CK_17  KC_Y
#define  CK_18  KC_N
#define  CK_19  LT(NUM,       KC_A)
#define  CK_20  LT(SYM,       KC_E)
#define  CK_21  MT(MOD_LSFT,  KC_I)
#define  CK_22  MT(MOD_LGUI,  KC_H)
#define  CK_23  MT(MOD_LALT,  KC_COMMA)
#define  CK_24  MT(MOD_LCTL,  KC_DOT)
#define  CK_25  LT(SYS,       KC_BSPC)
#define  CK_26  LT(SYM,       KC_ENT)

#define KC_EURO LSFT(LALT(KC_2))

// need to be included after custom keycode definition in order to use the
// keycodes in combos.def
#include "g/keymap_combo.h"

// base
#define  ___BASE_L1___  CK_1,   CK_2,   CK_3
#define  ___BASE_L1_30  KC_W,   CK_1,   CK_2,   CK_3,   KC_B
#define  ___BASE_R1___  CK_14,  CK_15,  CK_16
#define  ___BASE_R1_30  KC_K,   CK_14,  CK_15,  CK_16,  KC_ESC
#define  ___BASE_L2___  CK_4,   CK_5,   CK_6,   CK_7,   CK_8
#define  ___BASE_R2___  CK_17,  CK_18,  CK_19,  CK_20,  CK_21
#define  ___BASE_L3___  CK_9,   CK_10,  CK_11
#define  ___BASE_R3___  CK_22,  CK_23,  CK_24
#define  ___BASE_L4___  CK_12,  CK_13
#define  ___BASE_R4___  CK_25,  CK_26

// num
#define  ___NUM__L1___  KC_7,        KC_8,   KC_9
#define  ___NUM__L1_30  KC_NO,       KC_7,   KC_8,  KC_9,  KC_NO
#define  ___NUM__R1___  KC_7,        KC_8,   KC_9
#define  ___NUM__R1_30  KC_NO,       KC_7,   KC_8,  KC_9,  KC_TRNS
#define  ___NUM__L2___  KC_0,        KC_4,   KC_5,  KC_6,  C_KC_TZERO
#define  ___NUM__R2___  C_KC_TZERO,  KC_4,   KC_5,  KC_6,  KC_0
#define  ___NUM__L3___  KC_1,        KC_2,   KC_3
#define  ___NUM__R3___  KC_1,        KC_2,   KC_3
#define  ___NUM__L4___  KC_TRNS,     KC_SPC
#define  ___NUM__R4___  KC_BSPC,     KC_DEL

// sym
#define  ___SYM__L1___  KC_AT,        S(KC_3),      S(KC_4)
#define  ___SYM__L1_30  KC_NO,        KC_AT,        S(KC_3),     S(KC_4),      KC_NO
#define  ___SYM__R1___  KC_BSLS,      KC_SLASH,     S(KC_SLASH)
#define  ___SYM__R1_30  KC_NO,        KC_BSLS,      KC_SLASH,    S(KC_SLASH),  KC_TRNS
#define  ___SYM__L2___  S(KC_8),      S(KC_EQUAL),  KC_EQUAL,    S(KC_QUOTE),  S(KC_5)
#define  ___SYM__R2___  S(KC_1),      S(KC_SCLN),   RALT(KC_3),  S(KC_GRAVE),  S(KC_BSLS)
#define  ___SYM__L3___  KC_MINUS,     S(KC_7),      KC_GRAVE
#define  ___SYM__R3___  S(KC_COMMA),  S(KC_DOT),    C_KC_ARROW
#define  ___SYM__L4___  KC_TRNS,      KC_TRNS
#define  ___SYM__R4___  KC_TRNS,      KC_TRNS

// nav
#define  ___NAV__L1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__L1_30  KC_NO,       KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_NO
#define  ___NAV__R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___NAV__R1_30  KC_NO,       S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,      KC_TRNS
#define  ___NAV__L2___  KC_TRNS,     KC_TRNS,     MO(NAV2),    KC_TRNS,      KC_TRNS
#define  ___NAV__R2___  KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,     KC_TRNS
#define  ___NAV__L3___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV__R3___  KC_LBRC,     KC_RBRC,     KC_TRNS
#define  ___NAV__L4___  KC_TRNS,     KC_TRNS
#define  ___NAV__R4___  KC_BSPC,     KC_DEL

// nav2
#define  ___NAV2_L1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_L1_30  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_R1___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_R1_30  KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_L2___  SELWBAK,     KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS
#define  ___NAV2_R2___  A(KC_LEFT),  KC_TRNS,     KC_TRNS,     A(KC_RIGHT),  SELWFWD
#define  ___NAV2_L3___  KC_TRNS,     KC_TRNS,     KC_TRNS
#define  ___NAV2_R3___  SELLINE,     KC_TRNS,     KC_TRNS
#define  ___NAV2_L4___  KC_TRNS,     KC_TRNS
#define  ___NAV2_R4___  A(KC_BSPC),  A(KC_DEL)

// edit
#define  ___EDIT_L1___  SGUI(KC_G),  G(KC_F),     G(KC_G)
#define  ___EDIT_L1_30  KC_NO,       SGUI(KC_G),  G(KC_F),     G(KC_G),   KC_NO
#define  ___EDIT_R1___  S(KC_LBRC),  S(KC_RBRC),  KC_TRNS
#define  ___EDIT_R1_30  KC_NO,       S(KC_LBRC),  S(KC_RBRC),  KC_TRNS,   KC_TRNS
#define  ___EDIT_L2___  G(KC_A),     G(KC_X),     G(KC_C),     G(KC_V),   KC_TRNS
#define  ___EDIT_R2___  KC_LEFT,     KC_DOWN,     KC_UP,       KC_RIGHT,  KC_TRNS
#define  ___EDIT_L3___  KC_TRNS,     G(KC_Z),     G(KC_Z)
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
#define  ___FUN__R4___  A(KC_BSPC),  A(KC_DEL)

// sys
#define  ___SYS__L1___  MS_ACL0,         KC_BTN4,        KC_BTN5
#define  ___SYS__L1_30  KC_NO,           MS_ACL0,        KC_BTN4,  KC_BTN5,  KC_NO
#define  ___SYS__R1___  KC_VOLD,         KC_VOLU,        KC_MUTE
#define  ___SYS__R1_30  KC_NO,           KC_VOLD,        KC_VOLU,  KC_MUTE,  KC_TRNS
#define  ___SYS__L2___  KC_HOME,         KC_WH_R,        KC_WH_U,  KC_WH_D,  KC_WH_L
#define  ___SYS__R2___  KC_MS_L,         KC_MS_D,        KC_MS_U,  KC_MS_R,  KC_END
#define  ___SYS__L3___  MS_ACL1,         KC_BRID,        KC_BRIU
#define  ___SYS__R3___  G(KC_KP_MINUS),  G(KC_KP_PLUS),  RGB_TOG
#define  ___SYS__L4___  KC_BTN2,         KC_BTN1
#define  ___SYS__R4___  KC_TRNS,         KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo->keycode) {
        case C_LB_SH:
        case C_LB_WH:
            return 50;
        #ifndef KEY_COUNT_30
        case C_LB_W:
        case C_LB_B:
        case C_RB_K:
            return 50;
        case C_RB_ESC:
            return 15;
        #endif
    }
    return COMBO_TERM; // 35
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        case CK_24:
            return M_POST_DOT;
        case CK_23:
            return M_POST_COMMA;
        case CK_19:
            return M_POST_A;
        case KC_B:
            return M_POST_B;
        case CK_11:
            return M_POST_C;
        case CK_2:
            return M_POST_D;
        case CK_20:
            return M_POST_E;
        case CK_21:
            if (mods & MOD_MASK_SHIFT) {
                return M_POST_I_UP;
            }
            return M_POST_I;
        case KC_J:
            return M_POST_J;
        case CK_3:
            return M_POST_M;
        case CK_18:
            return M_POST_N;
        case CK_15:
            return M_POST_O;
        case KC_Q:
            return M_POST_Q;
        case CK_5:
            return M_POST_R;
        case CK_7:
            return M_POST_S;
        case CK_6:
            return M_POST_T;
        case CK_16:
            return M_POST_U;
        case KC_V:
            return M_POST_V;
        case KC_W:
            return M_POST_W;
        case KC_Z:
            return M_POST_Z;
        case CK_17:
            return M_POST_Y;
        case KC_EQL:
            return KC_GT;
        case SELWBAK:
            return SELWFWD;
        case SELWFWD:
            return SELWBAK;
        case KC_PLUS:
        case KC_MINS:
        case KC_ASTR:
        case KC_PERC:
        case KC_PIPE:
        case KC_CIRC:
        case KC_TILD:
        case KC_EXLM:
        case KC_DLR:
        case KC_RABK:
        case KC_LPRN:
        case KC_RPRN:
        case KC_UNDS:
        case KC_COLN:
            return KC_EQL;
    }
    return KC_TRNS;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CK_12:
            if (record->tap.count) {
                process_repeat_key(QK_AREP, record);
                return false;
            }
            return true;
        case SELWBAK: // backward word selection.
            if (record->event.pressed) {
                select_word_register('B');
            } else {
                select_word_unregister();
            }
            break;
        case SELWFWD: // forward word selection.
            if (record->event.pressed) {
                select_word_register('W');
            } else {
                select_word_unregister();
            }
            break;
        case SELLINE: // line selection.
            if (record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            break;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case C_KC_ARROW:
                SEND_STRING("->");
                return false;
            case C_KC_TZERO:
                SEND_STRING("000");
                return false;
            // alt repeat macros
            case M_POST_DOT:
                if (get_repeat_key_count() == -1) {
                    SEND_STRING("./"); // .->./
                } else if (get_repeat_key_count() <= -2) {
                    // continue to append updir characters
                    SEND_STRING("../");
                }
                break;
            case M_POST_COMMA:
                SEND_STRING(" but ");
                break; // ,-> but
            case M_POST_A:
                SEND_STRING("bout ");
                break; // a->bout
            case M_POST_B:
                if (get_repeat_key_count() == -1) {
                    SEND_STRING("ecause "); // b->ecause
                } else if (get_repeat_key_count() == -2) {
                    SEND_STRING("\b\b\b\b\b\b\before "); // b->efore
                }
                break;
            case M_POST_C:
                SEND_STRING("lass ");
                break; // c->lass
            case M_POST_D:
                SEND_STRING("ef ");
                break; // d->ef
            case M_POST_E:
                SEND_STRING("lse ");
                break; // e->lse
            case M_POST_I:
                SEND_STRING("mport ");
                break; // i->mport
            case M_POST_I_UP:
                SEND_STRING("'m ");
                break; // I->'m
            case M_POST_J:
                SEND_STRING("ust ");
                break; // j->ust
            case M_POST_M:
                SEND_STRING("ent ");
                break; // m->ent
            case M_POST_N:
                SEND_STRING("n't ");
                break; // n->'t
            case M_POST_O:
                SEND_STRING("n't ");
                break; // o->n't
            case M_POST_Q:
                SEND_STRING("uen");
                break; // q->uen
            case M_POST_R:
                SEND_STRING("eturn ");
                break; // r->eturn
            case M_POST_S:
                if (get_repeat_key_count() == -1) {
                    SEND_STRING("'nt "); // s->'nt
                } else if (get_repeat_key_count() == -2) {
                    SEND_STRING("\b\b\b\bion "); // s->ion
                }
                break;
            case M_POST_T:
                if (get_repeat_key_count() == -1) {
                    SEND_STRING("ment "); // t->ment
                } else if (get_repeat_key_count() == -2) {
                    SEND_STRING("\b\b\b\b\bhank"); // t->hank
                }
                break;
            case M_POST_U:
                SEND_STRING("pdate ");
                break; // u->pdate
            case M_POST_V:
                SEND_STRING("er");
                break; // v->er
            case M_POST_W:
                if (get_repeat_key_count() == -1) {
                    SEND_STRING("hat "); // w->hat
                } else if (get_repeat_key_count() == -2) {
                    SEND_STRING("\b\b\b\bhich "); // w->hich
                }
                break;
            case M_POST_Y:
                SEND_STRING("ou");
                break; // y->ou
            case M_POST_Z:
                SEND_STRING("ero ");
                break; // z->ero
        }
    }
    return true;
}

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    switch (keycode) {
        // required in order for AREP to work with layer tap
        case CK_12:
            return false;
    }
    return true;
}

// rgb light

const rgblight_segment_t PROGMEM default_layer[]   = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_WHITE});
const rgblight_segment_t PROGMEM capslock_layer[]  = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_RED});
const rgblight_segment_t PROGMEM osm_shift_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 1, HSV_GREEN});

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(default_layer, capslock_layer, osm_shift_layer);
void keyboard_post_init_user(void) {
    rgblight_layers = rgb_layers;
}

// default layer
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE));
    return state;
}

// light up led in red when caps lock in on
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.caps_lock);
    return true;
}

// light up led in yellow when sticky shift is activated
void oneshot_mods_changed_user(uint8_t mods) {
    if (mods & MOD_MASK_SHIFT) {
        rgblight_set_layer_state(2, true);
    }
    if (!mods) {
        rgblight_set_layer_state(2, false);
    }
}
