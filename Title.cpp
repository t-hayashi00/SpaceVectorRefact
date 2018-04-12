#include "Title.h"

Title::Title() {
	addScore(-getScore());
	setGameSpeed(2);
	resetEffect();
	image = LoadGraph("image/titlelogo.png");
	playMusic("title");
	fopen_s(&fp, "highscore.dat", "rb");
	if (fp != NULL) {
		fread(&score, sizeof(score), 1, fp);
		fclose(fp);
	}
	else {
		score = 0;
		fopen_s(&fp, "highscore.dat", "wb");
		if (fp != NULL) {
			fwrite(&score, sizeof(score), 1, fp);
			fclose(fp);
		}
		fopen_s(&fp, "highscore.dat", "rb");
		if (fp != NULL) {
			fread(&score, sizeof(score), 1, fp);
			fclose(fp);
		}
	}
}

Title::~Title() {

}

Scene* Title::update() {
	setVp(320, 390);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
	DrawRotaGraph(320, 140, 1.5, 0, image, 1);
	DrawFormatString(260, 300, GetColor(255, 255, 255), "PRESS Z KEY");
	DrawFormatString(260, 250, GetColor(255, 255, 255), "HISCORE %d", score);

	if (CheckHitKey(KEY_INPUT_Z)) {
		next = true;
	}
	if (next)frameCount++;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * (frameCount) / 6);
	DrawBox(0, 0, 640, 480, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
	if(frameCount>18)return new InGame();
	return this;
}