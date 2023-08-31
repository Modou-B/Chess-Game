//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_SERVICEREGISTRY_H
#define CHESSAPPLICATION_SERVICEREGISTRY_H

#include "Container/Container.h"

class ServiceRegistry {

public:
    static void registerServices();

    static void addFactories(Container *serviceContainer);

    static void addFacades(Container *serviceContainer);
};


#endif //CHESSAPPLICATION_SERVICEREGISTRY_H
