//
// Created by Julian Sommer on 01.10.23.
//

#include "FactoryResolverTrait.h"
#include "FactoryResolver.h"

FactoryResolver FactoryResolverTrait::createFactoryResolver() {
    return FactoryResolver();
}

AbstractFactory* FactoryResolverTrait::findFactory(string factoryClassName) {
    return FactoryResolverTrait::createFactoryResolver().getFactoryPointer(factoryClassName);
}