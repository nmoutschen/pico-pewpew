#include "pico_display.hpp"

using namespace pimoroni;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);

extern char SHIP_PALETTE[];
extern char SHIP_PIXELS[];
extern void draw_ship(PicoDisplay, Point);
extern void draw_hud(PicoDisplay, uint8_t, uint8_t);

uint8_t BG_COLOR[] = {65, 32, 81};

void draw_bg(PicoDisplay display) {
    display.set_pen(BG_COLOR[0], BG_COLOR[1], BG_COLOR[2]);
    Rect rect_bg(0, 0, PicoDisplay::WIDTH, PicoDisplay::HEIGHT);
    display.rectangle(rect_bg);
}

int main() {
    pico_display.init();
    pico_display.set_backlight(255);

    Point ship_pos(216, 70);

    while (true) {
        // Background
        draw_bg(pico_display);

        // HUD
        draw_hud(pico_display, 12, 5);

        // Ship
        if (pico_display.is_pressed(PicoDisplay::X)) {
            ship_pos.y -= 5;
            if (ship_pos.y < 0) {
                ship_pos.y = 0;
            }
        }
        if(pico_display.is_pressed(PicoDisplay::Y)) {
            ship_pos.y += 5;
            if (ship_pos.y > PicoDisplay::HEIGHT - 10) {
                ship_pos.y = PicoDisplay::HEIGHT - 10;
            }
        }
        draw_ship(pico_display, ship_pos);

        pico_display.update();
        sleep_ms(30);
    }
}
