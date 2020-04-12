//
//  TextureImporter.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 10/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef TextureImporter_hpp
#define TextureImporter_hpp

#include <fstream>
#include <string>

#include "Color.hpp"

class TextureImporter{
public:
    Color** open(std::string path, int& width, int& height);
};

#endif /* TextureImporter_hpp */
