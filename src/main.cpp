#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStandardItemModel>
#include <string>
#include "MainFacade.h"
#include "Application/ServiceRegistry.h"
#include "Chess/ChessPiece/QueenPiece.h"
#include "Chess/Model/ChessCell.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ServiceRegistry::registerServices();

    MainFacade mainFacade = MainFacade();
    QWidget *window = new QWidget;

    mainFacade.initializeGui(window);

    window->show();

    return QApplication::exec();
}

