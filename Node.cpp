#include "Node.h"

Node::Node(Cell pos, CELL_TYPE t)
	: myPos_(pos), status_(STATUS::NONE),type_(t),
	cost_(-1), hCost_(-1), score_(-1), parent_(nullptr)
{
}

Node::Node(Cell pos, CELL_TYPE t, Node* p)
	: myPos_(pos), status_(STATUS::NONE), type_(t),
	cost_(-1), hCost_(-1), score_(-1), parent_(p)
{
}

Node::~Node() {

}

void Node::CalcCost() {
	int c = -1;
	switch (type_) {
	case CELL_TYPE::WALL:
		return;
		break;
	case CELL_TYPE::PATH:
		c = 1;
		break;
	}
	cost_ = parent_->GetCost() + c;
}

void Node::CalcHCost(Cell& goal) {
	int dx = goal.x_ - myPos_.x_;
	int dy = goal.y_ - myPos_.y_;
	hCost_ = dx + dy;
}

void Node::CalcScore() {
	if (cost_ < 0 || hCost_ < 0)	return;
	score_ = cost_ + hCost_;
}

void Node::UpdateStatus() {
	switch (status_) {
	case STATUS::NONE:
		status_ = STATUS::OPEN;
		break;
	case STATUS::OPEN:
		status_ = STATUS::CLOSED;
		break;
	case STATUS::CLOSED:
		break;
	}
}
