#include "Player.h"

Player::Player()
{
	LoadDivGraph("image/pl.png", 3, 3, 1, 50, 50, image, 0);
	image[3] = LoadGraph("image/boost.png");
	drawData.vertex = &center;
//	drawData.draw = &draw;
	center.z = 425;
	OutputDebugString("‚¤‚Ü‚ê‚½\n");
}
Player::~Player()
{
	OutputDebugString("‚µ‚ñ‚¾\n");
}

void Player::update() {
	frameCount++;
	input();
	double distance = 150 + 1 * sin(toRad(15 * frameCount));
	center.x = 320 + 1.3 * distance * cos(toRad(degree));
	center.y = 240 + distance * sin(toRad(degree));

	for (int i = 0; i < sizeof(body) / sizeof(body[0]); i++) {
		body[i] = center;
	}
	for (int i = 0; i < sizeof(wing) / sizeof(wing[0]); i++) {
		wing[i] = center;
	}

	setVp(center.x, center.y);
	setGameSpeed(2);
	draw();
}

void Player::input() {
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		vec -= 0.5;
		if (vec < -3.0)vec = -3.0;
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) {
		vec += 0.5;
		if (vec > 3.0)vec = 3.0;
	}
	if (vec > 0)vec -= 0.125;
	if (vec < 0)vec += 0.125;
	degree += vec;
	if (degree < 0)degree += 360;
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

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 1);

	//body
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[3].x, view[3].y,image[0], FALSE);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[2].x, view[2].y,
		view[1].x, view[1].y, image[0], FALSE);
	DrawModiGraph(
		view[0].x, view[0].y,
		view[0].x, view[0].y,
		view[1].x, view[1].y,
		view[3].x, view[3].y, image[0], FALSE);

	//left wing
	DrawModiGraph(
		view[4].x, view[4].y,
		view[4].x, view[4].y,
		view[6].x, view[6].y,
		view[2].x, view[2].y, image[1], FALSE);

	//right wing
	DrawModiGraph(
		view[5].x, view[5].y,
		view[5].x, view[5].y,
		view[7].x, view[7].y,
		view[3].x, view[3].y, image[1], FALSE);

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
}
