#include "Node.h"

Node::Node(CELL pos, CELL* p)
	: myPos_(pos), status_(STATUS::NONE),
	cost_(-1), h_cost_(-1), score_(-1), parent_(p)
{
}

Node::~Node() {
}

void Node::CalcCost(int c, int p) {
	cost_ = p + c;
}

void Node::CalcHCost(CELL& g) {
	int hx = g.x_ - this->myPos_.x_;
	int hy = g.y_ - this->myPos_.y_;
	h_cost_ = hx + hy;
}

void Node::CalcScore() {
	if (cost_ > h_cost_) score_ = cost_;
	else				 score_ = h_cost_;
}
