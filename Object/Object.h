#pragma once
#include "module.h"

class Object{
private:

protected:
	unsigned int cr = 0;
	int frameCount = 0;
	int maxHp = 1;
	double transparancy = 1;
	TCHAR* type = "";
	double preZ = 0;
	double vel = 0;
	double degree = 0;

public:
	Object(double z, double vel_, double degree_);
	virtual ~Object() = 0;

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void affect(Object* target) = 0;
	double getPreZ();
	double getDegree();
	TCHAR* getObjectType();
	bool isChangedZ();
	virtual bool isDestroyable();

	Vector3D center;
	int hp = 1;
	int power = 1;
	double inactive = 0;
	double size = 0;
	double bomb = 900;
};