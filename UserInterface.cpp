#include "UserInterface.h"

UserInterface::UserInterface(int* hp_, double* bomb_) {
	hp = hp_;
	bomb = bomb_;
	image[0] = LoadGraph("image/vital.png");
	image[1] = LoadGraph("image/frame.png");
}

UserInterface::~UserInterface() {
}

void UserInterface::drawAll() {
	drawVital();
	drawBomb();
	drawScore();
	frameCount++;
}

void UserInterface::drawTriangle(int x, int y) {
	Point v[3];
	for (int i = 0; i < 3; i++) {
		v[i].x = x + 20 * sin(toRad(frameCount + i * 120));
		v[i].y = y + 20 * cos(toRad(frameCount + i * 120));
	}

	for (int i = 0; i < 3; i++) {
		DrawModiGraph(
			x, y,
			v[i].x, v[i].y,
			v[(i + 1) % 3].x, v[(i + 1) % 3].y,
			x, y, image[0], FALSE);
		DrawLine(v[i].x, v[i].y, v[(i + 1) % 3].x, v[(i + 1) % 3].y, GetColor(100, 155, 55), 2);
	}
}

void UserInterface::drawVital(){
	SetDrawBlendMode(DX_BLENDMODE_ADD, 220);
	for (int i = 0; i < *hp; i++) {
		Point pos;
		pos.x = 30 + 25 * i;
		pos.y = 50;
		drawTriangle(pos.x, pos.y);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
}

void UserInterface::drawBomb(){
	traceBomb += (*bomb - traceBomb) / 3;
	Point pos;
	pos.x = 15;
	pos.y = 80;
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 255);
	unsigned int cr;
	if (*bomb < 900) {
		cr = GetColor(255 - 255 * (traceBomb) / 900, 200 * (traceBomb) / 900, 0);
	}
	else {
		cr = GetColor(
			127 * (1 + sin(toRad(frameCount%360))),
			200 + 27 * (1 + sin(toRad(frameCount % 360))),
			127 * (1 + sin(toRad(frameCount % 360))));
	}
	DrawBox(pos.x, pos.y, pos.x + 130 * (traceBomb) / 900, pos.y + 24, cr, TRUE);
	DrawGraph(pos.x, pos.y, image[1], 1);
	DrawFormatString(pos.x + 20, pos.y + 4, 0xFFFFFF, "BOMB %3.0f %%", *bomb / 9);
}

void UserInterface::drawScore() {
	DrawFormatString(10, 10, GetColor(255, 255, 255), "SCORE %10.0f", getScore());
}