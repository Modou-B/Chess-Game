file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(MultiplayerGuiLib
        ${SOURCES})

target_link_libraries(MultiplayerGuiLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        )

target_include_directories(MultiplayerGuiLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})