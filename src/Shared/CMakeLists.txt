file(GLOB_RECURSE SOURCES
        *.h
        *.cpp
        )

add_library(SharedLib
        ${SOURCES})

target_link_libraries(SharedLib
        Qt::Core
        Qt::Gui
        Qt::Widgets
        Qt::Network
        )

target_include_directories(SharedLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})