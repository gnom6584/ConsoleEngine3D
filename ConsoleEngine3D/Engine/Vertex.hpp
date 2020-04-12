//
//  Vertex.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Vertex_hpp
#define Vertex_hpp

#include "Vector.hpp"
#include "Color.hpp"

struct Vertex{
    Vector position;
    Vector uv;
    Vector normal;
    Color color;
};

#endif /* Vertex_hpp */
