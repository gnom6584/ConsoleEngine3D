#ifndef Transform_hpp
#define Transform_hpp

#include "Vector.hpp"

struct Transform{
private:
    Vector localPosition;
    Vector localRotation;
    Vector localScale;
public:
    Transform();
    
    Transform* parent;
    
    static Vector rotateVector(const Vector &vector, const Vector &rotation);
    
    void setLocalPosition(const Vector &newPosition);
    //void setPosition(const Vector &newPosition);
    
    void setLocalRotation(const Vector &newRotation);
    //void setRotation(const Vector &newRotation);
    
    void setLocalScale(const Vector &newScale);
   // void setScale(const Vector &newScale);
    
    Vector getPosition() const;
    Vector getLocalPosition() const;
    
    Vector getRotation() const;
    Vector getLocalRotation() const;
    
    Vector getScale() const;
    Vector getLocalScale() const;
    
    void moveLocal(const Vector &moveVector);
    void moveLocal(float x, float y, float z);
    
    void rotateLocal(const Vector &rotateVector);
    void rotateLocal(float x, float y, float z);
};

#endif /* Transform_hpp */
