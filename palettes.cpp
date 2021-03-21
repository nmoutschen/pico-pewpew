#include <iterator>
#include "pico_display.hpp"

int8_t COLOR_BG               = 0;
int8_t COLOR_WHITE            = 1;
int8_t COLOR_BLUE             = 2;
int8_t COLOR_RED              = 3;
int8_t COLOR_BG_ALT           = 4;

int8_t COLOR_SHIP_LIGHT       = 5;
int8_t COLOR_SHIP_MID         = 6;
int8_t COLOR_SHIP_DARK        = 7;
int8_t COLOR_SHIP_VISOR       = 2;
int8_t COLOR_SHIP_VISOR_DARK  = 8;
int8_t COLOR_SHIP_TRAIL       = 3;

int8_t COLOR_ENEMY_LIGHT      = 9;
int8_t COLOR_ENEMY_MID        = 10;
int8_t COLOR_ENEMY_DARK       = 11;
int8_t COLOR_ENEMY_VISOR      = 12;
int8_t COLOR_ENEMY_VISOR_DARK = 4;
int8_t COLOR_ENEMY_TRAIL      = 3;

int8_t COLOR_BULLET_LIGHT     = 13;
int8_t COLOR_BULLET_MID       = 3;
int8_t COLOR_BULLET_DARK      = 14;

// Note: palettes are RGB565 colors, with bytes swapped
uint16_t PALETTES[16] = {
    0x0a41, // 0 Background
    0xfcff, // 1 White
    0xdb8e, // 2 Blue
    0x09c2, // 3 Red
    0x8e59, // 4 Alternate background
    0x53f6, // 5 Ship light
    0xd0d3, // 6 Ship mid
    0xf1aa, // 7 Ship dark
    0xb975, // 8 Ship visor dark
    0x10e5, // 9 Enemy light
    0x8dc3, // 10 Enemy mid
    0x6aa2, // 11 Enemy dark
    0x1082, // 12 Enemy visor
    0x4ae3, // 13 Bullet light
    0x6991, // 14 Bullet dark
    0x0000  // 15 EMPTY
};
