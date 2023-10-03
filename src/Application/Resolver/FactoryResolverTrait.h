//
// Created by Julian Sommer on 01.10.23.
//

#ifndef CHESSAPPLICATION_FACTORYRESOLVERTRAIT_H
#define CHESSAPPLICATION_FACTORYRESOLVERTRAIT_H

#include <string>

using namespace std;

class FactoryResolver;
class AbstractFactory;

namespace FactoryResolverTrait {
    FactoryResolver createFactoryResolver();

    AbstractFactory *findFactory(string factoryClassName);
};

#endif // CHESSAPPLICATION_FACTORYRESOLVERTRAIT_H
