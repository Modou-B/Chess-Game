//
// Created by Julian Sommer on 28.08.23.
//

#ifndef CHESSAPPLICATION_FACTORYRESOLVER_H
#define CHESSAPPLICATION_FACTORYRESOLVER_H

#include "AbstractResolver.h"

class FactoryResolver: public AbstractResolver {
public:
    AbstractFactory *getFactoryPointer(std::string factoryClassName);
};


#endif //CHESSAPPLICATION_FACTORYRESOLVER_H
