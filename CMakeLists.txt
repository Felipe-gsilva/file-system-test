cmake_minimum_required(VERSION 3.10)

project(FileSystemTest VERSION 1.0)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

file(GLOB SRC_FILES src/*.c)

include_directories(src)

add_executable(file_system_test ${SRC_FILES})

