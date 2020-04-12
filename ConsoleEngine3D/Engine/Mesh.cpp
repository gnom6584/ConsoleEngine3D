//
//  Mesh.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Mesh.hpp"
#include "Transform.hpp"
#include "GameObject.hpp"


#define getOrDefault(vector, index, defaultValue) ((index < vector.size())? vector[index] : defaultValue)


void Mesh::onDraw(Painter3D& painter) {
    for(unsigned int i = 0; i < indices.size(); i += 3){
        unsigned int vIndices[3] = {indices[i], indices[i + 1], indices[i + 2]};
        Vertex vertex[3];
        auto& transform = getGameObject().getTransform();
        
        Vector position = transform.getPosition();
        Vector rotation = transform.getRotation();
        Vector scale = transform.getScale();
        
        Vector defaultNormal = Vector::cross(vertices[vIndices[2]] - vertices[vIndices[0]] , vertices[vIndices[1]] - vertices[vIndices[0]]).getNormalized();
        
        for(unsigned int vIndex = 0; vIndex < 3; vIndex++){
            auto index = vIndices[vIndex];
            vertex[vIndex].position = Transform::rotateVector(Vector::scale(getOrDefault(vertices, index, Vector(0.0f)), scale), rotation) + position;
            vertex[vIndex].uv = getOrDefault(uv, index, Vector(0.0f));
            vertex[vIndex].normal = Vector::scale(Transform::rotateVector(getOrDefault(normals, index, defaultNormal), -rotation), scale);
            vertex[vIndex].color = getOrDefault(colors, index, Color(255));
        }
        
        painter.drawTriangle(getShader(), vertex[0], vertex[1], vertex[2]);
    }
}
