cmake_minimum_required(VERSION 3.28)
project(game-patterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Esporta compile_commands.json per IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(command-pattern)
# poi aggiungere: add_subdirectory(observer-pattern), ecc.