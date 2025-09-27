#pragma once

#define Q0_MAX_LAYER_INDICATOR_LEDS {23, 4, 9, 14, 18}
#define Q0_MAX_HYPER_LAYER_COLOUR { RGB_G }
#define RGB_MATRIX_FALLBACK (0xff)

typedef enum _rgb_index_e {
    RGB_R = 0,
    RGB_G,
    RGB_B,
    RGB_MAX
} Q0_MAX_rgb_index_t;

enum q0_max_layers {
    BASE,
    L1,
    L2,
    L3,
    L4,

    // Hyperlayers must go here
    // H1BASE,
    // H1L1,
    // H1L2,
    // H1L3,
    // H1L4,

#ifdef Q0_MAX_EXTENDED_LAYERS
# ifdef Q0_MAX_EXTENDED_LAYERS_X1
    X1,
# endif
# ifdef Q0_MAX_EXTENDED_LAYERS_X2
    X2,
# endif
# ifdef Q0_MAX_EXTENDED_LAYERS_X3
    X3,
# endif
# ifdef Q0_MAX_EXTENDED_LAYERS_X4
    X4,
# endif
#endif
    FN
};
