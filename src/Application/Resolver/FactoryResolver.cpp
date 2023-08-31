//
// Created by Julian Sommer on 28.08.23.
//

#include "FactoryResolver.h"

AbstractFactory *FactoryResolver::getFactoryPointer(std::string factoryClassName) {
    return this->getContainer()->getFactory(factoryClassName);
}
