//
// Created by Julian Sommer on 28.08.23.
//

#ifndef CHESSAPPLICATION_FACADERESOLVER_H
#define CHESSAPPLICATION_FACADERESOLVER_H

#include "AbstractResolver.h"

class FacadeResolver: public AbstractResolver {
public:
    AbstractFacade *getFacadePointer(std::string facadeClassName);
};


#endif //CHESSAPPLICATION_FACADERESOLVER_H
