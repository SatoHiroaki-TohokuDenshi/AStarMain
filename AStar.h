#pragma once
#include <vector>
#include "Node.h"

class AStar {
private:
	std::vector <std::vector<Node*>> map_;
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
};