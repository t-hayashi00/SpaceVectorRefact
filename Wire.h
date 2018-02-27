#pragma once
#include "module.h"

class Wire {
private:
	Vector3D center;
	Vector3D rect[4];
	Point view[4];
	void draw();
	unsigned int cr;
	double theta = 0;
public:
	Wire(double theta_);
	~Wire();
	bool update();
};
