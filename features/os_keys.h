#pragma once

#include QMK_KEYBOARD_H

// OS-aware keycodes
// These use the correct modifier for the detected OS (Cmd on macOS, Ctrl on Linux/Windows)
enum os_keys_keycodes {
    // clipboard
    OS_COPY = QK_USER, // start after QMK's built-in keycodes
    OS_CUT,
    OS_PASTE,
    OS_UNDO,
    OS_REDO,
    OS_ALL, // select all
    // file operations
    OS_SAVE,
    OS_NEW,
    OS_OPEN,
    OS_CLOSE, // close tab/window
    OS_PRINT,
    // search
    OS_FIND,
    OS_F_NEXT, // find next
    OS_F_PREV, // find previous
    // text formatting
    OS_BOLD,
    OS_ITALIC,
    // cursor navigation
    OS_L_W,    // move cursor left one word
    OS_R_W,    // move cursor right one word
    OS_HOME,   // start of line
    OS_END,    // end of line
    OS_TOP,    // top of document
    OS_BOTTOM, // bottom of document
    // word delete
    OS_BSPC_W, // backspace one word
    OS_DEL_W,  // delete one word
    // browser/tabs
    OS_RELOAD,
    OS_TAB_N, // next tab
    OS_TAB_P, // previous tab
    OS_ZOOM_IN,
    OS_ZOOM_OUT,
    // system
    OS_SCRN,           // screenshot
    OS_LOCK,           // lock screen
    OS_KEYS_SAFE_RANGE // start your custom keycodes from here
};

bool process_os_keys(uint16_t keycode, keyrecord_t *record);
