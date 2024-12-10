cmake_minimum_required(VERSION 3.23)

add_subdirectory(external/glad)
add_subdirectory(external/glfw)

project(learnopengl)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_executable(learnopengl "src/main.cpp")

target_link_libraries(learnopengl glad glfw)
