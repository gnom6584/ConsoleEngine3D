//
//  RenderPipeLine.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "RenderPipeLine.hpp"
#include "Drawable.hpp"

RenderPipeLine* RenderPipeLine::currentRenderPipeLine;

void RenderPipeLine::addDrawableToConveyor(Drawable *drawable) {
    int addToLayer = drawable->getShader().isTransparent()? 1 : 0;
    drawableConveoyr[drawable->drawLayer + addToLayer].push_back(drawable);
}

void RenderPipeLine::drawAllDrawables() {
    for(auto& drawableLayer : drawableConveoyr){
        for(auto& drawable : drawableLayer.second){
            drawable->onDraw(painter);
        }
        drawableLayer.second.clear();
    }
    drawableConveoyr.clear();
}

RenderPipeLine::RenderPipeLine(Painter3D &painter) : painter(painter) {
    currentRenderPipeLine = this;
}
