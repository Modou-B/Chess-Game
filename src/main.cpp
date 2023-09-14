#include <QApplication>
#include <QWidget>
#include <string>
#include "MainFacade.h"
#include "Application/ServiceRegistry.h"
#include "iostream"
#include <filesystem>

int main(int argc, char *argv[]) {

    std::cout << "asdasd " << std::filesystem::current_path() << std::endl;

    QApplication app(argc, argv);

    ServiceRegistry::registerServices();

    MainFacade mainFacade = MainFacade();
    QWidget *window = new QWidget;

    mainFacade.initializeChessGame();
    mainFacade.initializeGui(window);

    window->show();

    return QApplication::exec();
}

