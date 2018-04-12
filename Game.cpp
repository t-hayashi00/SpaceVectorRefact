#pragma once
#include "module.h"
#include "ScreenEffect.h"
#include "PanoramaManager.h"
#include "Scene.h"
#include "Title.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetMainWindowText("SpaceVectorRefact");
	ChangeWindowMode(1);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	int scr = MakeScreen(640, 480, 0);
	PanoramaManager pm;
	setupSound();
	setupEffect();
	Scene* scene = new Title();

	int curFrame = 0;
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE) && !ClearDrawScreen()) {
		ClearDrawScreen();

		pm.update();
		backEffect();
		Scene* nextScene = scene->update();
		if (scene != nextScene) {
			OutputDebugString("シーンチェンジ");
			delete scene;
			scene = nextScene;
		}
		frontEffect();
		curFrame++;
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}