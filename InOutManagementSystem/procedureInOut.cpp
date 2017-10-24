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
	//���ُ󋵂̃`�F�b�N���s��
	inoutCheck();
	//���ݎ�������ފق̎��ԂƂ��ăZ�b�g����
	setInOutTime();
	//
	writeFile();
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
	//���ݎ������擾����		
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);

	//�J�����g�̓��t���Z�b�g����
	currentInout = pnow->tm_year * 10000 + (pnow->tm_mon + 1) * 100 + pnow->tm_mday;

	//���ق̎�
	if (inout == INOUT::In) {
		//���ق̂��̓��̃f�[�^�ɓ��������i�[����
		inTime[pnow->tm_mday].day = pnow->tm_mday;
		inTime[pnow->tm_mday].hour = pnow->tm_hour;
		inTime[pnow->tm_mday].minute = pnow->tm_min;
	}
	//�ފق̎�
	else {
		//�ފق̂��̓��̃f�[�^�ɓ��������i�[����
		outTime[pnow->tm_mday].day = pnow->tm_mday;
		outTime[pnow->tm_mday].hour = pnow->tm_hour;
		outTime[pnow->tm_mday].minute = pnow->tm_min;
	}

}

void procedureInOut::inoutCheck()
{


}

