//
// Created by Julian Sommer on 27.08.23.
//

#include "AbstractFactory.h"

FacadeResolver AbstractFactory::getFacadeResolver() {
    return FacadeResolver();
}

AbstractFacade *AbstractFactory::findFacade(std::string facadeName) {
    return this->getFacadeResolver().getFacadePointer(facadeName);
}
