//
// Created by Julian Sommer on 07.09.23.
//

#ifndef CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
#define CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H

class ChessField;
class ChessCreator;

class GameApplicationManager {
private:
    ChessCreator *chessCreator;

public:
    GameApplicationManager(ChessCreator *chessCreator);

    void initiateChessApplication();
};


#endif //CHESSAPPLICATION_GAMEAPPLICATIONMANAGER_H
