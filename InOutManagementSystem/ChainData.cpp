#include <exception>
#include "ChainData.h"

using namespace std;

/*
�֐���:�R���X�g���N�^
�T�v:���������s��
����:����
�ԋp�l:�Ȃ�
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
ChainData::ChainData()
{
	//�e����������
	this->inout = INOUT::In;
	this->day = 0;
	this->hour = 0;
	this->minute = 0;

	//�Z��(��Ɖ��̍s)�ւ̃|�C���^���i���ɂ���
	this->upper = nullptr;
	this->under = nullptr;
}

/*
�֐���:�f�X�g���N�^
�T�v:���ɂ܂��s������΍폜����
����:����
�ԋp�l:����
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
ChainData::~ChainData()
{
	//���ɂ܂��s�������
	if (nullptr != under) {
		//���̍s���폜����
		delete under;
	}
}


/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��17��(��)
�쐬��:���c�C�V
*/
ChainData * ChainData::getRow(int row)
{
	////�Z��̐����擾����
	//int broNum  ;
	////�������Z��̐���葽�����
	//if (broNum < row + 1) {
	//	//��O�𑗏o����
	//	throw exception();
	//}

	//���g���J�����g�Ƃ��Ċi�[����
	ChainData* current = this;
	//�������J��Ԃ�
	for (int i = 0; i <= row; i++) {
		//���̌Z��ֈړ�����
		current = current->under;
	}

	//�ړI�̍s��ԋp����
	return current;
}

int ChainData::getValue(int col)
{
	//�l���i�[����ϐ���p��
	int val = 0;
	//�����̗񐔂ɂ���ĕ���
	switch (col)
	{
	//1���
	case 0:
		//���ނǂ���Ȃ̂���Ԃ�
		val = this->inout;
		break;
	//2���
	case 1:
		//���ނ̓��t��Ԃ�
		val = this->day;
		break;
	//3���
	case 2:
		//���Ԃ�Ԃ�
		val = this->hour;
		break;
	//4���
	case 3:
		//����Ԃ�
		val = this->minute;
		break;
	default:
		break;
	}

	//����ɂ���Ċi�[���ꂽ�l��ԋp����
	return val;
}

//�}��
ChainData * ChainData::insertUpper(int row)
{
	//�V�����}������s���쐬����
	ChainData* insertRow = new ChainData();
	
	//�I�����ꂽ�s���擾����
	ChainData* selected = getRow(row);
	//�I�����ꂽ�s�̏�̍s���擾����
	ChainData* upper = selected->upper;

	//�I�����ꂽ�s�̏�ɒǉ�����
	selected->addUpper(insertRow);
	//�}������s�̏�ɏ�̍s��ǉ�����
	insertRow->addUpper(upper);

	//�}�������s�̏���Ԃ�
	return insertRow;
}

//�폜
void ChainData::remove(int row)
{
	//�I�����ꂽ�s���擾
	ChainData* selected = getRow(row);
	//��̍s���擾����
	ChainData* upper = selected->upper;
	//�����i���ł͂Ȃ��Ƃ�
	if (nullptr != selected->under) {
		//�����擾����
		ChainData* under = selected->under;
		//��̉��ɉ����i�[����
		upper->addUnder(under);
		//�폜����Z���̉��ւ̃|�C���^�Ƀi�����i�[����(�f�X�g���N�^�ŉ����ꏏ�ɔj������Ă��܂�����)
		selected->under = nullptr;
	}
	//�����i���̎�
	else {
		//��̃Z���̉��ւ̃|�C���^(�I������Ă����s���w���Ă�������)���i����
		upper->under = nullptr;
	}

	//�I�����ꂽ�s���폜����
	delete selected;
}

//��ɒǉ�����
void ChainData::addUpper(ChainData * upper)
{
	this->upper = upper;
	upper->under = this;
}

//���ɒǉ�����
void ChainData::addUnder(ChainData * under)
{
	this->under = under;
	under->upper = this;
}

//�z��̃f�[�^����s�̏����쐻����
void ChainData::applyVecData(std::vector<InoutDay> data)
{
	//���g���J�����g�Ƃ���
	ChainData* current = this;
	//�z��̃T�C�Y�������J��Ԃ�
	for (int i = 0; i < data.size(); i++) {
		//�J�����g�̉��ɒǉ�����
		current->addUnder(new ChainData());
		//���̒ǉ��������̃f�[�^���J�����g�Ƃ���
		current = current->under;

		//�J�����g�̓��ɂ����Z�b�g����
		current->day = data[i].day;
		//���Ԃ��Z�b�g
		current->hour = data[i].hour;
		//�����Z�b�g
		current->minute = data[i].minute;
	}
}

//�z��̏����쐻����
void ChainData::makeDataForVec(std::vector<InoutDay> inoutdays)
{
	//���g�̉��̃f�[�^���n�܂�ʒu���J�����g�Ƃ���
	ChainData* current = this->under;
	//�J�����g���i�����A�����̔z��̃T�C�Y�������J��Ԃ�
	for (int i = 0; i < inoutdays.size() && current != nullptr; i++) {
		//
		inoutdays.;
		//

		//

		//

	}

}
