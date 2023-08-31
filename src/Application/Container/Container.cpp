//
// Created by Julian Sommer on 27.08.23.
//

#include "Container.h"

std::map<std::string, std::function<std::shared_ptr<AbstractFacade>()>> Container::facadeMap;
std::map<std::string, std::function<std::shared_ptr<AbstractFactory>()>> Container::factoryMap;

void Container::setFacade(std::string facadeClassName, std::function<std::shared_ptr<AbstractFacade>()> callback) {
    facadeMap[facadeClassName] = callback;
}

void Container::setFactory(std::string factoryClassName, std::function<std::shared_ptr<AbstractFactory>()> callback) {
    factoryMap[factoryClassName] = callback;
}

AbstractFacade *Container::getFacade(std::string facadeClassName) {
    return facadeMap[facadeClassName]().get();
}

AbstractFactory* Container::getFactory(std::string factoryClassName) {
    return factoryMap[factoryClassName]().get();
}

