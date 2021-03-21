#include "pico_display.hpp"

extern uint16_t PALETTES[16];

void draw_sprite(
    pimoroni::PicoDisplay display,
    uint8_t sprite[],
    pimoroni::Point offset
) {
    uint8_t x = sprite[0];
    uint8_t y = sprite[1];

    uint8_t color1 = 0;
    uint8_t color2 = 0;
    pimoroni::Point cursor(offset.x, offset.y);

    for(uint8_t i = 0; i < y * x; i++) {
        color1 = (sprite[2 + i] & 0xf0) >> 4;
        color2 = (sprite[2 + i] & 0x0f);

        if (color1 != 0x0f) {
            display.set_pen(PALETTES[color1]);
            display.pixel(cursor);
        }
        cursor.x++;

        if (color2 != 0x0f) {
            display.set_pen(PALETTES[color2]);
            display.pixel(cursor);
        }
        cursor.x++;

        if(i % x == x-1) {
            cursor.x = offset.x;
            cursor.y++;
        }
    }
}
