/* Copyright 2024 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include "q0_max_layers.h"


#define SG(key) S(G(key))
#define CG(key) C(G(key))

#define MX(layer) MO(layer)
#define MX1 MX(X1)
#define MX2 MX(X2)
#define MX3 MX(X3)
#define MX4 MX(X4)

#ifndef Q0_MAX_EXTENDED_LAYERS_X1
# undef  MX1
# define MX1 XXXXXXX
#endif
#ifndef Q0_MAX_EXTENDED_LAYERS_X2
# undef  MX2
# define MX2 XXXXXXX
#endif
#ifndef Q0_MAX_EXTENDED_LAYERS_X3
# undef  MX3
# define MX3 XXXXXXX
#endif
#ifndef Q0_MAX_EXTENDED_LAYERS_X4
# undef  MX4
# define MX4 XXXXXXX
#endif

#ifdef ENABLE_COMPILE_KEYCODE
# define QX_MOD QK_LSFT|QK_LCTL
# define QX_BOOT QK_MAKE
#else
# define QX_MOD XXXXXXX
# define QX_BOOT QK_BOOT
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Generic "as-is"
    [BASE] = LAYOUT_tenkey_27(
        KC_MUTE, KC_ESC,  KC_LPAD, KC_LCMD, KC_SNAP,
        DF(L1),	 KC_BSPC, KC_PSLS, KC_PAST, KC_PMNS,
        DF(L2),	 KC_P7,	  KC_P8,   KC_P9,	KC_PPLS,
        DF(L3),	 KC_P4,	  KC_P5,   KC_P6,
        DF(L4),	 KC_P1,	  KC_P2,   KC_P3,	KC_PENT,
        MO(FN),  KC_P0,            KC_PDOT          ),

    // Blender + Nomad
    [L1] = LAYOUT_tenkey_27(
        KC_F12,  QK_LSFT, G(KC_Z), SG(KC_Z),KC_DEL,
        MX1,     KC_ESC,  KC_S,    KC_SPC,  KC_H,
        DF(L2),  KC_P7,   KC_P8,   KC_P9,   KC_F3,
        DF(L3),  KC_P4,   KC_P5,   KC_P6,
        DF(L4),  KC_P1,   KC_P2,   KC_P3,   KC_M,
        DF(BASE),KC_P0,            KC_PDOT          ),

    [L2] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        DF(L1),  _______, _______, _______, _______,
        MX2,     _______, _______, _______, _______,
        DF(L3),  _______, _______, _______,
        DF(L4),  _______, _______, _______, _______,
        DF(BASE),_______,          _______          ),

    [L3] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        DF(L1),  _______, _______, _______, _______,
        DF(L2),  _______, _______, _______, _______,
        MX3,     _______, _______, _______,
        DF(L4),  _______, _______, _______, _______,
        DF(BASE),_______,          _______          ),

    // Programming
    [L4] = LAYOUT_tenkey_27(
        _______, KC_F16,  KC_F17,  KC_F18,  KC_F19,
        DF(L1),  _______, _______, _______, G(KC_DOT),
        DF(L2),  _______, _______, _______, KC_F13,
        DF(L3),  _______, _______, _______,
        MX4,     _______, _______, _______, G(KC_R),
        DF(BASE),_______,          _______          ),

#ifdef Q0_MAX_EXTENDED_LAYERS
# ifdef Q0_MAX_EXTENDED_LAYERS_X1
    // Nomad tools
    [X1] = LAYOUT_tenkey_27(
        _______, KC_Y,    KC_W,    G(KC_S), G(KC_N),
        _______, KC_Z,    KC_PSLS, KC_PAST, KC_MINS,
        _______, KC_7,    KC_8,    KC_9,    KC_Q,
        _______, KC_4,    KC_5,    KC_6,
        _______, KC_1,    KC_2,    KC_3,    KC_V,
        _______, KC_0,             KC_T             ),
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X2
    [X2] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______          ),
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X3
    [X3] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______          ),
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X4
    [X4] = LAYOUT_tenkey_27(
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______,          _______          ),
# endif
#endif

    [FN] = LAYOUT_tenkey_27(
        RGB_TOG, BT_HST1, BT_HST2, BT_HST3, P2P4G,
        SE_LOCK, RGB_MOD, RGB_VAI, RGB_HUI, CG(KC_Q),
        XXXXXXX, RGB_RMOD,RGB_VAD, RGB_HUD, QX_MOD,
        XXXXXXX, RGB_SAI, RGB_SPI, KC_MPRV,
        XXXXXXX, RGB_SAD, RGB_SPD, KC_MPLY, QX_BOOT,
        XXXXXXX, RGB_TOG,          KC_MNXT          )
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L1]   = {ENCODER_CCW_CW(KC_PMNS, KC_PPLS)},
    [L2]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L3]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [L4]   = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},

#ifdef Q0_MAX_EXTENDED_LAYERS
# ifdef Q0_MAX_EXTENDED_LAYERS_X1
    [X1]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X2
    [X2]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X3
    [X3]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
# endif

# ifdef Q0_MAX_EXTENDED_LAYERS_X4
    [X4]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
# endif
#endif

    [FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},
};
#endif // ENCODER_MAP_ENABLE

#ifdef RGB_MATRIX_ENABLE

enum modes {
    MODE__DISABLED,
    MODE__ACTIVE,
#ifdef Q0_MAX_EXTENDED_LAYERS
    MODE__EXTENDED,
#endif
};
bool rgb_matrix_indicators_user(void) {
    uint8_t indicators[] = Q0_MAX_LAYER_INDICATOR_LEDS;
    enum modes default_mode = MODE__DISABLED;

#ifdef SECURE_ENABLE
    if (unlikely(secure_is_locked()))
    {
        rgb_matrix_set_color_all(255, 0, 0);
        return true;
    }
    else if (unlikely(secure_is_unlocking()))
    {
        rgb_matrix_set_color_all(255, 255, 0);
        return true;
    }
#endif

#ifdef Q0_MAX_EXTENDED_LAYERS
    if (unlikely(get_highest_layer(layer_state|default_layer_state) != get_highest_layer(default_layer_state)))
    {
        default_mode = MODE__EXTENDED;
    }
#endif

    for ( uint8_t i = 0; i < ARRAY_SIZE(indicators); ++i )
    {
        uint8_t rgb[RGB_MAX] = {0};
        enum modes mode = default_mode;

        if (IS_LAYER_ON_STATE(default_layer_state, i))
        {
            mode = MODE__ACTIVE;
        }

        switch (mode)
        {
#ifdef Q0_MAX_EXTENDED_LAYERS
            case MODE__EXTENDED:
                rgb[RGB_R] = 255;
                // rgb[RGB_G] = 255;
                rgb[RGB_B] = 255;
                // FALLTHROUGH
#endif
            case MODE__ACTIVE:
                rgb[RGB_G] = 255;
                break;
            default:
                break;
        }

        rgb_matrix_set_color(indicators[i], rgb[RGB_R], rgb[RGB_G], rgb[RGB_B]);
    }

    return true;
}
#endif

#ifdef Q0_MAX_RGBS_PER_LAYER
layer_state_t default_layer_state_set_user(layer_state_t state)
{
    static uint8_t default_rgb_mode = RGB_MATRIX_FALLBACK;
    static uint8_t last_rgb_mode = RGB_MATRIX_FALLBACK;
    uint8_t current_rgb_mode = rgb_matrix_get_mode();
    uint8_t new_rgb_mode = RGB_MATRIX_NONE;
    uint8_t layer_index = get_highest_layer(state);

    const uint8_t modes[] = Q0_MAX_RGBS_PER_LAYER_MODES;

    if (unlikely(RGB_MATRIX_FALLBACK == default_rgb_mode))
    {
        last_rgb_mode = default_rgb_mode = current_rgb_mode;
    }
    else if (unlikely(last_rgb_mode != current_rgb_mode))
    {
        // Updated externally
        default_rgb_mode = current_rgb_mode;
    }

    if (layer_index >= ARRAY_SIZE(modes))
        return state;


    new_rgb_mode = modes[layer_index];
    if (RGB_MATRIX_FALLBACK == new_rgb_mode)
        new_rgb_mode = default_rgb_mode;

    rgb_matrix_mode_noeeprom(new_rgb_mode);
    last_rgb_mode = new_rgb_mode;

    return state;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef SECURE_ENABLE
    if (unlikely(secure_is_locked()) && likely(keycode != MO(FN)))
    {
        return false;
    }
    else if (unlikely(secure_is_locked()))
    {
        secure_request_unlock();
        return false;
    }
#endif
    if (!process_record_keychron_common(keycode, record)) {
        return false;
    }
    return true;
}
