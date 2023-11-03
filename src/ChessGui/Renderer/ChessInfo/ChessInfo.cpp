//
// Created by modou on 03.11.2023.
//

#include "ChessInfo.h"

ChessInfo::ChessInfo() {
    connect(this, &QPushButton::released, this, &ChessInfo::getChessInfo);
}

void ChessInfo::getChessInfo() {
    QDesktopServices::openUrl(QUrl("https://www.wiki-schacharena.de/Schachregeln_f%C3%BCr_Einsteiger", QUrl::TolerantMode));
}