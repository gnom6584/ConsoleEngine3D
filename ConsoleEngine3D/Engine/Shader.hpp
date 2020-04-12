//
//  Shader.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "Vertex.hpp"

class Shader {
public:
    virtual Vertex vertex(Vertex& vertex);
    
    virtual Color fragment(Vertex& vertex);
    
    virtual bool isTransparent();
};

#endif /* Shader_hpp */
