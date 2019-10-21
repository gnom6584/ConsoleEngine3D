#pragma once
#include <vector>
#include "Transform.h"
class Component;
class GameObject final{
private:
	std::vector<Component*> components;
	int id;
public:
	Transform transform;
	const void addComponent(Component &component);
	const void removeComponent(Component &component);
	template<class T>
	const void removeComponent();
	const void remove();
	const void update();
	GameObject();
	~GameObject();
};

template<class T>
inline const void GameObject::removeComponent(){
	int findI = -1;
	for (int i = 0; i < components.size(); i++) {
		if (dynamic_cast<T*>(components[i]) != nullptr) {
			findI = i;
		}
	}
	if (findI != -1) {
		components.erase(components.begin() + findI);
	}
}
