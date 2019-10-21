#include "pch.h"
#include "Canvas.h"
#include <iostream>
#include <math.h>
#include "Functions.h"

Canvas::Canvas(Camera &camera, const int width, const int height, const char background) : Bitmap<char>(width, height, background), depth(width, height, 10000000.0f) {
	attachCamera(camera);
}

Canvas::~Canvas() {}

const void Canvas::set(char chr, const int x, const int y, const float d){
	if (d < depth.get(x, y) && d > -camera->near) {
		int index = getIndex(x, y);
		if (x >= 0 && x < width && y >= 0 && y < height) {
			buffer[index] = chr;
			depth.set(d, x, y);
		}
	}
}

const void Canvas::attachCamera(Camera &camera) {
	camera.center = Vector(width / 2.0f, height / 2.0f);
	this->camera = &camera;
}

const void Canvas::draw() {

	for (int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->update();
	}

	const int doubleWidht = width * 2;
	char* bottomCorener = new char[doubleWidht];
	for (int j = 0; j < doubleWidht - 1; j++) {
		bottomCorener[j] = 196;
	}
	bottomCorener[doubleWidht - 1] = '\0';
	std::cout << '*' << bottomCorener << '*' << '\n';
	char* drawBuffer = new char[doubleWidht];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < doubleWidht - 1; j++) {
			if (j % 2 == 0) {
				drawBuffer[j] = get(j / 2, height - i - 1);
			}
			else {
				drawBuffer[j] = ' ';
			}
		}
		drawBuffer[doubleWidht - 1] = '\0';
		std::cout << '|' << drawBuffer << '|' << '\n';
	}
	std::cout << '*' << bottomCorener << '*' << '\n';
	clear();
	depth.clear();
	delete bottomCorener;
	delete drawBuffer;
}

const void Canvas::drawPoint(const char chr, const Vector &point) {
	Vector transformed = camera->transformPoint(point);
	set(chr, transformed.x, transformed.y, point.z);
}

const void Canvas::drawLine(const char chr, Vector point0, Vector point1, bool perspecitveOff = false) {
	float tempz0 = point0.z;
	float tempz1 = point1.z;
	if (!perspecitveOff)	{	
		point0 = camera->transformPoint(point0);
		point1 = camera->transformPoint(point1);
	}
	Vector direction = point1 - point0;
	float lenght = direction.getLenght();
	for (int i = 0; i <= lenght; i++) {
		set(chr, round(point0.x + direction.x * i/lenght), round(point0.y + direction.y * i / lenght), tempz0 + (tempz1 - tempz0) * (i/lenght));
	}
}

const void Canvas::drawWireframeSquare(const char chr, Vector point0, Vector point1, Vector point2, Vector point3){
	drawLine(chr, point0, point1);
	drawLine(chr, point0, point2);
	drawLine(chr, point1, point3);
	drawLine(chr, point2, point3);
}

const void Canvas::drawWireframeCube(const char chr, Vector point0, Vector point1, Vector point2, Vector point3, Vector point4, Vector point5, Vector point6, Vector point7) {
	drawWireframeSquare(chr, point0, point1, point2, point3);
	drawWireframeSquare(chr, point4, point5, point6, point7);
	drawWireframeSquare(chr, point0, point4, point2, point6);
	drawWireframeSquare(chr, point1, point5, point6, point7);
}

const void Canvas::drawTriangle(Vector point0, Vector point1, Vector point2){
	char brighntess = 0;
	float tempz0 = point0.z;
	float tempz1 = point1.z;
	float tempz2 = point2.z;

	Vector normal = Vector::cross(point1 - point0, point2 - point0).normalize();
	
	brighntess = Vector::dot(normal, light.normalize()) * 2;
	if (brighntess > 1) {
		brighntess = 1;
	}
	point0 = camera->transformPoint(point0);
	point1 = camera->transformPoint(point1);
	point2 = camera->transformPoint(point2);
	point2.z = tempz2;
	point0.z = tempz0;
	point1.z = tempz1;
	Vector direction = point1 - point0;
	float lenght = direction.getLenght();
	for (int i = 0; i <= lenght; i+= 1) {
		drawLine((int)brighntess + 177, Vector(ceil(point0.x + direction.x * i / lenght), ceil(point0.y + direction.y * i / lenght), tempz0 + (tempz1 - tempz0) * (i / lenght)), point2, true);
	}
}

