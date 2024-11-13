/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include QMK_KEYBOARD_H
#include "sendstring_german.h"

// clang-format off

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_L1,
    WIN_L2,
    WIN_L3,
    WIN_L4
};

enum keycodes {
    NEO_GRV = SAFE_RANGE,
    NEO_BTK,
    NEO_EUR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //========================================//
    // Layers when switch is flipped to "Mac" //
    //========================================//
    [MAC_BASE] = LAYOUT_iso_99(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_NO,    KC_NO,    RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,    KC_VOLD,  KC_VOLU,            KC_DEL,   KC_HOME,  KC_END,     KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_NUM,   KC_PSLS,  KC_PAST,    KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,                      KC_P7,    KC_P8,    KC_P9,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,  KC_ENT,             KC_P4,    KC_P5,    KC_P6,      KC_PPLS,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,    KC_P1,    KC_P2,    KC_P3,
        KC_LCTL,  KC_LOPT,  KC_LCMD,                                KC_SPC,                                 KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_P0,    KC_PDOT,    KC_PENT),
    [MAC_FN] = LAYOUT_iso_99(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,     KC_F11,   KC_F12,             _______,  _______,  _______,    RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,    _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,    _______,                      _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,  _______,  _______,    _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______,  _______,  _______,    _______),

//========================================//
// Layers when switch is flipped to "Win" //
//========================================//
[WIN_L1] = LAYOUT_iso_99(
    KC_ESC,               KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,               KC_DEL,    KC_HOME,   KC_END,    KC_MUTE,
    DE_CIRC,   DE_1,      DE_2,      DE_3,      DE_4,      DE_5,      DE_6,      DE_7,      DE_8,      DE_9,      DE_0,      DE_MINS,   DE_GRV,    KC_BSPC,              KC_NUM,    KC_PSLS,   KC_PAST,   KC_PMNS,
    KC_TAB,    DE_X,      DE_V,      DE_L,      DE_C,      DE_W,      DE_K,      DE_H,      DE_G,      DE_F,      DE_Q,      DE_SS,     DE_ACUT,                         KC_P7,     KC_P8,     KC_P9,
    MO(WIN_L3),DE_U,      DE_I,      DE_A,      DE_E,      DE_O,      DE_S,      DE_N,      DE_R,      DE_T,      DE_D,      DE_Y,      MO(WIN_L3),KC_ENT,               KC_P4,     KC_P5,     KC_P6,     KC_PPLS,
LM(WIN_L2,MOD_LSFT),MO(WIN_L4),DE_UDIA,DE_ODIA, DE_ADIA,   DE_P,      DE_Z,      DE_B,      DE_M,      DE_COMM,   DE_DOT,    DE_J,      LM(WIN_L2,MOD_RSFT),  KC_UP,     KC_P1,     KC_P2,     KC_P3,
    KC_LCTL,   KC_LWIN,   KC_LALT,                                    KC_SPC,                                     MO(WIN_L4),KC_RALT,   KC_RCTL,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_P0,     KC_PDOT,   KC_PENT),
[WIN_L2] = LAYOUT_iso_99(
    _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_NO,                           _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_NO,     KC_NO,     _______,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,                                    S(KC_SPC),                                  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______),
[WIN_L3] = LAYOUT_iso_99(
    _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    KC_NO,     DE_DEG,    DE_SUP2,   DE_SUP3,   KC_NO,     DE_SECT,   DE_DLR,    DE_EURO,   KC_NO,     KC_NO,     KC_NO,     KC_NO,     _______,   _______,              _______,   _______,   _______,   _______,
    _______,   KC_NO,     DE_UNDS,   DE_LBRC,   DE_RBRC,   NEO_GRV,   DE_EXLM,   DE_LABK,   DE_RABK,   DE_EQL,    DE_AMPR,   _______,   _______,                         _______,   _______,   _______,
    _______,   DE_BSLS,   DE_SLSH,   DE_LCBR,   DE_RCBR,   DE_ASTR,   DE_QUES,   DE_LPRN,   DE_RPRN,   DE_MINS,   DE_COLN,   DE_AT,     _______,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   DE_HASH,   DE_DLR,    DE_PIPE,   DE_TILD,   NEO_BTK,   DE_PLUS,   DE_PERC,   DE_DQUO,   DE_QUOT,   DE_SCLN,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______),
[WIN_L4] = LAYOUT_iso_99(
    _______,              _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_NUM,    KC_PSLS,   KC_PAST,   KC_PMNS,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    _______,   KC_PGUP,   KC_BSPC,   KC_UP,     KC_DEL,    KC_PGDN,   KC_NO,     KC_P7,     KC_P8,     KC_P9,     KC_PPLS,   _______,   _______,                         _______,   _______,   _______,
    _______,   KC_HOME,   KC_LEFT,   KC_DOWN,   KC_RGHT,   KC_END,    KC_NO,     KC_P4,     KC_P5,     KC_P6,     KC_PDOT,   _______,   _______,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   KC_ESC,    KC_TAB,    C(DE_V),   KC_ENT,    C(DE_Z),   KC_NO,     KC_P1,     KC_P2,     KC_P3,     KC_PENT,   _______,              _______,   _______,   _______,   _______,
    _______,   _______,   _______,                                    _______,                                    _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_L1]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_L2]   = {ENCODER_CCW_CW(KC_BRID, KC_BRIU) },
    [WIN_L3]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
    [WIN_L4]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
        case NEO_EUR:
            if (record->event.pressed) {
                SEND_STRING("€");
            }
            return false;
        default:
            return true;
    }
}
