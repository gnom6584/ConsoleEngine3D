//
//  GameObject.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef GameObject_hpp
#define GameObject_hpp

#include <unordered_map>
#include <memory>
#include <string>

#include "Component.hpp"
#include "Transform.hpp"

class Scene;

class GameObject final {
public:
    template<typename T>
    T& addComponent();
    
    template<typename T>
    T& getComponent();
    
    template<typename T>
    bool hasComponent();
    
    template<typename T>
    void removeComponent();
        
    void destroy();
    
    const std::string& getName() const;
    
    Scene& getScene() const;
    
    Transform& getTransform();
private:
    std::unordered_map<std::string, std::unique_ptr<Component>> components;
    std::string name;
    bool isDestroyed;
    Scene* scene;
    Transform transform;
    
    void callComponentsUpdates();
    GameObject(const std::string name, Scene* scene);
friend Scene;
};

#include "GameObject.ipp"

#endif /* GameObject_hpp */
