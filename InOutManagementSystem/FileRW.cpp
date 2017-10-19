#include "FileRW.h"
#include <fstream>

using namespace std;

FileRW::FileRW()
{
}


FileRW::~FileRW()
{
}

void FileRW::writeData(int id, std::string data)
{
	string filename = to_string(id) + ".txt";
	//�o�̓X�g���[����p��
	ofstream ofs;
	//id�𕶎���ɕς��Ă���ID�Ńt�@�C�����J��
	ofs.open(filename);

	//�I�[�v���ł��Ȃ������Ƃ�
	if (!ofs) {
		//���b�Z�[�W��Y���ė�O�𑗏o����
		throw exception("�f�[�^�ێ��p�̃t�@�C�����J���܂���ł����B");
	}
	 
	//�t�@�C���Ɉ����̃f�[�^���o�͂���
	ofs << data;
	//�t�@�C�������
	ofs.close();
}

/*
�֐���:readFileData
�T�v:�t�@�C������f�[�^��ǂݎ��
����:int id  �f�[�^���擾�������l��ID
	vector<string> recvData�@�擾�����f�[�^���i�[���邽�߂̔z��@
�ԋp�l:����
�쐬��:10��18��(��)
�쐬��:���c�C�V
*/
vector<string> FileRW::readFileData(int id)
{
	vector<string> recvData;
	//������id����t�@�C�������쐻����
	string fileName = to_string(id) + ".txt";
	//�t�@�C���̓��̓X�g���[���𐶐�����
	ifstream ifs;
	//�t�@�C�����Ńt�@�C�����J��
	ifs.open(fileName);

	//�����̊i�[��̃t�@�C�����N���A���Ă���
	recvData.clear();
	//��s���Ƃ̃f�[�^���i�[���邽�߂̃o�b�t�@���擾����
	string buff;
	//��s���Ƃɓǂ݂��ނ��s��
	while (std::getline(ifs, buff)) {
		//�ǂ݂��񂾈�s�̃f�[�^���󂯎�����z��̌��ւƒǉ����Ă���
		recvData.push_back(buff);
	}
	ifs.close();

	return recvData;
}

bool FileRW::checkId(int id)
{
	//����p�̕ϐ�
	int judge = 0;
	//������ID�𕶎���ɕϊ�
	string filename = to_string(id) + ".txt";
	//�t�@�C�����̓X�g���[���𐶐�
	ifstream ifs;
	//�t�@�C�����J��
	ifs.open(filename);

	//����p�̕ϐ�
	string check;
	//��s�ڂ�ǂݍ���
	getline(ifs,check);

	//�����񂪓ǂ݂��߂Ă���
	if ("" != check) {
		//true�������l���i�[����
		judge = 1;
	}

	//�����ԋp����
	return 1 == judge;
}
