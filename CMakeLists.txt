cmake_minimum_required(VERSION 3.23)

add_subdirectory(external/SDL)

project(rika-village)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(rika-village "src/main.cpp")

target_link_libraries(rika-village PRIVATE SDL3::SDL3)
