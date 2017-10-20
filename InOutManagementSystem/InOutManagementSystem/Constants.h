#pragma once

#ifndef __Constants
#define __Constants


#include <sstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <assert.h>
#include <fstream>
#include <iomanip>

class Constants {
public:
	//
	const std::string MESSAGE_RESOURSE_NO_SERVICE = "Smart Card�T�[�r�X���N������Ă��܂���";
	const std::string MESSAGE_RESOUSE_ERROR = "Smart Card�T�[�r�X�Ƃ̐ڑ��Ɏ��s���܂����B";
	const std::string MESSAGE_NO_READER = "�J�[�h���[�_�[���ڑ�����Ă��܂���";
	const std::string MESSAGE_READER_ACCESS_ERROR = "�J�[�h���[�_�[�Ƃ̐ڑ��Ɏ��s���܂����B";
	const std::string MESSAGE_NO_CARD = "�J�[�h���Z�b�g����Ă��܂���";
	const std::string MESSAGE_CARD_ACCESS_ERROR = "�J�[�h�Ƃ̐ڑ��Ɏ��s���܂����B";
	const std::string MESSAGE_CARD_REMOVE = "�J�[�h�����O����܂����B";
	const std::string MESSAGE_FAILED_SEND_COMMAND = "�R�}���h�̑��M�Ɏ��s���܂����B";
	const std::string MESSAGE_WARNING_WRITE_ACCESS_BLOCK = "�A�N�Z�X����̃u���b�N�ɏ������ނ��Ƃ͂ł��܂���B";
	const std::string MESSAGE_NO_SUCH_ID = "���݂��Ȃ�ID�ł�";
	const std::string MESSAGE_CANNOT_OPEN_ID_FILE = "ID�̃t�@�C���̃t�@�C�����J���܂���ł����B";

	const std::string MESSAGE_NO_ID = "ID���F�؂ł��܂���";
	const std::string MESSAGE_CHARACTER_REJECT = "���ً��ێ҂ł��B";
	const std::string MESSAGE_CHARACTER_CAUTION_NEED = "�v���Ӑl���ł��B";

	const std::string MESSAGE_IN_ERROR = "�ފق��Ă��܂���";
	const std::string MESSAGE_OUT_ERROR = "���ق��Ă��܂���";
	const std::string MESSAGE_INOUT_OVER_ERROR = "���ފق̊Ǘ�������31���𒴂��܂���\n�Ǘ��҂ɕ񍐂��Ă�������";

	//�p�����[�^�̒l
	const static int general = 0x00;
	
	const static int noInout = 0x01;
	const static int cautionNeed = 0x02;

	const static int admin = 0x01;

	const static int parttime = 0x01;
	const static int butyou = 0x02;

	const static int group1 = 0x01;
	const static int group2 = 0x02;
	const static int group3 = 0x04;

	const static int eigyou = 0x01;
	const static int soumu = 0x02;
	const static int kaihatu = 0x04;


	//���[�U�[ID�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int userIdSectorNum = 0;
	const static int userIdBlockNum = 0;
	const static int userIdStartByteNum = 0;

	//�c���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int lastNameSectorNum = 0;
	const int lastNameBlockNum = 1;
	const static int lastNameStartByteNum = 0;

	//���O�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int firstNameSectorNum = 0;
	const static int firstNameBlockNum = 2;
	const static int firstNameStartByteNum = 0;

	//�p�X���[�h�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int passSectorNum = 1;
	const static int passBlockNum = 0;
	const static int passStartByteNum = 0;

	//�d�b�ԍ��̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int tellSectorNum = 1;
	const static int tellBlockNum = 1;
	const static int tellStartByteNum = 0;

	//���N�����̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int birthdaySectorNum = 1;
	const static int birthdayBlockNum = 2;
	const static int birthdayStartByteNum = 0;

	//�p�����[�^�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int parameterSectorNum = 1;
	const static int parameterBlockNum = 2;
	const static int parameterStartByteNum = 4;

	//�Z���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int addressSectorNum = 2;
	const static int addressBlockNum = 0;
	const static int addressStartByteNum = 0;

	//���ފق̔N���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int inoutTimeSectorNum = 4;
	const static int inoutTimeBlockNum = 0;
	const static int inoutTimeStartByteNum = 0;

	//���ق̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int inTimeSectorNum = 4;
	const static int inTimeBlockNum = 0;
	const static int inTimeStartByteNum = 2;

	//�ފق̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const static int outTimeSectorNum = 6;
	const static int outTimeBlockNum = 0;
	const static int outTimeStartByteNum = 2;


	//��1�E2�Z�N�^�[���g�p�s�̂��߁A8�u���b�N�����炵�ď������s�����߂̒����ϐ�
	const static int adjustBlock = 8;

	/*
	�֐���:StrToC_str
	�T�v:System::String^����std::string�ɕϊ����ĕԂ��֐�
	����:String^ �ϊ���
	�ԋp�l:string �ϊ���̕�����
	�쐬��:9��15��(��)
	�쐬��:���c�C�V
	*/
	std::string StrToc_str(System::String^ temp) {
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	}
};

//Constants constants;


#endif // !__Constants