//
// Created by Julian Sommer on 26.08.23.
//

#include "ChessCell.h"

ChessCell::ChessCell(BaseChessPiece *chessPiece, std::pair<int, int> coordinates) {
    this->chessPiece = chessPiece;
    this->coordinates = coordinates;
}

void ChessCell::handleCellClick() {
    /*
    std::cout << this->chessFieldModel->wasCellWithChessPieceClicked() << std::endl;

    if (!this->chessFieldModel->wasCellWithChessPieceClicked() && this->chessPiece) {
        this->chessFieldModel->toggleCellWithChessPieceClickedValue();

        this->chessFieldModel->setPreviouslyClickedCellCoordinates(this->coordinates);

        return;
    }

    if (this->chessFieldModel->wasCellWithChessPieceClicked()) {
        std::cout << "this->chessFieldModel->wasCellWithChessPieceClicked()" << std::endl;

        auto previouslyClickedCellCoordinates = this->chessFieldModel->getPreviouslyClickedCellCoordinates();
        auto previousChessCell = this->chessFieldModel->getChessCell(
                previouslyClickedCellCoordinates.first,
                previouslyClickedCellCoordinates.second
        );

        this->chessPiece = previousChessCell->getChessPiece();


        auto *chessCell = new ChessCell(
                nullptr,
                nullptr,
        previouslyClickedCellCoordinates);

        this->chessFieldModel->getGridLayout()->addWidget(previousChessCell, this->getCoordinates().first, this->getCoordinates().second);
        this->chessFieldModel->getGridLayout()->addWidget(chessCell, previousChessCell->getCoordinates().first, previousChessCell->getCoordinates().second);

        this->chessFieldModel->toggleCellWithChessPieceClickedValue();
    }
*/
    return;
}

void ChessCell::setChessPiece(BaseChessPiece *baseChessPiece) {
    this->chessPiece = baseChessPiece;
}

std::pair<int, int> ChessCell::getCoordinates() {
    return this->coordinates;
}

BaseChessPiece *ChessCell::getChessPiece() {
    return this->chessPiece;
}
