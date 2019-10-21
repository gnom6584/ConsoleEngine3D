// ConsoleEngine3D.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include "Vector.h"
#include "Debugger.h"
#include <iostream>
#include <ctime>
#include <conio.h>
#include "Mesh.h"
#include "GameObject.h"
#include "Global.h"
Vector position = 0.0;
char key;
int keyPressed;

class Bullet : public Component {
	const void update() {
		gameObject->transform.position.z += 2;
		if (gameObject->transform.position.z > 1000){
			gameObject->remove();
		}
	}
};

int main() {
	long deltaTime = 50;
	long timer = -deltaTime;
	float z = 0;
	while (key != 'q') {
		if (clock() - timer > deltaTime) {
			system("CLS");
			canvas.draw();
			timer = clock();
			keyPressed = false;
			if (_kbhit()) {
				keyPressed = true;
				key = _getch();
				if (key == 32) {
					GameObject* bullet = new GameObject();
					Mesh* bulletMesh = new Mesh();
					Bullet* script = new Bullet();
					bulletMesh->setCube();
					bullet->transform.position = Vector(15, 15, 15);
					bullet->transform.scale = Vector(1, 1, 1);
					bullet->addComponent(*bulletMesh);
					bullet->addComponent(*script);
				}
			}
		}
	}
	system("CLS");
}