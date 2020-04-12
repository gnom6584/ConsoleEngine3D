//
//  Component.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Component.hpp"
#include "GameObject.hpp"

GameObject& Component::getGameObject() const { 
    return *gameObject;
}

bool Component::isEnabled() const {
    return enabled;
}

void Component::setEnable(bool state) { 
    enabled = state;
}

