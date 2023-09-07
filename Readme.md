# Chess Application made with Qt written in C++

## Design Structure:
- Source code is split up into modules
  - each module has a Facade and a factory
  
- Facades are the only entry point into the functionality of the module

- Factories initiate the needed classes that execute the logic of the facade methods
  - Factories can also retrieve the facades of other modules via the DI container
  
####Important
- If you create a new module you need to register the facade and factory inside the ServiceRegistry class to be able to retrieve them later
  
## Project Design
- The entry point of the whole project is the MainFacade. The MainFacade calls the facades from other modules to initiate the chess application

- The gui of the chess board is a 8x8 Qt QGridlayout where every ChessGuiCell is a child of the QPushButton class
- The logic of the application is handled via a different chessField variable inside the GameApplication class
