#include "DataManager.h"
#include <sstream>

using namespace std;

namespace {
	Constants DataMConstants;
};

/*
�֐���:�R���X�g���N�^
�T�v:�e�����o������������
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
DataManager::DataManager()
{
	this->userId = "";
	this->birthday = 0;
	this->inoutYM = 0;
	this->userFirstName = "";
	this->userLastName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->chara = 0;
	this->auth = 0;
	this->password = "";
}

/*
�֐���:�f�X�g���N�^
�T�v:
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
DataManager::~DataManager()
{
}

/*
�֐���:init
�T�v:����������
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::init()
{
	//�J�[�h���[�_�̏��������s��
	card.init();
}

/*
�֐���:checkId
�T�v:�擾����ID��PC��ɑ��݂��邩�ǂ����𔻒�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::checkId()
{
	//�����o�ɃZ�b�g���ꂽID��PC��ɂȂ�
	if (!file.checkId(userId)) {
		//���b�Z�[�W��Y���ė�O�𑗏o����
		throw exception(DataMConstants.MESSAGE_NO_ID.c_str());
	}
}

/*
�֐���:checkCharacter
�T�v:�l���̔�����s��
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::checkCharacter()
{
	//���ً��ێ҂̎�
	if (chara == DataMConstants.noInout) {
		//��O�ł��̂��Ƃ�`����
		throw exception(DataMConstants.MESSAGE_CHARACTER_REJECT.c_str());
	}
}

/*
�֐���:readCardData
�T�v:�J�[�h�̃f�[�^��ǂݍ���
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::readCardData()
{
	//�J�[�h��ǂݍ���Ō��ʂ��擾����
	CardData* result;
	result = card.readCard();
	//�擾�����f�[�^���烁���o�ɃZ�b�g
	applyData(result);
}

/*
�֐���:writeData
�T�v:�����o�̃f�[�^���J�[�h�ƃt�@�C���֏�������
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::writeData()
{
	//�J�[�h�p�Ƀf�[�^��ϊ����ăJ�[�h�ɏ�������
	card.writeCard(makeDataForCard());
	//�t�@�C���p�Ƀf�[�^��ϊ����ăJ�[�h�ɏ�������
	file.writeData(userId, makeDataForFile());
}

/*
�֐���:
�T�v:
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::readFileData()
{
	//�t�@�C���̃f�[�^���i�[���邽�߂̕ϐ���p��
	vector<string> filedata;
	//�t�@�C���̃f�[�^��ǂݍ���ŗp�ӂ����ϐ��Ɋi�[����

	filedata = file.readFileData(userId);

	//�ǂ݂��񂾃f�[�^�������o�ɓK�p������
	applyFileData(filedata);
}

/*
�֐���:
�T�v:
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::readCardId()
{
	//�J�[�h����firstname�݂̂��擾���Ċi�[����
	userId = card.readCardID();
}

/*
�֐���:
�T�v:
����:�Ȃ�
�ԋp�l:string 
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
std::string DataManager::makeDataForFile()
{
	//�t�@�C���ɏ������ނ��߂̃X�g���[�����m��
	std::stringstream ss;

	//�e�����i�[���Ă���
	ss << userId << endl;			// 1
	ss << userLastName << endl;		// 3
	ss << userFirstName << endl;
	ss << password << endl;			// 10
	ss << telNo << endl;			// 4
	ss << birthday << endl;			// 2
	ss << to_string(group) << endl;	// 6
	ss << to_string(cast) << endl;	// 7
	ss << to_string(chara) << endl;	// 8
	ss << to_string(auth) << endl;

	ss << address << endl;			// 5
	ss << inoutYM << endl;			// 9

	//���ފَ����ɂ��Ă��������z�񕔕��J��Ԃ���
	for (int i = 0; i < inTime.size(); i++) {
		//���̎��̔z��̒l���i�[����
		ss << inTime[i] << endl;
	}

	ss << "end intime" << endl;

	for (int i = 0; i < outTime.size(); i++) {
		ss << outTime[i] << endl;
	}

	//�X�g���[���𕶎���ɕς��ĕԋp����
	return ss.str();
}

/*
�֐���:makeDataForCard
�T�v:�����o����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
CardData* DataManager::makeDataForCard()
{
	//����g�p����8�Z�N�^�[���̃f�[�^���i�[����J�[�h�f�[�^��p��
	CardData* carddata = new CardData(9);

	makeIdDataForCard(carddata);
	makeNameDataForCard(carddata);
	makePassDataForCard(carddata);
	makeTellDataForCard(carddata);
	makeBirthDataForCard(carddata);
	makeParameterDataForCard(carddata);
	makeAddressDataForCard(carddata);
	makeInTimeDataForCard(carddata);
	makeOutTimeDataForCard(carddata);

	//�쐬�����������݂����J�[�h�f�[�^��ԋp����
	return carddata;
}

/*
�֐���:makeIdDataForCard
�T�v:���[�U�[ID����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeIdDataForCard(CardData * card)
{
	//���[�U�[��ID�𕶎����
	const char* id = userId.c_str();
	int len = strlen(id);
	//���[�U�[ID���J�[�h�փZ�b�g����
	setDataForCardData(card, DataMConstants.userIdSectorNum, DataMConstants.userIdBlockNum, DataMConstants.userIdStartByteNum, (BYTE*)id, len);
}

/*
�֐���:makeNameDataForCard
�T�v:���O����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeNameDataForCard(CardData * card)
{
	//�c�����o�C�g�z��ɒ���
	const char* firstname = userFirstName.c_str();
	int len = strlen(firstname);
	//�c�����J�[�h�̃f�[�^�փZ�b�g����
	setDataForCardData(card, DataMConstants.firstNameSectorNum, DataMConstants.firstNameBlockNum, DataMConstants.firstNameStartByteNum, (BYTE*)firstname, len);
	//
	const char* lastname = userLastName.c_str();
	len = strlen(lastname);
	//
	setDataForCardData(card, DataMConstants.lastNameSectorNum, DataMConstants.lastNameBlockNum, DataMConstants.lastNameStartByteNum, (BYTE*)lastname, len);
}

/*
�֐���:makePassDataForCard
�T�v:�p�X���[�h����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makePassDataForCard(CardData * card)
{
	const char* pass = password.c_str();
	int len = strlen(pass);

	setDataForCardData(card, DataMConstants.passSectorNum, DataMConstants.passBlockNum, DataMConstants.passStartByteNum, (BYTE*)pass, len);
}

/*
�֐���:makeTellDataForCard
�T�v:�d�b�ԍ�����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeTellDataForCard(CardData * card)
{
	const char* tel = telNo.c_str();
	int len = strlen(tel);

	setDataForCardData(card, DataMConstants.tellSectorNum, DataMConstants.tellBlockNum, DataMConstants.tellStartByteNum, (BYTE*)tel, len);
}

/*
�֐���:makeBirthdayDataForCard
�T�v:���N��������J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeBirthDataForCard(CardData * card)
{
	char birth[4];
	memcpy(birth, &birthday, sizeof(int));

	setDataForCardData(card, DataMConstants.birthdaySectorNum, DataMConstants.birthdayBlockNum, DataMConstants.birthdayStartByteNum, (BYTE*)birth, sizeof(int));
}

/*
�֐���:makeParameterDataForCard
�T�v:�����o����J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeParameterDataForCard(CardData * card)
{
	char para[4];
	para[0] = chara;
	para[1] = auth;
	para[2] = cast;
	para[3] = group;

	setDataForCardData(card, DataMConstants.parameterSectorNum, DataMConstants.parameterBlockNum, DataMConstants.parameterStartByteNum, (BYTE*)para, sizeof(int));
}

/*
�֐���:makeAddressDataForCard
�T�v:�Z������J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeAddressDataForCard(CardData * card)
{
	const char* addr = address.c_str();
	int len = strlen(addr);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k++) {
				if (len > i * 48 + j * 16 + k) {
					card->sector[2 + i]->RWBlock[j][k] = addr[i * 48 + j * 16 + k];
				}
				else {
					card->sector[2 + i]->RWBlock[j][k] = '\0';
				}
			}
		}
	}

}

/*
�֐���:makeInTimeDataForCard
�T�v:���َ��Ԃ���J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeInTimeDataForCard(CardData * card)
{
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &inoutYM, sizeof(short));
	setDataForCardData(card, 4, 0, 0, (BYTE*)tempbuf, sizeof(short));

	int len = this->inTime.size();
	for (int i = 1; i < len + 1; i++) {
		short temp = inTime[i - 1];
		memcpy(tempbuf, &temp, sizeof(short));

		setDataForCardData(card, i / 24 + 4, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}


}

/*
�֐���:makeOutTimeDataForCard
�T�v:�ފَ��Ԃ���J�[�h�ɏ������ރf�[�^���쐬����
����:����
�ԋp�l:CardData
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::makeOutTimeDataForCard(CardData * card)
{

	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &inoutYM, sizeof(short));
	setDataForCardData(card, 6, 0, 0, (BYTE*)tempbuf, sizeof(short));

	int len = this->outTime.size();
	for (int i = 1; i < len + 1; i++) {
		short temp = outTime[i - 1];
		memcpy(tempbuf, &temp, sizeof(short));

		setDataForCardData(card, i / 24 + 6, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}
}

/*
�֐���
����:CardData* card �J�[�h
	:int sector�@�Z�N�^�[
	:int block�@�u���b�N
	:int fromByte�@���o�C�g�ڂ��炩
	:Byte* data�@�i�[�������f�[�^
	:int len ���o�C�g����
*/
void DataManager::setDataForCardData(CardData * card, int sector, int block, int fromByte, BYTE * data, int dataLen)
{
	//�����̃o�C�g����
	for (int i = 0; i < dataLen; i++) {
		//
		card->sector[sector]->RWBlock[block][fromByte + i] = data[i];
	}
}

