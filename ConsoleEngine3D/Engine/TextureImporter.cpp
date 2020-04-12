//
//  TextureImporter.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 10/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "TextureImporter.hpp"

Color **TextureImporter::open(std::string path, int& width, int& height) {
    std::ifstream file(path);
    int sizeBuf[2];
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    
    width = sizeBuf[0];
    height = sizeBuf[1];
    
    Color** texture = new Color*[width];
    for(unsigned int i = 0; i < height; i++){
        texture[i] = new Color[height];
    }
    
    for(unsigned int i = 0; i < width; ++i){
        for(unsigned int j = 0; j < height; ++j){
            float buffer[4];
            file.read((char*)buffer, sizeof(buffer));
            texture[i][j] = Color(buffer[0] * COLOR_VALUE_MAX, buffer[1] * COLOR_VALUE_MAX, buffer[2] * COLOR_VALUE_MAX,buffer[3] * COLOR_VALUE_MAX);
        }
    }
    file.close();
    return texture;
}
