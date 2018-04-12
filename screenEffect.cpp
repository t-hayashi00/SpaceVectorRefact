#include "screenEffect.h"

EffectElement e_flash;
EffectElement e_bomb;
EffectElement e_shake;
EffectElement e_nega;
Point bomb;
int image;
void setupEffect() {
	image = LoadGraph("image/bomb.png");
}

void backEffect()
{
	if (e_flash.time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, (e_flash.power * e_flash.time) / 30);
		DrawBox(0, 0, 640, 480, e_flash.color, 1);
		e_flash.time--;
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void frontEffect()
{
	if (e_shake.time > 0)
	{
		Point vp = getVp();
		vp.x += GetRand(e_shake.power) - e_shake.power / 2;
		vp.y += GetRand(e_shake.power) - e_shake.power / 2;
		setVp(vp.x, vp.y);
		e_shake.time--;
	}

	if (e_nega.time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_INVDESTCOLOR, 255);
		DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), 1);
		e_nega.time--;
	}

	if (e_bomb.time > 0)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * e_bomb.time / 30);
		DrawRotaGraph(bomb.x, bomb.y, 121 - 2 * e_bomb.time, 0, image, TRUE);
		e_bomb.time--;
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void bomb_flash(int x, int y)
{
	if (image == 0)image = LoadGraph("image/bomb.png");
	e_bomb.time = 60;
	bomb.x = x;
	bomb.y = y;
}

void flash(int time, int power, unsigned int color)
{
	e_flash.time = time;
	e_flash.power = power;
	e_flash.color = color;
}

void shake(int time, int power)
{
	e_shake.time = time;
	e_shake.power = power;
}

void nega(int time)
{
	e_shake.time = time;
}

void resetEffect()
{
	e_flash.time = 0;
	e_shake.time = 0;
	e_shake.time = 0;
}