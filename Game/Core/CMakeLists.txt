file(GLOB CORE_HEADERS
    "includes/*.h"
)

file(GLOB CORE_SOURCES
    "sources/*.cpp"
)

add_library(Core ${CORE_HEADERS} ${CORE_SOURCES})

target_include_directories(Core PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
    "${CMAKE_SOURCE_DIR}/Game/Patterns/includes"
    "${CMAKE_SOURCE_DIR}/Game/Controllers/includes"
    "${CMAKE_SOURCE_DIR}/Game/Map/includes"
    "${CMAKE_SOURCE_DIR}/Game/Math/includes"
)
