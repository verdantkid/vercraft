cmake_minimum_required(VERSION 3.16.0)
project(Vercraft-windows)

# Win32 Build
target_compile_definitions(Vercraft-core
    PUBLIC HANDLE_CHARS_SEPARATELY
)

# Libraries
target_link_libraries(Vercraft-core
    PUBLIC gdi32
    PUBLIC uuid
)

if(NBC_GFX_API STREQUAL "OGL")
    target_link_libraries(Vercraft-core
        PUBLIC opengl32
        PUBLIC glu32
    )
elseif(NBC_GFX_API STREQUAL "D3D11")
    target_link_libraries(Vercraft-core
        PUBLIC d3d11
        PUBLIC d3dcompiler
        PUBLIC dxgi
        PUBLIC dxguid
    )
endif()

set(ICON_FILE "${CMAKE_SOURCE_DIR}/game/assets/app/icons/icon.ico")
configure_file(
    VercraftClient.Win32.rc
    ${CMAKE_CURRENT_SOURCE_DIR}/VercraftClient.Win32.configured.rc
    @ONLY
)

# Build
add_executable(Vercraft WIN32
    LoggerWin32.cpp
    AppPlatform_win32.cpp
    main.cpp
    VercraftClient.Win32.configured.rc
)

# Core
target_link_libraries(Vercraft Vercraft-core)

# stb_image (If Needed)
target_link_libraries(Vercraft stb_image)
