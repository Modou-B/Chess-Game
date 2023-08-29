file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(ApplicationLib
        ${SOURCES})

target_include_directories(ApplicationLib PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        )