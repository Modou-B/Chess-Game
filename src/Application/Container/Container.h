//
// Created by Julian Sommer on 27.08.23.
//

#ifndef CHESSAPPLICATION_CONTAINER_H
#define CHESSAPPLICATION_CONTAINER_H

#include <map>
#include <functional>
#include <string>

class AbstractFactory;
class AbstractFacade;

class Container {
private:
    static std::map<std::string, std::function<std::shared_ptr<AbstractFacade>()>> facadeMap;
    static std::map<std::string, std::function<std::shared_ptr<AbstractFactory>()>> factoryMap;

public:
    AbstractFacade* getFacade(std::string facadeClassName);
    AbstractFactory* getFactory(std::string factoryClassName);

    void setFacade(std::string facadeClassName, std::function<std::shared_ptr<AbstractFacade>()> callback);
    void setFactory(std::string factoryClassName, std::function<std::shared_ptr<AbstractFactory>()> callback);
};


#endif //CHESSAPPLICATION_CONTAINER_H
