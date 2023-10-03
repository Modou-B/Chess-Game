add_subdirectory(Application)
add_subdirectory(Chess)
add_subdirectory(ChessGui)
add_subdirectory(Shared)
add_subdirectory(ChessTimeline)

add_library(MainLib
        MainFacade.cpp
        MainFacade.h
        MainFactory.cpp
        MainFactory.h
        )

add_executable(ChessApplication main.cpp)

target_link_libraries(ChessApplication
        Qt::Core
        Qt::Gui
        Qt::Widgets
        ChessLib
        ChessGuiLib
        ChessTimelineLib
        MainLib
        ApplicationLib
        SharedLib
        )


