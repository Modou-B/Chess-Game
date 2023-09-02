//
// Created by Julian Sommer on 27.08.23.
//

#include "ChessFacade.h"
#include "Model/ChessCell.h"

ChessField *ChessFacade::createChessField() {
    return ChessFacade::getFactory()->createChessCreator()->createChessField();
}

ChessCell *ChessFacade::createChessCell(ChessCellTransfer *chessCellTransfer) {
    return ChessFacade::getFactory()->createChessCreator()->createChessCell(chessCellTransfer);
}

BaseChessPiece *ChessFacade::createChessPiece(ChessPieceTransfer *chessPieceTransfer) {
    return ChessFacade::getFactory()->createChessCreator()->createChessPiece(chessPieceTransfer);
}

ChessFactory *ChessFacade::getFactory() {
    return static_cast<ChessFactory*>(this->findFactory(typeid(ChessFactory).name()));
}