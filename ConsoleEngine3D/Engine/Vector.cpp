#include "Vector.hpp"
#include <cmath>

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {}

Vector::Vector(float x, float y) : x(x), y(y), z(0.0f){}

Vector::Vector(float value) : x(value), y(value), z(value) {}

Vector::Vector() : x(0.0f), y(0.0f), z(0.0f){}


float Vector::getLength() const { 
    return sqrtf(x * x + y * y + z * z);
}

Vector Vector::getNormalized() {
    return *this / getLength();
}

Vector Vector::scale(const Vector &vector) { 
    return Vector(x * vector.x, y * vector.y, z * vector.z);
}

float Vector::distance(Vector &vector0, Vector &vector1) {
    return (vector1 - vector0).getLength();
}

Vector Vector::cross(const Vector &vector0, const Vector &vector1) {
    return Vector(vector0.y * vector1.z - vector0.z * vector1.y, vector0.x * vector1.z - vector0.z * vector1.x, vector0.x * vector1.y - vector0.y * vector1.x);
}

float Vector::dot(const Vector &vector0, const Vector &vector1) {
    return vector0.x * vector1.x + vector0.y * vector1.y + vector0.z * vector1.z;
}

Vector Vector::scale(const Vector &vector0, const Vector &vector1) {
    return Vector(vector0.x * vector1.x, vector0.y * vector1.y, vector0.z * vector1.z);
}

Vector Vector::operator+(const Vector &vector) { 
    return Vector(x + vector.x, y + vector.y, z + vector.z);
}

Vector Vector::operator-(const Vector &vector) { 
    return Vector(x - vector.x, y - vector.y, z - vector.z);
}

Vector Vector::operator*(float increment) { 
    return Vector(x * increment, y * increment, z * increment);
}

Vector Vector::operator/(float increment) { 
    return Vector(x / increment, y / increment, z / increment);
}

void Vector::operator+=(const Vector &vector) { 
    *this = *this + vector;
}

void Vector::operator-=(const Vector &vector) { 
    *this = *this - vector;
}

void Vector::operator*=(float increment) { 
    *this = *this * increment;
}

void Vector::operator/=(float increment) { 
    *this = *this / increment;
}

Vector Vector::operator-() { 
    return *this * - 1.0f;
}

Vector operator*(float value, Vector &vector){
    return vector * value;
}
