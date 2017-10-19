#include "DataManager.h"
#include <sstream>

using namespace std;

namespace {
	Constants DataMConstants;
};

DataManager::DataManager()
{
	this->userId = 0;
	this->birthday = 0;
	this->inoutYM = 0;
	this->userName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->attr = 0;
	this->password = "";
}


DataManager::~DataManager()
{
}

void DataManager::init()
{
	//�J�[�h���[�_�̏��������s��
	card.init();
}

void DataManager::checkId()
{
	//�����o�ɃZ�b�g���ꂽID��PC��ɂȂ�
	if (!file.checkId(userId)) {
		//���b�Z�[�W��Y���ė�O�𑗏o����
		throw exception(DataMConstants.MESSAGE_NO_ID.c_str());
	}
}

/*

*/
void DataManager::checkCharacter()
{
	//�l���̒l���擾����
	int chara = getCharacter();
	//���ً��ێ҂̎�
	if (chara == 1) {
		//��O�ł��̂��Ƃ�`����
		throw exception(DataMConstants.MESSAGE_CHARACTER_REJECT.c_str());
	}
}

void DataManager::readCardData()
{
	//�J�[�h��ǂݍ���Ō��ʂ��擾����
	CardData* result;
	result = card.readCard();
	//�擾�����f�[�^���烁���o�ɃZ�b�g
	applyData(result);
}

void DataManager::writeData()
{
	//�J�[�h�p�Ƀf�[�^��ϊ����ăJ�[�h�ɏ�������
	card.writeCard(makeDataForCard());
	//�t�@�C���p�Ƀf�[�^��ϊ����ăJ�[�h�ɏ�������
	file.writeData(userId, makeDataForFile());
}

void DataManager::readFileData()
{
	//�t�@�C���̃f�[�^���i�[���邽�߂̕ϐ���p��
	vector<string> filedata;
	//�t�@�C���̃f�[�^��ǂݍ���ŗp�ӂ����ϐ��Ɋi�[����
	filedata = file.readFileData(userId);

	//�ǂ݂��񂾃f�[�^�������o�ɓK�p������
	applyFileData(filedata);
}

//ID�݂̂��擾����
void DataManager::readCardId()
{
	//�J�[�h����id�݂̂��擾���Ċi�[����
	userId = card.readCardID();
}


std::string DataManager::makeDataForFile()
{
	//�t�@�C���ɏ������ނ��߂̃X�g���[�����m��
	std::stringstream ss;

	//�e�����i�[���Ă���
	ss << userId << endl;		// 1
	ss << birthday << endl;		// 2
	ss << userName << endl;		// 3
	ss << telNo << endl;		// 4
	ss << address << endl;		// 5
	ss << group << endl;		// 6
	ss << cast << endl;			// 7
	ss << attr << endl;			// 8
	ss << inoutYM << endl;		// 9
	ss << password << endl;		// 10

	//���ފَ����ɂ��Ă��������z�񕔕��J��Ԃ���
	for (int i = 0; i < inoutTime.size(); i++) {
		//���̎��̔z��̒l���i�[����
		ss << inoutTime[i] << endl;
	}

	//�X�g���[���𕶎���ɕς��ĕԋp����
	return ss.str();
}


