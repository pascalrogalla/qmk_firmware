/* Copyright 2020 ipetepete
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
enum keyboard_layers { BASE = 0, FUNCTION_LAYER = 1, CAPSLOCK_LAYER = 2};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_60_ansi(
        KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
        MO(CAPSLOCK_LAYER), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT_UP,
        KC_LCTL, KC_LALT, KC_LGUI, KC_SPC, KC_RGUI, KC_RALT_LEFT, KC_RCTL_DOWN , KC_FN1_RIGHT
    ),
    [FUNCTION_LAYER] = LAYOUT_60_ansi(
        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_DEL,
        _______, _______, KC__VOLUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_MRWD, KC__VOLDOWN, KC_MFFD, KC__MUTE, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, KC_MEDIA_PLAY_PAUSE, _______, _______, _______, _______
    ),

    [CAPSLOCK_LAYER] = LAYOUT_60_ansi(
        _______, KC_BRMD, KC_BRMU, KC_MCON, KC_LPAD, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_RMOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

/********************************************************************************/
/* Using layers to do RGB underlighting */
/********************************************************************************/

//TODO: Layer Lighting: https://github.com/qmk/qmk_firmware/blob/1e5df7117d9fe4da459cde53e7288f7f25ee988c/keyboards/bm60poker/keymaps/ipetepete/keymap.c
void rgb_matrix_indicators_kb(void)
{
	if (!g_suspend_state && rgb_matrix_config.enable) {
        switch (get_highest_layer(layer_state)) {

            case FUNCTION_LAYER:
                rgb_matrix_set_color(1, 0xB5, 0xB5, 0xB5);//F1
                rgb_matrix_set_color(2, 0xB5, 0xB5, 0xB5);//F2
                rgb_matrix_set_color(3, 0xB5, 0xB5, 0xB5);//F3
                rgb_matrix_set_color(4, 0xB5, 0xB5, 0xB5);//F4
                rgb_matrix_set_color(5, 0xB5, 0xB5, 0xB5);//F5
                rgb_matrix_set_color(6, 0xB5, 0xB5, 0xB5);//F6
                rgb_matrix_set_color(7, 0xB5, 0xB5, 0xB5);//F7
                rgb_matrix_set_color(8, 0xB5, 0xB5, 0xB5);//F9
                rgb_matrix_set_color(9, 0xB5, 0xB5, 0xB5);//F9
                rgb_matrix_set_color(10, 0xB5, 0xB5, 0xB5);//F10
                rgb_matrix_set_color(11, 0xB5, 0xB5, 0xB5);//F11
                rgb_matrix_set_color(12, 0xB5, 0xB5, 0xB5);//F12
                rgb_matrix_set_color(13, 0xD4, 0x00, 0x00);//DEL

                rgb_matrix_set_color(16, 0x00, 0xD0, 0xFF);//KC__VOLUP
                rgb_matrix_set_color(29, 0x00, 0xD0, 0xFF);//KC_MRWD
                rgb_matrix_set_color(30, 0x00, 0xD0, 0xFF);//KC__VOLDOWN
                rgb_matrix_set_color(31, 0x00, 0xD0, 0xFF);//KC_MFFD

                rgb_matrix_set_color(32, 0xFF, 0x5F, 0x00);//KC__MUTE

                rgb_matrix_set_color(56, 0x00, 0xD0, 0xFF);//KC_MEDIA_PLAY_PAUSE
                break;
            case CAPSLOCK_LAYER:
                rgb_matrix_set_color(1, 0xFF, 0xFF, 0xFF);//KC_BRMD
                rgb_matrix_set_color(2, 0xFF, 0xFF, 0xFF);//KC_BRMU
                rgb_matrix_set_color(3, 0xFF, 0x00, 0xD0);//KC_MCON
                rgb_matrix_set_color(4, 0xFF, 0x00, 0xD0);//KC_LPAD

//----RGB start
                rgb_matrix_set_color(14, 0xFF, 0x5F, 0x00);//RGB_TOG

                rgb_matrix_set_color(15, 0x00, 0xFF, 0x27);//RGB_MOD
                rgb_matrix_set_color(29, 0x00, 0xFF, 0x27);//RGB_RMOD

                rgb_matrix_set_color(16, 0x00, 0xFC, 0xFF);//RGB_HUI
                rgb_matrix_set_color(30, 0x00, 0xFC, 0xFF);//RGB_HUD

                rgb_matrix_set_color(17, 0x0A, 0x00, 0xFF);//RGB_SAI
                rgb_matrix_set_color(31, 0x0A, 0x00, 0xFF);//RGB_SAD

                rgb_matrix_set_color(18, 0x62, 0x00, 0xFF);//RGB_VAI
                rgb_matrix_set_color(32, 0x62, 0x00, 0xFF);//RGB_VAD
//----RGB end
                break;
        }
    }
}