//
// Created by Julian Sommer on 28.08.23.
//

#include "AbstractResolver.h"

Container* AbstractResolver::container = nullptr;

void AbstractResolver::setContainer(Container *serviceContainer) {
    AbstractResolver::container = serviceContainer;
}

Container *AbstractResolver::getContainer() {
    return AbstractResolver::container;
}