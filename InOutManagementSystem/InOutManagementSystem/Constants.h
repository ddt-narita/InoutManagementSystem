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

const static class Constants {
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

	//�p�����[�^�̒l
	const int general = 0x00;
	
	const int noInout = 0x01;
	const int cautionNeed = 0x02;

	const int admin = 0x01;

	const int parttime = 0x01;
	const int butyou = 0x02;

	const int group1 = 0x01;
	const int group2 = 0x02;
	const int group3 = 0x04;

	const int eigyou = 0x01;
	const int soumu = 0x02;
	const int kaihatu = 0x04;


	//���[�U�[ID�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int userIdSectorNum = 0;
	const int userIdBlockNum = 0;
	const int userIdStartByteNum = 0;

	//�c���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int lastNameSectorNum = 0;
	const int lastNameBlockNum = 1;
	const int lastNameStartByteNum = 0;

	//���O�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int firstNameSectorNum = 0;
	const int firstNameBlockNum = 2;
	const int firstNameStartByteNum = 0;

	//�p�X���[�h�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int passSectorNum = 1;
	const int passBlockNum = 0;
	const int passStartByteNum = 0;

	//�d�b�ԍ��̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int tellSectorNum = 1;
	const int tellBlockNum = 1;
	const int tellStartByteNum = 0;

	//���N�����̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int birthdaySectorNum = 1;
	const int birthdayBlockNum = 2;
	const int birthdayStartByteNum = 0;

	//�p�����[�^�̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int parameterSectorNum = 1;
	const int parameterBlockNum = 2;
	const int parameterStartByteNum = 4;

	//�Z���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int addressSectorNum = 2;
	const int addressBlockNum = 0;
	const int addressStartByteNum = 0;

	//���ފق̔N���̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int inTimeSectorNum = 4;
	const int inTimeBlockNum = 0;
	const int inTimeStartByteNum = 0;

	//���ق̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int inTimeSectorNum = 4;
	const int inTimeBlockNum = 0;
	const int inTimeStartByteNum = 2;

	//�ފق̃Z�N�^�[�ƃu���b�N�Ǝn�܂�̃o�C�g
	const int outTimeSectorNum = 6;
	const int outTimeBlockNum = 0;
	const int outTimeStartByteNum = 2;


	//��1�E2�Z�N�^�[���g�p�s�̂��߁A8�u���b�N�����炵�ď������s�����߂̒����ϐ�
	const int adjustBlock = 8;

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