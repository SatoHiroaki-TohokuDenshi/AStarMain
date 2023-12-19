#pragma once

// 2次元座標系を表す構造体
struct Cell {
	int x_;
	int y_;

	// コンストラクタ
	Cell(int x, int y)
		: x_(x), y_(y) {};

	// 加算演算子
	Cell operator+(const Cell& param) {
		return { this->x_ + param.x_, this->y_ + param.y_ };
	}

	// 等価比較演算子
	bool operator==(Cell& param) {
		return (this->x_ == param.x_ && this->y_ == param.y_);
	}
};

// ノードの状態を表す列挙型
enum class STATUS {
	NONE = 0,		// 未着手
	OPEN,			// 調査対象
	CLOSED,			// 調査済み
};

// セルの種類を表す列挙型
enum class CELL_TYPE {
	WALL = 0,	// 壁・通行不可
	PATH = 1,	// 道・基本のセル
};

// ノード情報を表すクラス
class Node {
private:
	Cell myPos_;		// 自分の座標
	CELL_TYPE type_;	// セルの種類
	STATUS status_;		// 調査状況
	int cost_;			// 実コスト
	int hCost_;			// 推定コスト
	int score_;			// コストの評価値
	Node* parent_;		// 親のノード

public:
	Node(Cell pos, CELL_TYPE t);
	Node(Cell pos, CELL_TYPE t, Node* p);
	~Node();

	// 実コストを計算
	void CalcCost();
	// 推定コストを計算
	void CalcHCost(Cell& goal);
	// コストを評価
	void CalcScore();

	Cell GetPos() { return myPos_; };
	int GetPosX() { return myPos_.x_; };
	int GetPosY() { return myPos_.y_; };
	// コストを取得
	int GetCost() { return cost_; };
	// スコアを取得
	int GetScore() { return score_; };

	// コストを設定
	void SetCost(int c) { cost_ = c; };
	// 親を設定
	void SetParent(Node* p) { parent_ = p; };

	bool IsNone() { return status_ == STATUS::NONE; };
	bool IsOpen() { return status_ == STATUS::OPEN; };
	void UpdateStatus();

	bool IsThrough() { return type_ != CELL_TYPE::WALL; };
};