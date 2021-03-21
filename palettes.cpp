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
int8_t COLOR_ENEMY_VISOR_DARK = 13;
int8_t COLOR_ENEMY_TRAIL      = 3;

int8_t COLOR_BULLET_LIGHT     = 14;
int8_t COLOR_BULLET_MID       = 3;
int8_t COLOR_BULLET_DARK      = 15;

uint8_t COLORS[] = {
    0x41, 0x20, 0x51, // 0 Background
    0xff, 0xff, 0xe0, // 1 White
    0x89, 0xd9, 0xd9, // 2 Blue
    0xc7, 0x42, 0x4f, // 3 Red
    0x5b, 0x33, 0x74, // 4 Background Alt
    0xf2, 0xcb, 0x9b, // 5 SHIP Light tones
    0xd3, 0x7b, 0x86, // 6 SHIP Mid tones
    0xaf, 0x5d, 0x8b, // 7 SHIP Dark tones
    0x72, 0xb6, 0xcf, // 8 SHIP Visor Dark
    0xe3, 0xa0, 0x84, // 9 ENEMY Light tones
    0xc7, 0x73, 0x69, // 10 ENEMY Mid tones
    0xa1, 0x4d, 0x55, // 11 ENEMY Dark tones
    0x80, 0x40, 0x85, // 12 ENEMY Visor
    0x5b, 0x33, 0x74, // 13 ENEMY Visor Dark
    0xe0, 0x6b, 0x51, // 14 BULLET Light tones
    0x94, 0x2c, 0x4b  // 15 BULLET Dark tones
};

uint16_t PALETTES[16];


void init_palettes(pimoroni::PicoDisplay display) {
    for (int i = 0; i < std::size(PALETTES); i++) {
        PALETTES[i] = display.create_pen(
            COLORS[i*3],
            COLORS[i*3+1],
            COLORS[i*3+2]
        );
    }
}
