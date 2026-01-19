cmake_minimum_required(VERSION 3.16)

project(ch1_3 LANGUAGES CXX)

add_executable(ch1_3 main.cpp)

target_include_directories(ch1_3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_compile_features(ch1_3 PRIVATE cxx_std_20)