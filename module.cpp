#include "module.h"

Point convertToView(Vector3D* v3d) {
	Point v;
	v3d->zoom = 0.00001*0.5*(v3d->z*v3d->z - v3d->z) + 0.0003;
	v.x = (v3d->x - VP_X)*v3d->zoom + VP_X;
	v.y = (v3d->y - VP_Y)*v3d->zoom + VP_Y;
	return v;
}
