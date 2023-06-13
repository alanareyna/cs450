cmake_minimum_required(VERSION 3.23)
project(cs450 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(cs450
        forkTest.c)
