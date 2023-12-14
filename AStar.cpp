#include "AStar.h"

namespace {
	const int DEFAULT_X = 15;
	const int DEFAULT_Y = 15;
}

AStar::AStar() {
	map_.resize(DEFAULT_X);
	for (auto& e : map_) {
		e.resize(DEFAULT_Y);
	}

	for (int x = 0; x < map_.size(); x++) {
		for (int y = 0; y < map_[x].size(); y++) {
			map_[x][y] = nullptr;
		}
	}
}

AStar::AStar(int x, int y) {
	if (x < 5)	x = 5;
	if (y < 5)	y = 5;
	if (x % 2 == 0)	x++;
	if (y % 2 == 0)	y++;

	map_.resize(x);
	for (auto& e : map_) {
		e.resize(y);
	}

	for (int x = 0; x < map_.size(); x++) {
		for (int y = 0; y < map_[x].size(); y++) {
			map_[x][y] = nullptr;
		}
	}
}

AStar::~AStar()
{
}

void AStar::SetStart(CELL& s) {
	startCell_ = s;
}

void AStar::SetStart(int x, int y) {
	startCell_ = CELL(x, y);
}

void AStar::SetGoa(CELL& g) {
	goalCell_ = g;
}

void AStar::SetGoal(int x, int y) {
	goalCell_ = CELL(x, y);
}
