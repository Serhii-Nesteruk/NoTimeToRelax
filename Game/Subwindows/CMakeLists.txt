file(GLOB SUBWINDOWS_SOURCES
    "sources/*.cpp"
)

file(GLOB SUBWINDOWS_HEADERS
    "includes/*.h"
)

add_library(Subwindows ${SUBWINDOWS_SOURCES} ${SUBWINDOWS_HEADERS})

target_include_directories(Subwindows PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
    "${CMAKE_SOURCE_DIR}/Game/Patterns/includes"
    "${CMAKE_SOURCE_DIR}/Game/Controllers/includes"
    "${CMAKE_SOURCE_DIR}/Game/Core/includes"
)

target_link_libraries(Subwindows PRIVATE 
    Core
)