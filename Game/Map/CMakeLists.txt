    file(GLOB MAP_SOURCES
    "sources/*.cpp"
)

file(GLOB MAP_HEADERS
    "includes/*.h"
)

add_library(Map ${MAP_SOURCES} ${MAP_HEADERS})

target_include_directories(Map PUBLIC 
    "includes"
    "${CMAKE_SOURCE_DIR}/Game/Patterns/includes"
    "${CMAKE_SOURCE_DIR}/Game/Controllers/includes"s
    "${CMAKE_SOURCE_DIR}/Game/Core/includes"
    "${CMAKE_SOURCE_DIR}/Game/Subwindows/includes"
)

target_link_libraries(Map PRIVATE 
    Core
    Subwindows
)