cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-audio-directsound)

# Build
add_library(Vercraft-audio STATIC
    SoundSystemDS.cpp
    SoundStreamDS.cpp
)

# Libraries
target_link_libraries(Vercraft-audio
    Vercraft-core
    dsound
    dxguid
)

# Headers
target_include_directories(Vercraft-audio PUBLIC .)
