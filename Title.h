#pragma once
#include "Scene.h"
#include "InGame.h"

class Title : public Scene{
private:
	int image;
	FILE *fp;
	int score;
	bool next = false;
	double frameCount = 0;
protected:
public:
	Title();
	~Title();
	Scene* update();
};