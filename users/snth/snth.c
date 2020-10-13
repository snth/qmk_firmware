#include "snth.h"

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
        case CTL_AMPR:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    register_code16(KC_AMPR);
                } else {
                    unregister_code16(KC_AMPR);
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
