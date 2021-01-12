#include "snth.h"

/*
 * The `LAYOUT_crkbd_base` macro is a template to allow the use of identical
 * modifiers for the default layouts (eg QWERTY, Colemak, Dvorak, etc), so
 * that there is no need to set them up for each layout, and modify all of
 * them if I want to change them.  This helps to keep consistency and ease
 * of use. K## is a placeholder to pass through the individual keycodes
 */

#define LAYOUT_crkbd_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, \
                   K34, K35, K36, K37, K38, K39       \
  ) \
  LAYOUT_wrapper( \
    KC_TAB,  K01,   K02,   K03,    K04,     K05,                              K06,     K07,     K08,     K09,     K0A,    KC_BSPC,   \
    CK_COLN, K11,   K12,   K13,    K14,     K15,                              K16,     K17,     K18,     K19,     K1A,    KC_MINS,   \
    CTL_ESC, K21,   K22,   K23,    K24,     K25,                              K26,     K27,     K28,     K29,     K2A,    CTL_BSLS,  \
                   		   K34,     K35,      K36,           K37,     K38,     K39 					     \
    )
#define LAYOUT_crkbd_base_wrapper(...)       LAYOUT_crkbd_base(__VA_ARGS__)

extern uint8_t is_master;


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAKDHM] = LAYOUT_crkbd_base_wrapper(
        _______________COLEMAQ_DHM_L1______________, _______________COLEMAQ_DHM_R1______________,
        _______________COLEMAQ_DHM_L2______________, _______________COLEMAQ_DHM_R2______________,
        _______________COLEMAQ_DHM_L3______________, _______________COLEMAQ_DHM_R3______________,
        _______________COLEMAQ_DHM_L4______________, _______________COLEMAQ_DHM_R4______________
  ),
  [_NAV] = LAYOUT_crkbd_base_wrapper(
        ________________SNTH_NAV_L1________________, ________________SNTH_NAV_R1________________,
        ________________SNTH_NAV_L2________________, ________________SNTH_NAV_R2________________,
        ________________SNTH_NAV_L3________________, ________________SNTH_NAV_R3________________,
        ________________SNTH_NAV_L4________________, ________________SNTH_NAV_R4________________
  ), 
  [_NUM] = LAYOUT_crkbd_base_wrapper(
        ________________SNTH_NUM_L1________________, ________________SNTH_NUM_R1________________,
        ________________SNTH_NUM_L2________________, ________________SNTH_NUM_R2________________,
        ________________SNTH_NUM_L3________________, ________________SNTH_NUM_R3________________,
        ________________SNTH_NUM_L4________________, ________________SNTH_NUM_R4________________
  ), 
  [_SYM] = LAYOUT_crkbd_base_wrapper(
        ________________SNTH_SYM_L1________________, ________________SNTH_SYM_R1________________,
        ________________SNTH_SYM_L2________________, ________________SNTH_SYM_R2________________,
        ________________SNTH_SYM_L3________________, ________________SNTH_SYM_R3________________,
        ________________SNTH_SYM_L4________________, ________________SNTH_SYM_R4________________
  ), 
  [_NUM2] = LAYOUT_crkbd_base_wrapper(
        ________________SNTH_NUM_L1________________, ________________SNTH_NUM_R1________________,
        ________________SNTH_NUM_L2________________, ________________SNTH_NUM_R2________________,
        ________________SNTH_NUM_L3________________, ________________SNTH_NUM_R3________________,
        ________________SNTH_NUM_L4________________, ________________SNTH_NUM_R4________________
  ),
  [_PAD] = LAYOUT_crkbd_base_wrapper(
        ________________SNTH_PAD_L1________________, ________________SNTH_PAD_R1________________,
        ________________SNTH_PAD_L2________________, ________________SNTH_PAD_R2________________,
        ________________SNTH_PAD_L3________________, ________________SNTH_PAD_R3________________,
        ________________SNTH_PAD_L4________________, ________________SNTH_PAD_R4________________
  ),
  [_UTIL] = LAYOUT_crkbd_base_wrapper(
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

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_master) {
    return OLED_ROTATION_270;
  } else {
    return OLED_ROTATION_180;
  }
}

void render_crkbd_logo(void) {
  static const char PROGMEM crkbd_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0};
  oled_write_P(crkbd_logo, false);
}

void render_status(void) {
  // oled_write_P(PSTR("Layout: "), false);
  switch (get_highest_layer(default_layer_state)) {
    case _COLEMAKDHM:
      oled_write_P(PSTR("CLMK "), false);
      break;
  }

  oled_write_P(PSTR("\n"), false);

  switch (get_highest_layer(layer_state)) {
    case 0:
      oled_write_P(PSTR("     "), false);
      break;
    case _NAV:
      oled_write_P(PSTR("_NAV "), false);
      break;
    case _NUM:
      oled_write_P(PSTR("_NUM  "), false);
      break;
    case _SYM:
      oled_write_P(PSTR("_SYM  "), false);
      break;
    case _UTIL:
      oled_write_P(PSTR("_UTIL"), false);
      break;
    default:
      oled_write_P(PSTR("Unkn "), false);
      break;
  }
  oled_write_P(PSTR("\n"), false);

  uint8_t modifiers = get_mods();

  oled_write_P( (modifiers & MOD_MASK_CTRL)  ? PSTR("CTRL ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_SHIFT) ? PSTR("SHIFT") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_ALT)   ? PSTR("ALT  ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_GUI)   ? PSTR("GUI  ") : PSTR("     "), false);

  oled_write_P(PSTR("\n"), false);

  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(PSTR("Mode:\n"), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK)    ? PSTR(" NUM ") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK)   ? PSTR(" CAPS") : PSTR("     "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR(" SCRL") : PSTR("     "), false);
}

void oled_task_user(void) {
  if (is_master) {
    render_status();     // Renders the current keyboard state (layer, lock, caps, scroll, etc)
  } else {
    render_crkbd_logo();
    // oled_scroll_left();  // Turns on scrolling
  }
}
#endif

#ifdef RGB_MATRIX_ENABLE


void suspend_power_down_keymap(void) {
    rgb_matrix_set_suspend_state(true);
}

void suspend_wakeup_init_keymap(void) {
    rgb_matrix_set_suspend_state(false);
}

#endif
