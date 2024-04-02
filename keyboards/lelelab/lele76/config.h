#pragma once

#define USB_POLLING_INTERVAL_MS 10
#define USB_MAX_POWER_CONSUMPTION 500

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
// quantum default is 5, result to a 200Hz rate, fast enough
#define DEBOUNCE 5

#define OLED_DISPLAY_128X64
