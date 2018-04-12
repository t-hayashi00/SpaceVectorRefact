#include "Object.h"

Object::Object(double z, double vel_, double degree_) {
	degree = degree_;
	center.z = z;
	vel = vel_;
	OutputDebugString("オブジェクト生成\n");
}

Object::~Object() {
	OutputDebugString("オブジェクト削除\n");
}

double Object::getPreZ() { return preZ; }
double Object::getDegree() { return degree; }
TCHAR* Object::getObjectType() { return type; }
bool Object::isChangedZ() { return (preZ != center.z); }
bool Object::isDestroyable() { return !(0 <= center.z && center.z < 700); }