#pragma once

// 2�������W�n��\���\����
struct Cell {
	int x_;
	int y_;

	// �R���X�g���N�^
	Cell(int x, int y)
		: x_(x), y_(y) {};

	// ���Z���Z�q
	Cell operator+(const Cell& param) {
		return { this->x_ + param.x_, this->y_ + param.y_ };
	}

	// ������r���Z�q
	bool operator==(Cell& param) {
		return (this->x_ == param.x_ && this->y_ == param.y_);
	}
};

// �m�[�h�̏�Ԃ�\���񋓌^
enum class STATUS {
	NONE = 0,		// ������
	OPEN,			// �����Ώ�
	CLOSED,			// �����ς�
};

// �Z���̎�ނ�\���񋓌^
enum class CELL_TYPE {
	WALL = 0,	// �ǁE�ʍs�s��
	PATH = 1,	// ���E��{�̃Z��
};

// �m�[�h����\���N���X
class Node {
private:
	Cell myPos_;		// �����̍��W
	CELL_TYPE type_;	// �Z���̎��
	STATUS status_;		// ������
	int cost_;			// ���R�X�g
	int hCost_;			// ����R�X�g
	int score_;			// �R�X�g�̕]���l
	Node* parent_;		// �e�̃m�[�h

public:
	Node(Cell pos, CELL_TYPE t);
	Node(Cell pos, CELL_TYPE t, Node* p);
	~Node();

	// ���R�X�g���v�Z
	void CalcCost();
	// ����R�X�g���v�Z
	void CalcHCost(Cell& goal);
	// �R�X�g��]��
	void CalcScore();

	Cell GetPos() { return myPos_; };
	int GetPosX() { return myPos_.x_; };
	int GetPosY() { return myPos_.y_; };
	// �R�X�g���擾
	int GetCost() { return cost_; };
	// �X�R�A���擾
	int GetScore() { return score_; };

	// �R�X�g��ݒ�
	void SetCost(int c) { cost_ = c; };
	// �e��ݒ�
	void SetParent(Node* p) { parent_ = p; };

	bool IsNone() { return status_ == STATUS::NONE; };
	bool IsOpen() { return status_ == STATUS::OPEN; };
	void UpdateStatus();

	bool IsThrough() { return type_ != CELL_TYPE::WALL; };
};