#include "Matrix3x3.hpp"


Matrix3x3::Matrix3x3(std::vector<float> table) { 
    for(int i = 0; i < 9; i++){
        this->table[i] = table[i];
    }
}

Matrix3x3::Matrix3x3(float m00, float m10, float m20, float m01, float m11, float m21, float m02, float m12, float m22) { 
    table[0] = m00;
    table[1] = m10;
    table[2] = m20;
    table[3] = m01;
    table[4] = m11;
    table[5] = m21;
    table[6] = m02;
    table[7] = m12;
    table[8] = m22;
}

Vector Matrix3x3::operator*(const Vector &vector) { 
    return Vector(
        table[0] * vector.x + table[1] * vector.y + table[2] * vector.z,
        table[3] * vector.x + table[4] * vector.y + table[5] * vector.z,
        table[6] * vector.x + table[7] * vector.y + table[8] * vector.z
    );
}

