//
//  Camera.hpp
//  ConsoleEngine3D
//
//  Created by Апсех on 07/03/2020.
//  Copyright © 2020 gnom6584. All rights reserved.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Vector.hpp"
#include "Transform.hpp"

class Camera final{
public:
    Camera(float fieldOfView);
    static Camera& getCurrentCamera();
    Transform& getTransform();
    float getFieldOfView() const;
    void setFieldOfView(float fieldOfView);
    
    static Vector transformWorldToCameraSpace(const Vector &vector);
    
private:
    float fieldOfView;
    static Camera* currentCamera;
    Transform transform;
};

#endif /* Camera_hpp */
