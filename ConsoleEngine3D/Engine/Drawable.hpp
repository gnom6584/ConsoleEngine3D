//
//  Drawable.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Drawable_hpp
#define Drawable_hpp

#include "Component.hpp"
#include "Painter3D.hpp"
#include "RenderPipeLine.hpp"
#include "Shader.hpp"

class Drawable : public Component{
public:
    int drawLayer = 0;
    
    virtual void onDraw(Painter3D& painter) = 0;
    void onUpdate() override final;
    void setShader(Shader* shader);
    Shader& getShader() const;
    static void setDefaultShader(Shader* shader);
private:
    static Shader* defaultShader;
    Shader* shader;
};

#endif /* Drawable_hpp */
