    file(GLOB MAP_SOURCES
    "sources/*.cpp"
)

file(GLOB MAP_HEADERS
    "includes/*.h"
)

add_library(Map ${MAP_SOURCES} ${MAP_HEADERS})

target_include_directories(Map PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
    "${CMAKE_SOURCE_DIR}/Game/Patterns/includes"
    "${CMAKE_SOURCE_DIR}/Game/Controllers/includes"
    "${CMAKE_SOURCE_DIR}/Game/Core/includes"
    "${CMAKE_SOURCE_DIR}/Game/Subwindows/includes"
    "${CMAKE_SOURCE_DIR}/Game/Math"
)

target_link_libraries(Map PRIVATE 
    Subwindows
    Math
)