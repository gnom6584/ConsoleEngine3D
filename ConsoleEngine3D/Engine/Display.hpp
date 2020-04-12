//
//  Display.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Display_hpp
#define Display_hpp

#include "Color.hpp"

class Painter3D;
class Engine;

class Display {
public:
    Display(unsigned int width, unsigned int height);
    
    ~Display();
    
    unsigned int getWidth() const;
    
    unsigned int getHeight() const;
protected:
    virtual void onPixelDraw(const Color& color, int x, int y, float depth) const = 0;
private:
    void drawPixels() const;
    
    virtual void clearOpaqueBuffer();
    virtual void clearTransparentBuffer();
    virtual void clearDepthBuffer();
    
    unsigned int width;
    unsigned int height;
    Color** opaqueBuffer;
    Color** transparentBuffer;
    float** depthBuffer;
friend Painter3D;
friend Engine;
};

#endif /* Display_hpp */