const void Canvas::testangle(Vector v1, Vector v2, Vector v3) {
	v1 = camera->transformPoint(v1);
	v2 = camera->transformPoint(v2);
	v3 = camera->transformPoint(v3);

	auto swap = [](Vector* a, Vector* b) {
		Vector temp = *a;
		*a = *b;
		*b = temp;
	};
	if (v1.y > v2.y) {
		swap(&v1, &v2);
	}
	if (v1.y > v3.y) {
		swap(&v1, &v3);
	}
	if (v2.y > v3.y) {
		swap(&v2, &v3);
	}

	char brighntess = 0;
	Vector normal = Vector::cross(v2 - v1, v3 - v1).normalize();

	brighntess = Vector::dot(normal, light.normalize()) * 2;
	if (brighntess > 1) {
		brighntess = 1;
	}

	char c = (int)brighntess + 177;

	Vector v4 = Vector(v1.x + (v2.y - v1.y) / (v3.y - v1.y) * (v3.x - v1.x), v2.y);
	fillBottomFlatTriangle(c, v2, v4, v3);
	fillTopFlatTriangle(c, v2, v4, v1);
}

const void Canvas::fillBottomFlatTriangle(char c, Vector v1, Vector v2, Vector v3){;
	if (v1.x > v2.x) {
		Vector temp = v1;
		v1 = v2;
		v2 = temp;
	}
	Vector dir1 = v3 - v1;
	Vector dir2 = v3 - v2;
	dir1.z = 0;
	dir2.z = 0;
	float h = v3.y - v1.y;
	for (int i = 0; i <= h; i++) {
		float begin = (v1 + dir1 * i / h).x;
		float end = (v2 + dir2 * i / h).x;
		for (float x = begin; x <= end; x++) {
			set(c, x, i + v1.y, lerp(lerp(v1.z, v2.z, x/(end)), v3.z, i / h));
		}
	}
}

const void Canvas::fillTopFlatTriangle(char c, Vector v1, Vector v2, Vector v3){
	if (v1.x > v2.x) {
		Vector temp = v1;
		v1 = v2;
		v2 = temp;
	}
	Vector dir1 = v3 - v1;
	Vector dir2 = v3 - v2;
	dir1.z = 0;
	dir2.z = 0;
	float h = -(v3.y - v1.y);
	for (int i = 0; i <= h; i++) {
		float begin = (v1 + dir1 * i / h).x;
		float end = (v2 + dir2 * i / h).x;
		for (float x = (v1 + dir1 * i / h).x; x <= (v2 + dir2 * i / h).x; x++) {
			set(c, x,v1.y - i, lerp(lerp(v1.z, v2.z, x / (end)), v3.z, i / h));
		}
	}
}


const void Canvas::drawCube(Vector point0, Vector point1, Vector point2, Vector point3, Vector point4, Vector point5, Vector point6, Vector point7){
	//front
	drawTriangle(point0, point1, point2);
	drawTriangle(point1, point3, point2);
	//right
	drawTriangle(point1, point7, point5);
	drawTriangle(point1, point3, point7);
	//left
	drawTriangle(point0, point4, point6);
	drawTriangle(point0, point6, point2);
	//top
	drawTriangle(point2, point6, point7);
	drawTriangle(point2, point7, point3);
	//bot
	drawTriangle(point0, point1, point4);
	drawTriangle(point0, point1, point5);
	//back
	drawTriangle(point4, point5, point6);
	drawTriangle(point5, point7, point6);
}