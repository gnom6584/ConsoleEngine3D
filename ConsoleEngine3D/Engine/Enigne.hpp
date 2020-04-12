//
//  Enigne.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Enigne_hpp
#define Enigne_hpp

#include "SceneManager.hpp"
#include "Display.hpp"
#include "Painter3D.hpp"
#include "RenderPipeLine.hpp"

class Engine{
public:
    Engine(Display& display, float frameRate = 30);
    
    template<typename LaunchScene>
    void start(){
        sceneManager.setCurrentScene<LaunchScene>();
        startLoop();
    }
    
private:
    Display& display;
    Painter3D painter;
    RenderPipeLine renderPipeLine;
    SceneManager sceneManager;
    bool isWorking;
    float frameRate;
    
    void startLoop();
};
#endif /* Enigne_hpp */
