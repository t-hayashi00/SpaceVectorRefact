#pragma once
#include "module.h"

class UserInterface {
private:
	void drawTriangle(int x, int y);
	int frameCount = 0;
	int image[2];
	int* hp;
	double* bomb;
	double traceBomb = 0;
public:
	UserInterface(int* hp_, double* bomb_);
	~UserInterface();
	void drawAll();
	void drawVital();
	void drawBomb();
	void drawScore();
};