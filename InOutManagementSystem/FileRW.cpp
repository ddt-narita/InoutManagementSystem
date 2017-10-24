#include "FileRW.h"
#include <fstream>

using namespace std;
using namespace boost::property_tree;

FileRW::FileRW()
{
}


FileRW::~FileRW()
{
}

void FileRW::writeData(std::string id, boost::property_tree::ptree tree)
{
	//json�������݂�try catch
	try {
		//ID����t�@�C�������쐬����
		string filename = id + ".txt";
		//�쐬�����t�@�C�����̃t�@�C���Ɏ󂯎����json�f�[�^����������
		write_json(filename, tree);
	}
	//�������݂ŗ�O�����������Ƃ�
	catch (...) {
		//�������݂Ɏ��s�������Ƃ��O�Œʒm
		throw exception("�t�@�C���ւ̃f�[�^�������݂��ł��܂���ł����B");
	}

}

void FileRW::readFileData(std::string id, boost::property_tree::ptree recvTree)
{
	//json�ǂݍ��݂�try catch
	try {
		//������ID����t�@�C�������쐬����
		string filename = id + ".txt";
		//�t�@�C�����̃t�@�C����json�f�[�^��������json�I�u�W�F�N�g�Ŏ󂯎��
		read_json(filename, recvTree);
	}
	//json�ǂݍ��݂�try catch
	catch (...) {
		//id�̃t�@�C���ǂݍ��݂��ł��Ȃ��������Ƃ�ʒm
		throw exception(("PC���id: "+ id +"\n�̃t�@�C���̃f�[�^���ǂݎ��܂���ł����B").c_str());
	}
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
vector<string> FileRW::readFileData(string id)
{
	vector<string> recvData;
	//������id����t�@�C�������쐻����
	string fileName = id + ".txt";
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

bool FileRW::checkId(string id)
{
	//����p�̕ϐ�
	int judge = 0;
	//������ID�𕶎���ɕϊ�
	string filename = id + ".txt";
	//�t�@�C�����̓X�g���[���𐶐�
	ifstream ifs;
	//�t�@�C�����J��
	ifs.open(filename);

	if (!ifs) {
		judge = 0;
		return false;
	}

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
