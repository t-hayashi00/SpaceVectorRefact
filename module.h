#pragma once
#include "DxLib.h"
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
	double zoom;
};

struct DrawData {
//	void(*Player::draw)();
	Vector3D *vertex;
};

typedef struct Point Point;
typedef struct Vector3D Vector3D;
typedef struct DrawData DrawData;
Point convertToView(Vector3D* vsd);
double toRad(double degree);
void setVp(double x, double y);
void setGameSpeed(double speed);
double getGameSpeed();