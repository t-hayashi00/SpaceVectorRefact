#pragma once
#include "module.h"
#include "Object.h"
#include "Player.h"
#include "Block.h"
#include "Ring.h"
#include <list>
#include <map>



class ObjectGenerator
{
private:
	class Parameter {
	private:
	public:
		Parameter(TCHAR* type_, int hp_, double z_, double vel_, double degree_) {
			type = type_;
			hp = hp_;
			z = z_;
			vel = vel_;
			degree = degree_;
		}
		~Parameter(){
		}
		TCHAR* type ;
		int hp;
		double z;
		double vel;
		double degree;
	};
	void setPattern();
	void patRandom();
	void patRing();
	void patTornado();
	void wait(int);

	std::list<std::list<Parameter*>> seq;
public:
	ObjectGenerator();
	~ObjectGenerator();
	void generateObject(std::multimap<double, Object*> *objects);
};