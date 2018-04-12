#pragma once
#include "module.h"
#include "Object.h"

class Bullet : public Object {
private:
	Vector3D body[6];
	Point view[6];
	int image;
	int lifeTime = 40;
	bool invincible = false;

public:
	Bullet(int hp, double z, double vel, double degree_);
	~Bullet();
	void update();
	void draw();
	void affect(Object* target);
	bool isDestroyable();

};