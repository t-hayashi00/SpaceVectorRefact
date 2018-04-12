#pragma once
#include "module.h"

struct EffectElement {
	int time = 0;
	int power = 0;
	unsigned int color = 0;
};

void setupEffect();
void backEffect();
void frontEffect();
void bomb_flash(int x, int y);
void flash(int time, int power, unsigned int color);
void shake(int time, int power);
void nega(int time);
void resetEffect();
