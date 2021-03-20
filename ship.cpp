#include <iterator>

#include "pico_display.hpp"

using namespace pimoroni;

// TODO: optimise this by pre-creating the pens
char SHIP_PALETTE[] = {
    242, 203, 155, // 0 Light
    211, 123, 134, // 1 Middle
    175,  93, 139, // 2 Dark
    137, 217, 217, // 3 Visor Light
    114, 182, 207, // 4 Visor Dark
    199,  66,  79  // 5 Thrusters
};

// X, Y, Color ID
char SHIP_PIXELS[] = {
    // Row 0
    5, 0, 1,
    // Row 1
    6, 1, 0,
    5, 1, 1,
    4, 1, 2,
    // Row 2
    6, 2, 0,
    5, 2, 4,
    4, 2, 2,
    // Row 3
    7, 3, 0,
    6, 3, 3,
    5, 3, 3,
    4, 3, 4,
    3, 3, 2,
    // Row 4
    7, 4, 0,
    6, 4, 3,
    5, 4, 3,
    4, 4, 4,
    3, 4, 2,
    // Row 5
    10, 5, 0,
    7, 5, 0,
    6, 5, 3,
    5, 5, 3,
    4, 5, 4,
    3, 5, 2,
    0, 5, 2,
    // Row 6,
    10, 6, 0,
    9, 6, 2,
    8, 6, 0,
    7, 6, 1,
    6, 6, 3,
    5, 6, 3,
    4, 6, 4,
    3, 6, 2,
    2, 6, 2,
    1, 6, 0,
    0, 6, 2,
    // Row 7
    10, 7, 0,
    9, 7, 2,
    8, 7, 1,
    7, 7, 0,
    6, 7, 0,
    5, 7, 1,
    4, 7, 2,
    3, 7, 2,
    2, 7, 1,
    1, 7, 0,
    0, 7, 2,
    // Row 8
    10, 8, 5,
    8, 8, 1,
    7, 8, 0,
    6, 8, 0,
    5, 8, 0,
    4, 8, 2,
    3, 8, 2,
    2, 8, 1,
    0, 8, 5,
    // Row 9
    7, 9, 5,
    5, 9, 5,
    3, 9, 5
};

void draw_ship(PicoDisplay display, Point offset) {
    uint16_t palettes[6];
    for(uint i = 0; i < std::size(SHIP_PALETTE)/3; i++) {
        palettes[i] = display.create_pen(
            SHIP_PALETTE[3*i],
            SHIP_PALETTE[3*i+1],
            SHIP_PALETTE[3*i+2]
        );
    }

    for (uint16_t i = 0; i < std::size(SHIP_PIXELS); i += 3) {
        Point cursor(
            offset.x + SHIP_PIXELS[i+1],
            offset.y + SHIP_PIXELS[i]
        );
        uint8_t color = SHIP_PIXELS[i+2];

        display.set_pen(palettes[color]);

        display.pixel(cursor);
    }
}
