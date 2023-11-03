file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(ChessGuiLib
        ${SOURCES}
        Renderer/ChessInfo/ChessInfo.cpp
        Renderer/ChessInfo/ChessInfo.h
        Renderer/BackToMenu/BackToMenu.cpp
        Renderer/BackToMenu/BackToMenu.h)

target_link_libraries(ChessGuiLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

target_include_directories(ChessGuiLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})