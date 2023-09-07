file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(ChessGuiLib
        ${SOURCES})

target_link_libraries(ChessGuiLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(ChessGuiLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})