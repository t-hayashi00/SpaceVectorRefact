#pragma once
#include "module.h"

class Player {
private:
	void input();

	int image[5];
	Vector3D body[4];
	Vector3D wing[4];
	Point view[8];
	unsigned int cr = 0;
	int frameCount = 0;
	double vec = 0;
	double degree = 0;

public:
	Player();
	~Player();
	void update();
	void draw();

	Vector3D center;
	DrawData drawData;
	int hp = 5;
	double bomb = 100;
	double boost = 0;
};