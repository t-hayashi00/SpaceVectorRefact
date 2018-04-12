#pragma once
#include "Scene.h"
#include "GameOver.h"
#include "ObjectMediator.h"

class InGame : public Scene {
private:
	ObjectMediator* om;
	int frameCount = 0;
	int seq = 0;
	bool isGameOver = false;
protected:
public:
	InGame();
	~InGame();
	Scene* update();
};