# cmake_minimum_required(VERSION <specify CMake version here>)
project(sealox C)

set(CMAKE_C_STANDARD 99)

add_executable(sealox main.c common.h chunk.h chunk.c memory.h memory.c debug.h debug.c value.h value.c vm.h)