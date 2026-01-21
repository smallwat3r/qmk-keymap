// smallwat3r's QMK keymap

#include QMK_KEYBOARD_H
#ifdef SELECT_WORD_ENABLE
#    include "features/external/select_word.h"
#endif
#ifdef SENTENCE_CASE_ENABLE
#    include "features/external/sentence_case.h"
#endif
#ifdef LED_INDICATOR_ENABLE
#    include "features/led_indicator.h"
#endif
#ifdef RGB_INDICATOR_ENABLE
#    include "features/rgb_indicator.h"
#endif
#ifdef OS_KEYS_ENABLE
#    include "features/os_keys.h"
#    define USER_SAFE_RANGE OS_KEYS_SAFE_RANGE
#else
#    define USER_SAFE_RANGE SAFE_RANGE
#endif

enum layers {
    BASE, // default layout
    NUM,  // number pad (right side)
    SYM,  // symbols
    SYM2, // lighter symbols, home row passthrough for rolls
    NAV,  // navigation, arrows, brackets
    NAV2, // word navigation, selection
    EDIT, // clipboard, find operations
    FUN,  // function keys
    SYS,  // system (mouse, media, brightness, RGB)
    ROS,  // ROS2 teleop_twist_keyboard
    UNI,  // unicode (French accents)
};

enum custom_keycodes {
    // macros
    MK_ARROW = USER_SAFE_RANGE, // types "->"
    MK_000,                     // types "000"
    // selection
    MK_SEL_BACK, // select word backward
    MK_SEL_FWD,  // select word forward
    MK_SEL_LINE, // select entire line
    // unicode
    MK_EURO,  // types € (unicode)
    MK_POUND, // types £ (unicode)
    MK_HASH,  // types # (unicode, layout-safe)
    // tap-hold
    MK_RTS, // tap: OSM Shift, hold: Shift+Ctrl+Gui
    MK_RS,  // tap: "sh", hold: Ctrl+Gui
#ifdef SENTENCE_CASE_ENABLE
    // toggles
    MK_SC_TOGG, // toggle sentence case
#endif
};

enum unicode_names {
    UN_A_GRAVE,      // à
    UN_A_CIRCUMFLEX, // â
    UN_C_CEDILLA,    // ç
    UN_E_ACUTE,      // é
    UN_E_GRAVE,      // è
    UN_E_CIRCUMFLEX, // ê
    UN_E_DIAERESIS,  // ë
    UN_I_CIRCUMFLEX, // î
    UN_I_DIAERESIS,  // ï
    UN_O_CIRCUMFLEX, // ô
    UN_U_GRAVE,      // ù
    UN_U_CIRCUMFLEX, // û
    UN_OE_LIGATURE,  // œ
    UN_GUILL_L,      // «
    UN_GUILL_R,      // »
    UN_EURO,         // €
    UN_POUND,        // £
    UN_HASH,         // #
};

const uint32_t PROGMEM unicode_map[] = {
    [UN_A_GRAVE]      = 0x00E0, // à
    [UN_A_CIRCUMFLEX] = 0x00E2, // â
    [UN_C_CEDILLA]    = 0x00E7, // ç
    [UN_E_ACUTE]      = 0x00E9, // é
    [UN_E_GRAVE]      = 0x00E8, // è
    [UN_E_CIRCUMFLEX] = 0x00EA, // ê
    [UN_E_DIAERESIS]  = 0x00EB, // ë
    [UN_I_CIRCUMFLEX] = 0x00EE, // î
    [UN_I_DIAERESIS]  = 0x00EF, // ï
    [UN_O_CIRCUMFLEX] = 0x00F4, // ô
    [UN_U_GRAVE]      = 0x00F9, // ù
    [UN_U_CIRCUMFLEX] = 0x00FB, // û
    [UN_OE_LIGATURE]  = 0x0153, // œ
    [UN_GUILL_L]      = 0x00AB, // «
    [UN_GUILL_R]      = 0x00BB, // »
    [UN_EURO]         = 0x20AC, // €
    [UN_POUND]        = 0x00A3, // £
    [UN_HASH]         = 0x0023, // #
};

