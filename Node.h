#pragma once

// 2次元座標を表す構造体
struct CELL {
	int x_;		// x座標
	int y_;		// y座標

	// コンストラクタ
	CELL(int x, int y)
		: x_(x), y_(y) {};

	// 等価比較演算子
	bool operator==(CELL& c) {
		return (this->x_ == c.x_ && this->y_ == c.y_);
	}
};

// ノードの状態を表す列挙型
enum class STATUS {
	NONE = 0,		// 未着手
	OPEN,			// 調査対象
	CLOSED,			// 調査済み
};

// ノード情報を表すクラス
class Node {
private:
	CELL myPos_;	// 自分の座標
	STATUS status_;	// 現在の状態
	int cost_;		// 実コスト
	int h_cost_;	// 推定コスト
	int score_;		// 評価値
	CELL* parent_;	// 親のポインタ

public:
	Node(CELL pos, CELL* p);
	~Node();

	int GetCost() { return cost_; };
	int GetHCost() { return h_cost_; };
	int GetScore() { return score_; };

	/// <summary>コストを計算</summary>
	/// <param name="c">移動に掛かるコスト</param>
	/// <param name="p">親のコスト</param>
	void CalcCost(int c, int p);
	/// <summary>推定コストを計算</summary>
	/// <param name="g">ゴールのセル情報</param>
	void CalcHCost(CELL& g);
	/// <summary>スコアを評価</summary>
	void CalcScore();
};