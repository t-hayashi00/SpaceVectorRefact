#include "InGame.h"

InGame::InGame() {
	om = new ObjectMediator();
	playMusic("ingame");
	flash(12, 255, 0x000000);
}

InGame::~InGame() {
	delete om;
}

Scene* InGame::update() {
	Scene* result = this;
	isGameOver = om->updateAll();
	if (!isGameOver) {
		int freq = 60 / getGameSpeed();
		if (frameCount % freq == 0) {
			addScore(100);
		}
	}else{
		if (seq == 0) {
			stopMusic();
			playSound("dead");
			SetDrawBlendMode(DX_BLENDMODE_INVDESTCOLOR, 255);
			DrawBox(0, 0, 640, 480, GetColor(255, 255, 255), 1);
			ScreenFlip();
			WaitTimer(800);
			playSound("clash");
			bomb_flash(320, 240);
		}
		else if (seq == 30) {
			result = new GameOver();
		}
		seq++;
	}
	frameCount++;
	return result;
}