//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_ABSTRACTFACTORY_H
#define CHESSAPPLICATION_ABSTRACTFACTORY_H

#include "../Resolver/FacadeResolver.h"

class AbstractFactory {
public:
    FacadeResolver getFacadeResolver();

    AbstractFacade* findFacade(std::string facadeName);
};


#endif //CHESSAPPLICATION_ABSTRACTFACTORY_H
