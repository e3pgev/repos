cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

project(BattleCity)

add_executable(BattleCity src/main.cpp)

add_subdirectory("C:/Programming/repos/external/glfw" "${CMAKE_BINARY_DIR}/glfw-build")

target_link_libraries(BattleCity glfw)