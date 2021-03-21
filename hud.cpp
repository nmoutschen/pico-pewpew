#include <iterator>
#include "pico_display.hpp"

using namespace pimoroni;

extern uint16_t PALETTES[16];
extern int8_t COLOR_BG_ALT;
extern int8_t COLOR_BLUE;
extern int8_t COLOR_RED;
extern void draw_sprite(PicoDisplay, int8_t[], Point);
extern void draw_ship_small(PicoDisplay, Point);

int8_t SPRITE_HUD[] {
    6, 38,
    -1,  2, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
     2, -1, -1, -1, -1, -1,
    // D
     2, -1, -1,  2,  2, -1,
     2, -1,  2, -1, -1,  2,
     2, -1,  2,  2,  2,  2,
     2, -1, -1, -1, -1, -1,
    // L
     2, -1, -1, -1, -1,  2,
     2, -1, -1, -1, -1,  2,
     2, -1,  2,  2,  2,  2,
     2, -1, -1, -1, -1, -1,
    // E
     2, -1,  2, -1, -1,  2,
     2, -1,  2,  2, -1,  2,
     2, -1,  2,  2,  2,  2,
     2, -1, -1, -1, -1, -1,
     // I
     2, -1,  2,  2,  2,  2,
     2, -1, -1, -1, -1, -1,
     // H
     2, -1,  2,  2,  2,  2,
     2, -1, -1,  2, -1, -1,
     2, -1,  2,  2,  2,  2,
     2, -1, -1, -1, -1, -1,
     // S
     2, -1,  2, -1,  2, -1,
     2, -1,  2,  2, -1,  2,
     2, -1, -1,  2, -1,  2
};


void draw_hud(PicoDisplay display, uint8_t shield, uint8_t lives) {
    // Background
    display.set_pen(PALETTES[COLOR_BG_ALT]);
    Rect rect_hud(PicoDisplay::WIDTH-11, 0, 11, PicoDisplay::HEIGHT);
    display.rectangle(rect_hud);

    // Shield
    display.set_pen(PALETTES[COLOR_RED]);
    for(uint8_t i = 0; i < shield; i++) {
        if (i >= 3) {
            display.set_pen(PALETTES[COLOR_BLUE]);
        }

        display.rectangle(Rect(
            PicoDisplay::WIDTH - 8,
            PicoDisplay::HEIGHT - i * 4 - 5,
            6,
            3
        ));
    }

    // Draw text
    draw_sprite(display, SPRITE_HUD, Point(PicoDisplay::WIDTH-9, 46));

    // Ships
    for (uint16_t i = 0; i < lives; i++) {
        Point offset(
            PicoDisplay::WIDTH - 9,
            1 + 9 * i
        );
        draw_ship_small(display, offset);
    }
}
