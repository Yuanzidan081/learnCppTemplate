cmake_minimum_required(VERSION 3.16)

project(day1 LANGUAGES CXX)

add_executable(day1
	main.cpp
	vec.cpp
)

target_include_directories(day1 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(day1 PRIVATE cxx_std_17)

