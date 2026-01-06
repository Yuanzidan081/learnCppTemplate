cmake_minimum_required(VERSION 3.16)

project(day2 LANGUAGES CXX)

add_executable(day2
	main.cpp
)

target_include_directories(day2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(day2 PRIVATE cxx_std_17)