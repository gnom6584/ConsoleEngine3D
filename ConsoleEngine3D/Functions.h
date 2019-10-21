#pragma once
#include "Vector.h"
float lerp(float v0, float v1, float t) {
	return v0 + (v1 - v0) * t;
}

Vector lerp(Vector v0, Vector v1, float t) {
	return v0 + (v1 - v0) * t;
}
