//
//  Scene.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 05/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Scene.hpp"
#include "SceneManager.hpp"

GameObject& Scene::createGameObject(const std::string &name) { 
    auto newGameObject = new GameObject(name, this);
    gameObjects[name].insert(std::shared_ptr<GameObject>(newGameObject));
    return *newGameObject;
}

GameObject& Scene::getGameObjectWithName(const std::string &name) {
    return *gameObjects[name].begin()->get();
}

std::vector<std::reference_wrapper<GameObject>> Scene::getGameObjectsWithName(const std::string &name) {
    std::vector<std::reference_wrapper<GameObject>> outputGameObjects;
    auto gameObjectsWithName = gameObjects[name];
    for(auto& gameObject : gameObjectsWithName){
        outputGameObjects.push_back(*gameObject);
    }
    return outputGameObjects;
}

bool Scene::hasGameObjectWithName(const std::string &name) {
    if(gameObjects.count(name)){
        auto gameObjectsWithName = gameObjects[name];
        if(gameObjectsWithName.size() > 0){
            return true;
        }
    }
    return false;
}
#include <iostream>
void Scene::updateGameObjects() { 
    for(auto& gameObjectsNames : gameObjects){
        auto gameObjectIterator = gameObjectsNames.second.begin();
        while (gameObjectIterator != gameObjectsNames.second.end()) {
            if (gameObjectIterator->get()->isDestroyed) {
                gameObjectIterator = gameObjectsNames.second.erase(gameObjectIterator);
            }
            else {
                gameObjectIterator->get()->callComponentsUpdates();
                gameObjectIterator++;
            }
        }
    };
}


SceneManager &Scene::getSceneManager() const{ 
    return *sceneManager;
}
