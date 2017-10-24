#include "DataManager.h"
#include <sstream>

using namespace std;
using namespace boost::property_tree;

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
	this->currentInout = 0;
	this->userFirstName = "";
	this->userLastName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->chara = 0;
	this->auth = 0;
	this->password = "";
	this->inTime = vector<InoutDay>(31);
	this->outTime = vector<InoutDay>(31);
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


/*
�֐���:readFileData
�T�v:�t�@�C������f�[�^��ǂݎ���ă����o�ɓK�p������
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::readFileData()
{
	//�t�@�C���̃f�[�^��ǂݍ���Ń����o�̃t�@�C������ۊǂ���ϐ��Ɋi�[
	file.readFileData(userId, fileData);
	//�ǂ݂��񂾃f�[�^�������o�ɓK�p������
	applyFileData(fileData);
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

//�J�[�h�ւƏ�������
void DataManager::writeCard()
{
	//�J�[�h�ւƏ������ރf�[�^���쐬���ď�������
	card.writeCard(makeDataForCard());
}

//�t�@�C���p�̃f�[�^���쐬(�ǉ�)���ăt�@�C���ւƏ�������
void DataManager::writeFile()
{
	//�t�@�C���p�̃f�[�^���쐬����
	makeDataForFile();
	//�쐬�����f�[�^���t�@�C���ւƏ�������
	file.writeData(userId, fileData);
}

/*
�֐���:
�T�v:
����:�Ȃ�
�ԋp�l:string 
�쐬��:10��16��(��)
�쐬��:���c�C�V
*/
void DataManager::makeDataForFile()
{
	


}

/*
�֐���:applyFileData
�T�v:�����o�Ɏ擾�����t�@�C���̃f�[�^���ق��̃����o�ɓK�p������
����:property_tree fileData �t�@�C������̃f�[�^
�ԋp�l:����
�쐬��:10��24��(��)
�쐬��:���c�C�V
*/
void DataManager::applyFileData(boost::property_tree::ptree fileData)
{
	//���[�U�[ID��K�p
	userId = fileData.get_value("userId");
	//�c����K�p
	userLastName = fileData.get_value("userLastName");
	//���O��K�p
	userFirstName = fileData.get_value("userFirstName");
	//�p�X���[�h��K�p
	password = fileData.get_value("password");
	//�d�b�ԍ���K�p
	telNo = fileData.get_value("telNo");
	//�a�����𐔒l�ɕϊ����Ċi�[����
	birthday = stoi(fileData.get_value("birthday"));
	//�l���̒l�𐔒l�ɕς��ēK�p
	chara = stoi(fileData.get_value("character"));
	//�����̒l�𐔒l�ɕς��ēK�p
	auth = stoi(fileData.get_value("auth"));
	//��E�̒l�𐔒l�ɕς��ēK�p
	cast = stoi(fileData.get_value("cast"));
	//�����̒l�𐔒l�ɕς��ēK�p
	group = stoi(fileData.get_value("group"));
	//�Z����K�p
	address = fileData.get_value("address");
	//�J�����g�̓��ފٓ��̒l�𐔒l�ɕς��ēK�p
	currentInout = stoi(fileData.get_value("currentInout"));

}

/*
�֐���:applyFileInData
�T�v:�����o�Ɏ擾�����t�@�C���̓��كf�[�^�������o�ɓK�p������
����:property_tree fileData �t�@�C������̃f�[�^
�ԋp�l:����
�쐬��:10��24��(��)
�쐬��:���c�C�V
*/
void DataManager::applyFileIndata(boost::property_tree::ptree fileData)
{
	ptree inData = fileData.get_child("in");


}

