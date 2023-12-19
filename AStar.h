#pragma once
#include <array>
#include <vector>
#include "Node.h"

class AStar {
private:
	std::vector<std::vector<Node*>> map_;
	std::array<Cell, 8> adjacentCells{
		Cell(-1, -1),	Cell(0, -1),	Cell(1, -1),
		Cell(-1, 0),					Cell(1, 0),
		Cell(-1, 1),	Cell(0, 1),		Cell(1, 1)
	};
	Cell startCell_;
	Cell goalCell_;

public:
	AStar();
	~AStar();

	void Initialize();
	void Serach();

private:
	void OpenCell(Node* n);
};