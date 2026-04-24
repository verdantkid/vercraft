cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-audio-xaudio2)

# Build
add_library(Vercraft-audio STATIC
    SoundSystemXA2.cpp
)

# Libraries
target_link_libraries(Vercraft-audio
    Vercraft-core
    xaudio2
)

# Headers
target_include_directories(Vercraft-audio PUBLIC .)
