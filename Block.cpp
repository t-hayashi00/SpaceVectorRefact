#include "Block.h"

Block::Block(int hp_, double z, double vel_, double degree_) :Object(z, vel_, degree_)
{
	LoadDivGraph("image/bl.png", 4, 4, 1, 50, 50, image, 0);
	type = "block";
	size = 100;
	hp = hp_;
	if (hp > 3)hp = 3;
	preZ = center.z;
	OutputDebugString("->ブロックが生成された\n");
}
Block::~Block()
{
	OutputDebugString("ブロックが削除された\n");
}

void Block::update()
{
	frameCount++;
	degree += vel;
	while (degree < 0)degree += 360;
	while (degree >= 360)degree -= 360;
	double distance = 150;
	center.x = 320 + 1.3 * distance * cos(toRad(degree));
	center.y = 240 + distance * sin(toRad(degree));

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		body[i] = center;
	}

	if (hp <= 0) {
		inactive = 1;
	}

	preZ = center.z;
	center.z += getGameSpeed();
}

void Block::draw() {
	double scale = 100;
	cr = GetColor(55, 155, 155);

	for (int i = 0; i < 4; i++) {
		body[i].x += scale * cos(toRad(degree + 90 * i + frameCount * 2));
		body[i].y += scale * sin(toRad(degree + 90 * i + frameCount * 2));
	}
	body[4].z -= scale * 0.2;
	body[5].z += scale * 0.2;

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		view[i] = convertToView(&body[i]);
	}

	if (center.z > 425)transparancy = 5 / (center.z - 425);

	//body
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (220 - 220 * inactive) * transparancy);
	for (int i = 0; i < 4; i++) {
		DrawModiGraph(
			view[4].x, view[4].y,
			view[4].x, view[4].y,
			view[i].x, view[i].y,
			view[(i + 1) % 4].x, view[(i + 1) % 4].y, image[hp], FALSE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 * transparancy);
	for (int i = 0; i < 4; i++) {
		DrawLine(
			view[4].x, view[4].y,
			view[i].x, view[i].y, cr);
	}
	for (int i = 0; i < 4; i++) {
		DrawLine(
			view[i].x, view[i].y,
			view[(i + 1) % 4].x, view[(i + 1) % 4].y, cr);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, (220 - 220 * inactive) * transparancy);
	for (int i = 0; i < 4; i++) {
		DrawModiGraph(
			view[5].x, view[5].y,
			view[5].x, view[5].y,
			view[i].x, view[i].y,
			view[(i + 1) % 4].x, view[(i + 1) % 4].y, image[hp], FALSE);
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 155 * transparancy);
	for (int i = 0; i < 4; i++) {
		DrawLine(
			view[5].x, view[5].y,
			view[i].x, view[i].y, cr);
		DrawLine(
			view[i].x, view[i].y,
			view[(i + 1) % 4].x, view[(i + 1) % 4].y, cr);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Block::affect(Object* target)
{
	if (target->getObjectType() == "bullet")
	{
		target->hp -= power;
		addScore(1000);
	}
	if (target->getObjectType() == "player")
	{
		if (target->inactive == 0) {
			target->hp -= power;
			target->inactive = 180;
			if (target->hp <= 0)return;
			playSound("damage");
			shake(6, 50);
			flash(30, 255, 0xFF0000);
		}
	}
}