// define one alias per key to use on the base layer, this is a
// useful level of abstraction in order to define combos
// naming: K_<side><row><position> (L/R, T/H/B/TH, 1-5)
#define K_LT1 KC_L
#define K_LT2 KC_D
#define K_LT3 LT(UNI, KC_P)
#define K_LH1 MT(MOD_LSFT, KC_W)
#define K_LH2 LT(SYM2, KC_R)
#define K_LH3 LT(NUM, KC_T)
#define K_LH4 LT(NAV, KC_S)
#define K_LH5 LT(ROS, KC_G)
#define K_LB1 MT(MOD_LCTL, KC_K)
#define K_LB2 MT(MOD_LALT, KC_M)
#define K_LB3 MT(MOD_LGUI, KC_C)
#define K_LTH1 LT(EDIT, KC_TAB)
#define K_LTH2 LT(FUN, KC_SPC)
#define K_RT1 KC_F
#define K_RT2 KC_O
#define K_RT3 KC_U
#define K_RH1 KC_Y
#define K_RH2 LT(SYS, KC_N)
#define K_RH3 KC_A
#define K_RH4 LT(SYM2, KC_E)
#define K_RH5 MT(MOD_RSFT, KC_I)
#define K_RB1 MT(MOD_RGUI, KC_H)
#define K_RB2 MT(MOD_RALT, KC_COMMA)
#define K_RB3 MT(MOD_RCTL, KC_DOT)
#define K_RTH1 LT(SYS, KC_BSPC)
#define K_RTH2 LT(SYM, KC_ENT)

#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h" // must follow K_* definitions used in combos.def
#endif

// base
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │ L  │ D  │ P  │                    │ F  │ O  │ U  │
// ┌────┼────┼────┼UNI─┼────┐          ┌────┼────┼────┼────┼────┐
// │ W  │ R  │ T  │ S  │ G  │          │ Y  │ N  │ A  │ E  │ I  │
// └LSft┼SYM2┼NUM─┼NAV─┼ROS─┘          └────┼SYS─┼────┼SYM2┼RSft┘
//      │ K  │ M  │ C  │                    │ H  │ ,  │ .  │
//      └LCtl┴LAlt┴LGui┘                    └RGui┴RAlt┴RCtl┘
//                ┌────┬────┐    ┌────┬────┐
//                │Tab │Spc │    │Bsp │Ent │
//                └EDIT┴FUN─┘    └SYS─┴SYM─┘
#define BASE_L_TOP K_LT1, K_LT2, K_LT3
#define BASE_L_HOME K_LH1, K_LH2, K_LH3, K_LH4, K_LH5
#define BASE_L_BOT K_LB1, K_LB2, K_LB3
#define BASE_L_THUMB K_LTH1, K_LTH2
#define BASE_R_TOP K_RT1, K_RT2, K_RT3
#define BASE_R_HOME K_RH1, K_RH2, K_RH3, K_RH4, K_RH5
#define BASE_R_BOT K_RB1, K_RB2, K_RB3
#define BASE_R_THUMB K_RTH1, K_RTH2

// num
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │    │    │    │                    │ 7  │ 8  │ 9  │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │    │    │░░T░│ .  │    │          │000 │ 4  │ 5  │ 6  │ 0  │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │ ,  │                    │ 1  │ 2  │ 3  │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │Spc │    │Bsp │Del │
//                └────┴────┘    └────┴────┘
#define NUM_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NUM_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_DOT, KC_TRNS
#define NUM_L_BOT KC_TRNS, KC_TRNS, KC_COMMA
#define NUM_L_THUMB KC_TRNS, KC_SPC
#define NUM_R_TOP KC_7, KC_8, KC_9
#define NUM_R_HOME MK_000, KC_4, KC_5, KC_6, KC_0
#define NUM_R_BOT KC_1, KC_2, KC_3
#define NUM_R_THUMB KC_BSPC, KC_DEL

// sym
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │ @  │ £  │ $  │                    │ \  │ /  │ ?  │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │ *  │ -  │ =  │ "  │ %  │          │ !  │ :  │ #  │ ~  │ |  │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │ +  │ &  │ `  │                    │ <  │ >  │ -> │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │Spc │    │    │░░░░│
//                └────┴────┘    └────┴────┘
#define SYM_L_TOP KC_AT, MK_POUND, S(KC_4)
#define SYM_L_HOME S(KC_8), KC_MINUS, KC_EQUAL, S(KC_QUOTE), S(KC_5)
#define SYM_L_BOT S(KC_EQUAL), S(KC_7), KC_GRAVE
#define SYM_L_THUMB KC_TRNS, KC_SPC
#define SYM_R_TOP KC_BSLS, KC_SLASH, S(KC_SLASH)
#define SYM_R_HOME S(KC_1), S(KC_SCLN), MK_HASH, S(KC_GRAVE), S(KC_BSLS)
#define SYM_R_BOT S(KC_COMMA), S(KC_DOT), MK_ARROW
#define SYM_R_THUMB KC_TRNS, KC_TRNS

