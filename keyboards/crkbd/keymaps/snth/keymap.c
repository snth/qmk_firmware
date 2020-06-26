#include QMK_KEYBOARD_H

extern uint8_t is_master;

enum layer_names {
  _COLEMAKDHM,
  _NUM,
  _SYM,
  _NAV,
  _UTIL
};

// Base layers
#define COLEMAK DF(_COLEMAKDHM)

// Layer toggle and switch
#define NAV_SPC LT(_NAV, KC_SPACE)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define NAV_ESC LT(_NAV, KC_ESC)
#define NAV_TAB LT(_NAV, KC_TAB)
#define T_NAV TT(_NAV)
#define S_NAV MO(_NAV)

#define NUM_BSPC LT(_NUM, KC_BSPC)
#define NUM_SPC LT(_NUM, KC_SPACE)
#define NUM_ENT LT(_NUM, KC_ENTER)
#define NUM_ESC LT(_NUM, KC_ESC)
#define NUM_ALT LT(_NUM, KC_LALT)
#define NUM_DEL LT(_NUM, KC_DEL)
#define NUM_TAB LT(_NUM, KC_TAB)
#define T_NUM TT(_NUM)
#define S_NUM MO(_NUM)

#define SYM_SPC LT(_SYM, KC_SPACE)
#define SYM_ENT LT(_SYM, KC_ENTER)
#define SYM_TAB LT(_SYM, KC_TAB)
#define SYM_ESC LT(_SYM, KC_ESC)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#define SYM_DEL LT(_SYM, KC_DEL)
#define T_SYM TT(_SYM)

#define UTL_BSPC LT(_UTIL, KC_BSPC)
#define S_UTIL MO(_UTIL)

// Home row tap and modifier combos
#define LALT_A LALT_T(KC_A)
#define LGUI_R LGUI_T(KC_R)
#define LSFT_S LSFT_T(KC_S)
#define LCTL_Tee LCTL_T(KC_T)

#define RALT_O RALT_T(KC_O)
#define RGUI_I RGUI_T(KC_I)
#define RSFT_E RSFT_T(KC_E)
#define RCTL_N RCTL_T(KC_N)

// NUM layr Home row tap and modifier combos
#define LALT_7 LALT_T(KC_7)
#define LSFT_5 LSFT_T(KC_5)
#define LCTL_3 LCTL_T(KC_3)
#define LGUI_1 LGUI_T(KC_1)

#define RALT_6 RALT_T(KC_6)
#define RSFT_4 RSFT_T(KC_4)
#define RCTL_2 RCTL_T(KC_2)
#define RGUI_0 RGUI_T(KC_0)

// Layer keys with functionality on tap
#define NAV_0 LT(_NAV, KC_0)

// Tap/mod keys
#define CTL_LBR LCTL_T(KC_LBRACKET)
#define CTL_RBR RCTL_T(KC_RBRACKET)
#define CTL_AT  LCTL_T(S(KC_AT))
#define CTL_EQL RCTL_T(KC_EQL)
#define CTL_ESC RCTL_T(KC_ESC)
#define CTL_ENT RCTL_T(KC_ENTER)
#define CTL_TAB RCTL_T(KC_TAB)
#define CTL_DEL RCTL_T(KC_DEL)
#define CTL_BSPC RCTL_T(KC_BSPC)
#define CTL_AMPR RCTL_T(KC_AMPR)
#define CTL_SLSH RCTL_T(KC_SLSH)
#define CTL_BSLS RCTL_T(KC_BSLS)
#define CTL_SCLN RCTL_T(KC_SCLN)

#define SFT_TAB RSFT_T(KC_TAB)
#define SFT_ENT RSFT_T(KC_ENTER)
#define SFT_SPC RSFT_T(KC_SPACE)
#define SFT_BSPC LSFT_T(KC_BSPC)
#define SFT_ESC RSFT_T(KC_ESC)
#define SFT_OS OSM(MOD_LSFT)

#define ALT_SPC LALT_T(KC_SPACE)
#define ALT_ENT LALT_T(KC_ENTER)
#define ALT_TAB LALT_T(KC_TAB)
#define ALT_ESC LALT_T(KC_ESC)
#define ALT_INS LALT_T(KC_INS)
#define ALT_DEL LALT_T(KC_DEL)
#define ALT_BSPC LALT_T(KC_BSPC)

#define LGUI_BSPC LGUI_T(KC_BSPC)
#define LGUI_ESC LGUI_T(KC_ESC)
#define LGUI_TAB LGUI_T(KC_TAB)
#define RGUI_MINS RGUI_T(KC_MINS)
#define RGUI_TAB RGUI_T(KC_TAB)

// Global tab forward and backward
#define TBFWD LCTL(KC_TAB)
#define TBBCK LCTL(LSFT(KC_TAB))

// Custom key for NUM layer
#define CTEQL RCTL_T(KC_EQL)

