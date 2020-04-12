//
//  Shader.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Shader.hpp"
#include "Camera.hpp"

Vertex Shader::vertex(Vertex &vertex) {
    vertex.position = Camera::transformWorldToCameraSpace(vertex.position);
    return vertex;
}

Color Shader::fragment(Vertex &vertex) { 
    return vertex.color;
}

bool Shader::isTransparent() { 
    return false;
}