CardData* DataManager::makeDataForCard()
{
	//����g�p����8�Z�N�^�[���̃f�[�^���i�[����J�[�h�f�[�^��p��
	CardData* carddata = new CardData(9);

	//�Z�N�^�[1�u���b�N1�Ɋ�b��������Ċi�[����
	makeEleDataForCard(carddata->sector[0]->RWBlock[0]);
	//�Z�N�^�[1�u���b�N2�ɓd�b�ԍ��̃f�[�^���쐬���Ċi�[����
	makeTelDataForCard(carddata->sector[0]->RWBlock[1]);
	//�Z�N�^�[1�u���b�N3�ɒǉ������쐬���Ċi�[����
	makeAddDataForCard(carddata->sector[0]->RWBlock[2]);

	//�Z�N�^�[2�Ƀ��[�U�[���ō�����f�[�^���i�[����
	carddata->sector[1] = makeUsernameForCard();

	//�Z���̃f�[�^���쐬���Ď擾
	CardData* address = makeAddressForCard();
	//�Z���Ɋ��蓖�Ă�ꂽ3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//���蓖�Ă�ꂽ�Z�N�^�[3����5�܂łɏ��Ɋi�[���Ă���
		carddata->sector[2 + i] = address->sector[i];
	}

	//���ފَ��Ԃ̃f�[�^���쐬���Ċi�[����
	CardData* inout = makeInoutDataForCard();
	//���ފَ��ԂɊ��蓖�Ă�ꂽ3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//���蓖�Ă�ꂽ6����8�Z�N�^�[�ɏ��Ɋi�[���Ă���
		carddata->sector[5 + i] = inout->sector[i];
	}
	//�p�X���[�h�ɂ��Ă���������
	makePasswordForCard(carddata->sector[8]->RWBlock[0]);

	delete address;
	delete inout;

	//�쐬�����������݂����J�[�h�f�[�^��ԋp����
	return carddata;
}

BYTE * DataManager::makeEleDataForCard(BYTE* block)
{
	//�e�f�[�^���������ŃR�s�[���邽�߂̃o�C�g�z��p��
	unsigned char temp[sizeof(int)];
	//���[�UID���o�C�g�z��ɕϊ�
	memcpy(temp, &userId, sizeof(int));
	//int�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(int); i++) {
		//�󂯎�����z��̑O4�Ɋi�[
		block[i] = temp[i];
	}
	//���N�������o�C�g�z��ɕϊ�
	memcpy(temp, &birthday, sizeof(int));
	//int�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(int); i++) {
		//�����̔z��̂��̌���4�Ɋi�[
		block[4 + i] = temp[i];
	}
	//���ފق̔N�����o�C�g�z��ɕϊ�
	memcpy(temp, &inoutYM, sizeof(int));
	//int�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(int); i++) {
		//�����̔z��̍Ō��4�Ɋi�[
		block[8 + i] = temp[i];
	}

	return block;
}

BYTE * DataManager::makeTelDataForCard(BYTE* block)
{
	//�d�b�ԍ��̕������char*�̃o�C�g�z��ɒ���
	const char* chTel = telNo.c_str();
	//������̒������擾����
	int tellen = strlen(chTel);

	//�u���b�N���̃o�C�g�����J��Ԃ�
	for (int i = 0; i < BLOCK_BYTE; i++) {
		//�J�����g���d�b�ԍ��̒�����菬�����Ƃ�
		if (tellen > i) {
			//�d�b�ԍ��̒l��ԋp����o�C�g�z��Ɋi�[����
			block[i] = chTel[i];
		}
		//������傫���Ƃ�
		else {
			//�I�[�������i�[����
			block[i] = '\0';
		}
	}

	//�쐬�����u���b�N�̃o�C�g�z���ԋp����
	return block;
}

BYTE * DataManager::makeAddDataForCard(BYTE* block)
{
	//�e�f�[�^���������ŃR�s�[���邽�߂̃o�C�g�z��p��
	unsigned char temp[sizeof(short)];

	//�������o�C�g�z��ɕϊ�
	memcpy(temp, &group, sizeof(short));
	//short�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(short); i++) {
		//�󂯎�����z��̑O4�Ɋi�[
		block[0 + i] = temp[i];
	}
	//��E���o�C�g�z��ɕϊ�
	memcpy(temp, &cast, sizeof(short));
	//short�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(short); i++) {
		//�󂯎�����z��̂��̌���4�Ɋi�[
		block[2 + i] = temp[i];
	}
	//�������o�C�g�z��ɕϊ�
	memcpy(temp, &attr, sizeof(short));
	//short�̑傫�����J��Ԃ�
	for (int i = 0; i < sizeof(short); i++) {
		//�󂯎�����z��̍Ō��4�Ɋi�[
		block[4 + i] = temp[i];
	}
	return block;
}

