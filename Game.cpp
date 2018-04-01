#pragma once
#include "DxLib.h"
#include "Player.h"
#include "PanoramaManager.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("SpaceVectorRefact");
	ChangeWindowMode(1);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	int scr = MakeScreen(640, 480, 0);
	FILE *fp;

	PanoramaManager pm;
	Player player;
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && !ClearDrawScreen()) {
		ClearDrawScreen();
		pm.update();
		player.update();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}
