//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_MAINFACADE_H
#define CHESSAPPLICATION_MAINFACADE_H

#include "Application/Facade/AbstractFacade.h"
#include "MainFactory.h"
#include "typeinfo"

class MainFacade: AbstractFacade {
public:
    void testResolver();
    MainFactory * getFactory() override;
};


#endif //CHESSAPPLICATION_MAINFACADE_H
