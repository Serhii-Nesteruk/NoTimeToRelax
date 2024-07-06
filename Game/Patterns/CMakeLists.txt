file(GLOB PATTERNS_HEADERS
    "includes/*.h"
)

add_library(Patterns INTERFACE)

target_include_directories(Patterns INTERFACE ${PATTERNS_HEADERS})
