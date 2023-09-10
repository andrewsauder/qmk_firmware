/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once


#ifdef COMBO_ENABLE
#    define COMBO_COUNT 8
#    define COMBO_TERM 50
#endif

/* Disable unused features. */
#define NO_ACTION_ONESHOT

#ifndef TAPPING_TERM
/**
 * \brief Configure the global tapping term (default: 200ms).
 *
 * If you have a lot of accidental mod activations, crank up the tapping term.
 *
 * See docs.qmk.fm/using-qmk/software-features/tap_hold#tapping-term
 */
#    define TAPPING_TERM 200
#endif  // TAPPING_TERM


/* Charybdis-specific features. */

#ifdef POINTING_DEVICE_ENABLE
// Enable pointer acceleration, which increases the speed by ~2x for large
// displacement, while maintaining 1x speed for slow movements.
// - `CHARYBDIS_POINTER_ACCELERATION_FACTOR`
#    define CHARYBDIS_POINTER_ACCELERATION_ENABLE

// Automatically enable the pointer layer when moving the trackball.  See also:
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS`
// - `CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD`
// #define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
#endif  // POINTING_DEVICE_ENABLE

/* RGB Matrix. */

#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_MODS_ENABLE

#    define RGB_DISABLE_WHEN_USB_SUSPENDED

// Limit maximum brightness to keep power consumption reasonable, and avoid
// disconnects.
#    undef RGB_MATRIX_MAXIMUM_BRIGHTNESS
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 50

// Disable control of RGB matrix by keycodes (must use firmware implementation
// to control the feature).
#        define RGB_MATRIX_DISABLE_KEYCODES

// Startup values.
// #    define RGB_MATRIX_DEFAULT_HUE 0
// #    define RGB_MATRIX_DEFAULT_SAT 255
// #    define RGB_MATRIX_DEFAULT_VAL 50

// Rainbow swirl as startup mode.
#    undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT

#    define ENABLE_RGB_MATRIX_SOLID_COLOR
#    undef RGB_MATRIX_DEFAULT_MODE
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#    define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR


// Slow swirl at startup.
//#    define RGB_MATRIX_STARTUP_SPD 32

// Startup values.
#    define RGB_MATRIX_STARTUP_HUE 0
#    define RGB_MATRIX_STARTUP_SAT 255
#    define RGB_MATRIX_STARTUP_VAL 50
#    define RGB_MATRIX_STARTUP_HSV RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL
#endif  // RGB_MATRIX_ENABLE

#ifndef NO_DEBUG
#    define NO_DEBUG
#endif // !NO_DEBUG

#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
#    define NO_PRINT
#endif // !NO_PRINT
