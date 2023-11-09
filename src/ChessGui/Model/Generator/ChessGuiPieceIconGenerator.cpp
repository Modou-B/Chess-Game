//
// Created by Julian Sommer on 14.09.23.
//

#include "ChessGuiPieceIconGenerator.h"
#include "QIcon"
#include "QColor"
#include "Qt"
#include "../../../Shared/ChessGui/ChessGuiConstants.h"
#include <filesystem>
#include "QWidget"
#include <utility>
#include "QPainter"

QIcon ChessGuiPieceIconGenerator::generateIconFromFile(std::string fileName) {
    auto pathToFile = this->getFullPathToFile(fileName);

    return QIcon(QString::fromStdString(pathToFile));
}

QIcon ChessGuiPieceIconGenerator::generateTransparentIconFromFile(std::string fileName) {
    auto pathToFile = this->getFullPathToFile(fileName);

    auto pixmap = QPixmap(QString::fromStdString(pathToFile));
    auto mask = pixmap.createMaskFromColor(QColor(Qt::black), Qt::MaskOutColor);
    pixmap.fill(ChessGuiConstants::CELL_BLACK_COLOR);
    pixmap.setMask(mask);

    return QIcon(pixmap);
}

QIcon ChessGuiPieceIconGenerator::generateEmptyIcon() {
    return QIcon();
}

std::string ChessGuiPieceIconGenerator::getFullPathToFile(std::string fileName) {
    std::string pathToFile = std::filesystem::current_path().string();

    pathToFile.append("/../../public/");
    pathToFile.append(fileName);

    return pathToFile;
}
