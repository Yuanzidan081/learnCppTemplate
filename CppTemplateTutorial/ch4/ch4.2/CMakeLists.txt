cmake_minimum_required(VERSION 3.16)

project(ch4_2 LANGUAGES CXX)

add_executable(ch4_2 main.cpp)

target_include_directories(ch4_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(ch4_2 PRIVATE cxx_std_17)