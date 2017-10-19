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
	//DataManager::readCardData();
	
readCardId();
	
	
	//�ǂ݂��񂾃J�[�h��ID���画����s��
	DataManager::checkId();

readFileData();

	//�l���̃`�F�b�N���s��
	DataManager::checkCharacter();
	//���ފقɊւ��Ẵ`�F�b�N
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
		inoutTime.clear();
		//�����̒l���Z�b�g����
		inoutYM = (pnow->tm_year + 1900) * 100 + (pnow->tm_mon + 1);
	}

	//1�o�C�g�ڂɂ͓��ނǂ��炩�������l��
	charArraySizeInt[0] = this->inout;
	//2�o�C�g�ڂɂ͓��t��
	charArraySizeInt[1] = pnow->tm_mday;
	//3�o�C�g�ڂɂ͎��Ԃ�
	charArraySizeInt[2] = pnow->tm_hour;
	//4�o�C�g�ڂɂ͕����i�[����
	charArraySizeInt[3] = pnow->tm_min;

	//�쐬����4�o�C�g���̒l��p�ӂ���int�̕ϐ��Ƀ������R�s�[�ŃZ�b�g����
	memcpy(&setNo, charArraySizeInt, 4);

	//�쐬�����l�������o�̓��ފَ��ԂƂ��ăZ�b�g
	DataManager::inoutTime.push_back(setNo);
}

void procedureInOut::inoutCheck()
{
	//���ފق����߂Ă̎�
	if (inoutTime.size() < 1) {
		//�ފق̎�
		if (inout == INOUT::Out) {
			//���ق���Ă��Ȃ����Ƃ��x��
			throw exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}
	//���߂Ăł͂Ȃ��Ƃ�
	else {
		//�Ō�̃f�[�^
		int lastData = inoutTime[inoutTime.size() - 1];
		//int���i�[����o�C�g�z���p�ӂ���
		char lastDataByte[sizeof(int)];
		//�Ō�̃f�[�^���o�C�g�z��ɃR�s�[
		memcpy(lastDataByte, &lastData, sizeof(int));

		//1�o�C�g�ڂ̓��ނǂ��炩��\���l��������s�����Ƃ��Ă��鏈��(��/�ނǂ��炩)�������ɂȂ��Ă��܂��Ƃ�(���ޓ������ƘA���ł�낤�Ƃ����Ƃ�)
		if (lastDataByte[0] == inout) {
			//���̂�낤�Ƃ��Ă��铮��ɂ��킹����O�̃��b�Z�[�W���쐻
			std::string message = (inout == INOUT::In) ? InoutConstant.MESSAGE_IN_ERROR : InoutConstant.MESSAGE_OUT_ERROR;
			//���b�Z�[�W��Y���ė�O�𑗏o����
			throw std::exception(message.c_str());
		}
	}
}
