#include "procedureRegist.h"



procedureRegist::procedureRegist()
{
}


procedureRegist::~procedureRegist()
{
}

void procedureRegist::init()
{
	//�e�N���XDataManager�̏������֐��ŃJ�[�h���[�_�̏��������s��
	DataManager::init();
}

void procedureRegist::registData()
{
	//�t�@�C���ƃJ�[�h�֏�������
	writeData();
}
