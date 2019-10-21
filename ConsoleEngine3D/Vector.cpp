#include "pch.h"
#include "Vector.h"
#include <math.h>

Vector::Vector() {}

Vector::Vector(const float x, const float y, const float z) : x(x), y(y), z(z) {}

Vector::Vector(const float value) : x(value), y(value), z(value) {}

const float Vector::distance(const Vector &p0, const Vector &p1) {
	return sqrtf((p0.x - p1.x) * (p0.x - p1.x) + (p0.y - p1.y) * (p0.y - p1.y) + (p0.z - p1.z)*(p0.z - p1.z));
}

const float Vector::angle(Vector p0, Vector p1) {
	Vector scale = p0 * p1;
	return (float)acos((scale.x + scale.y + scale.z) / (p0.getLenght() * p1.getLenght()));
}

const float Vector::dot(const Vector & p0, const Vector & p1) {
	return p0.x * p1.x + p0.y * p1.y + p0.z * p1.z;
}

Vector Vector::cross(const Vector & p0, const Vector & p1){
	return Vector(p0.y * p1.z - p0.z * p1.y, p0.x * p1.z - p0.z * p1.x, p0.x * p1.y - p0.y * p1.x);
}

const float Vector::getLenght() {
	return sqrtf(x * x + y * y + z * z);
}

Vector Vector::normalize() {
	*this = *this / getLenght();
	return *this;
}


Vector Vector::operator + (const Vector &vector) {
	return Vector(x + vector.x, y + vector.y, z + vector.z);
}

Vector Vector::operator - (const Vector &vector) {
	return Vector(x - vector.x, y - vector.y, z - vector.z);
}

Vector Vector::operator * (const Vector &other) {
	return Vector(x * other.x, y * other.y, z * other.z);
}

Vector Vector::operator / (const Vector &vector) {
	return Vector(x / vector.x, y / vector.y, z / vector.z);
}

const void Vector::operator += (const Vector &vector) {
	*this = *this + vector;
}

const void Vector::operator -= (const Vector &vector) {
	*this = *this - vector;
}

const void Vector::operator *= (const Vector &other) {
	*this = *this + other;
}

const void Vector::operator /= (const Vector &vector) {
	*this = *this + vector;
}

Vector Vector::operator + (const float value) {
	return Vector(x + value, y + value, z + value);
}

Vector Vector::operator - (const float value) {
	return Vector(x - value, y - value, z - value);
}

Vector Vector::operator * (const float value) {
	return Vector(x * value, y * value, z * value);
}

Vector Vector::operator / (const float value) {
	return Vector(x / value, y / value, z / value);
}

const void Vector::operator += (const float value) {
	*this = *this + value;
}

const void Vector::operator -= (const float value) {
	*this = *this - value;
}

const void Vector::operator *= (const float value) {
	*this = *this * value;
}

const void Vector::operator /= (const float value) {
	*this = *this / value;
}

Vector operator*(const float value, Vector &vector) {
	return Vector(value * vector.x, value * vector.y, value * vector.z);
}

const void Vector::operator = (const float value) {
	x = value;
	y = value;
	z = value;
}

Vector Vector::operator - () {
	return *this * -1.0f;
	return *this;
}