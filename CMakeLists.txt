cmake_minimum_required(VERSION 3.13)

find_package(PNG REQUIRED)

include_directories(include)

add_executable(main
    src/main.c
    src/png_utils.c)

target_link_libraries(main PRIVATE PNG::PNG)