// sym2 (lighter layer that eases rolls for home row)
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │ @  │ £  │ $  │                    │ \  │ /  │ ?  │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │ *  │░░R░│ =  │ "  │ %  │          │ !  │ :  │ a  │░░E░│ |  │
// └────┼─r──┼────┼────┼────┘          └────┼────┼────┼─e──┼────┘
//      │ +  │ &  │ `  │                    │ <  │ >  │ -> │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │Spc │    │    │    │
//                └────┴────┘    └────┴────┘
#define SYM2_L_TOP SYM_L_TOP
#define SYM2_L_HOME S(KC_8), KC_R, KC_EQUAL, S(KC_QUOTE), S(KC_5)
#define SYM2_L_BOT SYM_L_BOT
#define SYM2_L_THUMB SYM_L_THUMB
#define SYM2_R_TOP SYM_R_TOP
#define SYM2_R_HOME S(KC_1), S(KC_SCLN), KC_A, KC_E, S(KC_BSLS)
#define SYM2_R_BOT SYM_R_BOT
#define SYM2_R_THUMB SYM_R_THUMB

// nav
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │    │    │    │                    │ {  │ }  │    │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │End │    │NAV2│░░S░│    │          │ ←  │ ↓  │ ↑  │ →  │Home│
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │    │                    │ [  │ ]  │    │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │ M2 │ M1 │    │Bsp │Del │
//                └────┴────┘    └────┴────┘
#define NAV_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV_L_HOME OS_END, KC_TRNS, MO(NAV2), KC_TRNS, KC_TRNS
#define NAV_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define NAV_L_THUMB KC_BTN2, KC_BTN1
#define NAV_R_TOP S(KC_LBRC), S(KC_RBRC), KC_TRNS
#define NAV_R_HOME KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, OS_HOME
#define NAV_R_BOT KC_LBRC, KC_RBRC, KC_TRNS
#define NAV_R_THUMB KC_BSPC, KC_DEL

// nav2
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │    │    │    │                    │    │    │    │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │    │    │░░░░│░░S░│    │          │ ←W │SelB│SelF│ →W │    │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │    │                    │Sel │    │    │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │    │    │BsW │DeW │
//                └────┴────┘    └────┴────┘
#define NAV2_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_L_THUMB KC_TRNS, KC_TRNS
#define NAV2_R_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define NAV2_R_HOME OS_L_W, MK_SEL_BACK, MK_SEL_FWD, OS_R_W, KC_TRNS
#define NAV2_R_BOT MK_SEL_LINE, KC_TRNS, KC_TRNS
#define NAV2_R_THUMB OS_BSPC_W, OS_DEL_W

// edit
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │ F← │Find│ F→ │                    │ {  │ }  │    │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │All │Cut │Copy│Pste│    │          │ ←  │ ↓  │ ↑  │ →  │    │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │Undo│Redo│                    │ [  │ ]  │    │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │░░░░│    │    │Bsp │Del │
//                └────┴────┘    └────┴────┘
#define EDIT_L_TOP OS_F_PREV, OS_FIND, OS_F_NEXT
#define EDIT_L_HOME OS_ALL, OS_CUT, OS_COPY, OS_PASTE, KC_TRNS
#define EDIT_L_BOT KC_TRNS, OS_UNDO, OS_REDO
#define EDIT_L_THUMB KC_TRNS, KC_TRNS
#define EDIT_R_TOP S(KC_LBRC), S(KC_RBRC), KC_TRNS
#define EDIT_R_HOME KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_TRNS
#define EDIT_R_BOT KC_LBRC, KC_RBRC, KC_TRNS
#define EDIT_R_THUMB KC_BSPC, KC_DEL

// fun
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │    │    │    │                    │ F7 │ F8 │ F9 │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │    │    │    │    │    │          │    │ F4 │ F5 │ F6 │    │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │    │                    │ F1 │ F2 │ F3 │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │░░░░│    │BsW │DeW │
//                └────┴────┘    └────┴────┘
#define FUN_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define FUN_L_THUMB KC_TRNS, KC_TRNS
#define FUN_R_TOP KC_F7, KC_F8, KC_F9
#define FUN_R_HOME KC_TRNS, KC_F4, KC_F5, KC_F6, KC_TRNS
#define FUN_R_BOT KC_F1, KC_F2, KC_F3
#define FUN_R_THUMB OS_BSPC_W, OS_DEL_W

