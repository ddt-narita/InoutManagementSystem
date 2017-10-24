#include "procedureInOut.h"
#include <stdio.h>
#include <time.h>
#include <exception>

using namespace std;

namespace {
	Constants InoutConstant;
}

procedureInOut::procedureInOut()
{
}

procedureInOut::~procedureInOut()
{
}

/*
�֐���:init
�T�v:�J�[�h���[�_�[�̏������ȂǏ������������s���֐�
����:����
�ԋp�l:����
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void procedureInOut::init()
{
	//�e�N���XDataManager�̏������֐��ŃJ�[�h���[�_�[��������
	DataManager::init();
}

/*
�֐���:InOut
�T�v:���ފُ������s���֐�
����:����
�ԋp�l:����
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void procedureInOut::InOut()
{
	//�J�[�h����f�[�^�����o���ă����o�ɕۊ�
	DataManager::readCardData();
	//�ǂ݂��񂾃J�[�h��ID���画����s��
	DataManager::checkId();
	//�l���̃`�F�b�N���s��
	DataManager::checkCharacter();
	inoutCheck();
	//���ݎ�������ފق̎��ԂƂ��ăZ�b�g����
	setInOutTime();
	//�����o�̃f�[�^����������
	writeData();
}

/*
�֐���:setInOutTime
�T�v:���ݎ�������ފق̎��ԂƂ��ăZ�b�g����
����:����
�ԋp�l:����
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void procedureInOut::setInOutTime()
{
	//int�T�C�Y���̃o�C�g�z����쐬����
	char charArraySizeInt[sizeof(int)];
	//���ފَ��ԂƂ��ăZ�b�g���邽�߂̒l��p�ӂ���
	int setNo = 0;
	//���ݎ������擾����
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);

	//�Z�b�g����Ă��錎���ǂݍ��܂ꂽ���t�̌��ƈႤ
	if (getInoutM() != pnow->tm_mon + 1) {
		//���ފق̎��Ԃ̔z����N���A
		inTime.clear();
		outTime.clear();
		//�����̒l���Z�b�g����
		inoutYM = (pnow->tm_year + 1900) * 12 + (pnow->tm_mon) + 1;
	}
	//�ݒ肷�鎞�����Z�b�g
	setNo = (pnow->tm_mday * 24 * 60) + (pnow->tm_hour * 60) + pnow->tm_min;
	
	//
	if (inout == INOUT::In) {
		//
		DataManager::inTime.push_back(setNo);
	}
	else {
		DataManager::outTime.push_back(setNo);
	}


}

void procedureInOut::inoutCheck()
{
	//�ފٓ�����31���𒴂��Ă���Ƃ�
	if (outTime.size() >= 31) {
		//��O�𑗏o���ĊǗ��҂ɕ񍐂���悤�Ɍx��
		throw std::exception(InoutConstant.MESSAGE_INOUT_OVER_ERROR.c_str());
	}
	//�o�^�㏉�߂Ă̎�
	if (inTime.size() == 0) {
		//�ފق��悤�Ƃ��Ă���
		if (inout == INOUT::Out) {
			//�ފكG���[��ʒm
			throw std::exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}

	//���ނǂ����
	if (inTime.size() == outTime.size()) {
		//
		if (inout == INOUT::Out) {
			//
			throw exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}
	//
	else if(inTime.size() > outTime.size()) {
		//
		if (inout == INOUT::In) {
			//
			throw exception(InoutConstant.MESSAGE_IN_ERROR.c_str());
		}
	}

}

