#pragma once
#include "PanoramaManager.h"

PanoramaManager::PanoramaManager()
{
	pnrm = LoadGraph("image/panorama.png");
}

PanoramaManager::~PanoramaManager()
{
}

void PanoramaManager::update() {
	DrawGraph(0, 0, pnrm, FALSE);
	int freq = 60 / getGameSpeed();
	if (time % freq == 0) {
		wires.push_back(std::make_shared<Wire>((time/10)%360));
	}
	int cnt = 0;
	std::vector<int>eraseList;

	for(auto wire : wires) {
		if (wire->update()) {
			eraseList.push_back(cnt);
		}
		cnt++;
	}
	while (!eraseList.empty()) {
		wires.erase(wires.begin() + eraseList.back());
		eraseList.pop_back();
	}

	SetDrawBlendMode(DX_BLENDGRAPHTYPE_NORMAL, 1);
	time ++;
}