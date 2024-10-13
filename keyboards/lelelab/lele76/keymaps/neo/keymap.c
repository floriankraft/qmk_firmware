#include QMK_KEYBOARD_H
#include "sendstring_german.h"
#include "stdio.h"

enum layer_names { _LAYER1, _LAYER2, _LAYER3, _LAYER4 };
// clang-format off
enum keycodes {
    NEO_M2 = SAFE_RANGE, NEO_M3, NEO_M4,
    NEO_GRV, NEO_BTK
};
// clang-format on

static bool is_m2_pressed = false;
static bool is_m3_pressed = false;
static bool is_m4_pressed = false;
static char last_key_pressed[7];

bool handle_modifier_key(void) {
    if (is_m2_pressed && !is_m3_pressed && !is_m4_pressed) {
        layer_on(_LAYER2);
        layer_off(_LAYER3);
        layer_off(_LAYER4);
    } else if (!is_m2_pressed && is_m3_pressed && !is_m4_pressed) {
        layer_off(_LAYER2);
        layer_on(_LAYER3);
        layer_off(_LAYER4);
    } else if (!is_m2_pressed && !is_m3_pressed && is_m4_pressed) {
        layer_off(_LAYER2);
        layer_off(_LAYER3);
        layer_on(_LAYER4);
    } else {
        layer_off(_LAYER2);
        layer_off(_LAYER3);
        layer_off(_LAYER4);
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
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

        case NEO_GRV:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;
        case NEO_BTK:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            return false;

        default:
            snprintf(last_key_pressed, sizeof(last_key_pressed), "0x%04X", keycode);
            return true;
    }
}

///////////////////////////////////////////////////////////////////////////////
// Keymap

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
// Parameters of different LAYOUT functions are defined in info.json at "layouts.<LAYOUTNAME>.layout".
// One line like this
//          { "label": "↻", "matrix": [0, 0], "x": 0, "y": 0 }
// represents one keycode here.
// The order of parameters is very important as each keycode will be mapped to the given matrix coordinates.

[_LAYER1] = LAYOUT(
//╔═══════╗
   KC_MUTE,
//╠═══════╣╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═════════════════╦═══════╗
   KC_ESC,  DE_CIRC, DE_1,   DE_2,   DE_3,   DE_4,   DE_5,   DE_6,   DE_7,   DE_8,   DE_9,   DE_0,  DE_MINS, DE_GRV,     KC_BSPC,     KC_DEL,
//╠═══════╣╠═══════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═════════════╬═══════╣
   KC_PSCR,    KC_TAB,    DE_X,   DE_V,   DE_L,   DE_C,   DE_W,   DE_K,   DE_H,   DE_G,   DE_F,   DE_Q,   DE_SS, DE_ACUT, MO(_LAYER3),C(LSFT(DE_M)),
//╠═══════╣╠═══════════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═════════════╬═══════╣
   KC_HOME,  MO(_LAYER3),  DE_U,   DE_I,   DE_A,   DE_E,   DE_O,   DE_S,   DE_N,   DE_R,   DE_T,   DE_D,   DE_Y,        KC_ENT,       KC_PGUP,
//╠═══════╣╠═════════════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══════════╦═══════╬═══════╣
   KC_END,    MO(_LAYER2),   DE_UDIA,DE_ODIA,DE_ADIA, DE_P,   DE_Z,   DE_B,   DE_M,  DE_COMM,DE_DOT,  DE_J,     MO(_LAYER2),   KC_UP, KC_PGDN,
//╠═══════╣╠═══════╦═══════╦═╩═════╦═╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═════╦═╩═══════╩═╦═════╩═══════╦═══════╬═══════╬═══════╣
MO(_LAYER4),KC_LCTL,KC_LCMD,KC_LALT,                       KC_SPACE,                        MO(_LAYER4),   KC_RCTL,   KC_LEFT,KC_DOWN,KC_RGHT
//╚═══════╝╚═══════╩═══════╩═══════╩═══════════════════════════════════════════════════════╩═══════════╩═════════════╩═══════╩═══════╩═══════╝
),

