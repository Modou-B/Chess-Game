#include <QApplication>
#include <QWidget>
#include <string>
#include "MainFacade.h"
#include "Application/ServiceRegistry.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ServiceRegistry::registerServices();

    MainFacade mainFacade = MainFacade();
    QWidget *window = new QWidget;

    mainFacade.initializeChessGame();
    mainFacade.initializeGui(window);
    window->setFixedSize(500,400);

    window->show();

    return QApplication::exec();
}

