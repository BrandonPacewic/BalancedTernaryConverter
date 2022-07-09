# Copyright (c) Brandon Pacewic
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.10)

project(balanced_ternary LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

add_executable(balanced_ternary src/main.cpp)

target_link_libraries(balanced_ternary PUBLIC src)
target_include_directories(balanced_ternary PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/src")