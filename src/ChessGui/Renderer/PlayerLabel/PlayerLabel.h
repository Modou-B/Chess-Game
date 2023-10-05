//
// Created by Modou on 05.10.23.
//

#ifndef CHESSAPPLICATION_PLAYERLABEL_H
#define CHESSAPPLICATION_PLAYERLABEL_H

#include "QLabel"

class PlayerLabel : public QLabel {

private:
public:
    void setCurrentPlayerColor();
    void removeCurrentPlayerColor();
};


#endif //CHESSAPPLICATION_PLAYERLABEL_H
