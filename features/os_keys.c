// OS-aware keycodes
// Automatically uses correct modifier (Cmd on macOS, Ctrl on Linux/Windows)

#include QMK_KEYBOARD_H
#include "os_keys.h"
#include "os_detection.h"

#define OS_TAP(mac_key, other_key) tap_code16(detected_host_os() == OS_MACOS ? (mac_key) : (other_key))

bool process_os_keys(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {
        // clipboard
        case OS_COPY:
            OS_TAP(G(KC_C), C(KC_C));
            return false;
        case OS_CUT:
            OS_TAP(G(KC_X), C(KC_X));
            return false;
        case OS_PASTE:
            OS_TAP(G(KC_V), C(KC_V));
            return false;
        case OS_UNDO:
            OS_TAP(G(KC_Z), C(KC_Z));
            return false;
        case OS_REDO:
            OS_TAP(SGUI(KC_Z), C(S(KC_Z)));
            return false;
        case OS_ALL:
            OS_TAP(G(KC_A), C(KC_A));
            return false;
        // file operations
        case OS_SAVE:
            OS_TAP(G(KC_S), C(KC_S));
            return false;
        case OS_NEW:
            OS_TAP(G(KC_N), C(KC_N));
            return false;
        case OS_OPEN:
            OS_TAP(G(KC_O), C(KC_O));
            return false;
        case OS_CLOSE:
            OS_TAP(G(KC_W), C(KC_W));
            return false;
        case OS_PRINT:
            OS_TAP(G(KC_P), C(KC_P));
            return false;
        // search
        case OS_FIND:
            OS_TAP(G(KC_F), C(KC_F));
            return false;
        case OS_F_NEXT:
            OS_TAP(G(KC_G), C(KC_G));
            return false;
        case OS_F_PREV:
            OS_TAP(SGUI(KC_G), C(S(KC_G)));
            return false;
        // text formatting
        case OS_BOLD:
            OS_TAP(G(KC_B), C(KC_B));
            return false;
        case OS_ITALIC:
            OS_TAP(G(KC_I), C(KC_I));
            return false;
        // cursor navigation
        case OS_L_W:
            OS_TAP(A(KC_LEFT), C(KC_LEFT));
            return false;
        case OS_R_W:
            OS_TAP(A(KC_RIGHT), C(KC_RIGHT));
            return false;
        case OS_HOME:
            OS_TAP(G(KC_LEFT), KC_HOME);
            return false;
        case OS_END:
            OS_TAP(G(KC_RIGHT), KC_END);
            return false;
        case OS_TOP:
            OS_TAP(G(KC_UP), C(KC_HOME));
            return false;
        case OS_BOTTOM:
            OS_TAP(G(KC_DOWN), C(KC_END));
            return false;
        // word delete
        case OS_BSPC_W:
            OS_TAP(A(KC_BSPC), C(KC_BSPC));
            return false;
        case OS_DEL_W:
            OS_TAP(A(KC_DEL), C(KC_DEL));
            return false;
        // browser/tabs
        case OS_RELOAD:
            OS_TAP(G(KC_R), C(KC_R));
            return false;
        case OS_TAB_N:
            OS_TAP(SGUI(KC_RBRC), C(KC_TAB));
            return false;
        case OS_TAB_P:
            OS_TAP(SGUI(KC_LBRC), C(S(KC_TAB)));
            return false;
        case OS_ZOOM_IN:
            OS_TAP(G(KC_EQUAL), C(KC_EQUAL));
            return false;
        case OS_ZOOM_OUT:
            OS_TAP(G(KC_MINUS), C(KC_MINUS));
            return false;
        // system
        case OS_SCRN:
            OS_TAP(SGUI(KC_4), KC_PSCR);
            return false;
        case OS_LOCK:
            OS_TAP(C(G(KC_Q)), G(KC_L));
            return false;
    }
    return true;
}
