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
    mainFacade.testResolver();

    QWidget *window = new QWidget;

    QGridLayout *layout = new QGridLayout(window);

    int count = 0;
    int counter = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            count = j + i * 8 + 1;



            QueenPiece *piece = new QueenPiece;

            ChessCell *chessCell = new ChessCell(piece);

            QString str = QString::fromStdString(piece->getType());

            chessCell->setText(str);
            QPalette pal = chessCell->palette();
            if (j % 2 - counter == 0) {

                pal.setColor(QPalette::Button, QColor(Qt::black));

            } else {
                pal.setColor(QPalette::Button, QColor(Qt::white));
                pal.setColor(QPalette::ButtonText, QColor(Qt::black));

            }
            chessCell->setAutoFillBackground(true);
            chessCell->setPalette(pal);
            chessCell->update();
            chessCell->setMinimumSize(50,50);
            chessCell->setMaximumSize(1000,1000);
            layout->addWidget(chessCell, i, j);
        }

        counter++;

        if (counter > 1) {
            counter = 0;
        }
    }

    layout->setSpacing(0);
    window->show();

    return QApplication::exec();
}

