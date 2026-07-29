cmake_minimum_required(VERSION 3.31)
project(game-patterns VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Esporta compile_commands.json per IntelliSense
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#third party library
include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 12.2.0
)
FetchContent_MakeAvailable(fmt)
##

add_subdirectory(command-pattern)

target_link_libraries(command-pattern PRIVATE fmt::fmt)