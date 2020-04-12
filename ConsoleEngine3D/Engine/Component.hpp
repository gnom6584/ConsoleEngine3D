//
//  Component.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 03/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

class GameObject;

class Component {
public:
    virtual void onUpdate() = 0;
    
    GameObject& getGameObject() const;
    
    virtual ~Component() = default;
    
    bool isEnabled() const;
    
    void setEnable(bool state);
private:
    GameObject* gameObject;
    bool enabled = true;
    
    void* operator = (const Component& component) = delete;
friend GameObject;
};

#endif /* Component_hpp */
