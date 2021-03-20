#include <iterator>
#include "pico_display.hpp"

using namespace pimoroni;

uint8_t HUD_BG_COLOR[] = {91, 51, 116};
uint8_t HUD_RED_COLOR[] = {224, 107, 81};
uint8_t HUD_BLUE_COLOR[] = {137, 217, 217};

uint16_t HUD_TEXT[] {
    // D
    0, 1,
    0, 2,
    1, 0,
    1, 3,
    2, 0,
    2, 1,
    2, 2,
    2, 3,
    // L
    4, 3,
    5, 3,
    6, 0,
    6, 1,
    6, 2,
    6, 3,
    // E
    8, 0,
    8, 3,
    9, 0,
    9, 1,
    9, 3,
    10, 0,
    10, 1,
    10, 2,
    10, 3,
    // I
    12, 0,
    12, 1,
    12, 2,
    12, 3,
    // H
    14, 0,
    14, 1,
    14, 2,
    14, 3,
    15, 1,
    16, 0,
    16, 1,
    16, 2,
    16, 3,
    // S
    18, 0,
    18, 2,
    19, 0,
    19, 1,
    19, 3,
    20, 1,
    20, 3
};

char HUD_SHIP_PALETTE[] = {
    242, 203, 155, // 0 Light
    211, 123, 134, // 1 Middle
    175,  93, 139, // 2 Dark
    137, 217, 217, // 3 Visor Light
    114, 182, 207, // 4 Visor Dark
    199,  66,  79  // 5 Thrusters
};

uint16_t HUD_SHIP_PIXELS[] {
    3, 0, 0,
    4, 1, 0,
    3, 1, 3,
    2, 1, 2,
    6, 2, 0,
    4, 2, 0,
    3, 2, 3,
    2, 2, 2,
    0, 2, 2,
    6, 3, 0,
    5, 3, 2,
    4, 3, 0,
    3, 3, 3,
    2, 3, 2,
    1, 3, 0,
    0, 3, 2,
    6, 4, 5,
    4, 4, 1,
    3, 4, 2,
    2, 4, 2,
    0, 4, 5,
    4, 5, 5,
    2, 5, 5
};

void draw_hud(PicoDisplay display, uint8_t shield, uint8_t lives) {
    // Colours
    uint16_t palettes[6];
    for(uint i = 0; i < std::size(HUD_SHIP_PALETTE)/3; i++) {
        palettes[i] = display.create_pen(
            HUD_SHIP_PALETTE[3*i],
            HUD_SHIP_PALETTE[3*i+1],
            HUD_SHIP_PALETTE[3*i+2]
        );
    }
    uint16_t shield_red = display.create_pen(HUD_RED_COLOR[0], HUD_RED_COLOR[1], HUD_RED_COLOR[2]);
    uint16_t shield_blue = display.create_pen(HUD_BLUE_COLOR[0], HUD_BLUE_COLOR[1], HUD_BLUE_COLOR[2]);

    // Background
    display.set_pen(HUD_BG_COLOR[0], HUD_BG_COLOR[1], HUD_BG_COLOR[2]);
    Rect rect_hud(PicoDisplay::WIDTH-11, 0, 11, PicoDisplay::HEIGHT);
    display.rectangle(rect_hud);

    // Shield points
    display.set_pen(shield_red);
    for (uint8_t i = 0; i < shield; i++) {
        if (i >= 3) {
            display.set_pen(shield_blue);
        }

        Rect rect_shield(
            PicoDisplay::WIDTH-8,
            PicoDisplay::HEIGHT-i*4-5,
            6,
            3
        );
        display.rectangle(rect_shield);
    }

    // Text
    display.set_pen(shield_blue);
    
    display.rectangle(Rect(PicoDisplay::WIDTH-8, 48, 1, 37));
    display.pixel(Point(PicoDisplay::WIDTH-7, 47));

    for (uint16_t i = 0; i < std::size(HUD_TEXT); i += 2) {
        display.pixel(Point(
            PicoDisplay::WIDTH-6 + HUD_TEXT[i+1],
            63 + HUD_TEXT[i]
        ));
    }

    // Ships
    for (uint16_t i = 0; i < lives; i++) {
        Point offset(
            PicoDisplay::WIDTH - 8,
            3 + 9 * i
        );
        for (uint16_t j = 0; j < std::size(HUD_SHIP_PIXELS); j += 3) {
            Point cursor(
                offset.x + HUD_SHIP_PIXELS[j+1],
                offset.y + HUD_SHIP_PIXELS[j]
            );
            uint8_t color = HUD_SHIP_PIXELS[j+2];

            display.set_pen(palettes[color]);
            display.pixel(cursor);
        }
    }
}
