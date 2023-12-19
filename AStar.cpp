#include "AStar.h"

AStar::AStar()
	: startCell_(1, 1), goalCell_(4, 4)
{
	//　マップの初期化
	map_.resize(5);
	for (int x = 0; x < map_.size(); x++) {
		map_[x].resize(5);
		for (int y = 0; y < map_[x].size(); y++) {
			map_[x][y] = nullptr;
		}
	}
}

AStar::~AStar() {
	for (int x = 0; x < map_.size(); x++) {
		for (int y = 0; y < map_[x].size(); y++) {
			if (map_[x][y] == nullptr)	continue;
			else {
				delete map_[x][y];
				map_[x][y] = nullptr;
			}
		}
	}
}

void AStar::Initialize() {
	map_[startCell_.x_][startCell_.y_] = new Node(startCell_, CELL_TYPE::PATH);
}

void AStar::Serach() {
	if (!map_[startCell_.x_][startCell_.y_]->IsNone())	return;

	map_[startCell_.x_][startCell_.y_]->UpdateStatus();
	OpenCell(map_[startCell_.x_][startCell_.y_]);
}

void AStar::OpenCell(Node* n) {
	CELL_TYPE t = CELL_TYPE::PATH;
	for (auto& e : adjacentCells) {
		map_[(*n).GetPosX() + e.x_][(*n).GetPosY() + e.y_] = new Node((*n).GetPos() + e, t, n);
	}
}
