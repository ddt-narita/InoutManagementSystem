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


	//��1�E2�Z�N�^�[���g�p�s�̂��߁A8�u���b�N�����炵�ď������s�����߂̒����ϐ�
	const int adjustBlock = 8;



	void fileout(char* a) {
		std::stringstream ss;
		int len = strlen(a);
		for (int i = 0; i < len; i++) {

			ss << std::setw(2) << std::hex <<  a[i] << std::endl;

			if ((i + 1) >= len) {
				ss <<("\n");
			}
			else {
				ss << (" ");
			}

		}
		std::string filename = "debug.txt";
		std::ofstream ofs;
		ofs.open(filename, std::ios::app);
		ofs << ss.str();
		ofs.close();
	}


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