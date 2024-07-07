file(GLOB CONTROLLERS_SOURCES
    "sources/*.cpp"
)

file(GLOB CONTROLLERS_HEADERS
    "includes/*.h"
)

add_library(Controllers ${CONTROLLERS_SOURCES} ${CONTROLLERS_HEADERS})

target_include_directories(Controllers PRIVATE 
    ${CMAKE_SOURCE_DIR}/Game/Controllers/includes
)

target_link_libraries(Controllers PRIVATE Core)