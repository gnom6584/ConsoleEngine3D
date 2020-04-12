#ifndef Vector_hpp
#define Vector_hpp

struct Vector{
    float x;
    float y;
    float z;
    
    Vector(float x, float y, float z);
    Vector(float x, float y);
    Vector(float value);
    Vector();
    
    float getLength() const;
    Vector getNormalized();
    Vector scale(const Vector &vector);
    
    static float distance(Vector &vector0, Vector &vector1);
    static Vector cross(const Vector &vector0, const Vector &vector1);
    static float dot(const Vector &vector0, const Vector &vector1);
    static Vector scale(const Vector &vector0, const Vector &vector1);
    
    Vector operator + (const Vector &vector);
    Vector operator - (const Vector &vector);
    
    Vector operator * (float increment);
    Vector operator / (float increment);
    
    void operator += (const Vector &vector);
    void operator -= (const Vector &vector);
    
    void operator *= (float increment);
    void operator /= (float increment);
    
    Vector operator - ();
};

Vector operator*(float value, Vector &vector);

#endif /* Vector_hpp */
