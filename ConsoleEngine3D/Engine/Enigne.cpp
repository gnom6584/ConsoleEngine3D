//
//  Enigne.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include <ctime>

#include "Enigne.hpp"
#include "Drawable.hpp"


Engine::Engine(Display& display, float frameRate) : display(display), painter(Painter3D(display)), renderPipeLine(RenderPipeLine(painter)),
    frameRate(frameRate), isWorking(true) {
        
    }

void Engine::startLoop(){
    Shader def;
    Drawable::setDefaultShader(&def);
    long delay = 1000000 / frameRate;
    auto start = -delay;
    while (isWorking) {
        if(clock() - start > delay){
            display.clearDepthBuffer();
            display.clearOpaqueBuffer();
            display.clearTransparentBuffer();
            sceneManager.processCurrentScene();
            renderPipeLine.drawAllDrawables();
            display.drawPixels();
            start = clock();
        }
    }
}
