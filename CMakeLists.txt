cmake_minimum_required(VERSION 3.13)

include(pico_sdk_import.cmake)
include(pico_display_import.cmake)
project(pewpew C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

add_executable(pewpew
    pewpew.cpp
    palettes.cpp
    sprites.cpp
    hud.cpp
    ship.cpp
)

pico_enable_stdio_usb(pewpew 1)
pico_enable_stdio_uart(pewpew 1)

pico_add_extra_outputs(pewpew)

target_link_libraries(pewpew pico_stdlib hardware_spi hardware_pwm hardware_dma pico_display)
