#include "ObjectGenerator.h"

ObjectGenerator::ObjectGenerator()
{
}

ObjectGenerator::~ObjectGenerator()
{

}

void ObjectGenerator::generateObject(std::multimap<double, Object*> *objects)
{
	if (!seq.empty()) {
		std::list<Parameter*> row = seq.front();
		seq.pop_front();
		while (!row.empty()) {
			Object* result = nullptr;
			Parameter* p = row.front();
			row.pop_front();
			if (p->type == "block") {
				result = new Block(p->hp, p->z, p->vel, p->degree);
				objects->emplace(result->center.z, result);
			}
			else if (p->type == "ring") {
				result = new Ring(p->z, p->vel, p->degree);
				objects->emplace(result->center.z, result);
			}
			delete p;
		}
	}
	else {
		setPattern();
	}
}

void ObjectGenerator::setPattern() {
	switch (GetRand(2))
	{
	case 0:
		patRandom();
		break;
	case 1:
		patTornado();
		break;
	case 2:
		patRing();
		break;
	default:
		wait(2);
		break;
	}
}

void ObjectGenerator::patRandom()
{
	for (int i = 0; i < 5; i++) {
		std::list<Parameter*> row;
		int rowNum = GetRand(2) + 1;
		double vel = GetRand(2) - 1;
		double degree = GetRand(359);
		for (int j = 0; j < rowNum; j++) {
			row.push_back(new Parameter("block", GetRand(2) + 1, 0, vel, degree + j * 90));
		}
		seq.push_back(row);
		wait(2);
	}
	std::list<Parameter*> row;
	row.push_back(new Parameter("ring", 1, 0, 0, 0));
	row.push_back(new Parameter("ring", 1, 0, 0, 180));
	seq.push_back(row);
}

void ObjectGenerator::patRing()
{
	std::list<Parameter*> row;
	int rowNum = 2;
	double degree = GetRand(359);
	for (int j = 0; j < rowNum; j++) {
		row.push_back(new Parameter("ring", 1, 0, 0, degree + j * 90));
	}
	seq.push_back(row);
	wait(2);
}

void ObjectGenerator::patTornado()
{
	int rowNum = GetRand(2)+1;
	for (int i = 0; i < 20; i++) {
		std::list<Parameter*> row;
		double degree = i * 10;
		for (int j = 0; j < rowNum; j++) {
			row.push_back(new Parameter("block",1 , 0, 0, degree + j * (360 / rowNum)));
		}
		seq.push_back(row);
	}
}

void ObjectGenerator::wait(const int term)
{
	for (int i = 0; i < term; i++) {
		std::list<Parameter*> dummy;
		seq.push_back(dummy);
	}
}