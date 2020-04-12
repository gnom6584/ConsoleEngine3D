//
//  ModelImporter.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 10/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "ModelImporter.hpp"


void ModelImporter::open(std::string path, std::vector<Vector> &vertices, std::vector<unsigned int> &indices, std::vector<Vector> &uv, std::vector<Vector> &normals, std::vector<Color> &colors) { 
    std::ifstream file(path);
    int sizeBuf[1];
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    int size = sizeBuf[0];
    for (auto i = 0; i < size; ++i)
    {
        float buffer[3];
        file.read((char*)buffer, sizeof(buffer));
        vertices.push_back(Vector(buffer[0], buffer[1], buffer[2]));
    }
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    size = sizeBuf[0];
    for (auto i = 0; i < size; ++i)
    {
        int index[1];
        file.read((char*)index, sizeof(index));
        indices.push_back(index[0]);
    }
    
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    size = sizeBuf[0];
    for (auto i = 0; i < size; ++i)
    {
        float buffer[3];
        file.read((char*)buffer, sizeof(buffer));
        uv.push_back(Vector(buffer[0], buffer[1], buffer[2]));
    }
    
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    size = sizeBuf[0];
    for (auto i = 0; i < size; ++i)
    {
        float buffer[3];
        file.read((char*)buffer, sizeof(buffer));
        normals.push_back(Vector(buffer[0], buffer[1], buffer[2]));
    }
    
    file.read((char*)sizeBuf, sizeof(sizeBuf));
    size = sizeBuf[0];
    for (auto i = 0; i < size; ++i)
    {
        float buffer[4];
        file.read((char*)buffer, sizeof(buffer));
        colors.push_back(Color(buffer[0] * COLOR_VALUE_MAX, buffer[1] * COLOR_VALUE_MAX, buffer[2] * COLOR_VALUE_MAX, buffer[3] * COLOR_VALUE_MAX));
    }
    file.close();
}
