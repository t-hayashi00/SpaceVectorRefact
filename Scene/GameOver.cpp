#include "GameOver.h"

GameOver::GameOver() {
	fopen_s(&fp, "highscore.dat", "rb");
	if (fp != NULL) {
		fread(&score, sizeof(score), 1, fp);
		fclose(fp);
		if (int(getScore()) > score) {
			score = int(getScore());
			fopen_s(&fp, "highscore.dat", "wb");
			if (fp != NULL) {
				fwrite(&score, sizeof(score), 1, fp);
				fclose(fp);
			}
		}
	}
}

GameOver::~GameOver() {
}

Scene* GameOver::update() {
	Scene* result = this;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawBox(0, 0, 640, 480, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
	DrawFormatString(260, 240 - 25, GetColor(255, 255, 255), "PRESS Z KEY");
	DrawFormatString(260, 240 + 25, GetColor(255, 255, 255), "SCORE %d", score);

	if (CheckHitKey(KEY_INPUT_Z)) {
		next = true;
	}
	if (next)frameCount++;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * (frameCount) / 6);
	DrawBox(0, 0, 640, 480, 0x000000, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 1);
	if (frameCount>18)return new Title();

	return result;
}