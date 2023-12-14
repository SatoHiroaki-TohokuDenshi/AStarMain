#pragma once
#include <vector>
#include <array>
#include <map>
#include "Node.h"

namespace {
	enum TYPE {
		T_WALL = 0,	// 通行不可
		T_PATH = 1,	// コスト 1
		T_MAX,
	};
}

class AStar {
private:
	std::vector <std::vector<int>> map_;
	std::array<CELL, 4> surroundCell{ {
		{0, 1}, {-1, 0}, {1, 0}, {0, 1}
	} };
	std::map<TYPE, int> cost{
		{T_PATH, 1},
	};
	CELL startCell_;
	CELL goalCell_;

public:
	AStar();
	AStar(int x, int y);
	~AStar();

	void SetStart(CELL& s);
	void SetStart(int x, int y);
	void SetGoa(CELL& g);
	void SetGoal(int x, int y);

	void StartSearch();
};