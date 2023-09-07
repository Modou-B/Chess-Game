file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(SharedLib
        ${SOURCES})

target_include_directories(SharedLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})