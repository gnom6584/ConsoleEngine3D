//
//  Transform.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 20/02/2020.
//  Copyright © 2020 BatyaProfessionalGameStudio. All rights reserved.
//

#include <cmath>

#include "Transform.hpp"
#include "Matrix3x3.hpp"

Vector Transform::rotateVector(const Vector &vector, const Vector &rotation) {
    Matrix3x3 rx = Matrix3x3(1.0f, 0.0f, 0.0f, 0.0f, cos(rotation.x), -sin(rotation.x), 0.0f, sin(rotation.x), cos(rotation.x));
    Matrix3x3 ry = Matrix3x3(cos(rotation.y), 0.0f, sin(rotation.y), 0.0f, 1.0f, 0.0f, -sin(rotation.y), 0.0f, cos(rotation.y));
    Matrix3x3 rz = Matrix3x3(cos(rotation.z), -sin(rotation.z), 0.0f, sin(rotation.z), cos(rotation.z), 0.0f, 0.0f, 0.0f, 1.0f);
    return rx * (ry * (rz * vector));
}

void Transform::setLocalPosition(const Vector &newPosition) {
    localPosition = newPosition;
}

//void Transform::setPosition(const Vector &newPosition) {
//     if(parent != nullptr){
//           localRotation = -parent->getPosition() + newPosition;
//       }
//       else{
//           localRotation = newPosition;
//       }
//}

void Transform::setLocalRotation(const Vector &newRotation) {
    localRotation = newRotation;
}

//void Transform::setRotation(const Vector &newRotation) {
//    if(parent != nullptr){
//        localRotation = -parent->getRotation() + newRotation;
//    }
//    else{
//        localRotation = newRotation;
//    }
//}

void Transform::setLocalScale(const Vector &newScale) {
    localScale = newScale;
}

//void Transform::setScale(const Vector &newScale) {
//    if(parent != nullptr){
//           localScale = -parent->getScale() + newScale;
//       }
//       else{
//           localScale = newScale;
//       }
//}

Vector Transform::getPosition() const {
    if(parent != nullptr){
        return Vector::scale(rotateVector(localPosition, parent->getRotation()), parent->getScale()) + parent->getPosition();
    }
    else {
        return localPosition;
    }
}

Vector Transform::getLocalPosition() const {
    return localPosition;
}

Vector Transform::getRotation() const {
     if(parent != nullptr){
           return parent->getLocalRotation() + localRotation;
       }
       else {
           return localRotation;
       }
}

Vector Transform::getLocalRotation() const {
    return localRotation;
}

Vector Transform::getScale() const {
    if(parent != nullptr){
        return Vector::scale(parent->getScale(), localScale);
    }
    else {
        return localScale;
    }
}

Vector Transform::getLocalScale() const {
    return localScale;
}

void Transform::moveLocal(const Vector &moveVector) { 
    localPosition += moveVector;
}

void Transform::moveLocal(float x, float y, float z) { 
    localPosition.x += x;
    localPosition.y += y;
    localPosition.z += z;
}

void Transform::rotateLocal(const Vector &rotateVector) {
    localRotation += rotateVector;
}

void Transform::rotateLocal(float x, float y, float z) { 
    localRotation.x += x;
    localRotation.y += y;
    localRotation.z += z;
}

Transform::Transform() { 
    setLocalPosition(0.0f);
    setLocalRotation(0.0f);
    setLocalScale(1.0f);
    parent = nullptr;
}





