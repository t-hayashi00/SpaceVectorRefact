#pragma once

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

typedef struct Point Point;
typedef struct Vector3D Vector3D;

Point convertToView(Vector3D* vsd);
