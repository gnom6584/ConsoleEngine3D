//
//  Mesh.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "Drawable.hpp"

class Mesh final : public Drawable{
public:
    std::vector<Vector> vertices;
    std::vector<Vector> uv;
    std::vector<Vector> normals;
    std::vector<Color> colors;
    std::vector<unsigned int> indices;
private:
    void onDraw(Painter3D &painter) override;
};

#endif /* Mesh_hpp */