SectorData* DataManager::makeUsernameForCard()
{
	//���O�ɓ��Ă�ꂽ��̃Z�N�^�[���m��
	SectorData* userNameData = new SectorData();
	//���[�U�[���̒������擾
	int len = strlen(userName.c_str());
	//���[�U�[�����o�C�g�z��ɂ��Ă���
	const unsigned char* username = (unsigned char*)userName.c_str();
	//�u���b�N���J��Ԃ�
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//�o�C�g���������J��Ԃ�
		for (int j = 0; j < BLOCK_BYTE; j++) {
			//�I�[�łȂ����
			if ((i * 16 + j) < len) {
				//���̕������i�[���Ă���
				userNameData->RWBlock[i][j] = username[i * 16 + j];
			}
			//�����Ȃ�
			else {
				//�I�[�������i�[����
				userNameData->RWBlock[i][j] = '\0';
			}
		}
	}
	//�쐬�����z���ԋp����
	return userNameData;
}

CardData* DataManager::makeAddressForCard()
{
	//�Z���Ɋ��蓖�Ă�ꂽ3�Z�N�^�[���̃f�[�^���i�[����ϐ���p��
	CardData* addressData = new CardData(3);
	//�Z���̕�������o�C�g��̔z��ɒ���
	const char* chAddress = address.c_str();
	//�Z���̕�����̒������擾����
	int addrlen = strlen(chAddress);
	//�Z���Ɋ��蓖�Ă�ꂽ3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[���̃u���b�N�̐��J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N���̃o�C�g�����J��Ԃ�
			for (int k = 0; k < BLOCK_BYTE; k++) {
				//�Z���̕�����̒����̂ق��������Ƃ�
				if (addrlen > i * 48 + j * 16 + k) {
					//���̈ʒu�̃o�C�g���Ƃ̒l���i�[����
					addressData->sector[i]->RWBlock[j][k] = chAddress[i * 48 + j * 16 + k];
				}
				//�������Ƃ�(���łɏI����Ă���Ƃ�)
				else {
					//�I�[�������i�[����
					addressData->sector[i]->RWBlock[j][k] = '\0';
				}
			}
		}
	}
	//�쐬�����z���ԋp����
	return addressData;
}

CardData* DataManager::makeInoutDataForCard()
{
	//���ފَ��Ԃɓ��Ă�ꂽ3�Z�N�^�[���̃f�[�^���i�[����ϐ���p�ӂ���
	CardData* inoutData = new CardData(3);
	//int���������ŃR�s�[���ăo�C�g�z��ɂ��邽�߂̕ϐ���p�ӂ���
	char tempbuf[sizeof(int)];
	//�����o�̓��ފَ��Ԃ̔z��̒������擾
	int veclen = inoutTime.size();

	//���蓖�Ă�ꂽ3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[���̃u���b�N�̐����J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N���̃o�C�g�����J��Ԃ�
			for (int k = 0; k < BLOCK_BYTE / sizeof(int); k++) {
				//���̈ʒu���z��̒�����菬����(�܂��J�[�h�ɏ����Ȃ���΂Ȃ�Ȃ��l���c���Ă���)
				if (veclen > i * 12 + j * 4 + k) {
					//���̈ʒu�̔z��̗v�f��int���������ŃR�s�[���ăo�C�g�z��ɂ���
					memcpy(tempbuf, &inoutTime[i * 12 + j * 4 + k], sizeof(int));
					//int�̒����������J��Ԃ�
					for (int m = 0; m < sizeof(int); m++) {
						//�ł����o�C�g�z��̗v�f�����i�[���Ă���
						inoutData->sector[i]->RWBlock[j][4 * k + m] = tempbuf[m];
					}
				}
				//�����J�[�h�ɏ������ނׂ��l���Ȃ�
				else {
					//int�̒����������J��Ԃ�
					for (int m = 0; m < sizeof(int); m++) {
						//���̈ʒu�̏������ރf�[�^�ɖ����Ȓl���i�[���Ă���
						inoutData->sector[i]->RWBlock[j][4 * k + m] = 0xff;
					}
				}
			}
		}
	}
	//3�Z�N�^�[���̃f�[�^��ԋp����
	return inoutData;
}

