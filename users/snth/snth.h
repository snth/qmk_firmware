/*
Copyright 2020 Tobias Brandt <Tobias.Brandt@gmail.com> @snth
Adapted from @drashna

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once
#include QMK_KEYBOARD_H

/* Define layer names */
enum layer_names {
  _COLEMAKDHM,
  _NUM,
  _SYM,
  _NUM2,
  _PAD,
  _NAV,
  _UTIL
};

/* Define keycodes */
enum custom_keycodes {
    CK_AMPR = KC_F21,
    CK_COLN = SAFE_RANGE,
    CK_UNDS,
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

#define NUM2_ENT LT(_NUM2, KC_ENTER)

#define SYM_SPC LT(_SYM, KC_SPACE)
#define SYM_ENT LT(_SYM, KC_ENTER)
#define SYM_TAB LT(_SYM, KC_TAB)
#define SYM_ESC LT(_SYM, KC_ESC)
#define SYM_BSPC LT(_SYM, KC_BSPC)
#define SYM_DEL LT(_SYM, KC_DEL)
#define T_SYM TT(_SYM)

#define UTL_BSPC LT(_UTIL, KC_BSPC)
#define S_UTIL MO(_UTIL)

// BASE Layer Home row tap and modifier combos
#define LALT_A LALT_T(KC_A)
#define LGUI_R LGUI_T(KC_R)
#define LSFT_S LSFT_T(KC_S)
#define LCTL_Tee LCTL_T(KC_T)

#define RALT_O RALT_T(KC_O)
#define RGUI_I RGUI_T(KC_I)
#define RSFT_E RSFT_T(KC_E)
#define RCTL_N RCTL_T(KC_N)

// NUM layer Home row tap and modifier combos
#define LALT_7 LALT_T(KC_7)
#define LGUI_5 LGUI_T(KC_5)
#define LSFT_3 LSFT_T(KC_3)
#define LCTL_1 LCTL_T(KC_1)

#define RALT_6 RALT_T(KC_6)
#define RGUI_4 RGUI_T(KC_4)
#define RSFT_2 RSFT_T(KC_2)
#define RCTL_0 RCTL_T(KC_0)

// SYM layer Home row tap and modifier combos
// #define LALT_LT LALT_T(KC_LT)
// #define LSFT_GT LSFT_T(KC_GT)
// #define LCTL_LPRN LCTL_T(KC_LPRN)
// #define LGUI_RPRN LGUI_T(KC_RPRN)
// 
// #define RALT_LCBR RALT_T(MT_LCBR)
// #define RSFT_RCBR RSFT_T(MT_RCBR)
// #define RCTL_LBRC RCTL_T(KC_LBRC)
// #define RGUI_RBRC RGUI_T(KC_RBRC)
// 
// #define LSFT_0 LSFT_T(KC_0)

// PAD layer Home row tap and modifier combos
// #define LALT_LT LALT_T(KC_LT)
// #define LSFT_GT LSFT_T(KC_GT)
// #define LCTL_LPRN LCTL_T(KC_LPRN)
// #define LGUI_RPRN LGUI_T(KC_RPRN)

#define RALT_DOT RALT_T(KC_DOT)
#define RSFT_6 RSFT_T(KC_6)
 #define RCTL_5 RCTL_T(KC_5)
 #define RGUI_4 RGUI_T(KC_4)

#define LSFT_0 LSFT_T(KC_0)

// Layer keys with functionality on tap
#define NAV_0 LT(_NAV, KC_0)

// Tap/mod keys
#define CTL_LBR LCTL_T(KC_LBRACKET)
#define CTL_RBR RCTL_T(KC_RBRACKET)
#define CTL_AT  LCTL_T(S(KC_AT))
#define CTL_EQL RCTL_T(KC_EQL)
#define CTL_GRV RCTL_T(KC_GRV)
#define CTL_ESC RCTL_T(KC_ESC)
#define CTL_ENT RCTL_T(KC_ENTER)
#define CTL_TAB RCTL_T(KC_TAB)
#define CTL_DEL RCTL_T(KC_DEL)
#define CTL_BSPC RCTL_T(KC_BSPC)
#define CTL_AMPR RCTL_T(CK_AMPR)
#define CTL_SLSH RCTL_T(KC_SLSH)
#define CTL_BSLS RCTL_T(KC_BSLS)
#define CTL_SCLN RCTL_T(KC_SCLN)
#define CTL_COLN RCTL_T(CK_COLN)	// doesn't work
#define CTL_QUOT RCTL_T(KC_QUOT)

#define SFT_TAB RSFT_T(KC_TAB)
#define SFT_ENT RSFT_T(KC_ENTER)
#define SFT_SPC RSFT_T(KC_SPACE)
#define SFT_BSPC LSFT_T(KC_BSPC)
#define SFT_BSLS RSFT_T(KC_BSLS)
#define SFT_AMPR RSFT_T(KC_AMPR)
#define SFT_ESC RSFT_T(KC_ESC)
#define OSM_SFT OSM(MOD_RSFT)

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

/* Defines Layers */

/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/
#if (!defined(LAYOUT) && defined(KEYMAP))
#    define LAYOUT KEYMAP
#endif

// clang-format off
#define LAYOUT_gergo_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)
#define LAYOUT_crkbd_wrapper(...)            LAYOUT_gergo(__VA_ARGS__)

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/
#define ______________COLEMAQ_DHM_L1_______________       KC_QUOT, KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAQ_DHM_L2_______________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAQ_DHM_L3_______________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define ______________COLEMAQ_DHM_L4_______________                         CTL_ENT, NAV_SPC, SYM_TAB,       

#define ______________COLEMAQ_DHM_R1_______________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_Q
#define ______________COLEMAQ_DHM_R2_______________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAQ_DHM_R3_______________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH
#define ______________COLEMAQ_DHM_R4_______________       NUM_ENT, OSM_SFT, ALT_TAB 


#define _______________SNTH_NAV_L1_________________       KC_AMPR, KC_PERC, KC_HASH, KC_EXLM, KC_WH_U
#define _______________SNTH_NAV_L2_________________       ALT_INS, LGUI_TAB,SFT_BSPC,CTL_DEL, KC_WH_D
#define _______________SNTH_NAV_L3_________________       LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_D),LCTL(KC_V)
#define _______________SNTH_NAV_L4_________________                         CTL_ENT, NAV_SPC, SYM_TAB,       

#define _______________SNTH_NAV_R1_________________       KC_ASTR, KC_HOME, KC_PGUP, KC_PGDN, KC_END
#define _______________SNTH_NAV_R2_________________       KC_EQL,  KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
#define _______________SNTH_NAV_R3_________________       KC_MINS, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R
#define _______________SNTH_NAV_R4_________________       NUM_ENT, OSM_SFT, ALT_TAB 


#define _______________SNTH_NUM_L1_________________       KC_F7,   KC_F5,   KC_F3,   KC_F1,   KC_F9
#define _______________SNTH_NUM_L2_________________       LALT_7,  LGUI_5,  LSFT_3,  LCTL_1,  KC_9
#define _______________SNTH_NUM_L3_________________       LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_D),LCTL(KC_V)
#define _______________SNTH_NUM_L4_________________                         CTL_ENT, NAV_SPC, SYM_TAB,       

#define _______________SNTH_NUM_R1_________________       KC_F8,  KC_F10,   KC_F2,   KC_F4,   KC_F6
#define _______________SNTH_NUM_R2_________________       KC_8,   RCTL_0,   RSFT_2,  RGUI_4,  RALT_6
#define _______________SNTH_NUM_R3_________________       KC_MINS,KC_PLUS,  _______, _______, _______
#define _______________SNTH_NUM_R4_________________       NUM_ENT, OSM_SFT, ALT_TAB 


#define _______________SNTH_SYM_L1_________________       KC_AMPR, KC_PERC, KC_HASH, KC_EXLM, KC_F11
#define _______________SNTH_SYM_L2_________________       KC_LABK, KC_RABK, KC_LPRN, KC_RPRN, KC_QUOT
#define _______________SNTH_SYM_L3_________________       LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),LCTL(KC_D),LCTL(KC_V)
#define _______________SNTH_SYM_L4_________________                         _______, S_UTIL,  _______

#define _______________SNTH_SYM_R1_________________       KC_ASTR, KC_GRV,  KC_AT,   KC_DLR,  KC_CIRC
#define _______________SNTH_SYM_R2_________________       KC_EQL,  KC_RBRC, KC_LBRC, KC_RCBR, KC_LCBR
#define _______________SNTH_SYM_R3_________________       KC_MINS, KC_PLUS, _______, _______, _______
#define _______________SNTH_SYM_R4_________________       NUM2_ENT,SFT_SPC, _______ 


#define _______________SNTH_PAD_L1_________________       KC_QUOT, KC_PIPE, KC_LCBR, KC_RCBR, KC_HASH
#define _______________SNTH_PAD_L2_________________       KC_LT,   KC_GT,   KC_LPRN, KC_RPRN, KC_EXLM
#define _______________SNTH_PAD_L3_________________       KC_PERC, KC_COMM, KC_LBRC, KC_RBRC, KC_CIRC
#define _______________SNTH_PAD_L4_________________                         _______, _______, _______

#define _______________SNTH_PAD_R1_________________       KC_GRV,  KC_7,    KC_8,    KC_9,    KC_PLUS
#define _______________SNTH_PAD_R2_________________       KC_BSLS, RGUI_4,  RCTL_5,  RSFT_6,  RALT_DOT
#define _______________SNTH_PAD_R3_________________       KC_DLR,  KC_1,    KC_2,    KC_3,    KC_SLSH
#define _______________SNTH_PAD_R4_________________       CTL_ENT, LSFT_0,  T_SYM


#define _______________SNTH_UTL_L1_________________       RESET,   KC_MSTP, KC_VOLU, KC_MPLY, KC_CAPS
#define _______________SNTH_UTL_L2_________________       XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,                      
#define _______________SNTH_UTL_L3_________________       KC_SLEP, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,                      
#define _______________SNTH_UTL_L4_________________                         _______, _______, _______,    

#define _______________SNTH_UTL_R1_________________       COLEMAK, RGB_TOG, XXXXXXX, RESET, EEP_RST,\
#define _______________SNTH_UTL_R2_________________       RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,\
#define _______________SNTH_UTL_R3_________________       RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,\
#define _______________SNTH_UTL_R4_________________       _______, _______, _______ \


#define _________________QWERTY_L1_________________        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________        KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________COLEMAK_L1________________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_G
#define _________________COLEMAK_L2________________       KC_A,    KC_R,    KC_S,    KC_T,    KC_D
#define _________________COLEMAK_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________COLEMAK_R1________________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _________________COLEMAK_R2________________       KC_H,    KC_N,    KC_E,    KC_I,    KC_O
#define _________________COLEMAK_R3________________       KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________DVORAK_L1_________________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define _________________DVORAK_L2_________________        KC_A,    KC_O,    KC_E,   KC_U,     KC_I
#define _________________DVORAK_L3_________________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define _________________DVORAK_R1_________________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define _________________DVORAK_R2_________________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define _________________DVORAK_R3_________________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z


#define ________________DVORAK_AU_L1_______________        KC_QUOT, KC_COMM, KC_DOT, KC_P,     KC_Y
#define ________________DVORAK_AU_L2_______________        KC_O,    KC_A,    KC_E,   KC_I,     KC_U
#define ________________DVORAK_AU_L3_______________        KC_SCLN, KC_Q,    KC_J,   KC_K,     KC_X

#define ________________DVORAK_AU_R1_______________        KC_F,    KC_G,    KC_C,    KC_R,    KC_L
#define ________________DVORAK_AU_R2_______________        KC_D,    KC_H,    KC_T,    KC_N,    KC_S
#define ________________DVORAK_AU_R3_______________        KC_B,    KC_M,    KC_W,    KC_V,    KC_Z

#define _________________WORKMAN_L1________________       KC_Q,    KC_D,    KC_R,   KC_W,     KC_B
#define _________________WORKMAN_L2________________       KC_A,    KC_S,    KC_H,   KC_T,     KC_G
#define _________________WORKMAN_L3________________       KC_Z,    KC_X,    KC_M,   KC_C,     KC_V

#define _________________WORKMAN_R1________________       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN
#define _________________WORKMAN_R2________________       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I
#define _________________WORKMAN_R3________________       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________NORMAN_L1_________________       KC_Q,    KC_W,    KC_D,    KC_F,    KC_K
#define _________________NORMAN_L2_________________       KC_A,    KC_S,    KC_E,    KC_T,    KC_G
#define _________________NORMAN_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________NORMAN_R1_________________       KC_J,    KC_U,    KC_R,    KC_L,    KC_SCLN
#define _________________NORMAN_R2_________________       KC_Y,    KC_N,    KC_I,    KC_O,    KC_U
#define _________________NORMAN_R3_________________       KC_P,    KC_M,    KC_COMM, KC_DOT,  KC_SLASH


#define _________________MALTRON_L1________________       KC_Q,    KC_P,    KC_Y,    KC_C,    KC_B
#define _________________MALTRON_L2________________       KC_A,    KC_N,    KC_I,    KC_S,    KC_F
#define _________________MALTRON_L3________________       KC_SCLN, KC_SLSH, KC_J,    KC_G,    KC_COMM

#define _________________MALTRON_R1________________       KC_V,    KC_M,    KC_U,    KC_Z,    KC_L
#define _________________MALTRON_R2________________       KC_D,    KC_T,    KC_D,    KC_O,    KC_R
#define _________________MALTRON_R3________________       KC_DOT,  KC_W,    KC_K,    KC_MINS, KC_X


#define _________________EUCALYN_L1________________       KC_SLSH, KC_COMM, KC_DOT,  KC_F,    KC_Q
#define _________________EUCALYN_L2________________       KC_A,    KC_O,    KC_E,    KC_I,    KC_U
#define _________________EUCALYN_L3________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_W

#define _________________EUCALYN_R1________________       KC_M,    KC_R,    KC_D,    KC_Y,    KC_P
#define _________________EUCALYN_R2________________       KC_G,    KC_T,    KC_K,    KC_S,    KC_N
#define _________________EUCALYN_R3________________       KC_B,    KC_H,    KC_J,    KC_L,    KC_SCLN


#define _____________CARPLAX_QFMLWY_L1_____________       KC_Q,    KC_F,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QFMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QFMLWY_L3_____________       KC_Z,    KC_V,    KC_G,    KC_C,    KC_X

#define _____________CARPLAX_QFMLWY_R1_____________       KC_Y,    KC_U,    KC_O,    KC_B,    KC_J
#define _____________CARPLAX_QFMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_H,    KC_SCLN
#define _____________CARPLAX_QFMLWY_R3_____________       KC_P,    KC_K,    KC_COMM, KC_DOT,  KC_SLSH


#define _____________CARPLAX_QGMLWB_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWB_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWB_L3_____________       KC_Z,   KC_X,    KC_C,    KC_F,    KC_J

#define _____________CARPLAX_QGMLWB_R1_____________       KC_B,    KC_Y,    KC_U,    KC_V,    KC_SCLN
#define _____________CARPLAX_QGMLWB_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _____________CARPLAX_QGMLWB_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define _____________CARPLAX_QGMLWY_L1_____________       KC_Q,    KC_G,    KC_M,    KC_L,    KC_W
#define _____________CARPLAX_QGMLWY_L2_____________       KC_D,    KC_S,    KC_T,    KC_N,    KC_R
#define _____________CARPLAX_QGMLWY_L3_____________       KC_Z,   KC_X,    KC_C,    KC_V,    KC_J

#define _____________CARPLAX_QGMLWY_R1_____________       KC_Y,    KC_F,    KC_U,    KC_B,    KC_SCLN
#define _____________CARPLAX_QGMLWY_R2_____________       KC_I,    KC_A,    KC_E,    KC_O,    KC_H
#define _____________CARPLAX_QGMLWY_R3_____________       KC_K,    KC_P,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________WHITE_R1__________________       KC_V,    KC_Y,    KC_D,    KC_COMM, KC_QUOT
#define _________________WHITE_R2__________________       KC_A,    KC_T,    KC_H,    KC_E,    KC_B
#define _________________WHITE_R3__________________       KC_P,    KC_K,    KC_G,    KC_W,    KC_Q

#define _________________WHITE_L1__________________       KC_INT1, KC_J,    KC_M,    KC_L,    KC_U
#define _________________WHITE_L2__________________       KC_MINS, KC_C,    KC_S,    KC_N,    KC_O  // KC_I
#define _________________WHITE_L3__________________       KC_X,    KC_R,    KC_F,    KC_DOT,  KC_Z


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________        _______, _______, _______, _______, _______


#define _________________LOWER_L1__________________        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________        _________________FUNC_LEFT_________________
#define _________________LOWER_L3__________________        _________________FUNC_RIGHT________________

#define _________________LOWER_R1__________________        KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN
#define _________________LOWER_R2__________________        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR
#define _________________LOWER_R3__________________        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT



#define _________________RAISE_L1__________________        ________________NUMBER_LEFT________________
#define _________________RAISE_L2__________________        ___________________BLANK___________________
#define _________________RAISE_L3__________________        ___________________BLANK___________________

#define _________________RAISE_R1__________________        ________________NUMBER_RIGHT_______________
#define _________________RAISE_R2__________________        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC
#define _________________RAISE_R3__________________        _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END



#define _________________ADJUST_L1_________________        RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, RGB_TOG
#define _________________ADJUST_L2_________________        MU_TOG , CK_TOGG, AU_ON,   AU_OFF,  CG_NORM
#define _________________ADJUST_L3_________________        RGB_RMOD,RGB_HUD,RGB_SAD, RGB_VAD, KC_RGB_T

#define _________________ADJUST_R1_________________        KC_SEC1, KC_SEC2, KC_SEC3, KC_SEC4, KC_SEC5
#define _________________ADJUST_R2_________________        CG_SWAP, QWERTY,  COLEMAK, DVORAK,  WORKMAN
#define _________________ADJUST_R3_________________        MG_NKRO, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT

// clang-format on
