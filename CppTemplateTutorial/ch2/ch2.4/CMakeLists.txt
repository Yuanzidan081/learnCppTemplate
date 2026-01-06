cmake_minimum_required(VERSION 3.16)

project(day3 LANGUAGES CXX)

add_executable(day3
	main.cpp
)

target_include_directories(day3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(day3 PRIVATE cxx_std_17)