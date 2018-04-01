#include "module.h"

double gameSpeed = 2;
Point vp;

Point convertToView(Vector3D* v3d) {
	Point v;
	v3d->zoom = 0.00001*0.5*(v3d->z*v3d->z - v3d->z) + 0.0003;
	v.x = (v3d->x - vp.x)*v3d->zoom + vp.x;
	v.y = (v3d->y - vp.y)*v3d->zoom + vp.y;
	return v;
}

double toRad(double degree) {
	return PI / 180 * degree;
}

void setVp(double x, double y) {
	vp.x = VP_X + (x - vp.x) * 0.5;
	vp.y = VP_Y + (y - vp.y) * 0.5;
}

void setGameSpeed(double speed) {
	gameSpeed = speed;
}

double getGameSpeed() {
	return gameSpeed;
}