BYTE * DataManager::makePasswordForCard(BYTE * block)
{
	const char* pass = password.c_str();
	
	int len = strlen(pass);
	for (int i = 0; i <	len; i++) {
		block[i] = pass[i];
	}
	
	return block;
}




/*
�֐���:applyData
�T�v:�ǂݎ�����f�[�^�������o�ɓK�p������
����:CardData carddata �ǂݎ�����J�[�h�̃f�[�^
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyData(CardData* carddata)
{
	//�Z�N�^�[1�u���b�N1�̊�b�f�[�^��K�p
	applyElementData(carddata->sector[0]->RWBlock[0]);
	//�Z�N�^�[1�u���b�N2�̓d�b�ԍ��f�[�^�������o�ɓK�p
	applyTelNoData(carddata->sector[0]->RWBlock[1]);
	//�Z�N�^�[1�u���b�N�R�̒ǉ��f�[�^�������o�ɓK�p
	applyAddData(carddata->sector[0]->RWBlock[2]);

	//�Z�N�^�[2�̖��O��K�p
	applyUserName(carddata->sector[1]);
	//�Z�����擾���邽�߂̃J�[�h�f�[�^�p��
	CardData* address = new CardData(3);
	//3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[3����5�̏Z���f�[�^���i�[����
		address->sector[i] = carddata->sector[2 + i];
	}
	//�擾�����Z���f�[�^�œK�p������
	applyAddressData(address);

	//���ފَ����̃f�[�^���擾���邽�߂̃J�[�h�f�[�^��p��
	CardData* inout = new CardData(3);
	//3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[6����8�̓��ފَ����f�[�^���i�[����
		inout->sector[i] = carddata->sector[5 + i];
	}
	//�擾�������ފَ����f�[�^�������o�ɓK�p������
	applyInout(inout);

	//�p�X���[�h�������o�ɓK�p������
	applyPassword(carddata->sector[8]->RWBlock[0]);

}


/*
�֐���:applyElementData
�T�v:��b���������o�ɓK�p������
����:BYTE* element�@��b���̓������u���b�N�̏��
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyElementData(BYTE * element)
{
	int intlen = sizeof(int);

	//4�o�C�g����char�̃o�C�g�z���p�ӂ���
	char tempbuf[sizeof(int)];
	//4�o�C�g(int)���J��Ԃ�
	for (int i = 0; i < intlen; i++) {
		//�ŏ���4���i�[����
		tempbuf[i] = element[0 + i];
	}
	//���[�UID�Ƀ������[�R�s�[���ăZ�b�g
	memcpy(&userId, tempbuf, intlen);

	//4�o�C�g(int)���J��Ԃ�
	for (int i = 0; i < intlen; i++) {
		//���̎���4���i�[����
		tempbuf[i] = element[4 + i];
	}
	//�a�����Ƀ������[�R�s�[���ăZ�b�g
	memcpy(&birthday, tempbuf, intlen);

	//4�o�C�g(int)���J��Ԃ�
	for (int i = 0; i < intlen; i++) {
		//���̎���4���i�[����
		tempbuf[i] = element[8 + i];
	}
	//���ނ̔N���ɃR�s�[���ăZ�b�g
	memcpy(&inoutYM, tempbuf, intlen);
}

/*
�֐���:applyTelNoData
�T�v:�d�b�ԍ��������o�ɓK�p������
����:BYTE* tel�@�ǂݎ�����d�b�ԍ��̃f�[�^
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyTelNoData(BYTE * tel)
{
	//�������擾����
	int len = strlen((char*)tel);
	//������16�ȉ��Ȃ�
	if (len <= 16) {
		//���[�U�[���Ɋi�[����
		telNo = (char*)tel;
	}
	//16���傫���Ȃ�
	else {
		//��O�𑗏o����
		throw std::exception("�f�[�^�������ł�");
	}
}

/*
�֐���:applyAddData
�T�v:�ǉ����������o�ɓK�p������
����:BYTE*�@block �ǉ����̃u���b�N
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyAddData(BYTE * addData)
{
	int shortlen = sizeof(short);

	//2�o�C�g�̔z���p�ӂ���
	char tempbuf[sizeof(short)];

	//2�o�C�g���J��Ԃ�
	for (int i = 0; i < shortlen; i++) {
		//���߂�2���i�[����
		tempbuf[i] = addData[0 + i];
	}
	//�����Ƀ������[�R�s�[���ăZ�b�g
	memcpy(&group, tempbuf, shortlen);

	//2�o�C�g���J��Ԃ�
	for (int i = 0; i < shortlen; i++) {
		//���߂�2���i�[����
		tempbuf[i] = addData[2 + i];
	}
	//��E�Ƀ������[�R�s�[���ăZ�b�g
	memcpy(&cast, tempbuf, shortlen);

	//2�o�C�g���J��Ԃ�
	for (int i = 0; i < 2; i++) {
		//���߂�2���i�[����
		tempbuf[i] = addData[4 + i];
	}
	//�����Ƀ������[�R�s�[���ăZ�b�g
	memcpy(&attr, tempbuf, sizeof(short));
}


/*
�֐���:applyUserName
�T�v:���[�U���������o�ɓK�p������
����:SectorData* nameData ���O�̊i�[���ꂽ�Z�N�^�[�̃f�[�^
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyUserName(SectorData * nameData)
{
	//���O���i�[����ϐ���p�ӂ���
	string name;
	//�Z�N�^�[���̃u���b�N�̐�(3)�����J��Ԃ�
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//�擪�̕����񂪏I�[�����ł͂Ȃ����
		if ('\0' != nameData->RWBlock[i]) {
			//�p�ӂ����ϐ��ɒǉ�����
			name += (char*)nameData->RWBlock[i];
		}
	}
	//���O�������o�ɓK�p����
	userName = name;
}

/*
�֐���:applyAddressData
�T�v:�Z���������o�ɓK�p������
����:CardData addressData �Z���̊i�[���ꂽ3�Z�N�^�[���̃J�[�h�f�[�^
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyAddressData(CardData* addressData)
{
	//�Z���̕�������i�[���邽�߂̕ϐ���p��
	char* addr = new char[144];
	//�Z���Ɋ��蓖�Ă�ꂽ3�Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[���̃u���b�N�̐����J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N�̐擪�̕������I�[���������̂ł͂Ȃ��Ȃ�
			if ('\0' != addressData->sector[i]->RWBlock[j]) {

				for (int k = 0; k < 16; k++) {
					addr[i * 48 + j * 16 + k] = addressData->sector[i]->RWBlock[j][k];
				}
			}
		}
	}
	//�ł����Z���������o�Ɋi�[����
	address = addr;

}

/*
�֐���:applyInout
�T�v:���ފَ��Ԃ̃f�[�^�������o�ɓK�p������
����:CardData inoutData ���ފُ��̊i�[���ꂽ3�Z�N�^�[���̃J�[�h�f�[�^
�ԋp�l:����
�쐬��:10��11��
�쐬��:���c�C�V
*/
void DataManager::applyInout(CardData* inoutData)
{
	//�o�C�g�z��int�ɂ���ϊ����邽�߂̕ϐ���p��
	char tempbuf[sizeof(int)];
	//���ފَ����f�[�^�Ɋ��蓖�Ă�ꂽ3�Z�N�^�[�������J��Ԃ�
	for (int i = 0; i < 3; i++) {
		//�Z�N�^�[���̃u���b�N��(3)�����J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N����16�o�C�g�̒���4�o�C�g(int)���s��
			for (int k = 0; k < sizeof(int); k++) {
				//����4�o�C�g���̐擪�������Ȓl�łȂ��Ȃ�
				if (0xff != inoutData->sector[i]->RWBlock[j][k * 4]) {
					//����int��4�o�C�g�����J��Ԃ�
					for (int m = 0; m < sizeof(int); m++) {
						//���̈ʒu�̃u���b�N��4k�Ԗڂ����4�������̐�r
						tempbuf[m] = inoutData->sector[i]->RWBlock[j][k * 4 + m];
					}
					//�������R�s�[�̂��߂�int�^�ϐ���p��
					int tempint;
					//�쐬����4�o�C�g���Ƃ̔z����������R�s�[����
					memcpy(&tempint, tempbuf, sizeof(int));
					//�����o�̓��ގ��Ԃɒǉ����Ă���
					inoutTime.push_back(tempint);
				}
				//�擪�������Ȓl�̎�
				else {
					//���̂��Ƃɂ͂Ȃ��Ƃ��ă��[�v�𔲂���
					break;
				}
			}
		}
	}
}

