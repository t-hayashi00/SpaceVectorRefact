#include "Player.h"

Player::Player(double z, double vel_, double degree_) :Object(z, vel_, degree_)
{
	LoadDivGraph("image/pl.png", 2, 2, 1, 50, 50, image, 0);
	type = "player";
	size = 10;
	maxHp = 5;
	hp = maxHp;
	bomb = 900;
	center.z = 425;
	preZ = center.z;
}
Player::~Player()
{
}

void Player::update()
{
	frameCount++;
	input();
	degree += vel;
	if (degree < 0)degree += 360;
	double distance = 150 + 1 * sin(toRad(15 * frameCount));
	center.x = 320 + 1.3 * distance * cos(toRad(degree));
	center.y = 240 + distance * sin(toRad(degree));

	if (hp > 5)hp = 5;
	if (hp <= 0)inactive = 6000;
	if (bomb < 900)bomb += 1;
	if (bomb > 900)bomb = 900;


	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		body[i] = center;
	}
	for (int i = 0; i < sizeof(wing) / sizeof(wing[0]); i++) {
		wing[i] = center;
	}

	preZ = center.z;
	setVp(center.x, center.y);
	if(inactive > 0)inactive--;
}

void Player::input() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		vel -= 0.5;
		if (vel < -3.0)vel = -3.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		vel += 0.5;
		if (vel > 3.0)vel = 3.0;
	}
	if (vel > 0)vel -= 0.125;
	if (vel < 0)vel += 0.125;
}

void Player::draw() {
	double scale = 25;
	cr = GetColor(155, 55, 55);

	body[0].z -= 2.5 * scale;
	body[1].z += 2.5 * scale;
	body[2].z += 2.5 * scale;
	body[3].z += 2.5 * scale;

	wing[0].z += 1.5 * scale;
	wing[1].z += 1.5 * scale;
	wing[2].z += 3 * scale;
	wing[3].z += 3 * scale;

	body[1].x += scale * cos(toRad(degree + 180));
	body[1].y += scale * sin(toRad(degree + 180));
	body[2].x += scale * cos(toRad(degree + 90));
	body[2].y += scale * sin(toRad(degree + 90));
	body[3].x += scale * cos(toRad(degree + 270));
	body[3].y += scale * sin(toRad(degree + 270));

	wing[0].x = body[2].x;
	wing[0].y = body[2].y;
	wing[1].x = body[3].x;
	wing[1].y = body[3].y;

	wing[2].x += 3 * scale * cos(toRad(degree + 90));
	wing[2].y += 3 * scale * sin(toRad(degree + 90));
	wing[3].x += 3 * scale * cos(toRad(degree - 90));
	wing[3].y += 3 * scale * sin(toRad(degree - 90));
	
	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		view[i] = convertToView(&body[i]);
	}
	for (int i = 0; i < sizeof(wing) / sizeof(wing[0]); i++) {
		view[i + sizeof(body) / sizeof(body[0])] = convertToView(&wing[i]);
	}

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_ALPHA, 255 - 255 * (inactive/20));

	//body
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[3].x, view[3].y,image[0], TRUE);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[1].x, view[1].y, image[0], TRUE);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[1].x, view[1].y,
		view[3].x, view[3].y, image[0], TRUE);

	//left wing
	DrawModiGraph(
		view[4].x, view[4].y,
		view[4].x, view[4].y,
		view[6].x, view[6].y,
		view[2].x, view[2].y, image[1], TRUE);

	//right wing
	DrawModiGraph(
		view[5].x, view[5].y,
		view[5].x, view[5].y,
		view[7].x, view[7].y,
		view[3].x, view[3].y, image[1], TRUE);

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 1);
	//edge
	DrawTriangle(
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[3].x, view[3].y, cr, 0);
	DrawTriangle(
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[1].x, view[1].y, cr, 0);
	DrawTriangle(
		view[0].x, view[0].y,
		view[1].x, view[1].y,
		view[3].x, view[3].y, cr, 0);
	cr = GetColor(255, 55, 55);
	DrawTriangle(
		view[5].x, view[5].y,
		view[7].x, view[7].y,
		view[3].x, view[3].y, cr, 0);
	DrawTriangle(
		view[4].x, view[4].y,
		view[6].x, view[6].y,
		view[2].x, view[2].y, cr, 0);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	Point pos = convertToView(&center);
	if(bomb<900){
		DrawBox(pos.x - 30, pos.y + 40, (pos.x + 30) - 60 * bomb/900, pos.y + 50, 0xFF0000, TRUE);
	}
}

void Player::affect(Object* target) {
	target->hp = 0;
}