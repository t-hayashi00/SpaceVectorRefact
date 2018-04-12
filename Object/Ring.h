#pragma once
#include "module.h"
#include "Object.h"

class Ring : public Object {
private:
	Vector3D body[6 * 12];
	Point view[6 * 12];
	int ringType = 1;
	int interval = 0;
	double scale = 100;

public:
	Ring(double z, double vel, double degree_);
	~Ring();
	void update();
	void draw();
	void affect(Object* target);
};