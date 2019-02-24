cmake_minimum_required(VERSION 3.13)
find_package(PNG REQUIRED)
file(TO_CMAKE_PATH $ENV{NRF_SDK_ROOT} NRF_SDK_ROOT)

include_directories(include)

add_definitions()

add_executable(main
    src/main.c
    src/nrf_gfx.c
    src/buffer_display.c
    src/roboto8pt.c
    src/png_utils.c)

target_link_libraries(main PRIVATE PNG::PNG)
