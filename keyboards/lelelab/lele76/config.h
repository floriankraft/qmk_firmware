// Copyright 2024 Florian Kraft (@Florian Kraft)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID 0xCA21
#define PRODUCT_ID 0x004c
#define DEVICE_VER 0x0390
#define MANUFACTURER "LeleLab"
#define PRODUCT "Lele76"

#define USB_POLLING_INTERVAL_MS 10
#define USB_MAX_POWER_CONSUMPTION 500

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS \
    { A0, A1, A2, A3, A4 }
#define MATRIX_COL_PINS \
    { B0, B1, B2, B3, B4, A5, A6, A7, C7, C6, C5, C4, C3, C2, D7, D4 }
#define UNUSED_PINS \
    { D0, D1, D5, D7 }

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// quantum default is 5, result to a 200Hz rate, fast enough
#define DEBOUNCE 5

#define ENCODERS_PAD_A \
    { B6 }
#define ENCODERS_PAD_B \
    { B5 }

#define ENCODER_RESOLUTION 4

#define OLED_DISPLAY_128X64

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
// #define NO_DEBUG

/* disable print */
// #define NO_PRINT

/* disable action features */
// #define NO_ACTION_LAYER
// #define NO_ACTION_TAPPING
// #define NO_ACTION_ONESHOT