file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(ChessTimelineLib
        ${SOURCES})

target_include_directories(ChessTimelineLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})