// €
#define KC_EUR ALGR(KC_5)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Nav Layer (based on Extend)
 *
 * ,------,----------------------------------.           ,----------------------------------.------.
 * |      |      | WH U | MS L | MS R | MS U |           | BTN2 | HOME |  UP  | END  | INS  |      |
 * |------|------+------+------+------+------|           |------+------+------+------+------|------|
 * |      | ALT  | WH D | SFT  | CTL  | MS D |           | BTN1 | LEFT | DOWN | RIGHT| DEL  |      |
 * |------|------+------+------+------+------|           |------+------+------+------+------|------|
 * |      |      |      |      | BTN1 | BTN2 |           | BSPC | PG UP| PG DN| ACL2?| BSPC |      |
 * `------`----------------------------------'           `----------------------------------'------'
 *                         ,--------------------.    ,--------------------.
 *                         |      |      |      |    |      |      |      |
 *                         `------+------|      |    |      |------+------'
 *                                       |      |    |      |
 *                                       `------'    `------'
 */
/* Colemak DHm
 *
 * ,------,----------------------------------.           ,----------------------------------.------.
 * | TAB  |   '  |   W  |   F  |   P  |   B  |           |   J  |   L  |   U  |   Y  |   Q  |   /  |
 * |------|------+------+------+------+------|           |------+------+------+------+------|------|
 * | BSPC | ALT/A| GUI/R| SFT/S| CTL/T|   G  |           |   M  | CTL/N| SFT/E| GUI/I| ALT/O|   -  |
 * |------|------+------+------+------+------|           |------+------+------+------+------|------|
 * | CTL/[| SYS/Z|   X  |   C  |   D  |   V  |           |   K  |   H  |   ,  |   .  |   ;  | CTL/]|
 * `------`----------------------------------'           `----------------------------------'------'
 *                         ,--------------------.    ,--------------------.
 *                         | NAV  |SFT/SP|      |    |      |SFT/EN| NUM  |
 *                         `------+------|ALT/  |    |GUI/  |------+------'
 *                                       |  ESC |    | BSPC |
 *                                       `------'    `------'
 */
  [_COLEMAKDHM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_AMPR, KC_QUOT,    KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_Q,  KC_EQL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_COLN,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                         KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CTL_BSLS,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH,CTL_SCLN,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ALT_TAB, NAV_SPC, SYM_BSPC,    NUM_ENT, SFT_OS, ALT_DEL \
                                      //`--------------------------'  `--------------------------'
  ),
  [_NAV] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_MS_U,  KC_GRV,LCTL(KC_W),KC_ESC,  KC_ENT, KC_HASH,                      KC_BTN1, KC_MS_L,   KC_UP, KC_MS_D, KC_MS_R, KC_BTN2,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_AT, ALT_INS,SFT_BSPC, CTL_DEL,LGUI_TAB, KC_EXLM,                      KC_WH_U, KC_LEFT, KC_DOWN, KC_RGHT, KC_RGHT, KC_EXLM,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_DOT,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),KC_SPC,LCTL(KC_V),                  KC_WH_D, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, KC_ASTR,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+---------|
                                          _______, _______, _______,    _______, SFT_ESC, _______ \
                                      //`--------------------------'  `--------------------------'
  ), 
  [_NUM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_F11,   KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9,                        KC_F8,  KC_F10,   KC_F2,   KC_F4,   KC_F6,  KC_F12,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  LALT_7,  LSFT_5,  LCTL_3,  LGUI_1,    KC_9,                         KC_8,  RGUI_0,  RCTL_2,  RSFT_4,  RALT_6, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_DOT, KC_PERC, KC_LCBR, KC_LPRN, KC_LBRC, KC_CIRC,                       KC_DLR, KC_RBRC, KC_RPRN, KC_RCBR, KC_SLSH, KC_ASTR, \
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, SFT_SPC,   T_NUM \
                                      //`--------------------------'  `--------------------------'
  ), 
  [_SYM] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_QUOT, KC_PIPE, KC_LCBR, KC_RCBR, KC_HASH,                       KC_GRV,    KC_7,    KC_8,    KC_9, KC_PLUS, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_LT,   KC_GT, KC_LPRN, KC_RPRN, KC_EXLM,                      KC_BSLS,    KC_4,    KC_5,    KC_6,  KC_DOT, _______,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       S_UTIL, KC_PERC, KC_COMM, KC_LBRC, KC_RBRC, KC_CIRC,                       KC_DLR,    KC_1,    KC_2,    KC_3, KC_SLSH, KC_ASTR,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            T_SYM, _______, _______,    CTL_ENT,    KC_0,   T_SYM \
                                      //`--------------------------'  `--------------------------'
  ),


  [_UTIL] = LAYOUT( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      EEP_RST,   RESET, KC_MSTP, KC_VOLU, KC_MPLY, XXXXXXX,                      COLEMAK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                      XXXXXXX, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XXXXXXX, KC_SLEP, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      RGB_TOG,RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______ \
                                      //`--------------------------'  `--------------------------'
  )
};

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

  oled_write_P( (modifiers & MOD_MASK_CTRL)  ? PSTR("PROG ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_SHIFT) ? PSTR("PULSE") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_ALT)   ? PSTR("STBY ") : PSTR("     "), false);
  oled_write_P( (modifiers & MOD_MASK_GUI)   ? PSTR("GYRO ") : PSTR("     "), false);

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
