#pragma once
#include "Scene.h"
#include "Title.h"

class GameOver : public Scene {
private:
	int image;
	FILE *fp;
	int score;
	bool next = false;
	double frameCount = 0;
protected:
public:
	GameOver();
	~GameOver();
	Scene* update();
};