file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(MultiplayerLib
        ${SOURCES})

target_link_libraries(MultiplayerLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        )

target_include_directories(MultiplayerLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})