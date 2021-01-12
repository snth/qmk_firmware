#include "snth.h"

/*
 * The `LAYOUT_gergo_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#define LAYOUT_gergo_base( \
    K01, K02, K03, K04, K05,           K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15,           K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25,           K26, K27, K28, K29, K2A, \
                   K34, K35, K36, K37, K38, K39       \
  ) \
  LAYOUT_gergo_wrapper( \
  LGUI_ESC,   K01,  K02,  K03,  K04,  K05,                                                   K06,  K07,  K08,  K09,  K0A,   KC_BSPC,   \
 LCTL_COLN,   K11,  K12,  K13,  K14,  K15,   KC_DLR,                              KC_CIRC,   K16,  K17,  K18,  K19,  K1A, RCTL_MINS,   \
 LSFT_BSLS,   K21,  K22,  K23,  K24,  K25,  KC_PERC,    KC_DEL,        CK_COLN,   KC_AMPR,   K26,  K27,  K28,  K29,  K2A,  RSFT_EQL,   \
                                K34,  K35,      K36,   NUM_ENT,        SYM_TAB,       K37,   K38,  K39 			               \
    )
#define LAYOUT_gergo_base_wrapper(...)       LAYOUT_gergo_base(__VA_ARGS__)

extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDHM] = LAYOUT_gergo_base_wrapper(
        _______________COLEMAK_DHM_L1______________, _______________COLEMAK_DHM_R1______________,
        _______________COLEMAK_DHM_L2______________, _______________COLEMAK_DHM_R2______________,
        _______________COLEMAK_DHM_L3______________, _______________COLEMAK_DHM_R3______________,
        _______________COLEMAK_DHM_L4______________, _______________COLEMAK_DHM_R4______________
  ),
  [_NAV] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_NAV_L1________________, ________________SNTH_NAV_R1________________,
        ________________SNTH_NAV_L2________________, ________________SNTH_NAV_R2________________,
        ________________SNTH_NAV_L3________________, ________________SNTH_NAV_R3________________,
        ________________SNTH_NAV_L4________________, ________________SNTH_NAV_R4________________
  ), 
  [_NUM] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_NUM_L1________________, ________________SNTH_NUM_R1________________,
        ________________SNTH_NUM_L2________________, ________________SNTH_NUM_R2________________,
        ________________SNTH_NUM_L3________________, ________________SNTH_NUM_R3________________,
        ________________SNTH_NUM_L4________________, ________________SNTH_NUM_R4________________
  ), 
  [_SYM] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_SYM_L1________________, ________________SNTH_SYM_R1________________,
        ________________SNTH_SYM_L2________________, ________________SNTH_SYM_R2________________,
        ________________SNTH_SYM_L3________________, ________________SNTH_SYM_R3________________,
        ________________SNTH_SYM_L4________________, ________________SNTH_SYM_R4________________
  ), 
  [_NUM2] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_NUM_L1________________, ________________SNTH_NUM_R1________________,
        ________________SNTH_NUM_L2________________, ________________SNTH_NUM_R2________________,
        ________________SNTH_NUM_L3________________, ________________SNTH_NUM_R3________________,
        ________________SNTH_NUM_L4________________, ________________SNTH_NUM_R4________________
  ),
  [_PAD] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_PAD_L1________________, ________________SNTH_PAD_R1________________,
        ________________SNTH_PAD_L2________________, ________________SNTH_PAD_R2________________,
        ________________SNTH_PAD_L3________________, ________________SNTH_PAD_R3________________,
        ________________SNTH_PAD_L4________________, ________________SNTH_PAD_R4________________
  ),
  [_UTIL] = LAYOUT_gergo_base_wrapper(
        ________________SNTH_UTL_L1________________, ________________SNTH_UTL_R1________________,
        ________________SNTH_UTL_L2________________, ________________SNTH_UTL_R2________________,
        ________________SNTH_UTL_L3________________, ________________SNTH_UTL_R3________________,
        ________________SNTH_UTL_L4________________, ________________SNTH_UTL_R4________________
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // static uint16_t mt_mod_timer;
    const uint8_t shift_mods = MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT);
    const uint8_t real_mods = get_mods();
    uint16_t keycode_to_register = keycode;

    switch (keycode) {
        case CK_COLN:
            if (real_mods & shift_mods) { // act as a semi-colon when shift is pressed
                keycode_to_register = KC_SCLN;
            } else {
                keycode_to_register = KC_COLN;
            }
            del_mods(real_mods & shift_mods);
            if (record->event.pressed) {
                register_code16(keycode_to_register);
            } else {
                unregister_code16(keycode_to_register);
            }
            add_mods(real_mods & shift_mods);
            return false; //we handled this keypress
            break;
        case LCTL_COLN:
            if (record->tap.count > 0) {
                if (real_mods & shift_mods) { // act as a semi-colon when shift is pressed
                    keycode_to_register = KC_SCLN;
                } else {
                    keycode_to_register = KC_COLN;
                }
                del_mods(real_mods & shift_mods);
                if (record->event.pressed) {
                    register_code16(keycode_to_register);
                } else {
                    unregister_code16(keycode_to_register);
                }
                add_mods(real_mods & shift_mods);
            return false; //we handled this keypress
            }
            break;
        case CK_UNDS:
            if (real_mods & shift_mods) { // act as a minus when shift is pressed
                keycode_to_register = KC_MINS;
            } else {
                keycode_to_register = KC_UNDS;
            }
            del_mods(real_mods & shift_mods);
            if (record->event.pressed) {
                register_code16(keycode_to_register);
            } else {
                unregister_code16(keycode_to_register);
            }
            add_mods(real_mods & shift_mods);
            return false; //we handled this keypress
            break;
        case LALT_LCBR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LCBR);
                } else {
                    unregister_code16(KC_LCBR);
                }
                return false; //we handled this keypress
            }
            break;
        case LGUI_RCBR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_RCBR);
                } else {
                    unregister_code16(KC_RCBR);
                }
                return false; //we handled this keypress
            }
            break;
        case LSFT_LPRN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LPRN);
                } else {
                    unregister_code16(KC_LPRN);
                }
                return false; //we handled this keypress
            }
            break;
        case LCTL_RPRN:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_RPRN);
                } else {
                    unregister_code16(KC_RPRN);
                }
                return false; //we handled this keypress
            }
            break;
        case RALT_LABK:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LABK);
                } else {
                    unregister_code16(KC_LABK);
                }
                return false; //we handled this keypress
            }
            break;
        case RGUI_RABK:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_RABK);
                } else {
                    unregister_code16(KC_RABK);
                }
                return false; //we handled this keypress
            }
            break;
        case RSFT_LBRC:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_LBRC);
                } else {
                    unregister_code16(KC_LBRC);
                }
                return false; //we handled this keypress
            }
            break;
        case RCTL_RBRC:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_RBRC);
                } else {
                    unregister_code16(KC_RBRC);
                }
                return false; //we handled this keypress
            }
            break;
    }
    return true; // We didn't handle other keypresses
}

// layer_state_t layer_state_set_user(layer_state_t state) {
//   switch (get_highest_layer(default_layer_state)) {
//     case _COLEMAKDHM:
//       state = update_tri_layer_state(state, _NUM, _NAV, _UTIL);
//       break;
//   }
//   return state;
// }
