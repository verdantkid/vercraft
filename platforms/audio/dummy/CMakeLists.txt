cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-audio-dummy)

# Build
add_library(Vercraft-audio STATIC
	SoundSystemNull.cpp
)

target_link_libraries(Vercraft-audio PUBLIC Vercraft-core)

# Headers
target_include_directories(Vercraft-audio PUBLIC .)
