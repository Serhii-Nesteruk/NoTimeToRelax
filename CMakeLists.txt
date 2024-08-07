cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game/Subwindows)
add_subdirectory(Game/Core)
add_subdirectory(Game/Patterns)
add_subdirectory(Game/Controllers)
add_subdirectory(Game/Map)
add_subdirectory(Game/Math)

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
    Controllers
    Subwindows
    Map
)

target_include_directories(NotTimeToRelax PRIVATE 
    "${CMAKE_SOURCE_DIR}/Game/Core/includes"
    "${CMAKE_SOURCE_DIR}/Game/Patterns/includes"
    "${CMAKE_SOURCE_DIR}/Game/Controllers/includes"
)