void DataManager::applyPassword(BYTE * passBlock)
{
	//������̔z���p��
	char* pass = new char[16];
	//�u���b�N���̃o�C�g�����J��Ԃ�
	for (int i = 0; i < BLOCK_BYTE; i++) {
		//�n���ꂽ�z����R�s�[���Ă���
		pass[i] = passBlock[i];
	}

	//�p�X���[�h�Ɋi�[����
	password = pass;
	//�p�ӂ����z����폜
	delete pass;
}

int DataManager::getAuthority()
{
	//�������i�[����ϐ�
	int authority = 0;
	//1�o�C�g�������J��Ԃ�
	for (int i = 0; i < 8; i++) {
		//�����̒l�̉���
		if (attr & (1 << (15 - i))) {
			//
			authority = i;
			//
			break;
		}
	}
	//
	return authority;
}

int DataManager::getCharacter()
{
	int chara = 0;
	for (int i = 0; i < 8; i++) {
		if (attr & (1 << (7 - i))) {
			chara = i;
			break;
		}
	}

	return chara;
}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:
�쐬��:
*/
int DataManager::getInoutY()
{
	//
	return inoutYM / 100;
}

/*

*/
int DataManager::getInoutM()
{
	//
	return inoutYM - getInoutY() * 100;
}

void DataManager::applyFileData(vector<string> fileData)
{
	//1�s�ڂ����[�U�[ID��
	userId = stoi(fileData[0]);
	//2�s�ڂ�a������
	birthday = stoi(fileData[1]);
	//3�s�ڂ𖼑O��
	userName = fileData[2];
	//4�s�ڂ�d�b��
	telNo = fileData[3];
	//5�s�ڂ��Z����
	address = fileData[4];
	//6�s�ڂ�������
	group = stoi(fileData[5]);
	//7�s�ڂ��E��
	cast = stoi(fileData[6]);
	//8�s�ڂ𑮐���
	attr = stoi(fileData[7]);
	//9�s�ڂ���ނ̔N����
	inoutYM = stoi(fileData[8]);
	//10�s�ڂ��p�X���[�h��
	password = fileData[9];

	//10�s�ڂ��������ׂ�
	for (int i = 10; i < fileData.size(); i++) {
		//�����o�Ɍ�납��ǉ����Ă���
		inoutTime.push_back(stoi(fileData[i]));
	}
}

void DataManager::clear()
{
	card.clear();
}

