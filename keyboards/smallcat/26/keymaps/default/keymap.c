#include QMK_KEYBOARD_H

#include "smallwat3r.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYER_DEF(BASE),
    [NUM]  = LAYER_DEF(NUM),
    [SYM]  = LAYER_DEF(SYM),
    [SYM2] = LAYER_DEF(SYM2),
    [NAV]  = LAYER_DEF(NAV),
    [NAV2] = LAYER_DEF(NAV2),
    [EDIT] = LAYER_DEF(EDIT),
    [FUN]  = LAYER_DEF(FUN),
    [SYS]  = LAYER_DEF(SYS),
    [ROS]  = LAYER_DEF(ROS),
    [UNI]  = LAYER_DEF(UNI),
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
