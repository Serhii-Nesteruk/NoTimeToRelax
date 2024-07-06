cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game/Core)
add_subdirectory(Game/Patterns)

set(SOURCES 
    main.cpp
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(NotTimeToRelax ${SOURCES})

target_link_libraries(NotTimeToRelax PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system
    Core
    Patterns
)