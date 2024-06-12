cmake_minimum_required(VERSION 3.28)

project(
        LeetArchive
        VERSION 1.0
        DESCRIPTION "Archive of submissions"
        LANGUAGES CXX
    )

set(CMAKE_CXX_STANDARD 20 CACHE STRING "C++ standard to use")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_compile_options(-Wall -Wextra -Wpedantic)

add_subdirectory(problems/easy)
add_subdirectory(problems/medium)