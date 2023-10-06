//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_PLAYERLABEL_H
#define CHESSAPPLICATION_PLAYERLABEL_H

#include "QLabel"
#include <string>

using namespace std;

class PlayerLabel : public QLabel {
private:
    string labelText;

public:
    PlayerLabel(string labelText);

    void setCurrentPlayerColor();
    void removeCurrentPlayerColor();
};


#endif //CHESSAPPLICATION_PLAYERLABEL_H
