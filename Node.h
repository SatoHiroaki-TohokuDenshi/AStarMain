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
	int score_;		// �]���l
	CELL* parent_;	// �e�̃|�C���^

public:
	Node(CELL pos, CELL* p);
	~Node();

	int GetCost() { return cost_; };
	int GetHCost() { return h_cost_; };
	int GetScore() { return score_; };

	/// <summary>�R�X�g���v�Z</summary>
	/// <param name="c">�ړ��Ɋ|����R�X�g</param>
	/// <param name="p">�e�̃R�X�g</param>
	void CalcCost(int c, int p);
	/// <summary>����R�X�g���v�Z</summary>
	/// <param name="g">�S�[���̃Z�����</param>
	void CalcHCost(CELL& g);
	/// <summary>�X�R�A��]��</summary>
	void CalcScore();
};