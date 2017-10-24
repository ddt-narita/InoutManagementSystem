#pragma once

#include <string>
#include <vector>
#include "InoutDay.h"
#include "CardRW.h"
#include "FileRW.h"


class DataManager
{
public:
	std::string userId;
	std::string userFirstName;
	std::string userLastName;
	std::string password;
	std::string telNo;
	int birthday;
	byte group;
	byte cast;
	byte chara;
	byte auth;
	std::string address;
	int currentInout;
	std::vector<InoutDay> inTime;
	std::vector<InoutDay> outTime;
	
	boost::property_tree::ptree fileData;

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

	//�t�@�C���̃f�[�^��ǂݍ���
	void readFileData();
	//�J�[�h��ID�̂ݓǂݍ���
	void readCardId();

	//�J�[�h�֑O��܂ł̃f�[�^�̏������݂��s��
	void writeCard();
	//�t�@�C���֓��ފق̂̏����܂ŏI�����チ���o�̃f�[�^����������
	void writeFile();

	

	
	//�����o�̃f�[�^���J�[�h�ɏ������ރR�}���h�悤�ɕϊ�����
	CardData* makeDataForCard();
	void makeIdDataForCard(CardData* card);
	void makeNameDataForCard(CardData* card);
	void makePassDataForCard(CardData* card);
	void makeTellDataForCard(CardData* card);
	void makeBirthDataForCard(CardData* card);
	void makeParameterDataForCard(CardData* card);
	void makeAddressDataForCard(CardData* card);
	void makeInTimeDataForCard(CardData* card);
	void makeOutTimeDataForCard(CardData* card);


	//�Z�N�^�[�ƃu���b�N�A�u���b�N���̉��o�C�g�ڂ��炩�����߁A�f�[�^�̒��������i�[����
	void setDataForCardData(CardData* card, int sector, int block, int fromByte, BYTE* data, int dataLen);

	////�ǂ݂��񂾃f�[�^�������o�ɓK�p����
	void applyData(CardData* carddata);
	////��b�f�[�^�𔽉f������
	void applyUserID(CardData* carddata);
	void applyUserName(CardData* carddata);
	////�p�X���[�h��K�p������
	void applyPassword(CardData* carddata);
	////�d�b�ԍ�
	void applyTelNoData(CardData* carddata);
	void applyBirthday(CardData* carddata);
	void applyParameter(CardData* carddata);
	////�Z��
	void applyAddressData(CardData* carddata);
	void applyInoutYM(CardData* carddata);
	////�ǂ݂��񂾃f�[�^����ފَ��Ԃ̔z��ɒ���
	void applyInTime(CardData* carddata);
	void applyOutTime(CardData* carddata);
	
	void setChara(int select);
	void setAuth(int select);
	void setCast(int select);
	void setAffli(int select);
	void setGroup(int select);

	int getSelectedChara();
	int getSelectedAuth();
	int getSelectedCast();
	int getSelectedAffli();
	int getSelectedGroup();



	//���ފق̔N���擾
	int getInoutY();
	//���ފق̌����擾
	int getInoutM();

	//�����o�̃f�[�^���t�@�C���ɏ������ނ悤�ɕϊ�����
	void makeDataForFile();
	//�󂯎�����t�@�C���̃f�[�^�������o�ɓK�p������
	void applyFileData(boost::property_tree::ptree fileData);
	//�t�@�C���̓��ق̃f�[�^�������o�ɓK�p������
	void applyFileIndata(boost::property_tree::ptree fileData);
	//�t�@�C���̑ފق̃f�[�^�������o�ɓK�p������
	void applyFileOutdata(boost::property_tree::ptree fileData);

	//�J�[�h���[�_�̊J���Ȃǂ̌㏈��
	void clear();
};

