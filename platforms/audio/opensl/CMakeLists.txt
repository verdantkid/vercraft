cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-audio-opensl)

# Build
add_library(Vercraft-audio STATIC
	SoundSystemOSL.cpp
)

# Core
target_link_libraries(Vercraft-audio PUBLIC Vercraft-core)

# OpenSL
target_link_libraries(Vercraft-audio PUBLIC OpenSLES)

# Headers
target_include_directories(Vercraft-audio PUBLIC .)
