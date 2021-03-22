#include "pico_display.hpp"
#include "pico/stdlib.h"

using namespace pimoroni;

uint16_t buffer[PicoDisplay::WIDTH * PicoDisplay::HEIGHT];
PicoDisplay pico_display(buffer);
Point ship_pos(0, 0);
uint8_t pew_counter = 0;
Point pews[32];

extern uint16_t PALETTES[16];
extern void draw_sprite(PicoDisplay, uint8_t[], Point);
extern void draw_ship(PicoDisplay, Point);
extern void draw_hud(PicoDisplay, uint8_t, uint8_t);

void draw_bg(PicoDisplay display) {
    display.set_pen(PALETTES[0]);
    Rect rect_bg(0, 0, PicoDisplay::WIDTH, PicoDisplay::HEIGHT);
    display.rectangle(rect_bg);
}

uint8_t SPRITE_PEW[] {
    2, 3,
    0xfe, 0xff,
    0xc3, 0xef,
    0xfc, 0xff,
};

bool tick(struct repeating_timer *t) {
    // Background
    draw_bg(pico_display);

    // HUD
    draw_hud(pico_display, 12, 5);

    // Ship movement
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

    // Ship firing
    pew_counter++;
    if(pew_counter % 8 == 0) {
        pews[pew_counter / 8].x = ship_pos.x;
        pews[pew_counter / 8].y = ship_pos.y + 4;

        // Reset counter
        if(pew_counter % (32*8) == 0) {
            pew_counter = 0;
        }
    }

    for(int i = 0; i < 32; i++) {
        pews[i].x -= 2;
        if(pews[i].x > 0) {
            draw_sprite(pico_display, SPRITE_PEW, pews[i]);
        }
    }

    draw_ship(pico_display, ship_pos);

    pico_display.update();

    return true;
}

int main() {
    // Inits
    stdio_init_all();
    pico_display.init();
    pico_display.set_backlight(255);
    ship_pos.x = 216;
    ship_pos.y = 70;

    for(int i = 0; i < 32; i++) {
        pews[i].x = 0;
        pews[i].y = 0;
    }

    struct repeating_timer timer;
    add_repeating_timer_ms(-30, tick, NULL, &timer);

    while (true) {
        sleep_ms(2000);
    }
}
