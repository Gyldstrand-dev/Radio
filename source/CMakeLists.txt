cmake_minimum_required(VERSION 3.2)
project(Radio)

add_executable(
	Radio
	main.cpp
)

target_compile_options(Radio PUBLIC -std=c++17)