cmake_minimum_required(VERSION 3.13)
find_package(PNG REQUIRED)
file(TO_CMAKE_PATH $ENV{NRF_SDK_ROOT} NRF_SDK_ROOT)

include_directories(include
    ${NRF_SDK_ROOT}/components/libraries/gfx
    ${NRF_SDK_ROOT}/components/libraries/util
    ${NRF_SDK_ROOT}/components/device
    ${NRF_SDK_ROOT}/components/softdevice/s132/headers)

add_definitions(-D__INLINE= -DSTACK_BASE=0 -DSTACK_TOP=0)


add_executable(main
    ${NRF_SDK_ROOT}/components/libraries/gfx/nrf_gfx.c
    src/main.c
    src/png_utils.c)

target_link_libraries(main PRIVATE PNG::PNG)