#pragma once
#include <vector>
#include "InoutDay.h"
#include "procedureInOut.h"

class ChainData
{
public:
	INOUT inout;	//���ނǂ��炩
	int day;	//���t
	int hour;	//����
	int minute;	//��

	//��̍s�ւ̃|�C���^
	ChainData* upper;
	//���̍s�ւ̃|�C���^
	ChainData* under;

public:
	//�R���X�g���N�^
	ChainData();
	~ChainData();

	//�s�̃f�[�^���擾����
	ChainData* getRow(int row);
	int getValue(int col);

	//�s��}������
	ChainData* insertUpper(int row);
	//�s����菜��
	void remove(int row);

	//�㉺�ւǂ�������݂��̃|�C���^���w���悤�ɂ���
	void addUpper(ChainData* upper);
	void addUnder(ChainData* under);

	//vector�̏�񂩂�s���Ƃ̏����쐬����(���ނ̎��Ԃ̔z���K�p������)
	void applyVecData(std::vector<InoutDay> data);
	//vector�̃f�[�^���쐻����
	void makeDataForVec(std::vector<InoutDay> inoutdays);
};