[_LAYER2] = LAYOUT(
//╔═══════╗
   _______,
//╠═══════╣╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═════════════════╦═══════╗
   _______,  KC_NO, DE_DEG, DE_SECT, KC_NO,  KC_NO,  KC_NO, DE_DLR,DE_EURO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      _______,     _______,
//╠═══════╣╠═══════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═════════════╬═══════╣
   _______,   _______,  S(DE_X),S(DE_V),S(DE_L),S(DE_C),S(DE_W),S(DE_K),S(DE_H),S(DE_G),S(DE_F),S(DE_Q),_______, KC_NO,    _______,   _______,
//╠═══════╣╠═══════════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═════════════╬═══════╣
   _______,    _______,   S(DE_U),S(DE_I),S(DE_A),S(DE_E),S(DE_O),S(DE_S),S(DE_N),S(DE_R),S(DE_T),S(DE_D),S(DE_Y),      _______,      _______,
//╠═══════╣╠═════════════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══════════╦═══════╬═══════╣
   _______,  _______,S(DE_UDIA),S(DE_ODIA),S(DE_ADIA),S(DE_P),S(DE_Z),S(DE_B),S(DE_M), KC_NO,  KC_NO, S(DE_J),    _______,    LSFT(KC_UP),_______,
//╠═══════╣╠═══════╦═══════╦═╩═════╦═╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═════╦═╩═══════╩═╦═════╩═══════╦═══════╬═══════╬═══════╣
   _______, _______,_______,_______,                       _______,                           _______,  _______,LSFT(KC_LEFT),LSFT(KC_DOWN),LSFT(KC_RGHT)
//╚═══════╝╚═══════╩═══════╩═══════╩═══════════════════════════════════════════════════════╩═══════════╩═════════════╩═══════╩═══════╩═══════╝
),

[_LAYER3] = LAYOUT(
//╔═══════╗
   _______,
//╠═══════╣╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═════════════════╦═══════╗
   _______,  KC_NO,  KC_NO, DE_SUP2,DE_SUP3, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,      _______,     _______,
//╠═══════╣╠═══════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═════════════╬═══════╣
   _______,   _______,   KC_NO, DE_UNDS,DE_LBRC,DE_RBRC,NEO_GRV,DE_EXLM,DE_LABK,DE_RABK, DE_EQL,DE_AMPR,_______, KC_NO,    _______,   _______,
//╠═══════╣╠═══════════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═════════════╬═══════╣
   _______,    _______,   DE_BSLS,DE_SLSH,DE_LCBR,DE_RCBR,DE_ASTR,DE_QUES,DE_LPRN,DE_RPRN,DE_MINS,DE_COLN, DE_AT,       _______,      _______,
//╠═══════╣╠═════════════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══════════╦═══════╬═══════╣
   _______,     _______,      DE_HASH, DE_DLR,DE_PIPE,DE_TILD,NEO_BTK,DE_PLUS,DE_PERC,DE_DQUO,DE_QUOT,DE_SCLN,    _______,    _______,_______,
//╠═══════╣╠═══════╦═══════╦═╩═════╦═╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═════╦═╩═══════╩═╦═════╩═══════╦═══════╬═══════╬═══════╣
   _______, _______,_______,_______,                       _______,                           _______,     _______,   _______,_______,_______
//╚═══════╝╚═══════╩═══════╩═══════╩═══════════════════════════════════════════════════════╩═══════════╩═════════════╩═══════╩═══════╩═══════╝
),

[_LAYER4] = LAYOUT(
//╔═══════╗
   _______,
//╠═══════╣╔═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═══════╦═════════════════╦═══════╗
   _______,  KC_NO,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,     _______,     _______,
//╠═══════╣╠═══════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═════════════╬═══════╣
   _______,   _______,  KC_PGUP,KC_BSPC, KC_UP,  KC_DEL,KC_PGDN, KC_NO,  DE_7,   DE_8,   DE_9,  DE_PLUS,_______, KC_NO,    _______,   _______,
//╠═══════╣╠═══════════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═╦═════╩═════════════╬═══════╣
   _______,    _______,   KC_HOME,KC_LEFT,KC_DOWN,KC_RGHT, KC_END, KC_NO,  DE_4,   DE_5,   DE_6,  DE_COMM, DE_DOT,      _______,      _______,
//╠═══════╣╠═════════════╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══╦═══╩═══════════╦═══════╬═══════╣
   _______,     _______,       KC_ESC, KC_TAB, KC_NO,  KC_ENT, KC_NO, DE_COLN, DE_1,   DE_2,   DE_3,  DE_SCLN,    _______,    _______,_______,
//╠═══════╣╠═══════╦═══════╦═╩═════╦═╩═══════╩═══════╩═══════╩═══════╩═══════╩═══════╩═════╦═╩═══════╩═╦═════╩═══════╦═══════╬═══════╬═══════╣
   _______, _______,_______,_______,                       _______,                           _______,     _______,   _______,_______,_______
//╚═══════╝╚═══════╩═══════╩═══════╩═══════════════════════════════════════════════════════╩═══════════╩═════════════╩═══════╩═══════╩═══════╝
)
};
// clang-format on

///////////////////////////////////////////////////////////////////////////////
// OLED Features (see: https://docs.qmk.fm/#/feature_oled_driver)

#ifdef OLED_ENABLE

// Display seems to be a 64x128 mounted horizontally.
// I didn't find a better way than just rotating it by 90 degrees.
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_90;
}

// Print the LED states of the keyboard, the name of the current layer and the last pressed key.
bool oled_task_user() {
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\n") : PSTR("\n"), false);

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
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}
#endif