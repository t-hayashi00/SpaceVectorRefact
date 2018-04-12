#include "Bullet.h"

Bullet::Bullet(int hp_, double z, double vel_, double degree_) :Object(z, vel_, degree_)
{
	image = LoadGraph("image/shot.png");
	type = "bullet";
	size = 35;
	hp = hp_;
	power = 1;
	preZ = center.z;
	OutputDebugString("->バレットが生成された\n");
}
Bullet::~Bullet()
{
	OutputDebugString("->バレットが削除された\n");
}

void Bullet::update()
{
	frameCount++;
	while (degree < 0)degree += 360;
	while (degree >= 360)degree -= 360;
	double distance = 150;
	center.x = 320 + 1.3 * distance * cos(toRad(degree));
	center.y = 240 + distance * sin(toRad(degree));

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		body[i] = center;
	}

	if (lifeTime-- <= 0 || hp <= 0) {
		inactive = 1;
	}

	preZ = center.z;
	center.z -= vel;
}

void Bullet::draw() {
	double scale = size*1.4;

	for (int i = 0; i < 4; i++) {
		body[i].x += scale * cos(toRad(degree + 90 * i + frameCount * 6));
		body[i].y += scale * sin(toRad(degree + 90 * i + frameCount * 6));
	}
	body[4].z -= scale * 0.5;
	body[5].z += scale * 0.5;

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		view[i] = convertToView(&body[i]);
	}

	transparancy = lifeTime;
	transparancy /= 40;

	//body
	SetDrawBlendMode(DX_BLENDMODE_ADD, (255 - 255 * inactive) * transparancy);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[1].x, view[1].y,
		view[2].x, view[2].y,
		view[3].x, view[3].y, image, TRUE);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[4].x, view[4].y,
		view[2].x, view[2].y,
		view[5].x, view[5].y, image, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Bullet::affect(Object* target)
{
	target->hp -= power;
	playSound("shoot");
}

bool Bullet::isDestroyable() { return inactive == 1; }
