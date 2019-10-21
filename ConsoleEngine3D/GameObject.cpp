#include "pch.h"
#include "GameObject.h"
#include"Global.h"
#include "Component.h"
const void GameObject::addComponent(Component &component){
	components.push_back(&component);
	int last = components.size() - 1;
	components[last]->gameObject = this;
}

const void GameObject::removeComponent(Component &component){
	components.erase(components.begin() + component.id);
}

const void GameObject::remove(){
	canvas.gameObjects.erase(canvas.gameObjects.begin() + id);
	for (auto o : canvas.gameObjects) {
		if (o->id > id) {
			o->id--;
		}
	}
	for (auto c : components) {
		delete c;
	}
}

const void GameObject::update(){
	for (auto component : components) {
		component->update();
	}
}
GameObject::~GameObject() {
	remove();
}
GameObject::GameObject(){
	canvas.gameObjects.push_back(this);
	id = canvas.gameObjects.size() - 1;
}