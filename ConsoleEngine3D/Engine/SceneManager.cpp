//
//  SceneManager.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 05/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "SceneManager.hpp"

void SceneManager::processCurrentScene() {
    scenesStack.top()->updateGameObjects();
}

void SceneManager::removeCurrentScene() { 
    scenesStack.pop();
}
