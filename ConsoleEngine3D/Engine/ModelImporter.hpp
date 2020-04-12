//
//  ModelImporter.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 10/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef ModelImporter_hpp
#define ModelImporter_hpp

#include <string>
#include <vector>
#include <fstream>

#include "Color.hpp"
#include "Vector.hpp"

class ModelImporter{
public:
    void open(std::string path, std::vector<Vector>& vertices, std::vector<unsigned int>& indices, std::vector<Vector>& uv, std::vector<Vector>& normals, std::vector<Color>& colors);
};

#endif /* ModelImporter_hpp */
