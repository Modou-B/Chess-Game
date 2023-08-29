//
// Created by Julian Sommer on 28.08.23.
//

#ifndef CHESSAPPLICATION_ABSTRACTRESOLVER_H
#define CHESSAPPLICATION_ABSTRACTRESOLVER_H

#include "../Container/Container.h"

class AbstractResolver {
private:
    static Container* container;

public:
    Container* getContainer();

    static void setContainer(Container* serviceContainer);
};


#endif //CHESSAPPLICATION_ABSTRACTRESOLVER_H
