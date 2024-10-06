#include QMK_KEYBOARD_H

enum layer_names {
    _LAYER1,
    _LAYER2,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Parameters of different LAYOUT functions are defined in info.json at "layouts.<LAYOUTNAME>.layout".
    // One line like this
    //          { "label": "↻", "matrix": [0, 0], "x": 0, "y": 0 }
    // represents one keycode here.
    // The order of parameters is very important as each keycode will be mapped to the given matrix coordinates.
    [_LAYER1] = LAYOUT(
        KC_NO,
        KC_ESC,KC_GRAVE,KC_1,KC_2,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_BSPC,KC_PGUP,
        KC_ESC,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_PGDN,
        KC_ESC,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_HOME,
        KC_ESC,MO(_LAYER2),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSFT,KC_UP,KC_END,
        KC_ESC,KC_LCTL,KC_LCMD,KC_LALT,KC_SPACE,KC_RCTL,KC_RCMD,KC_LEFT,KC_DOWN,KC_RIGHT
    ),
    [_LAYER2] = LAYOUT(
        KC_NO,
        KC_ESC,KC_GRAVE,KC_2,KC_1,KC_3,KC_4,KC_5,KC_6,KC_7,KC_8,KC_9,KC_0,KC_MINUS,KC_EQUAL,KC_BSPC,KC_PGUP,
        KC_ESC,KC_TAB,KC_Q,KC_W,KC_E,KC_R,KC_T,KC_Y,KC_U,KC_I,KC_O,KC_P,KC_LBRC,KC_RBRC,KC_BSLS,KC_PGDN,
        KC_ESC,KC_CAPS,KC_A,KC_S,KC_D,KC_F,KC_G,KC_H,KC_J,KC_K,KC_L,KC_SCLN,KC_QUOT,KC_ENT,KC_HOME,
        KC_ESC,MO(_LAYER2),KC_Z,KC_X,KC_C,KC_V,KC_B,KC_N,KC_M,KC_COMMA,KC_DOT,KC_SLASH,KC_RSFT,KC_UP,KC_END,
        KC_ESC,KC_LCTL,KC_LCMD,KC_LALT,KC_SPACE,KC_RCTL,KC_RCMD,KC_LEFT,KC_DOWN,KC_RIGHT
    )
};
// clang-format on

#ifdef OLED_ENABLE

// Display seems to be a 64x128 mounted horizontally.
// I didn't find a better way than just rotating it by 90 degrees.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

// Print the name of the current layer and the LED states of the keyboard.
bool oled_task_user() {
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _LAYER1:
            oled_write_P(PSTR("Layer 1\n"), false);
            break;
        case _LAYER2:
            oled_write_P(PSTR("Layer 2\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);

    return false;
}
#endif