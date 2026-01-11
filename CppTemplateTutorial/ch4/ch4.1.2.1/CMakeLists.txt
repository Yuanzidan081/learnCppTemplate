cmake_minimum_required(VERSION 3.16)

project(ch4_1_2_1 LANGUAGES CXX)

add_executable(ch4_1_2_1
    main.cpp
)

target_include_directories(ch4_1_2_1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(ch4_1_2_1 PRIVATE cxx_std_17)