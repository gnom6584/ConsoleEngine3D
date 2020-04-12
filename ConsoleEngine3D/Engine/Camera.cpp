//
//  Camera.cpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#include "Camera.hpp"
#include <cmath>


Camera* Camera::currentCamera;

Camera::Camera(float fieldOfView) {
    setFieldOfView(fieldOfView);
    currentCamera = this;
}

Vector Camera::transformWorldToCameraSpace(const Vector &vector){
    Vector transformed = vector;
    transformed = Transform::rotateVector(transformed, -currentCamera->transform.getLocalRotation());
    transformed -= currentCamera->transform.getLocalPosition();
    
    float zDivider = abs(transformed.z);
    
    if(zDivider == 0){
        zDivider = 0.001;
    }
    
    float fowModifier = atan(currentCamera->fieldOfView);
    
    transformed.x /= zDivider * fowModifier;
    transformed.y /= zDivider * fowModifier;
    return transformed;
}

Camera &Camera::getCurrentCamera() {
    return *currentCamera;
}

Transform& Camera::getTransform() { 
    return transform;
}

float Camera::getFieldOfView() const { 
    return fieldOfView * 2;
}

void Camera::setFieldOfView(float newFieldOfView) {
    fieldOfView = newFieldOfView / 2;
}




