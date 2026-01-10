cmake_minimum_required(VERSION 3.16)

project(ch2_2 LANGUAGES CXX)

add_executable(ch2_2
	main.cpp
	vec.cpp
)

target_include_directories(ch2_2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(ch2_2 PRIVATE cxx_std_17)
