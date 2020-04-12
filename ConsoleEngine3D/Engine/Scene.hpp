//
//  Scene.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 05/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Scene_hpp
#define Scene_hpp

#include <string>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "GameObject.hpp"

class SceneManager;

class Scene{
public:
    GameObject& createGameObject(const std::string& name);
    
    GameObject& getGameObjectWithName(const std::string& name);
    
    std::vector<std::reference_wrapper<GameObject>> getGameObjectsWithName(const std::string& name);
    
    bool hasGameObjectWithName(const std::string& name);
    
    SceneManager& getSceneManager() const;
private:
    SceneManager* sceneManager;
    std::unordered_map<std::string, std::unordered_set<std::shared_ptr<GameObject>>> gameObjects;
    
    void updateGameObjects();
friend SceneManager;
};
#endif /* Scene_hpp */
