cmake_minimum_required(VERSION 3.10)
project(SFML_Project)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES 
    Game/Game.cpp
    Game/Player.cpp
    Game/Entity.cpp
    main.cpp
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(NotTimeToRelax ${SOURCES})
target_link_libraries(NotTimeToRelax PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system
)

target_include_directories(NotTimeToRelax PUBLIC 
    Game/
)
