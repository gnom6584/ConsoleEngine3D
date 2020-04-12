#ifndef Matrix3x3_hpp
#define Matrix3x3_hpp
#include <vector>
#include "Vector.hpp"
struct Matrix3x3{
    float table[9];
    Matrix3x3(std::vector<float> table);
    Matrix3x3(
        float m00, float m10, float m20,
        float m01, float m11, float m21,
        float m02, float m12, float m22
    );
    Vector operator * (const Vector &vector);
};

#endif /* Matrix3x3_hpp */
