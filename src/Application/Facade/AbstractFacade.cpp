//
// Created by Julian Sommer on 27.08.23.
//

#include "AbstractFacade.h"

FactoryResolver AbstractFacade::getFactoryResolver() {
    return FactoryResolver();
}

AbstractFactory* AbstractFacade::findFactory(std::string factoryClassName) {
    if (!this->factory) {
        this->factory = this->getFactoryResolver().getFactoryPointer(factoryClassName);
    }

    return this->factory;
}

AbstractFactory *AbstractFacade::getFactory() {
    return nullptr;
}
