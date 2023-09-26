// Copyright 2023 Conor Burns (@Conor-Burns)
/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H
#include "sendstring_german.h"
#include <stdio.h>

#define RGB_STARTUP_DELAY_MS 200

// clang-format off
enum layer_names {
  _LAYER1,
  _LAYER2,
  _LAYER3,
  _LAYER4,
  _LAYER5,
  _LAYER6
};

enum keycodes {
  // Modifier Keys
  NEO_M2 = SAFE_RANGE,
  NEO_M3,
  NEO_M4,

  // Dead Keys
  NEO_CIRC
};

static bool is_m2_pressed = false;
static bool is_m3_pressed = false;
static bool is_m4_pressed = false;
static bool is_deadkey_waiting = false;
static uint16_t current_deadkey;
static char last_key_pressed[6];

bool handle_modifier_key(void) {
  if (is_m2_pressed && !is_m3_pressed && !is_m4_pressed) {
    layer_on(_LAYER2);
    layer_off(_LAYER3);
    layer_off(_LAYER4);
    layer_off(_LAYER5);
    layer_off(_LAYER6);
  } else if (!is_m2_pressed && is_m3_pressed && !is_m4_pressed) {
    layer_off(_LAYER2);
    layer_on(_LAYER3);
    layer_off(_LAYER4);
    layer_off(_LAYER5);
    layer_off(_LAYER6);
  } else if (!is_m2_pressed && !is_m3_pressed && is_m4_pressed) {
    layer_off(_LAYER2);
    layer_off(_LAYER3);
    layer_on(_LAYER4);
    layer_off(_LAYER5);
    layer_off(_LAYER6);
  } else if (is_m2_pressed && is_m3_pressed && !is_m4_pressed) {
    layer_off(_LAYER2);
    layer_off(_LAYER3);
    layer_off(_LAYER4);
    layer_on(_LAYER5);
    layer_off(_LAYER6);
  } else if (is_m2_pressed && !is_m3_pressed && is_m4_pressed) {
    layer_off(_LAYER2);
    layer_off(_LAYER3);
    layer_off(_LAYER4);
    layer_off(_LAYER5);
    layer_on(_LAYER6);
  } else {
    layer_off(_LAYER2);
    layer_off(_LAYER3);
    layer_off(_LAYER4);
    layer_off(_LAYER5);
    layer_off(_LAYER6);
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Modifier Keys
    case NEO_M2:
      is_m2_pressed = record->event.pressed;
      return handle_modifier_key();
    case NEO_M3:
      is_m3_pressed = record->event.pressed;
      return handle_modifier_key();
    case NEO_M4:
      is_m4_pressed = record->event.pressed;
      return handle_modifier_key();

    // Dead Keys
    case NEO_CIRC:
      current_deadkey = NEO_CIRC;
      is_deadkey_waiting = true;
      return false;
    case DE_A:
      if (is_deadkey_waiting) {
        switch (current_deadkey) {
          case NEO_CIRC:
            send_unicode_string("â");
            current_deadkey = 0;
            is_deadkey_waiting = false;
            return false;
          default:
            return true;
        }
      }

    default:
      snprintf(last_key_pressed, sizeof(last_key_pressed), "%u", keycode);
      return true;
  }
}

///////////////////////////////////////////////////////////////////////////////
// OLED Features (see: https://docs.qmk.fm/#/feature_oled_driver)

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _LAYER1:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("M2 (Shift)\n"), false);
            break;
        case _LAYER3:
            oled_write_P(PSTR("M3 (Special)\n"), false);
            break;
        case _LAYER4:
            oled_write_P(PSTR("M4 (Control)\n"), false);
            break;
        case _LAYER5:
            oled_write_P(PSTR("M5 (Greek)\n"), false);
            break;
        case _LAYER6:
            oled_write_P(PSTR("M6 (Math)\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("Last key: "), false);
    oled_write_ln_P(PSTR(last_key_pressed), false);

    return false;
}
#endif

///////////////////////////////////////////////////////////////////////////////
// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER1] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    XXXXXXX,     XXXXXXX,     NEO_M4,
//├────────────┼────────────╰────────────╯
    NEO_CIRC,    XXXXXXX,     NEO_M3,
//├────────────┼────────────┼────────────┤
    DE_A,        DE_E,        NEO_M2
//└────────────┴────────────┴────────────┘
),
[_LAYER2] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    _______,     _______,     _______,
//├────────────┼────────────╰────────────╯
    _______,     _______,     _______,
//├────────────┼────────────┼────────────┤
    S(DE_A),     S(DE_E),     _______
//└────────────┴────────────┴────────────┘
),
[_LAYER3] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    _______,     _______,     _______,
//├────────────┼────────────╰────────────╯
    _______,     _______,     _______,
//├────────────┼────────────┼────────────┤
    DE_LCBR,     DE_RCBR,     _______
//└────────────┴────────────┴────────────┘
),
[_LAYER4] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    _______,     _______,     _______,
//├────────────┼────────────╰────────────╯
    _______,     _______,     _______,
//├────────────┼────────────┼────────────┤
    KC_DOWN,     KC_RIGHT,    _______
//└────────────┴────────────┴────────────┘
),
[_LAYER5] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    _______,     _______,     _______,
//├────────────┼────────────╰────────────╯
    _______,     _______,     _______,
//├────────────┼────────────┼────────────┤
    UC(0x3B1),    UC(0x3B5),  _______
//└────────────┴────────────┴────────────┘
),
[_LAYER6] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    _______,     _______,     _______,
//├────────────┼────────────╰────────────╯
    _______,     _______,     _______,
//├────────────┼────────────┼────────────┤
    UC(0x2200),  UC(0x2203),  _______
//└────────────┴────────────┴────────────┘
)
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// ???

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_LAYER1] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LAYER2]  = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_LAYER3]  = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
    [_LAYER4]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [_LAYER5]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
    [_LAYER6]  = {ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)},
};
#endif

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_UNDERGLOW) {
                rgb_matrix_set_color(i, RGB_RED);
            }
        }
    }
    return true;
}

uint16_t startup_timer;
