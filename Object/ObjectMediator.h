#pragma once
#include "module.h"
#include "ObjectGenerator.h"
#include "UserInterface.h"
#include "Bullet.h"
#include <map>
class Object;

class ObjectMediator
{
private:
	bool isCollided(const Object& o1, const Object& o2);
	void addObject(Object* target);
	void removeObject(Object* target);
	void input();
	std::multimap<double, Object*> objects;
	std::list<Object*> bullets;
	Player* player;
	ObjectGenerator* og;
	UserInterface* UI;
	int frameCount = 0;
	bool isBlasted = false;

public:
	ObjectMediator();
	~ObjectMediator();
	bool updateAll();
	void drawAll();
};