#pragma once
#include "Vector.h"
struct Transform {
	Vector position = 0.0f;
	Vector scale = 1.0f;
	Vector rotation = 0.0f;
	Transform* parent;
};