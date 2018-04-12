#include "Ring.h"
#include "Player.h"

Ring::Ring(double z, double vel_, double degree_) :Object(z, vel_, degree_)
{
	type = "ring";
	size = 100;
	hp = 2;
	preZ = center.z;
}
Ring::~Ring()
{
}

void Ring::update()
{
	frameCount++;
	degree += vel;
	if (degree < 0)degree += 360;
	double distance = 150 + 1 * sin(toRad(15 * frameCount));
	center.x = 320 + 1.3 * distance * cos(toRad(degree));
	center.y = 240 + distance * sin(toRad(degree));

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		body[i] = center;
	}

	preZ = center.z;
	center.z += getGameSpeed();
}

void Ring::draw() {
#define POLYGON 6
#define LAYER 12
	if (inactive == 1) {
		scale += 5;
	}

	for (int i = 0; i < LAYER; i++) {
		for (int k = 0; k < POLYGON; k++) {
			body[k + i * POLYGON].x += (scale - i) * cos(toRad(360 / POLYGON * k + frameCount + i * 3));
			body[k + i * POLYGON].y += (scale - i) * sin(toRad(360 / POLYGON * k + frameCount + i * 3));
			body[k + i * POLYGON].z += (i - LAYER / 2);
		}
	}

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		view[i] = convertToView(&body[i]);
	}

	if(ringType > 0){
		cr = GetColor(0, 55, 255);
	}
	else {
		cr = GetColor(55, 35, 1);
	}
	if (center.z > 425)transparancy = 5 / (center.z - 425);

	SetDrawBlendMode(DX_BLENDMODE_ADD, 255 * transparancy);
	for (int i = 0; i < LAYER; i++) {
		for (int k = 0; k < POLYGON; k++) {
			DrawLine(
				view[k + i * POLYGON].x, view[k + i * POLYGON].y,
				view[(k+1)% POLYGON + i * POLYGON].x, view[(k + 1) % POLYGON + i * POLYGON].y, cr, 2);
		}
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Ring::affect(Object* target)
{
	if (interval <= 0 && target->getObjectType() == "bullet")
	{
		ringType *= -1;
		interval = 5;
	}
	interval--;
	if (target->getObjectType() == "player")
	{
		if (ringType > 0)
		{
			target->bomb = 900;
			flash(30, 200, 0xFFFFFF);
			setGameSpeed(getGameSpeed() + 1);
			playSound("accel");
		}
		else
		{
			target->hp = 5;
			flash(30, 200, 0xFFFFFF);
			setGameSpeed(getGameSpeed() - 1);
			playSound("brake");
		}
		target->inactive = 60;
		inactive = 1;
	}
}