// sys
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │Play│ M4 │ M5 │                    │Mute│Vol-│Vol+│
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │End │Wh→ │Wh↑ │Wh↓ │Wh← │          │Ms← │░░N░│Ms↑ │Ms→ │Home│
// └────┼────┼────┼────┼────┘          └────┼Ms↓─┼────┼────┼────┘
//      │Mctl│Bri-│Bri+│                    │RGB │Zm- │Zm+ │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │ M2 │ M1 │    │░░░░│    │
//                └────┴────┘    └────┴────┘
#define SYS_L_TOP KC_MPLY, KC_BTN4, KC_BTN5
#define SYS_L_HOME OS_END, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L
#define SYS_L_BOT KC_MCTL, KC_BRID, KC_BRIU
#define SYS_L_THUMB KC_BTN2, KC_BTN1
#define SYS_R_TOP KC_MUTE, KC_VOLD, KC_VOLU
#define SYS_R_HOME KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, OS_HOME
#define SYS_R_BOT RGB_TOG, OS_ZOOM_OUT, OS_ZOOM_IN
#define SYS_R_THUMB KC_TRNS, KC_TRNS

// ros (ros2 teleop)
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │    │    │    │                    │ U  │ I  │ O  │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │    │    │    │    │░░G░│          │    │ J  │ K  │ L  │    │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │    │                    │ M  │ ,  │ .  │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │    │    │    │    │
//                └────┴────┘    └────┴────┘
#define ROS_L_TOP KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_L_HOME KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define ROS_L_THUMB KC_TRNS, KC_TRNS
#define ROS_R_TOP KC_U, KC_I, KC_O
#define ROS_R_HOME KC_TRNS, KC_J, KC_K, KC_L, KC_TRNS
#define ROS_R_BOT KC_M, KC_COMMA, KC_DOT
#define ROS_R_THUMB KC_TRNS, KC_TRNS

// uni (unicode)
//      ┌────┬────┬────┐                    ┌────┬────┬────┐
//      │ ë  │ ï  │░░P░│                    │ ê  │ â  │ û  │
// ┌────┼────┼────┼────┼────┐          ┌────┼────┼────┼────┼────┐
// │ «  │ »  │    │    │    │          │ ù  │ è  │ à  │ é  │ ç  │
// └────┼────┼────┼────┼────┘          └────┼────┼────┼────┼────┘
//      │    │    │    │                    │ ô  │ î  │ œ  │
//      └────┴────┴────┘                    └────┴────┴────┘
//                ┌────┬────┐    ┌────┬────┐
//                │    │    │    │    │    │
//                └────┴────┘    └────┴────┘
#define UNI_L_TOP UM(UN_E_DIAERESIS), UM(UN_I_DIAERESIS), KC_TRNS
#define UNI_L_HOME UM(UN_GUILL_L), UM(UN_GUILL_R), KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_L_BOT KC_TRNS, KC_TRNS, KC_TRNS
#define UNI_L_THUMB KC_TRNS, KC_TRNS
#define UNI_R_TOP UM(UN_E_CIRCUMFLEX), UM(UN_A_CIRCUMFLEX), UM(UN_U_CIRCUMFLEX)
#define UNI_R_HOME UM(UN_U_GRAVE), UM(UN_E_GRAVE), UM(UN_A_GRAVE), UM(UN_E_ACUTE), UM(UN_C_CEDILLA)
#define UNI_R_BOT UM(UN_O_CIRCUMFLEX), UM(UN_I_CIRCUMFLEX), UM(UN_OE_LIGATURE)
#define UNI_R_THUMB KC_TRNS, KC_TRNS

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
// clang-format off
#define LAYER_DEF(layer) LAYOUT_wrapper( \
    layer##_L_TOP,   layer##_R_TOP, \
    layer##_L_HOME,  layer##_R_HOME, \
    layer##_L_BOT,   layer##_R_BOT, \
    layer##_L_THUMB, layer##_R_THUMB \
)
// clang-format on

// clang-format off
#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
             'L', 'L', 'L',            'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
             'L', 'L', 'L',            'R', 'R', 'R',
                       '*', '*',  '*', '*'
    );
#endif
// clang-format on

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
        case C_BL_RS:
        case C_BL_WH:
        case C_BR_UNDS:
        case C_BR_DASH:
        case C_BL_B:
            return COMBO_TERM_RELAXED;
        case C_BL_LBRC:
        case C_BR_RBRC:
        case C_BL_LPRN:
        case C_BR_RPRN:
            return COMBO_TERM_TIGHT;
    }
    return COMBO_TERM;
}
#endif

