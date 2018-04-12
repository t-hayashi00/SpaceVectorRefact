#pragma once
#include "module.h"
#include "Object.h"
#include <list>

class Player : public Object {
private:
	void input();
	Vector3D body[4];
	Vector3D wing[4];
	Point view[8];
	int image[4];
	std::list<Object*>* bullets;

public:
	Player(double z, double vel, double degree_);
	~Player();
	void update();
	void draw();
	void affect(Object* target);

	int interval = 0;
};