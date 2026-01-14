#include QMK_KEYBOARD_H

#include "smallwat3r.c"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_wrapper(
        BASE_L_TOP,   BASE_R_TOP,
        BASE_L_HOME,  BASE_R_HOME,
        BASE_L_BOT,   BASE_R_BOT,
        BASE_L_THUMB, BASE_R_THUMB
    ),
    [NUM] = LAYOUT_wrapper(
        NUM_L_TOP,   NUM_R_TOP,
        NUM_L_HOME,  NUM_R_HOME,
        NUM_L_BOT,   NUM_R_BOT,
        NUM_L_THUMB, NUM_R_THUMB
    ),
    [SYM] = LAYOUT_wrapper(
        SYM_L_TOP,   SYM_R_TOP,
        SYM_L_HOME,  SYM_R_HOME,
        SYM_L_BOT,   SYM_R_BOT,
        SYM_L_THUMB, SYM_R_THUMB
    ),
    [SYM2] = LAYOUT_wrapper(
        SYM2_L_TOP,   SYM2_R_TOP,
        SYM2_L_HOME,  SYM2_R_HOME,
        SYM2_L_BOT,   SYM2_R_BOT,
        SYM2_L_THUMB, SYM2_R_THUMB
    ),
    [NAV] = LAYOUT_wrapper(
        NAV_L_TOP,   NAV_R_TOP,
        NAV_L_HOME,  NAV_R_HOME,
        NAV_L_BOT,   NAV_R_BOT,
        NAV_L_THUMB, NAV_R_THUMB
    ),
    [NAV2] = LAYOUT_wrapper(
        NAV2_L_TOP,   NAV2_R_TOP,
        NAV2_L_HOME,  NAV2_R_HOME,
        NAV2_L_BOT,   NAV2_R_BOT,
        NAV2_L_THUMB, NAV2_R_THUMB
    ),
    [EDIT] = LAYOUT_wrapper(
        EDIT_L_TOP,   EDIT_R_TOP,
        EDIT_L_HOME,  EDIT_R_HOME,
        EDIT_L_BOT,   EDIT_R_BOT,
        EDIT_L_THUMB, EDIT_R_THUMB
    ),
    [FUN] = LAYOUT_wrapper(
        FUN_L_TOP,   FUN_R_TOP,
        FUN_L_HOME,  FUN_R_HOME,
        FUN_L_BOT,   FUN_R_BOT,
        FUN_L_THUMB, FUN_R_THUMB
    ),
    [SYS] = LAYOUT_wrapper(
        SYS_L_TOP,   SYS_R_TOP,
        SYS_L_HOME,  SYS_R_HOME,
        SYS_L_BOT,   SYS_R_BOT,
        SYS_L_THUMB, SYS_R_THUMB
    ),
    [ROS] = LAYOUT_wrapper(
        ROS_L_TOP,   ROS_R_TOP,
        ROS_L_HOME,  ROS_R_HOME,
        ROS_L_BOT,   ROS_R_BOT,
        ROS_L_THUMB, ROS_R_THUMB
    ),
    [UNI] = LAYOUT_wrapper(
        UNI_L_TOP,   UNI_R_TOP,
        UNI_L_HOME,  UNI_R_HOME,
        UNI_L_BOT,   UNI_R_BOT,
        UNI_L_THUMB, UNI_R_THUMB
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
