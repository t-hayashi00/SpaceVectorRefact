#pragma once
#include "module.h"

class Scene {
private:
protected:
public:
	Scene();
	virtual ~Scene() = 0;
	virtual Scene* update() = 0;
};