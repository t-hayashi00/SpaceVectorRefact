#pragma once
#include "DxLib.h"
#include "Player.cpp"
#include "PanoramaManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("Space Vector - hidden");
	ChangeWindowMode(1);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	int scr = MakeScreen(640, 480, 0);
	double gameSpeed = 2;
	FILE *fp;

	PanoramaManager pm;
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && !ClearDrawScreen()) {
		ClearDrawScreen();
		pm.update();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
