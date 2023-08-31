//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_ABSTRACTFACADE_H
#define CHESSAPPLICATION_ABSTRACTFACADE_H

#include "../Factory/AbstractFactory.h"
#include "../Resolver/FactoryResolver.h"
#include <memory>
#include <string>

class AbstractFacade {
private:
    AbstractFactory* factory;

protected:
    FactoryResolver getFactoryResolver();
public:
    virtual AbstractFactory *getFactory();

    AbstractFactory *findFactory(std::string factoryClassName);
};


#endif //CHESSAPPLICATION_ABSTRACTFACADE_H
