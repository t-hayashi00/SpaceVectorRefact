#include "Wire.h"

Wire::Wire(double theta_)
{
	cr = GetColor(25, 235, 255);
	theta = theta_;
	center.x = 320;
	center.y = 240;
	center.z = 10;
	for (int i = 0; i < sizeof(rect) / sizeof(rect[0]); i++) {
		rect[i].x = center.x + 400 * cos(toRad(i * 90 + theta));
		rect[i].y = center.y + 400 * sin(toRad(i * 90 + theta));
		rect[i].z = center.z;
		view[i] = convertToView(&rect[i]);
	}
}

Wire::~Wire()
{
}

bool Wire::update() {
	center.z += getGameSpeed();
	if (theta >= 360)theta = (int)theta%360;
	for (int i = 0; i < sizeof(rect) / sizeof(rect[0]); i++) {
		rect[i].x = center.x + 400 * cos(toRad(i * 90 + theta));
		rect[i].y = center.y + 400 * sin(toRad(i * 90 + theta));
		rect[i].z = center.z;
		view[i] = convertToView(&rect[i]);
	}
	draw();
	theta+=0.3;
	return center.z > 600;
}

void Wire::draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, rect[0].z / 2);
	DrawLine(view[0].x, view[0].y, view[1].x, view[1].y, cr, 1);
	DrawLine(view[1].x, view[1].y, view[2].x, view[2].y, cr, 1);
	DrawLine(view[2].x, view[2].y, view[3].x, view[3].y, cr, 1);
	DrawLine(view[3].x, view[3].y, view[0].x, view[0].y, cr, 1);
}