#pragma once
#include"Wire.h"
#include <vector>
#include <memory>
class PanoramaManager {
private:
	std::vector<std::shared_ptr<Wire>> wires;
	int pnrm;
	int time = 0;
public:
	PanoramaManager();
	~PanoramaManager();
	void update();
};