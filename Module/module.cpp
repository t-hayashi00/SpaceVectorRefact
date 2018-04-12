#include "module.h"

double gameSpeed = 2;
double score;
Point vp;

Point convertToView(const Vector3D* v3d) {
	Point v;
	double zoom = 0.00001 * 0.5 * (v3d->z * v3d->z - v3d->z) + 0.0003;
	v.x = (v3d->x - vp.x) * zoom + vp.x;
	v.y = (v3d->y - vp.y) * zoom + vp.y;
	return v;
}

double toRad(double degree) {
	return PI / 180 * degree;
}

void setVp(double x, double y) {
	vp.x = VP_X + (x - vp.x) * 0.5;
	vp.y = VP_Y + (y - vp.y) * 0.5;
}

Point getVp() {
	return vp;
}

void addScore(double point) {
	score += point;
}

double getScore() { return score; }

void setGameSpeed(double speed) {
	gameSpeed = speed;
	if (gameSpeed > 8)gameSpeed = 8;
	if (gameSpeed < 2)gameSpeed = 2;
}

double getGameSpeed() {
	return gameSpeed;
}