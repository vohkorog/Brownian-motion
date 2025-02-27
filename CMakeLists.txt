cmake_minimum_required(VERSION 3.19)

project(sfml_game VERSION 1.0.0)

set(FILES)

file(GLOB FILES 
    "src/*.cpp"
    "src/*.h"
)

add_executable(app ${FILES})

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIR})
target_link_libraries(app OpenGL::GL)

if(APPLE)
    set(SFML_PATH /opt/homebrew/Cellar/sfml/2.6.1)

    target_include_directories(app PUBLIC ${SFML_PATH}/include)
    
    target_link_libraries(app ${SFML_PATH}/lib/libsfml-graphics.2.6.1.dylib)
    target_link_libraries(app ${SFML_PATH}/lib/libsfml-network.2.6.1.dylib)
    target_link_libraries(app ${SFML_PATH}/lib/libsfml-system.2.6.1.dylib)
    target_link_libraries(app ${SFML_PATH}/lib/libsfml-window.2.6.1.dylib)
    target_link_libraries(app ${SFML_PATH}/lib/libsfml-audio.2.6.1.dylib)

    target_link_libraries(app "-framework Cocoa -framework IOKit")
endif()

if (WIN32)
    set(SFML_PATH D:\\Projects\\c++\\libs\\SFML-2.5.1)

    target_include_directories(app PUBLIC ${SFML_PATH}\\include)

    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-main-d.lib)
    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-graphics-d.lib)
    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-network-d.lib)
    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-system-d.lib)
    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-window-d.lib)
    target_link_libraries(app ${SFML_PATH}\\lib\\sfml-audio-d.lib)
endif()