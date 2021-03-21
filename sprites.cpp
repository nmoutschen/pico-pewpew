#include <iterator>
#include "pico_display.hpp"

extern uint16_t PALETTES[16];

void draw_sprite(
    pimoroni::PicoDisplay display,
    int8_t sprite[],
    pimoroni::Point offset
) {
    int x = sprite[0];
    int y = sprite[1];

    int8_t color;
    pimoroni::Point cursor(offset.x, offset.y);

    for(int16_t yi = 0; yi < y; yi++) {
        cursor.x = offset.x;
        cursor.y++;

        for(int16_t xi = 0; xi < x; xi++) {
            cursor.x++;
            color = sprite[2 + yi * x + xi];

            if(color != -1) {
                display.set_pen(PALETTES[color]);
                display.pixel(cursor);
            }
        }
    }
}
