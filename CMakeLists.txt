cmake_minimum_required(VERSION 4.1)
project(top_down_game)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

find_package(raylib REQUIRED)

add_executable(top_down_game
                src/main.cpp
                src/game-manager.cpp
                src/entities/entity.cpp
                src/objects/object.cpp
                src/entities/player.cpp
            )

target_include_directories(top_down_game PRIVATE include)
target_link_libraries(top_down_game PRIVATE raylib)
