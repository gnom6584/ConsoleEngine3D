//
//  GameObject.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "GameObject.hpp"
#include "Scene.hpp"
#include "Transform.hpp"

GameObject::GameObject(const std::string name, Scene* scene) : name(name), scene(scene), isDestroyed(false) {}

void GameObject::callComponentsUpdates() { 
    for(auto& component : components){
        if(component.second->isEnabled()){
            component.second->onUpdate();
        }
    }
}

Scene &GameObject::getScene() const {
    return *scene;
}

void GameObject::destroy(){
    isDestroyed = true;
}

const std::string& GameObject::getName() const{
    return name;
}

Transform &GameObject::getTransform() { 
    return transform;
}