/*
�֐���:applyFileData
�T�v:�����o�Ɏ擾�����t�@�C���̑ފكf�[�^�������o�ɓK�p������
����:property_tree fileData �t�@�C������̃f�[�^
�ԋp�l:����
�쐬��:10��24��(��)
�쐬��:���c�C�V
*/
void DataManager::applyFileOutdata(boost::property_tree::ptree fileData)
{
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

	//id���J�[�h�̃f�[�^�֊i�[����
	makeIdDataForCard(carddata);
	//���O���J�[�h�̃f�[�^�֊i�[����
	makeNameDataForCard(carddata);
	//�p�X���[�h���J�[�h�̃f�[�^�֊i�[����
	makePassDataForCard(carddata);
	//�d�b�ԍ����J�[�h�̃f�[�^�֊i�[����
	makeTellDataForCard(carddata);
	//�a�������J�[�h�̃f�[�^�֊i�[����
	makeBirthDataForCard(carddata);
	//�p�����[�^���J�[�h�̃f�[�^�֊i�[����
	makeParameterDataForCard(carddata);
	//�Z�����J�[�h�̃f�[�^�֊i�[����
	makeAddressDataForCard(carddata);
	//���َ��Ԃ��J�[�h�̃f�[�^�֊i�[����
	makeInTimeDataForCard(carddata);
	//�ފَ��Ԃ��J�[�h�̃f�[�^�֊i�[����
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
	//���O���o�C�g�z��ɒ���
	const char* lastname = userLastName.c_str();
	len = strlen(lastname);
	//���O���J�[�h�̃f�[�^���Z�b�g����
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
	//�p�X���[�h���o�C�g�z��ɒ���
	const char* pass = password.c_str();
	int len = strlen(pass);
	//�p�X���[�h���J�[�h�̃f�[�^�ɃZ�b�g����
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
	//�d�b�ԍ����o�C�g�z���
	const char* tel = telNo.c_str();
	int len = strlen(tel);
	//�d�b�ԍ����J�[�h�̃f�[�^�ɃZ�b�g����
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
	//�a�������o�C�g�z���
	char birth[4];
	memcpy(birth, &birthday, sizeof(int));
	//�a�������J�[�h�̃f�[�^�ɃZ�b�g����
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
	//�p�����[�^����ɂ܂Ƃ߂ăo�C�g�z���
	char para[4];
	para[0] = chara;
	para[1] = auth;
	para[2] = cast;
	para[3] = group;
	//�p�����[�^���J�[�h�̃f�[�^�ɃZ�b�g����
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
	//�Z�����o�C�g�z��ɒ���
	const char* addr = address.c_str();
	int len = strlen(addr);

	//�Z���Ɋ��蓖�Ă�ꂽ2�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 2; i++) {
		//�Z�N�^�[���̃u���b�N�������J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			///�u���b�N���̃o�C�g���������J��Ԃ�
			for (int k = 0; k < BLOCK_BYTE; k++) {
				//���̈ʒu���擾�����Z���̒������Z�����
				if (len > i * SECTOR_BLOCK_NUM * BLOCK_BYTE + j * BLOCK_BYTE + k) {
					//���̎��̃o�C�g�z��̒l���i�[����
					card->sector[DataMConstants.addressSectorNum + i]->RWBlock[j][k] = addr[i * SECTOR_BLOCK_NUM* BLOCK_BYTE + j * BLOCK_BYTE + k];
				}
				//������
				else {
					//�I�[�������i�[����
					card->sector[DataMConstants.addressSectorNum + i]->RWBlock[j][k] = '\0';
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
	//���ފق̔N�����o�C�g�z��֒���
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &currentInout, sizeof(short));
	//�J�[�h�̃f�[�^��
	setDataForCardData(card, DataMConstants.inTimeSectorNum, DataMConstants.inTimeBlockNum, DataMConstants.inTimeStartByteNum, (BYTE*)tempbuf, sizeof(short));

	//���َ��Ԃ̃f�[�^�̒������擾����
	int len = this->inTime.size();
	//���̒����������J��Ԃ�
	for (int i = 1; i < len + 1; i++) {
		//�ォ�珇�ɂ��̎��Ԃ��擾����
		short temp = inTime[i - 1].toSHRT();
		//�p�ӂ����o�C�g�z��ɒ���
		memcpy(tempbuf, &temp, sizeof(short));
		//���ގ��Ԃ̃o�C�g�z����Z�b�g����(�����͍ŏ���2�o�C�g���͓��ފق̔N���̂���)
		setDataForCardData(card, i / 24 + DataMConstants.inTimeSectorNum, (i / 8) % SECTOR_BLOCK_NUM, i * 2 % BLOCK_BYTE, (BYTE*)tempbuf, sizeof(short));
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
	//�o�C�g�z���p�ӂ��ē��ފق̔N�������̃o�C�g�z��Ɋi�[����
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &currentInout, sizeof(short));
	//���̃f�[�^���i�[����
	setDataForCardData(card, DataMConstants.inoutTimeSectorNum, DataMConstants.inoutTimeBlockNum, DataMConstants.inoutTimeStartByteNum, (BYTE*)tempbuf, sizeof(short));

	//�ފَ��Ԃ̒������擾����
	int len = this->outTime.size();
	//�ފَ��Ԃ̒����������J��Ԃ�
	for (int i = 1; i < len + 1; i++) {
		//���̈ʒu�̑ފَ��Ԃ��擾����
		short temp = outTime[i - 1].toSHRT();
		memcpy(tempbuf, &temp, sizeof(short));
		//���̃f�[�^���J�[�h�̃f�[�^�Ɋi�[����
		setDataForCardData(card, i / 24 + DataMConstants.outTimeSectorNum, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}
}

/*
�֐���:setDataForCardData
�T�v:�������Ɏ󂯎�����J�[�h�̃f�[�^�̈����̈ʒu�Ƀf�[�^���i�[����
����:CardData* card �J�[�h
	:int sector�@�Z�N�^�[
	:int block�@�u���b�N
	:int fromByte�@���o�C�g�ڂ��炩
	:Byte* data�@�i�[�������f�[�^
	:int len ���o�C�g����
�ԋp�l:�Ȃ�
�쐬��:10��20��(��)
�쐬��:���c�C�V
*/
void DataManager::setDataForCardData(CardData * card, int sector, int block, int fromByte, BYTE * data, int dataLen)
{
	//�����̃o�C�g����
	for (int i = 0; i < dataLen; i++) {
		//�����Ԗڂ̃Z�N�^�[���ŁA�����̃u���b�N�̒��̈����̒l�̈ʒu����n�܂�ʒu�Ƀf�[�^���i�[���Ă���
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
	//���[�U�[id���w��̊i�[���ꂽ�ӏ�����擾
	char temp[17] = { 0x00 };
	//�c�����w��̈ʒu����擾����
	strncpy(temp, (char*)carddata->sector[DataMConstants.userIdSectorNum]->RWBlock[DataMConstants.userIdBlockNum], 16);
	userId = temp;
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
	char temp[17] = {0x00};
	//�c�����w��̈ʒu����擾����
	strncpy(temp, (char*)carddata->sector[DataMConstants.lastNameSectorNum]->RWBlock[DataMConstants.lastNameBlockNum], 16);
	userLastName = temp;

	//���O���������w��̈ʒu����擾����
	strncpy(temp, (char*)carddata->sector[DataMConstants.firstNameSectorNum]->RWBlock[DataMConstants.firstNameBlockNum], 16);
	userFirstName = temp;
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
	char temp[17] = { 0x00 };
	//�p�X���[�h���w��̈ʒu����擾����
	strncpy(temp, (char*)carddata->sector[DataMConstants.passSectorNum]->RWBlock[DataMConstants.passBlockNum], 16);
	password = temp;
}

/*
�֐���:applyTelNoData
�T�v:�J�[�h����ǂݎ�����d�b�ԍ���K�p������
����:CardData �J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��19��(��)
�쐬��:���c�C�V
*/
void DataManager::applyTelNoData(CardData * carddata)
{
	//�d�b�ԍ����w��̈ʒu����擾���Ċi�[����
	telNo = (char*)carddata->sector[DataMConstants.tellSectorNum]->RWBlock[DataMConstants.tellSectorNum];
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
	//�a�������擾����o�b�t�@��p�ӂ���
	char temp[sizeof(int)];
	//int�̃T�C�Y�������J��Ԃ�
	for (int i = 0; i < sizeof(int); i++) {
		//�i�[���ꂽ�ʒu����擾���Ă���
		temp[i] = carddata->sector[DataMConstants.birthdaySectorNum]->RWBlock[DataMConstants.birthdayBlockNum][i];
	}
	//�a�����Ɏ擾�����o�C�g�z����i�[����
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
	//�p�����[�^���i�[����o�C�g�z����p�����[�^����4�o�C�g���p�ӂ���
	char temp[4];
	//�p�����[�^�̐������J��Ԃ�
	for (int i = 0; i < 4; i++) {
		//�w��̈ʒu���珇�Ɏ擾���Ă���
		temp[i] = carddata->sector[DataMConstants.parameterSectorNum]->RWBlock[DataMConstants.parameterBlockNum][i + DataMConstants.parameterStartByteNum];
	}

	//�ʒu�o�C�g�ڂ̐l�����擾����
	chara = temp[0];
	//2�o�C�g�ڂ̌������擾����
	auth = temp[1];
	//3�o�C�g�ڂ̖�E���擾����
	cast = temp[2];
	//4�o�C�g�ڂ̏������擾����
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
	//2�Z�N�^�[���̃o�C�g�z���p�ӂ���
	char addr[SECTOR_BLOCK_NUM * BLOCK_BYTE * 2 + 1] = { 0x00 };

	//�Z�N�^�[���������J��Ԃ�
	for (int i = 0; i < 2; i++) {
		//�Z�N�^�[���̃u���b�N�������J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�擪���I�[�������Ă��Ȃ����
			if ('\0' != carddata->sector[i]->RWBlock[j]) {
				//
				for (int k = 0; k < BLOCK_BYTE; k++) {
					//
					addr[i * 48 + j * 16 + k] = (char)carddata->sector[i + 2]->RWBlock[j][k];
				}
			}
			//
			else {
				break;
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

	memcpy(&currentInout, temp, sizeof(short));
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
	//short�^��2�o�C�g�����i�[����ϐ���p��
	char temp[sizeof(short)];

	//���قɗ^����ꂽ2�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 2; i++) {
		//�Z�N�^�[����3�u���b�N���J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N���̃o�C�g�����J��Ԃ�
			for (int k = 0; k < BLOCK_BYTE; k += 2) {
				//��ԍŏ��łȂ����(�ŏ��̓J�����g�̔N�����i�[����Ă���)
				if (i != 0 || j != 0 || k != 0) {
					//1�o�C�g�ڂ��擾����
					temp[0] = carddata->sector[i + 4]->RWBlock[j][k];
					//2�o�C�g�ڂ��擾����
					temp[1] = carddata->sector[i + 4]->RWBlock[j][k + 1];
					//�ǂ���ł��i�[����Ă���l�����݂���
					if (temp[0] != '\0' && temp[1] != '\0') {
						//short�^�ɂ���ϐ���p��
						short dayintime;
						//�i�[����2�o�C�g��short�^�ϐ��ɃR�s�[
						memcpy(&dayintime, temp, sizeof(short));
						//short�^�̒l���i�[����
						inTime[i * 24 + j * 8 + k].apply(dayintime);
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
	//short�^��2�o�C�g�����i�[����ϐ���p��
	char temp[sizeof(short)];

	//�ފقɗ^����ꂽ2�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 2; i++) {
		//�Z�N�^�[����3�u���b�N���J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N���̃o�C�g�����J��Ԃ�
			for (int k = 0; k < BLOCK_BYTE; k += 2) {
				//��ԍŏ��łȂ����(�ŏ��̓J�����g�̔N�����i�[����Ă���)
				if (i != 0 || j != 0 || k != 0) {
					//1�o�C�g�ڂ��擾����
					temp[0] = carddata->sector[i + DataMConstants.outTimeSectorNum]->RWBlock[j][k];
					//2�o�C�g�ڂ��擾����
					temp[1] = carddata->sector[i + DataMConstants.outTimeSectorNum]->RWBlock[j][k + 1];
					//�ǂ���ł��i�[����Ă���l�����݂���
					if (temp[0] != '\0' && temp[1] != '\0') {
						//short�^�ɂ���ϐ���p��
						short dayintime;
						//�i�[����2�o�C�g��short�^�ϐ��ɃR�s�[
						memcpy(&dayintime, temp, sizeof(short));
						//short�^�̒l���i�[����
						outTime[i * 24 + j * 8 + k].apply(dayintime);
					}
				}
			}
		}
	}
}

/*
�֐���:setChara
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
	return currentInout / 12;
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
	int month = currentInout % 12;
	if (month == 0) {
		month = 12;
	}

	//
	return month;
}


void DataManager::clear()
{
	card.clear();
}

