#pragma once

// 2�������W��\���\����
struct CELL {
	int x_;		// x���W
	int y_;		// y���W

	// �R���X�g���N�^
	CELL(int x, int y)
		: x_(x), y_(y) {};

	// ������r���Z�q
	bool operator==(CELL& c) {
		return (this->x_ == c.x_ && this->y_ == c.y_);
	}
};

// �m�[�h�̏�Ԃ�\���񋓌^
enum class STATUS {
	NONE = 0,		// ������
	OPEN,			// �����Ώ�
	CLOSED,			// �����ς�
};

// �m�[�h����\���N���X
class Node {
private:
	CELL myPos_;	// �����̍��W
	STATUS status_;	// ���݂̏��
	int cost_;		// ���R�X�g
	int h_cost_;	// ����R�X�g
	Node* parent_;	// �e�m�[�h�̃|�C���^

public:
	Node(CELL pos, Node* p)
		: myPos_(pos), status_(STATUS::NONE), cost_(-1), h_cost_(-1), parent_(p) {};
	~Node() {};

	// �R�X�g���擾
	int GetCost() { return cost_; };
};