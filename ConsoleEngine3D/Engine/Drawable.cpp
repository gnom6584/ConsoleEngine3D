//
//  Drawable.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 06/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Drawable.hpp"


Shader* Drawable::defaultShader;

void Drawable::onUpdate() {
     RenderPipeLine::currentRenderPipeLine->addDrawableToConveyor(this);
}


void Drawable::setShader(Shader *shader) { 
    this->shader = shader;
}

Shader &Drawable::getShader() const { 
    return (shader != nullptr)? *shader : *defaultShader;
}


void Drawable::setDefaultShader(Shader *shader) { 
    defaultShader = shader;
}
