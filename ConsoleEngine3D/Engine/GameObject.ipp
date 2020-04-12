//
//  GameObject.ipp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef GameObject_ipp
#define GameObject_ipp

#include <typeinfo>

#include "GameObject.hpp"

template<typename T>
T& GameObject::addComponent(){
    auto typeName = typeid(T).name();
    auto newComponent = new T();
    newComponent->gameObject = this;
    components.insert(std::make_pair(typeName, std::unique_ptr<T>(newComponent)));
    return *newComponent;
}


template<typename T>
T& GameObject::getComponent(){
    auto typeName = typeid(T).name();
    return (T&)(*components[typeName]);
}

template<typename T>
bool GameObject::hasComponent(){
    auto typeName = typeid(T).name();
    return components.count(typeName);
}


template<typename T>
void GameObject::removeComponent(){
    auto typeName = typeid(T).name();
    components.erase(typeName);
}


#endif /* GameObject_ipp */
