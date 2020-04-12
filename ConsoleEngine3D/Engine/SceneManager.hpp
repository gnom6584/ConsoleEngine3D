//
//  SceneManager.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 05/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <memory>
#include <stack>
#include <vector>

#include "Scene.hpp"

class Engine;

class SceneManager final{
public:
    template<typename T>
    T& setCurrentScene(){
        T* newScene = new T();
        newScene->sceneManager = this;
        scenesStack.push(std::unique_ptr<T>(newScene));
        return *newScene;
    }
    void processCurrentScene();
    
    void removeCurrentScene();
private:
    std::stack<std::unique_ptr<Scene>> scenesStack;
    SceneManager() = default;
friend Engine;
};

#endif /* SceneManager_hpp */
