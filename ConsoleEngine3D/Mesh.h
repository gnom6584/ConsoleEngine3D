#pragma once
#include "Vector.h"
#include <vector>
#include "Component.h"
#include "Global.h"
class Mesh final : public Component{
private:
	std::vector<Vector> vertices;
	std::vector<int> indices;
public:
	Mesh();
	Mesh(std::vector<Vector> vertices, std::vector<int> indices);
	const void update();
	const void setCube();
};