/*
�֐���:applyData
�T�v:�J�[�h����ǂݎ�����f�[�^��K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyData(CardData * carddata)
{
	applyUserID(carddata);
	applyUserName(carddata);
	////�p�X���[�h��K�p������
	applyPassword(carddata);
	///�d�b�ԍ�
	applyTelNoData(carddata);
	applyBirthday(carddata);
	applyParameter(carddata);
	////�Z��
	applyAddressData(carddata);
	////�ǂ݂��񂾃f�[�^����ފَ��Ԃ̔z��ɒ���
	applyInoutYM(carddata);
	applyInTime(carddata);
	applyOutTime(carddata);
}


/*
�֐���:applyUserID
�T�v:�J�[�h����ǂݎ�������[�U�[ID�K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyUserID(CardData * carddata)
{
	userId = (char*)carddata->sector[0]->RWBlock[0];
}

/*
�֐���:applyUserName
�T�v:�J�[�h����ǂݎ�������[�U�[����K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyUserName(CardData * carddata)
{
	userLastName = (char*)carddata->sector[0]->RWBlock[1];
	userFirstName = (char*)carddata->sector[0]->RWBlock[2];
}

/*
�֐���:applyPassword
�T�v:�J�[�h����ǂݎ�����p�X���[�h��K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyPassword(CardData * carddata)
{
	password = (char*)carddata->sector[1]->RWBlock[0];
}

/*
�֐���:applyTelNoData
�T�v:�J�[�h����ǂݎ�����p�X���[�h��K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyTelNoData(CardData * carddata)
{
	telNo = (char*)carddata->sector[1]->RWBlock[1];
}

/*
�֐���:applyBirthday
�T�v:�J�[�h����ǂݎ�������N������K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyBirthday(CardData * carddata)
{
	char temp[sizeof(int)];
	for (int i = 0; i < sizeof(int); i++) {
		temp[i] = carddata->sector[1]->RWBlock[2][i];
	}
	memcpy(&birthday, temp, sizeof(int));
}

/*
�֐���:applyParameter
�T�v:�J�[�h����ǂݎ�����p�����[�^��K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyParameter(CardData * carddata)
{
	char temp[4];
	for (int i = 0; i < 4; i++) {
		temp[i] = carddata->sector[1]->RWBlock[2][i + 4];
	}

	chara = temp[0];
	auth = temp[1];
	cast = temp[2];
	group = temp[3];
}

/*
�֐���:applyAddressData
�T�v:�J�[�h����ǂݎ�����Z����K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyAddressData(CardData * carddata)
{
	char addr[96] = { 0x00 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if ('\0' != carddata->sector[i]->RWBlock[j]) {
				for (int k = 0; k < 16; k++) {
					addr[i * 48 + j * 16 + k] = (char)carddata->sector[i + 2]->RWBlock[j][k];
				}
			}
		}
	}
	address = addr;
}

/*
�֐���:applyInoutYM
�T�v:�J�[�h����ǂݎ�������ق̔N����K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyInoutYM(CardData * carddata)
{
	char temp[sizeof(short)];
	temp[0] = carddata->sector[4]->RWBlock[0][0];
	temp[1] = carddata->sector[4]->RWBlock[0][1];

	memcpy(&inoutYM, temp, sizeof(short));
}

/*
�֐���:applyInTime
�T�v:�J�[�h����ǂݎ�������ُ���K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyInTime(CardData * carddata)
{
	char temp[sizeof(short)];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k += 2) {
				if (i != 0 || j != 0 || k != 0) {
					temp[0] = carddata->sector[i + 4]->RWBlock[j][k];
					temp[1] = carddata->sector[i + 4]->RWBlock[j][k + 1];
					if (temp[0] != '\0' && temp[1] != '\0') {
						short dayintime;
						memcpy(&dayintime, temp, sizeof(short));

						inTime.push_back(dayintime);
					}
					else {
						return;
					}
				}
			}
		}
	}
}

/*
�֐���:applyOutTime
�T�v:�J�[�h����ǂݎ�����ފَ��Ԃ�K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyOutTime(CardData * carddata)
{
	char temp[sizeof(short)];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k+=2) {
				if (i != 0 || j != 0 || k != 0) {
					temp[0] = carddata->sector[i + 6]->RWBlock[j][k];
					temp[1] = carddata->sector[i + 6]->RWBlock[j][k+1];

					if (temp[0] != '\0' && temp[1] != '\0') {
						short dayouttime;
						memcpy(&dayouttime, temp, sizeof(short));

						outTime.push_back(dayouttime);
					}
					else {
						return;
					}
				}
			}
		}
	}
}

/*
�֐���:set
�T�v:�l���̃p�����[�^���R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X�ŃZ�b�g����
����:int select
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::setChara(int select)
{
	if (select > 0) {
		chara = (0x01 << (select - 1));
	}
}

/*
�֐���:set
�T�v:�l���̃p�����[�^���R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X�ŃZ�b�g����
����:int select
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::setAuth(int select)
{
	if (select > 0) {
		auth = (0x01 << (select - 1));
	}
}

/*
�֐���:set
�T�v:�l���̃p�����[�^���R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X�ŃZ�b�g����
����:int select
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::setCast(int select)
{
	if (select > 0) {
		cast = (0x01 << (select - 1));
	}
}

/*
�֐���:set
�T�v:�l���̃p�����[�^���R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X�ŃZ�b�g����
����:int select
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::setAffli(int select)
{
	group |= (0x01 << select);
}

/*
�֐���:set
�T�v:�l���̃p�����[�^���R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X�ŃZ�b�g����
����:int select
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::setGroup(int select)
{
	group |= (0x01 << (select + 4));
}

/*
�֐���:getSelected
�T�v:�l���̃p�����[�^�̃R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X��Ԃ�
����:����
�ԋp�l:int �C���f�b�N�X
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
int DataManager::getSelectedChara()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (chara & (0x01 << i)) {
			retval = i + 1;
		}
	}
	return retval;
}

/*
�֐���:getSelected
�T�v:�l���̃p�����[�^�̃R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X��Ԃ�
����:����
�ԋp�l:int �C���f�b�N�X
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
int DataManager::getSelectedAuth()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (auth & (0x01 << i)) {
			retval = i + 1;
		}
	}

	return retval;
}

/*
�֐���:getSelected
�T�v:�l���̃p�����[�^�̃R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X��Ԃ�
����:����
�ԋp�l:int �C���f�b�N�X
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
int DataManager::getSelectedCast()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (cast & (0x01 << i)) {
			retval = i + 1;
		}
	}
	return retval;
}

/*
�֐���:getSelected
�T�v:�l���̃p�����[�^�̃R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X��Ԃ�
����:����
�ԋp�l:int �C���f�b�N�X
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
int DataManager::getSelectedAffli()
{
	int retval = 0;

	for (int i = 0; i < 4; i++) {
		if (group & (0x01 << i)) {
			retval = i;
		}
	}

	return retval;
}

/*
�֐���:getSelected
�T�v:�l���̃p�����[�^�̃R���{�{�b�N�X�̑I�΂ꂽ�C���f�b�N�X��Ԃ�
����:����
�ԋp�l:int �C���f�b�N�X
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
int DataManager::getSelectedGroup()
{
	int retval = 0;

	for (int i = 4; i < 8; i++) {
		if (group & (0x01 << i)) {
			retval = i - 4;
		}
	}


	return retval;
}

/*
�֐���:getInoutY
�T�v:���ފق�
����:int ���ފق̔N
�ԋp�l:����
�쐬��:10��20��(��)
�쐬��:���c�C�V
*/
int DataManager::getInoutY()
{
	//
	return inoutYM / 12;
}

