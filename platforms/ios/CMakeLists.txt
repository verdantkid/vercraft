cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-ios)

target_compile_definitions(Vercraft-core PUBLIC HANDLE_CHARS_SEPARATELY USE_GLES)

# Build
add_executable(Vercraft
    AppPlatform_iOS.mm
    EAGLView.m
    main.m
    NBCAppDelegate.mm
    NBCViewController.mm
    ShowKeyboardView.mm
)

# Core
target_link_libraries(Vercraft Vercraft-core)

# stb_image
target_link_libraries(Vercraft stb_image)

# libobjc
target_link_libraries(Vercraft objc)

# frameworks
target_link_libraries(Vercraft
    "-framework CoreGraphics"
    "-framework QuartzCore"
    "-framework Foundation"
    "-framework AVFoundation"
    "-framework UIKit"
    "-framework OpenGLES"
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../source/client/app)

# Check for the presence of some optional asset based features.
if(EXISTS "${MC_ROOT}/game/assets/gui/background/panorama_0.png")
    target_compile_definitions(Vercraft PUBLIC FEATURE_MENU_BACKGROUND)
endif()
if(EXISTS "${MC_ROOT}/game/assets/environment/clouds.png")
    target_compile_definitions(Vercraft PUBLIC FEATURE_CLOUDS)
endif()
if(EXISTS "${MC_ROOT}/game/assets/misc/grasscolor.png")
    target_compile_definitions(Vercraft PUBLIC FEATURE_GRASS_COLOR)
endif()
if(EXISTS "${MC_ROOT}/game/assets/misc/foliagecolor.png")
    target_compile_definitions(Vercraft PUBLIC FEATURE_FOLIAGE_COLOR)
endif()
