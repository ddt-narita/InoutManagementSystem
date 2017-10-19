#pragma once

#include <string>
#include <vector>
#include "CardRW.h"
#include "FileRW.h"


class DataManager
{
public:
	int userId;
	int birthday;
	std::string userName;
	std::string telNo;
	std::string address;
	short group;
	short cast;
	short attr;
	int inoutYM;
	std::vector<int> inoutTime;
	std::string password;

	//
	CardRW card;
	FileRW file;

public:
	DataManager();
	~DataManager();

	//�J�[�h���[�_�[�̏��������s���֐�
	void init();
	//ID�̃`�F�b�N���s��
	void checkId();
	//�l���̃`�F�b�N���s��
	void checkCharacter();
	//�J�[�h�̃f�[�^��ǂݍ���
	void readCardData();
	//�f�[�^���J�[�h�ƃt�@�C���֏�������
	void writeData();
	//�t�@�C���̃f�[�^��ǂݍ���
	void readFileData();
	//�J�[�h��ID�̂ݓǂݍ���
	void readCardId();
	
	//�����o�̃f�[�^���t�@�C���ɏ������ނ悤�ɕϊ�����
	std::string makeDataForFile();
	//�����o�̃f�[�^���J�[�h�ɏ������ރR�}���h�悤�ɕϊ�����
	CardData* makeDataForCard();
	BYTE* makeEleDataForCard(BYTE* block);
	BYTE* makeTelDataForCard(BYTE* block);
	BYTE* makeAddDataForCard(BYTE* block);
	SectorData* makeUsernameForCard();
	CardData* makeAddressForCard();
	CardData* makeInoutDataForCard();
	BYTE* makePasswordForCard(BYTE* block);

	//�ǂ݂��񂾃f�[�^�������o�ɓK�p����
	void applyData(CardData* carddata);
	//��b�f�[�^�𔽉f������
	void applyElementData(BYTE* element);
	//�d�b�ԍ�
	void applyTelNoData(BYTE* tel);
	//�ǉ�����K�p������
	void applyAddData(BYTE* addData);
	//���[�U�[��
	void applyUserName(SectorData* nameData);
	//�Z��
	void applyAddressData(CardData* addressData);
	//�ǂ݂��񂾃f�[�^����ފَ��Ԃ̔z��ɒ���
	void applyInout(CardData* inoutData);
	//�p�X���[�h��K�p������
	void applyPassword(BYTE* passBlock);

	//�������猠���擾
	int getAuthority();
	//��������l���擾
	int getCharacter();
	//���ފق̔N���擾
	int getInoutY();
	//���ފق̌����擾
	int getInoutM();

	//�󂯎�����t�@�C���̃f�[�^�������o�ɓK�p������
	void applyFileData(std::vector<std::string> fileData);
	
	//�J�[�h���[�_�̊J���Ȃǂ̌㏈��
	void clear();
};

