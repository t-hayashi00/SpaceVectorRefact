#pragma once
#include "Wire.h"
#include "module.h"
#include <algorithm>
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