#pragma once
class Vector final{
public:
	//variables
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
	//constructors
	Vector();
	Vector(const float x, const float y, const float z = 0.0f);
	Vector(const float value);
	//functions
	const float getLenght();
	Vector normalize();
	//static functions
	const static float distance(const Vector &p0, const Vector &p1);
	const static float angle(Vector p0, Vector p1);
	const static float dot(const Vector &p0, const Vector &p1);
	static Vector cross(const Vector &p0, const Vector &p1);

	//operators: Vector
	Vector operator + (const Vector &vector);
	Vector operator - (const Vector &vector);
	Vector operator * (const Vector &vector);
    Vector operator / (const Vector &vector);
	const void operator += (const Vector &vector);
	const void operator -= (const Vector &vector);
	const void operator *= (const Vector &vector);
	const void operator /= (const Vector &vector);
	//operators: Float
	Vector operator + (const float value);
	Vector operator * (const float value);
	Vector operator - (const float value);
	Vector operator / (const float value);
	const void operator += (const float value);
	const void operator -= (const float value);
	const void operator *= (const float value);
	const void operator /= (const float value);
	friend Vector operator*(const float value, Vector &vector);
	const void operator = (const float value);
	//operators: Other
	Vector operator - ();
};


