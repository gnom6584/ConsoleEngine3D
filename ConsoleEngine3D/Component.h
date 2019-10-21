#pragma once
#include "GameObject.h"
class Component{
public:
	int id;
	GameObject* gameObject;
	const virtual void start() {};
	const virtual void update() {};
};

