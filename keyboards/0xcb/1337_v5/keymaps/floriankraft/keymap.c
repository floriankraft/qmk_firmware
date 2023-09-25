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
    case NEO_M2:
      is_m2_pressed = record->event.pressed;
      return handle_modifier_key();
    case NEO_M3:
      is_m3_pressed = record->event.pressed;
      return handle_modifier_key();
    case NEO_M4:
      is_m4_pressed = record->event.pressed;
      return handle_modifier_key();
    default:
      snprintf(last_key_pressed, sizeof(last_key_pressed), "%u", keycode);
      return true;
  }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_LAYER1] = LAYOUT(
//┌────────────┬────────────╭────────────╮
    UC_PREV,     UC_NEXT,     NEO_M4,
//├────────────┼────────────╰────────────╯
    KC_PGUP,     KC_PGDN,     NEO_M3,
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

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     startup_timer = timer_read();
//     return rotation;
// }
// static void render_logo(void) {
//     static const char PROGMEM raw_logo[] = {
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,192,192, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,  0,192,192,  0,  0,  0,  0,  0,  0,192,192,  0,  0,  0,  0,  0,  0,192,192,240,240, 48, 48, 48, 48,240,240,192,192,  0,  0,  0,  0,240,240, 48, 48, 48, 48,240,240,192,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,  0,  0,  0,  2,  5,  8,  5,  2,  2,  2,  2,  2,  2,254,  0,  0,  0,  0,  0,  0,  0,  0,  0,254,  2,  2,  2,  2,  2,  2,  5,  8,  5,  2,  0,  0,  0,  0,  0,  0,128,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  3,  3,  0,  0,252,252,  0,  0,  3,  3,255,255,  0,  0,  0,  0,  3,  3, 12, 12,240,240, 12, 12,  3,  3,  0,  0,  0,  0,255,255,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255, 48, 48, 48, 48, 48, 48,207,207,  0,  0,  0,  0,  0,  0,  0,  0,  0,  2,  5,248,  5,  2,  0,  0,  0,  0,  0,  0,  0,128,192,192,224,224,112,112, 63, 56, 28, 28, 28,252, 28, 28, 28, 56, 63,112,112,224,224,192,192,128,  0,  0,  0,  0,  0,  0,  0,  2,  5,248,  5,  2,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3, 15, 15, 48, 48, 48, 48, 48, 48, 15, 15,  3,  3,  0,  0,  0,  0, 60, 60,  3,  3,  0,  0,  3,  3, 60, 60,  0,  0,  0,  0,  3,  3, 15, 15, 60, 60, 48, 48, 48, 48, 60, 60, 12, 12,  0,  0,  0,  0, 63, 63, 48, 48, 48, 48, 60, 60, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,160, 19,162, 66, 66, 66, 66, 66, 66, 66,255,255,255,  1,  0,  0,248,252,252,128,128,128,128,255,  0,  0,  0,124,124,120,120,  0,  0,  1,255,255,255, 66, 66, 66, 66, 66, 66, 66,162, 19,160, 64,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0, 60, 60, 12, 12,252,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 60, 60, 12, 12, 12, 12, 60, 60,240,240,  0,  0,  0,  0,  0,  0, 48, 48, 60, 60, 12, 12, 12, 12, 60, 60,240,240,  0,  0,  0,  0, 12, 12, 12, 12, 12, 12,204,204,252,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,249,  8,  8,  8,  8,  8,  8,  8,  8,255,255,255,128,  0,  0, 31, 63, 63,  1,  1,  1,  1,255,  0,  0,  0, 62, 62, 30, 30,  0,  0,128,255,255,255,  8,  8,  8,  8,  8,  8,  8,  8,249,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 12, 12, 12, 63, 63,243,243,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 12, 12, 12, 63, 63,243,243,  0,  0,  0,  0,  0,  0,  0,  0,255,255,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  4, 10, 17, 10,  4,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7, 14, 14,252, 60, 56, 56, 56,255, 56, 56, 56, 28,252, 14, 14,  7,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  4, 10, 17, 10,  4,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 12, 12, 12, 15, 15, 12, 12, 12, 12,  0,  0,  0,  0,  0,  0,  3,  3, 15, 15, 12, 12, 12, 12, 15, 15,  3,  3,  0,  0,  0,  0,  0,  0,  3,  3, 15, 15, 12, 12, 12, 12, 15, 15,  3,  3,  0,  0,  0,  0,  0,  0,  0,  0, 15, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 64,160, 16,160, 64, 64, 64, 64, 64, 64,127,  0,  0, 64,160, 31,160, 64,  0,  0,127, 64, 64, 64, 64, 64, 64,160, 16,160, 64,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//         0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//     };
//     oled_write_raw_P(raw_logo, sizeof(raw_logo));
// }

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
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

    // Host Keyboard LED Status
    // led_t led_state = host_keyboard_led_state();
    // oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    // oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    // oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif

/* Shows the name of the current layer and locks for the host (CAPS etc.) */
// bool oled_task_user(void) {
//     static bool finished_timer = false;
//         if (!finished_timer && (timer_elapsed(startup_timer) < 2000)) {
//         render_logo();
//     } else {
//             if (!finished_timer) {
//             oled_clear();
//             finished_timer = true;
//         }
//     led_t led_state = host_keyboard_led_state();
//     // clang-format off
//     static const char PROGMEM logo[8][3][9] = {
//         {{0x97, 0x98, 0x99, 0x9A, 0}, {0x91, 0x92, 0x93, 0x94, 0x95, 0x96, 0}, {0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0}},              /* L      num      CB */
//         {{0xB7, 0xB8, 0xB9, 0xBA, 0}, {0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0}, {0xBB, 0xBC, 0xBD, 0xBE, 0xBF, 0}},              /* 1      num      CB */
//         {{0xD7, 0xD8, 0xD9, 0xDA, 0}, {0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0}, {0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0}},              /* 1      cap      CB */
//         {{0xC6, 0xC7, 0xC8, 0xC9, 0}, {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0}, {0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0}},              /* L      cap      CB */
//         {{0xB7, 0x88, 0x89, 0xBA, 0}, {0xB7, 0x8A, 0x8B, 0xBA, 0},             {0xB7, 0x8C, 0x8D, 0xBA, 0}},                    /* 2       3       4  */
//         {{0xD7, 0xA8, 0xA9, 0xDA, 0}, {0xD7, 0xAA, 0xAB, 0xDA, 0},             {0xD7, 0xAC, 0xAD, 0xDA, 0}},                    /* 2       3       4  */
//         {{0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0},             {0xB8, 0xB9, 0x8A, 0x8B, 0x8A, 0x8B, 0x8E, 0x8F, 0}}, /* 0xcb    1337       */
//         {{0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0},             {0xD8, 0xD9, 0xAA, 0xAB, 0xAA, 0xAB, 0xAE, 0xAF, 0}}, /* 0xcb    1337       */

//     };
//     // clang-format on
//     oled_set_cursor(0, 0);
//     oled_write_P(logo[0][0], false);
//     oled_set_cursor(0, 3);
//     oled_write_P(logo[3][0], false);
//     switch (get_highest_layer(layer_state)) {
//         case _LAYER1:
//             oled_set_cursor(0, 1);
//             oled_write_P(logo[1][0], false);
//             oled_set_cursor(0, 2);
//             oled_write_P(logo[2][0], false);
//             break;
//         case _LAYER2:
//             oled_set_cursor(0, 1);
//             oled_write_P(logo[4][0], false);
//             oled_set_cursor(0, 2);
//             oled_write_P(logo[5][0], false);
//             break;
//         case _LAYER3:
//             oled_set_cursor(0, 1);
//             oled_write_P(logo[4][1], false);
//             oled_set_cursor(0, 2);
//             oled_write_P(logo[5][1], false);
//             break;
//         case _LAYER4:
//             oled_set_cursor(0, 1);
//             oled_write_P(logo[4][2], false);
//             oled_set_cursor(0, 2);
//             oled_write_P(logo[5][2], false);
//             break;
//         default:
//             oled_set_cursor(0, 1);
//             oled_write_P(PSTR("    "), false);
//             oled_set_cursor(0, 2);
//             oled_write_P(PSTR("    "), false);
//     }
//     oled_set_cursor(8, 0);
//     oled_write_P(led_state.num_lock ? logo[0][1] : PSTR("      "), false);
//     oled_set_cursor(8, 1);
//     oled_write_P(led_state.num_lock ? logo[1][1] : PSTR("      "), false);
//     oled_set_cursor(8, 2);
//     oled_write_P(led_state.caps_lock ? logo[2][1] : PSTR("      "), false);
//     oled_set_cursor(8, 3);
//     oled_write_P(led_state.caps_lock ? logo[3][1] : PSTR("      "), false);

//     oled_set_cursor(16, 0);
//     oled_write_P(logo[0][2], false);
//     oled_set_cursor(16, 1);
//     oled_write_P(logo[1][2], false);
//     oled_set_cursor(16, 2);
//     oled_write_P(logo[2][2], false);
//     oled_set_cursor(16, 3);
//     oled_write_P(logo[3][2], false);

//     /* 0xCB 1337 */
//     oled_set_cursor(0, 6);
//     oled_write_P(logo[6][0], false);
//     oled_set_cursor(0, 7);
//     oled_write_P(logo[7][0], false);

//     oled_set_cursor(13, 6);
//     oled_write_P(logo[6][1], false);
//     oled_set_cursor(13, 7);
//     oled_write_P(logo[7][1], false);
//     }
//     return false;
// }
