#include <iterator>

#include "pico_display.hpp"

using namespace pimoroni;

extern void draw_sprite(PicoDisplay, int8_t[], Point);

int8_t SPRITE_SHIP[] {
    10, 11,
    -1, -1, -1, -1, -1,  7,  7,  7,  3, -1,
    -1, -1, -1, -1, -1, -1,  5,  5, -1, -1,
    -1, -1, -1, -1, -1, -1,  7,  6,  6, -1,
    -1, -1, -1,  7,  7,  7,  7,  7,  7,  3,
    -1,  7,  7,  8,  8,  8,  8,  7,  7, -1,
     6,  6,  8,  2,  2,  2,  2,  6,  5,  3,
    -1,  5,  5,  2,  2,  2,  2,  5,  5, -1,
    -1, -1, -1,  5,  5,  5,  6,  5,  5,  3,
    -1, -1, -1, -1, -1, -1,  5,  6,  6, -1,
    -1, -1, -1, -1, -1, -1,  7,  7, -1, -1,
    -1, -1, -1, -1, -1,  5,  5,  5,  3, -1
};

int8_t SPRITE_SHIP_SMALL[] {
     6,  7,
    -1, -1,  7,  7,  3, -1,
    -1, -1, -1,  5, -1, -1,
    -1,  7,  7,  7,  7,  3,
     5,  2,  2,  2,  7, -1,
    -1,  5,  5,  5,  6,  3,
    -1, -1, -1,  7, -1, -1,
    -1, -1,  5,  5,  3, -1
};

void draw_ship(pimoroni::PicoDisplay display, pimoroni::Point offset) {
    draw_sprite(display, SPRITE_SHIP, offset);
}

void draw_ship_small(pimoroni::PicoDisplay display, pimoroni::Point offset) {
    draw_sprite(display, SPRITE_SHIP_SMALL, offset);
}
