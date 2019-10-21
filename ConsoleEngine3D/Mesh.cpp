#include "pch.h"
#include "Mesh.h"
Mesh::Mesh(std::vector<Vector> vertices, std::vector<int> indices) : vertices(vertices), indices(indices) {}
Mesh::Mesh() {}

const void Mesh:: update(){
	for (int i = 0; i < indices.size(); i+= 3) {
		Vector offset = gameObject->transform.position + ((gameObject->transform.parent != nullptr)? gameObject->transform.parent->position : 0.0f) + camera.position;
		canvas.drawTriangle(vertices[indices[i]] * gameObject->transform.scale + offset, vertices[indices[i + 1]] * gameObject->transform.scale + offset, vertices[indices[i + 2]] * gameObject->transform.scale + offset);
	}
}
const void Mesh::setCube(){
	vertices.push_back(Vector(-5.f, -5.f, -5.f));
	vertices.push_back(Vector(5.f, -5.f, -5.f));
	vertices.push_back(Vector(-5.f, 5.f, -5.f));
	vertices.push_back(Vector(5.f, 5.f, -5.f));

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);

	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(2);

	vertices.push_back(Vector(-5.f, -5.f, 5.f));
	vertices.push_back(Vector(5.f, -5.f, 5.f));
	vertices.push_back(Vector(-5.f, 5.f, 5.f));
	vertices.push_back(Vector(5.f, 5.f, 5.f));

	indices.push_back(4);
	indices.push_back(6);
	indices.push_back(5);

	indices.push_back(5);
	indices.push_back(6);
	indices.push_back(7);

	vertices.push_back(Vector(5.f, -5.f, -5.f));
	vertices.push_back(Vector(5.f, -5.f, 5.f));
	vertices.push_back(Vector(5.f, 5.f, -5.f));
	vertices.push_back(Vector(5.f, 5.f, 5.f));

	indices.push_back(8 + 3);
	indices.push_back(8 + 0);
	indices.push_back(8 + 1);

	indices.push_back(8 + 2);
	indices.push_back(8 + 0);
	indices.push_back(8 + 3);


	vertices.push_back(Vector(-5.f, -5.f, -5.f));
	vertices.push_back(Vector(-5.f, -5.f, 5.f));
	vertices.push_back(Vector(-5.f, 5.f, -5.f));
	vertices.push_back(Vector(-5.f, 5.f, 5.f));

	indices.push_back(12 + 0);
	indices.push_back(12 + 3);
	indices.push_back(12 + 1);

	indices.push_back(12 + 0);
	indices.push_back(12 + 2);
	indices.push_back(12 + 3);

	vertices.push_back(Vector(-5.f, 5.f, -5.f));
	vertices.push_back(Vector(5.f, 5.f, -5.f));
	vertices.push_back(Vector(-5.f, 5.f, 5.f));
	vertices.push_back(Vector(5.f, 5.f, 5.f));

	indices.push_back(16 + 0);
	indices.push_back(16 + 3);
	indices.push_back(16 + 1);

	indices.push_back(16 + 2);
	indices.push_back(16 + 3);
	indices.push_back(16 + 0);

	vertices.push_back(Vector(-5.f, -5.f, -5.f));
	vertices.push_back(Vector(5.f, -5.f, -5.f));
	vertices.push_back(Vector(-5.f, -5.f, 5.f));
	vertices.push_back(Vector(5.f, -5.f, 5.f));

	indices.push_back(20 + 0);
	indices.push_back(20 + 1);
	indices.push_back(20 + 3);

	indices.push_back(20 + 3);
	indices.push_back(20 + 2);
	indices.push_back(20 + 0);
}
;