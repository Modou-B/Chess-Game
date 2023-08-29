//
// Created by Julian Sommer on 28.08.23.
//

#include "FacadeResolver.h"

AbstractFacade *FacadeResolver::getFacadePointer(std::string facadeClassName) {
    return this->getContainer()->getFacade(facadeClassName);
}
