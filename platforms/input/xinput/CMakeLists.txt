cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-input-xinput)

# Build
add_library(Vercraft-input STATIC
	GameControllerHandler_xinput.cpp
	XInput.cpp
)

target_link_libraries(Vercraft-input
	PUBLIC xinput
)

target_link_libraries(Vercraft-input PUBLIC Vercraft-core)

# Headers
target_include_directories(Vercraft-input PUBLIC .)
