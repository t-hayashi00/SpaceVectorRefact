#pragma once
#include "module.h"
#include "Object.h"

class Block : public Object {
private:
	Vector3D body[6];
	Point view[6];
	int image[3];
	bool invincible = false;

public:
	Block(int hp_, double z, double vel, double degree_);
	~Block();
	void update();
	void draw();
	void affect(Object* target);

};