/*
�֐���:getInoutY
�T�v:���ފق�
����:int ���ފق̔N
�ԋp�l:����
�쐬��:10��20��(��)
�쐬��:���c�C�V
*/
int DataManager::getInoutM()
{
	int month = inoutYM % 12;
	if (month == 0) {
		month = 12;
	}

	//
	return month;
}

void DataManager::applyFileData(vector<string> fileData)
{
	//1�s�ڂ����[�U�[ID��
	userId = fileData[0];
	//2�s�ڂ�a������
	userFirstName = fileData[1];
	//3�s�ڂ𖼑O��
	userLastName = fileData[2];
	//4�s�ڂ�d�b��
	password = fileData[3];
	//5�s�ڂ��Z����
	telNo = fileData[4];
	//6�s�ڂ�������
	birthday = stoi(fileData[5]);
	//7�s�ڂ��E��
	group = stoi(fileData[6]);
	//8�s�ڂ𑮐���
	cast = stoi(fileData[7]);
	//9�s�ڂ���ނ̔N����
	chara = stoi(fileData[8]);
	//10�s�ڂ��p�X���[�h��
	auth = stoi(fileData[9]);
	//�Z����K�p
	address = fileData[10];
	//���ފق̔N����K�p
	inoutYM = stoi(fileData[11]);

	int i;

	//10�s�ڂ��������ׂ�
	for (i = 12; i < fileData.size(); i++) {
		if (fileData[i] == "end intime") {
			i++;
			break;
		}
		//�����o�Ɍ�납��ǉ����Ă���
		inTime.push_back(stoi(fileData[i]));
	}

	for (; i < fileData.size(); i++) {
		outTime.push_back(stoi(fileData[i]));
	}


}

void DataManager::clear()
{
	card.clear();
}
