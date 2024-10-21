cmake_minimum_required(VERSION 3.10)

project(feur VERSION 0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D__USE_MINGW_ANSI_STDIO=1")



add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/feur/src/main.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Game.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Game.hpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/State/State.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/State/State.hpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/State/MenuState.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/State/MenuState.hpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Interactable/IClickable.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Interactable/IClickable.hpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Interactable/Button.cpp
    ${CMAKE_SOURCE_DIR}/feur/src/Engine/Interactable/Button.hpp
)

include_directories(${CMAKE_SOURCE_DIR}/feur/vendor/sfml/include)

set(SFML_LIB_DIR "${CMAKE_SOURCE_DIR}/feur/vendor/sfml/lib")
set(SFML_DLL_DIR "${CMAKE_SOURCE_DIR}/feur/vendor/sfml/bin")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_link_libraries(${PROJECT_NAME}
        "${SFML_LIB_DIR}/openal32.lib"
        "${SFML_LIB_DIR}/sfml-audio-d.lib"
        "${SFML_LIB_DIR}/sfml-graphics-d.lib"
        "${SFML_LIB_DIR}/sfml-system-d.lib"
        "${SFML_LIB_DIR}/sfml-window-d.lib"
        "${SFML_DLL_DIR}/openal32.dll"
        "${SFML_LIB_DIR}/sfml-audio-d-2.dll"
        "${SFML_LIB_DIR}/sfml-graphics-d-2.dll"
        "${SFML_LIB_DIR}/sfml-system-d-2.dll"
        "${SFML_LIB_DIR}/sfml-window-d-2.dll"
    )
else()
    target_link_libraries(${PROJECT_NAME}
        "${SFML_LIB_DIR}/openal32.lib"
        "${SFML_LIB_DIR}/sfml-audio.lib"
        "${SFML_LIB_DIR}/sfml-graphics.lib"
        "${SFML_LIB_DIR}/sfml-system.lib"
        "${SFML_LIB_DIR}/sfml-window.lib"
        "${SFML_DLL_DIR}/openal32.dll"
        "${SFML_DLL_DIR}/sfml-audio-2.dll"
        "${SFML_DLL_DIR}/sfml-graphics-2.dll"
        "${SFML_DLL_DIR}/sfml-system-2.dll"
        "${SFML_DLL_DIR}/sfml-window-2.dll"
    )
endif()

