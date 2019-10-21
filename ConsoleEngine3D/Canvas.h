#pragma once
#include "Bitmap.h"
#include "Camera.h"
#include "Vector.h"
#include <vector>
#include "GameObject.h"

class Canvas final: public Bitmap<char>{
protected:
	Camera *camera;
	Bitmap<float> depth;
public:
	std::vector<GameObject*> gameObjects;
	Canvas(Camera &camera, const int width, const int height, const char background = ' ');
	~Canvas();

	Vector light = Vector(-0.0f, -1.0f, 0.75f);
	const void set(char chr, const int x, const int y, const float d);
	const void attachCamera(Camera &camera);
	const void draw();
	const void drawPoint(const char chr, const Vector &point);
	const void drawLine(const char chr, Vector point0, Vector point1, bool perspecitveOff);
	const void drawWireframeSquare(const char chr, Vector point0, Vector point1, Vector point2, Vector point3);
	const void drawWireframeCube(const char chr, Vector point0, Vector point1, Vector point2, Vector point3, Vector point4, Vector point5, Vector point6, Vector point7);
	const void drawTriangle(Vector point0, Vector point1, Vector point2);
	const void drawCube(Vector point0, Vector point1, Vector point2, Vector point3, Vector point4, Vector point5, Vector point6, Vector point7);
	const void testangle(Vector point0, Vector point1, Vector point2);
	const void fillBottomFlatTriangle(char c, Vector v1, Vector v2, Vector v3);
	const void fillTopFlatTriangle(char c, Vector v1, Vector v2, Vector v3);
};