#pragma once
#include "DataManager.h"

enum INOUT
{
	In = 0,
	Out = 1,
};

class procedureInOut :
	public DataManager
{
public:
	//���ނǂ���Ȃ̂��i�[����ϐ�
	INOUT inout;

public:
	procedureInOut();
	~procedureInOut();

	//�J�[�h���[�_�[���̏������������s���֐�
	void init();
	//���ފُ���
	void InOut();

	//���ݎ�������ގ��Ԃ̃����o�ɃZ�b�g����(���ފَ����Ƃ��ċL�^����)
	void setInOutTime();
	//���ނ̕s�������`�F�b�N����
	void inoutCheck();
};

