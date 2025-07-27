#include QMK_KEYBOARD_H

#include "smallwat3r.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_wrapper(
        ___BASE_L1___, ___BASE_R1___,
        ___BASE_L2___, ___BASE_R2___,
        ___BASE_L3___, ___BASE_R3___,
        ___BASE_L4___, ___BASE_R4___
    ),
    [NUM] = LAYOUT_wrapper(
        ___NUM__L1___, ___NUM__R1___,
        ___NUM__L2___, ___NUM__R2___,
        ___NUM__L3___, ___NUM__R3___,
        ___NUM__L4___, ___NUM__R4___
    ),
    [SYM] = LAYOUT_wrapper(
        ___SYM__L1___, ___SYM__R1___,
        ___SYM__L2___, ___SYM__R2___,
        ___SYM__L3___, ___SYM__R3___,
        ___SYM__L4___, ___SYM__R4___
    ),
    [SYM2] = LAYOUT_wrapper(
        ___SYM2_L1___, ___SYM2_R1___,
        ___SYM2_L2___, ___SYM2_R2___,
        ___SYM2_L3___, ___SYM2_R3___,
        ___SYM2_L4___, ___SYM2_R4___
    ),
    [NAV] = LAYOUT_wrapper(
        ___NAV__L1___, ___NAV__R1___,
        ___NAV__L2___, ___NAV__R2___,
        ___NAV__L3___, ___NAV__R3___,
        ___NAV__L4___, ___NAV__R4___
    ),
    [NAV2] = LAYOUT_wrapper(
        ___NAV2_L1___, ___NAV2_R1___,
        ___NAV2_L2___, ___NAV2_R2___,
        ___NAV2_L3___, ___NAV2_R3___,
        ___NAV2_L4___, ___NAV2_R4___
    ),
    [EDIT] = LAYOUT_wrapper(
        ___EDIT_L1___, ___EDIT_R1___,
        ___EDIT_L2___, ___EDIT_R2___,
        ___EDIT_L3___, ___EDIT_R3___,
        ___EDIT_L4___, ___EDIT_R4___
    ),
    [FUN] = LAYOUT_wrapper(
        ___FUN__L1___, ___FUN__R1___,
        ___FUN__L2___, ___FUN__R2___,
        ___FUN__L3___, ___FUN__R3___,
        ___FUN__L4___, ___FUN__R4___
    ),
    [SYS] = LAYOUT_wrapper(
        ___SYS__L1___, ___SYS__R1___,
        ___SYS__L2___, ___SYS__R2___,
        ___SYS__L3___, ___SYS__R3___,
        ___SYS__L4___, ___SYS__R4___
    ),
    [ROS] = LAYOUT_wrapper(
        ___ROS__L1___, ___ROS__R1___,
        ___ROS__L2___, ___ROS__R2___,
        ___ROS__L3___, ___ROS__R3___,
        ___ROS__L4___, ___ROS__R4___
    )
};

#ifdef CHORDAL_HOLD
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
             'L', 'L', 'L',            'R', 'R', 'R',
        'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R',
             'L', 'L', 'L',            'R', 'R', 'R',
                       '*', '*',  '*', '*'
    );
#endif
