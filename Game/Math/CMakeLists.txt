file(GLOB MATH_SOURCES
    "sources/*.cpp"
)

file(GLOB MATH_HEADERS
    "includes/*.h"
)

add_library(Math ${MATH_SOURCES} ${MATH_HEADERS})

target_include_directories(Math PUBLIC 
    "includes"
)