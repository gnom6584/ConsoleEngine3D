
//
//  Display.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Display.hpp"

Display::Display(unsigned int width, unsigned int height) : width(width), height(height) {
    opaqueBuffer = new Color*[width];;
    transparentBuffer = new Color*[width];
    depthBuffer = new float*[width];
    for(unsigned int i = 0; i < width; ++i){
        opaqueBuffer[i] = new Color[height];
        transparentBuffer[i] = new Color[height];
        depthBuffer[i] = new float[height];
    };
}

Display::~Display() {
    for(unsigned int i = 0; i < width; ++i){
        delete[] opaqueBuffer[i];
        delete[] transparentBuffer[i];
        delete[] depthBuffer[i];
    }
    delete[] opaqueBuffer;
    delete[] transparentBuffer;
    delete[] depthBuffer;
}

unsigned int Display::getWidth() const{
    return width;
}

unsigned int Display::getHeight() const{
    return height;
}

void Display::drawPixels() const { 
    for(int y = height - 1; y >= 0; --y){
        for(unsigned int x = 0; x < width; ++x){
            auto t = transparentBuffer[x][y].alpha / (float)COLOR_VALUE_MAX;
            auto color = opaqueBuffer[x][y] + (transparentBuffer[x][y] - opaqueBuffer[x][y]) * t;
            color.clamp();
            onPixelDraw(color, x, y, depthBuffer[x][y]);
        }
    }
}

void Display::clearOpaqueBuffer() {
    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            opaqueBuffer[i][j] = 0;
        }
    }
}

void Display::clearTransparentBuffer() {
    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            transparentBuffer[i][j] = 0;
        }
    }
}

void Display::clearDepthBuffer() {
    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            depthBuffer[i][j] = -1.0f;
        }
    }
}




