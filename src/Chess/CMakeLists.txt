file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(ChessLib
        ${SOURCES})

target_link_libraries(ChessLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(ChessLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})