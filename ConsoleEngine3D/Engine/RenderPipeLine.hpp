//
//  RenderPipeLine.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef RenderPipeLine_hpp
#define RenderPipeLine_hpp

#include <vector>
#include <unordered_map>

#include "Painter3D.hpp"

class Drawable;

class RenderPipeLine{
public:
    RenderPipeLine(Painter3D& painter);
    void drawAllDrawables();
private:
    static RenderPipeLine* currentRenderPipeLine;
    Painter3D& painter;
    std::unordered_map<int, std::vector<Drawable*>> drawableConveoyr;
    void addDrawableToConveyor(Drawable* drawable);
    
friend Drawable;
};

#endif /* RenderPipeLine_hpp */