// Tracks state for custom tap-hold keys. On press, store the keycode and
// time. On release, check if keycode matches and if elapsed time is within
// TAPPING_TERM to distinguish tap from hold.
typedef struct {
    uint16_t keycode;
    uint16_t time;
} tap_hold_state_t;

static tap_hold_state_t tap_hold_state = {0};

#if defined(LED_INDICATOR_ENABLE) || defined(RGB_INDICATOR_ENABLE)
static void flash_indicator(uint8_t count) {
#    ifdef LED_INDICATOR_ENABLE
    led_indicator_flash(count);
#    endif
#    ifdef RGB_INDICATOR_ENABLE
    rgb_indicator_flash(count);
#    endif
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OS_KEYS_ENABLE
    if (!process_os_keys(keycode, record)) {
        return false;
    }
#endif
#ifdef SELECT_WORD_ENABLE
    if (!process_select_word(keycode, record)) {
        return false;
    }
#endif
#ifdef SENTENCE_CASE_ENABLE
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
#endif

    if (!record->event.pressed) {
#ifdef SELECT_WORD_ENABLE
        switch (keycode) {
            case MK_SEL_BACK:
            case MK_SEL_FWD:
            case MK_SEL_LINE:
                select_word_unregister();
                return false;
        }
#endif
        if (tap_hold_state.keycode && tap_hold_state.keycode == keycode) {
            bool is_tap = TIMER_DIFF_16(record->event.time, tap_hold_state.time) < TAPPING_TERM;
            switch (keycode) {
                case MK_RTS:
                    unregister_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI));
                    if (is_tap) set_oneshot_mods(MOD_BIT(KC_LSFT));
                    break;
                case MK_RS:
                    unregister_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI));
                    if (is_tap) SEND_STRING("sh");
                    break;
            }
            tap_hold_state.keycode = 0;
            return false;
        }
        return true;
    }

    switch (keycode) {
#ifdef SELECT_WORD_ENABLE
        case MK_SEL_BACK:
            select_word_register('B');
            return false;
        case MK_SEL_FWD:
            select_word_register('W');
            return false;
        case MK_SEL_LINE:
            select_word_register('L');
            return false;
#endif
        case MK_ARROW:
            SEND_STRING("->");
            return false;
        case MK_000:
            SEND_STRING("000");
            return false;
        // Use unicode to ensure these symbols are always printed
        // correctly regardless of host keyboard layout
        case MK_EURO:
            register_unicodemap(UN_EURO);
            return false;
        case MK_POUND:
            register_unicodemap(UN_POUND);
            return false;
        case MK_HASH:
            register_unicodemap(UN_HASH);
            return false;
        case MK_RTS:
            tap_hold_state.keycode = keycode;
            tap_hold_state.time    = record->event.time;
            register_mods(MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI));
            return false;
        case MK_RS:
            tap_hold_state.keycode = keycode;
            tap_hold_state.time    = record->event.time;
            register_mods(MOD_BIT(KC_LCTL) | MOD_BIT(KC_LGUI));
            return false;
#if defined(AUTOCORRECT_ENABLE) && (defined(LED_INDICATOR_ENABLE) || defined(RGB_INDICATOR_ENABLE))
        case AC_TOGG:
            // flash 1 = turning ON, flash 2 = turning OFF
            flash_indicator(autocorrect_is_enabled() ? 2 : 1);
            return true;
#endif
#ifdef SENTENCE_CASE_ENABLE
        case MK_SC_TOGG:
#    if defined(LED_INDICATOR_ENABLE) || defined(RGB_INDICATOR_ENABLE)
            flash_indicator(is_sentence_case_on() ? 2 : 1);
#    endif
            sentence_case_toggle();
            return false;
#endif
    }
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGB_INDICATOR_ENABLE
    rgb_indicator_set_base_layer(layer_state_cmp(state, BASE));
#endif
    return state;
}

void oneshot_mods_changed_user(uint8_t mods) {
#ifdef RGB_INDICATOR_ENABLE
    rgb_indicator_oneshot_mods(mods);
#endif
#ifdef LED_INDICATOR_ENABLE
    led_indicator_oneshot_mods(mods);
#endif
}

void keyboard_post_init_user(void) {
#ifdef RGB_INDICATOR_ENABLE
    rgb_indicator_init();
#endif
#ifdef LED_INDICATOR_ENABLE
    led_indicator_init();
    led_indicator_startup_flash(3); // blink 3 times to indicate connection
#endif
#ifdef AUTOCORRECT_ENABLE
    if (!autocorrect_is_enabled()) autocorrect_enable();
#endif
}
