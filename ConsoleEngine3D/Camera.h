#pragma once
#include "Vector.h"
#include <math.h>
namespace Projections {
	enum Projection {
		Orthogonal, Perspective
	};
}
class Camera {
public:
	Vector position = 0.0f;
	Vector center = 0.0f;
	Projections::Projection projection;
	float far;
	float near;
	float fov;
	Camera(Projections::Projection projection, float near, float far, float fov) : projection(projection), near(near), far(far), fov(fov) {}
	Vector transformPoint(const Vector &vector) {
		if (projection = Projections::Perspective) {
			auto d = position.z + near;
			return Vector(round(center.x + (vector.x - center.x) * d / (vector.z + d)), round(center.y + (vector.y - center.y) * d / (vector.z + d)), vector.z);
		}
		else {
			return vector;
		}
	};
};