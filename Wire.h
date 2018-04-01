#pragma once
#include "module.h"

class Wire {
private:
	Vector3D rect[4];
	Point view[4];
	unsigned int cr;
	double theta = 0;
public:
	Wire(double theta_);
	~Wire();
	Vector3D center;
	bool update();
	void draw();
};
