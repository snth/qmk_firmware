/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// #define USE_SERIAL_PD2

// Tap-hold configuration
#ifdef IGNORE_MOD_TAP_INTERRUPT
    #undef IGNORE_MOD_TAP_INTERRUPT
#endif
#define IGNORE_MOD_TAP_INTERRUPT

#ifdef TAPPING_TERM
    #undef TAPPING_TERM
#endif
#define TAPPING_TERM 200

#ifdef TAPPING_TOGGLE
    #undef TAPPING_TOGGLE
#endif
#define TAPPING_TOGGLE 2
// #define TAPPING_FORCE_HOLD   // incompatible with TAPPING_TOGGLE

// One-shot configuration
#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT  500  /* Time (in ms) before the one shot key is released */
