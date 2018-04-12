#pragma once
#include "ObjectMediator.h"
#include "Object.h"
#include <list>

ObjectMediator::ObjectMediator()
{
	og = new ObjectGenerator();
	player = new Player(425, 0, 90);
	UI = new UserInterface(&player->hp, &player->bomb);
	objects.emplace(player->center.z, player);
}

ObjectMediator::~ObjectMediator()
{
	delete og;
	std::list<Object*> destroy;
	for (auto p : objects)
	{
		destroy.push_back(p.second);
	}
	for (Object* obj : destroy)
	{
		removeObject(obj);
		delete obj;
	}
}

bool ObjectMediator::isCollided(const Object& o1, const Object& o2)
{
	bool inRangeZ = abs(o1.center.z - o2.center.z) < 10;
	bool inCircle =
		  (o1.center.x - o2.center.x)*(o1.center.x - o2.center.x)
		+ (o1.center.y - o2.center.y)*(o1.center.y - o2.center.y)
		< (o1.size + o2.size)*(o1.size + o2.size);
	return inRangeZ && inCircle;
}

bool ObjectMediator::updateAll() 
{
	input();
	int freq = 60 / getGameSpeed();
	if (frameCount++ % freq == 0) {
		og->generateObject(&objects);
	}
	std::list<Object*> destroy;
	//pairŒ^ map‚Ìê‡first‚É‚Íkey, second‚É‚Ívalue
	for (auto p : objects)
	{
		p.second->update();

		if (p.second->getObjectType() != "bullet"
			&& p.second->getObjectType() != "player")
		{
			if (isBlasted)p.second->hp = 0;
			if (p.second->inactive == 0)
			{
				// bullet
				for (auto b : bullets) {
					if (isCollided(*p.second, *b)) {
						p.second->affect(b);
						b->affect(p.second);
					}
				}
				if (isCollided(*p.second, *player))
				{
					p.second->affect(player);
					player->affect(p.second);
				}
			}
		}

		if (p.second->isDestroyable())
		{
			if (p.second->getObjectType() == "bullet") {
				bullets.remove(p.second);
			}
			destroy.push_back(p.second);
		}
	}
	for (Object* obj : destroy)
	{
		removeObject(obj);
		delete obj;
	}
	isBlasted = false;
	UI->drawAll();
	drawAll();
	return player->hp <= 0;
}

void ObjectMediator::drawAll() 
{
	std::list<Object*> change;
	for (auto p : objects) {
		p.second->draw();
		if (p.second->isChangedZ())
		{
			change.push_back(p.second);
		}
	}
	for (Object* obj : change)
	{
		removeObject(obj);
		addObject(obj);
	}
}

void ObjectMediator::addObject(Object* target)
{
	objects.emplace(target->center.z, target);
}

void ObjectMediator::removeObject(Object* target)
{
	// iterator ‚Ìbegin end‚ªpair‚Å•Ô‚Á‚Ä‚­‚é
	auto &p = objects.equal_range(target->getPreZ());
	for (auto it = p.first; it != p.second; it++)
	{
		if (it->second == target) 
		{
			objects.erase(it);
			break;
		}
	}
}

void ObjectMediator::input() {
	if (CheckHitKey(KEY_INPUT_Z) && player->interval <= 0) {
		player->interval = 20;
		Object* bullet = new Bullet(1, player->center.z - 20, 4, player->getDegree());
		bullets.push_back(bullet);
		objects.emplace(bullet->center.z, bullet);
	}
	else player->interval--;
	if (CheckHitKey(KEY_INPUT_X) && player->bomb >= 900) {
		Point v = convertToView(&player->center);
		bomb_flash(v.x, v.y);
		shake(30, 30);
		playSound("bomb");
		player->bomb = 0;
		player->inactive = 180;
		isBlasted = true;
	}
}