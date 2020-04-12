//
//  Painter3D.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef _Painter3D_hpp
#define _Painter3D_hpp

#include <iostream>

#include "Display.hpp"
#include "Color.hpp"
#include "Vertex.hpp"
#include "Shader.hpp"

#define ABS(x) ((x >= 0) ? x : -x)
#define CLIP(x, lower, upper) ((x < lower) ? lower : ((x > upper)? upper : x))

class Painter3D final {
public:
    Painter3D(Display& display);
    ~Painter3D();
    
    void drawPoint(const Color& color, unsigned int x, unsigned int y,
    float depth, bool transparent = false, bool ignoreDepth = false);
    
    void drawTriangle(Shader &shader, Vertex v0, Vertex v1, Vertex v2);
private:
    Display& display;
    unsigned int width;
    unsigned int height;
    int** contourX;
    
    void scanLine(int x1, int y1, int x2, int y2);
};

#endif /* _Painter3D_hpp */
