#pragma once
#include "DxLib.h"
#include "screenEffect.h"
#include "sound.h"
#include "userInterface.h"
#include <cmath>

#define VP_X 320
#define VP_Y 240
#define PI 3.141592654

struct Point {
	double x;
	double y;
};

struct Vector3D {
	double x;
	double y;
	double z;
};

Point convertToView(const Vector3D* vsd);
double toRad(double degree);
void setVp(double x, double y);
Point getVp();
void addScore(double point);
double getScore();
void setGameSpeed(double speed);
double getGameSpeed();