#include "CardRW.h"

using namespace std;

#pragma comment (lib, "winscard.lib")

#define PCSC_TRANS_BUFF_LEN	(262)
#define PCSC_RECV_BUFF_LEN	(262)
Constants cardRWConstant;

CardRW::CardRW()
{
	this->hContext = 0;
	this->readerName = 0;
	this->cardName = 0;
	this->activeProtocol = 0;
}


CardRW::~CardRW()
{
}

/*
�֐���:init
�T�v:�������֐�
����:�Ȃ�
�ԋp�l:�Ȃ�
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void CardRW::init()
{
	//�J�[�h���[�_���Ƃ̐ڑ��̌��ʂ��i�[���邽�߂̕ϐ�
	LONG lResult;
	//���\�[�X�}�l�[�W���[�ɐڑ������̃n���h���������o�ɃZ�b�g����
	lResult = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &hContext);
	//�����o�Ȃ��Ȃ�
	if (lResult != SCARD_S_SUCCESS) {
		//���\�[�X�}�l�[�W���[���Ȃ��Ƃ�
		if (lResult == SCARD_E_NO_SERVICE) {
			throw exception(cardRWConstant.MESSAGE_RESOURSE_NO_SERVICE.c_str());
		}
		//����ȊO�̏ꍇ
		else {
			stringstream message;
			message << ("ErrorCode %08X\n", lResult);

			throw exception((cardRWConstant.MESSAGE_RESOUSE_ERROR + '\n' + message.str()).c_str());
		}
	}
	//
	DWORD	dwAutoAllocate = SCARD_AUTOALLOCATE;

	//�J�[�h���[�_�֐ڑ����s���A���[�_�[�̖��O�������o�Ɋi�[����
	lResult = ::SCardListReaders(hContext, NULL, (LPTSTR)&readerName, &dwAutoAllocate);
	//�����łȂ��Ȃ�
	if (lResult != SCARD_S_SUCCESS) {
		//�g�p�\�ȃ��[�_��������Ȃ������Ƃ�
		if (lResult == SCARD_E_NO_READERS_AVAILABLE) {
			//
			throw exception(cardRWConstant.MESSAGE_NO_READER.c_str());
		}
		//����ȊO�̌���
		else {
			//
			throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
		}
	}

}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void CardRW::getStatusChange(int tout)
{
	//�J�[�h���[�_�̏�Ԃ��擾���邽�߂̕ϐ���p��
	SCARD_READERSTATE readerState;
	//�p�ӂ����ϐ��Ƀ��[�_�[�̖��O�������̂���
	readerState.szReader = readerName;
	//��Ԃ��킩��Ȃ����Ƃ������l���i�[����
	readerState.dwCurrentState = SCARD_STATE_UNAWARE;

	//���݂̏�Ԃ��擾����
	LONG lResult = SCardGetStatusChange(hContext, 0, &readerState, 1);

	//��Ԃ̎擾�Ɏ��s(���[�_�[�Ƃ̐ڑ��Ɏ��s)
	if (lResult != SCARD_S_SUCCESS) {
		//��O�𑗏o����
		throw exception(cardRWConstant.MESSAGE_NO_READER.c_str());
	}
	//�Z�b�g����Ă��Ȃ��Ƃ�
	if (readerState.dwEventState & SCARD_STATE_EMPTY) {
		//���݂̏�Ԃ��i�[����
		readerState.dwCurrentState = readerState.dwEventState;
		//�����̃^�C���A�E�g���ԂŃJ�[�h�����������̂�҂�
		lResult = SCardGetStatusChange(hContext, tout, &readerState, 1);
		//�J�[�h���������ꂽ��
		if (readerState.dwEventState & SCARD_STATE_PRESENT) {
			//�������Ȃ��A���̏����ֈڍs
		}
		//�J�[�h��������Ȃ��Ƃ�
		else if (readerState.dwEventState & SCARD_STATE_UNAVAILABLE) {
			//��O�𑗏o
			throw exception(cardRWConstant.MESSAGE_NO_CARD.c_str());
		}
		//����ȊO�Ő������Ȃ������Ƃ�
		else {
			//��O�𑗏o����
			throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
		}
	}
	//���łɃZ�b�g����Ă���Ƃ�
	else if (readerState.dwEventState & SCARD_STATE_PRESENT) {
		//�������Ȃ��A���ɏ����ֈڍs

		int n;
	}
	//���̑��ŃG���[�����鎞
	else {
		//��O�𑗏o����
		throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
	}
}


/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void CardRW::connectCard()
{
	//�J�[�h�ɐڑ����Ďg�p�\�ȃJ�[�h���ƃv���g�R�����擾
	LONG lResult = SCardConnect(hContext, readerName, SCARD_SHARE_SHARED, SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, &cardName, &activeProtocol);
	//�ʐM�������ł͂Ȃ�
	if (lResult != SCARD_S_SUCCESS) {
		if (lResult == SCARD_W_REMOVED_CARD) {
			throw exception(cardRWConstant.MESSAGE_NO_CARD.c_str());
		}
		else {
			throw exception(cardRWConstant.MESSAGE_CARD_ACCESS_ERROR.c_str());
		}
	}
}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
SCARD_IO_REQUEST *CardProtocol2PCI(DWORD dwProtocol)
{
	if (dwProtocol == SCARD_PROTOCOL_T0) {
		return (SCARD_IO_REQUEST *)SCARD_PCI_T0;
	}
	else if (dwProtocol == SCARD_PROTOCOL_T1) {
		return (SCARD_IO_REQUEST *)SCARD_PCI_T1;
	}
	else if (dwProtocol == SCARD_PROTOCOL_RAW) {
		return (SCARD_IO_REQUEST *)SCARD_PCI_RAW;
	}
	else if (dwProtocol == SCARD_PROTOCOL_UNDEFINED) {
		assert(false);
		return NULL;
	}

	return (SCARD_IO_REQUEST *)SCARD_PCI_T1;
}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
BYTE * CardRW::sendCommand(SENDCOMM cmd)
{
	//���X�|���X�̒������i�[����ϐ�
	//@0�ł͂Ȃ�������ƃo�b�t�@�̃T�C�Y�n���Ȃ���΂�����ƃ��X�|���X���擾�ł��Ȃ�
	DWORD recvBufSize = PCSC_RECV_BUFF_LEN;
	//�����18�o�C�g�ȏ�͂��肦�Ȃ�
	BYTE retbuf[PCSC_RECV_BUFF_LEN] = {0x00};
	//�󂯎�����R�}���h�ŃR�}���h���M
	LONG lResult = SCardTransmit(cardName, CardProtocol2PCI(activeProtocol),
		cmd.bCommand, cmd.iLength, NULL, retbuf, &recvBufSize);

	//���ʂ������łȂ����
	if (lResult != SCARD_S_SUCCESS) {
		//���b�Z�[�W��Y���ė�O�𑗏o����
		throw std::exception("�R�}���h�̑��M�Ɏ��s���܂����B");
	}

	unsigned char* retRecvdata = new unsigned char[recvBufSize];
	for (int i = 0; i < recvBufSize; i++) {
		retRecvdata[i] = retbuf[i];
	}

	//
	return retRecvdata;
}


/*
�֐���:writeCard
�T�v:�J�[�h�ɏ������ފ֐�
����:vector<BYTE*>�쐬�����f�[�^�Q
�ԋp�l:�Ȃ�
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
void CardRW::writeCard(CardData* data)
{
	//�J�[�h�����������܂ő҂�
	getStatusChange(2000);
	//�J�[�h�����邱�Ƃ��m�F������J�[�h�ɐڑ�����
	connectCard();

	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	sendCommand(se);

	SENDCOMM send = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//����g���Z�N�^�[���J��Ԃ�
	for (int i = 0; i < 9; i++) {
		createAuthenticCommand(i, &send);
		//���̃Z�N�^�[�ւ̓ǂݏ������̃R�}���h���쐬���đ��M����
		sendCommand(send);
		//�Z�N�^�[���̃u���b�N��(3)�����J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�u���b�N�ɏ������ރR�}���h���i�[������i�u���b�N�̓Z�N�^�[*4+���̎��̃Z�N�^�[���̃u���b�N�Ԗ�
			createWriteCommand(i * 4 + j, data->sector[i]->RWBlock[j], &send);
			//���̈ʒu�̃f�[�^���u���b�N���v�Z���ď������݂̃R�}���h���쐬���đ��M����
			sendCommand(send);
		}
	}
}

/*
�֐���:readCard
�T�v:�J�[�h�������ǂݍ��ފ֐�
����:�Ȃ�
�ԋp�l:vector<BYTE*>�@�ǂݎ�����f�[�^
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
CardData* CardRW::readCard()
{
	//9�Z�N�^�[���̃J�[�h�̃f�[�^���쐬����
	CardData* readResult = new CardData(9);

	//�J�[�h�����������܂ő҂�
	getStatusChange(10000);
	//�J�[�h�ɐڑ�����
	connectCard();

	SENDCOMM send;

	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	sendCommand(se);

	//�g�p���̃Z�N�^�[�������J��Ԃ�
	for (int i = 0; i < 9; i++) {
		//
		createAuthenticCommand(i, &send);
		//���̃Z�N�^�[�ɐڑ����邽�߂̃R�}���h���쐬���đ��o
		unsigned char* authresult  = sendCommand(send);
		delete authresult;

		//�Z�N�^�[���̃u���b�N���������J��Ԃ�
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//�Z�N�^�[���̃u���b�N�ɓǂݍ��݂̃R�}���h�𓊂����X�|���X���擾
			//
			createReadCommand(i * 4 + j, &send);
			//
			unsigned char* result = sendCommand(send);

			for (UINT uiRespIdx = 0; uiRespIdx < 18; uiRespIdx++) {
				_ftprintf_s(stdout, _T("%02X"), result[uiRespIdx]);
				if ((uiRespIdx + 1) >= 18) {
					_ftprintf_s(stdout, _T("\n"));
				}
				else {
					_ftprintf_s(stdout, _T(" "));
				}
			}

			//�󂯎�������X�|���X��16�o�C�g��(1�u���b�N�̒l)�����p�ӂ����J�[�h�̃f�[�^�ɃR�s�[
			for (int k = 0; k < 16; k++) {
				readResult->sector[i]->RWBlock[j][k] = result[k];
			}

			delete result;
		}
	}
	//�i�[�������ʂ�ԋp����
	return readResult;
}

int CardRW::readCardID()
{
	//�J�[�h�����������܂ő҂�
	getStatusChange(10000);
	//�J�[�h�ɐڑ�����
	connectCard();
	//�J�[�h�w��̃R�}���h���쐻
	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	//�R�}���h�𑗐M
	sendCommand(se);
	//�R�}���h���擾���邽�߂̍\���̂�p��
	SENDCOMM send;
	//ID�̓������Z�N�^�[�ւ̓ǂݏ������̃R�}���h���쐻
	createAuthenticCommand(0, &send);
	//�R�}���h�𑗐M
	sendCommand(send);
	//ID�̓������u���b�N�ւ̓ǂݍ��݃R�}���h���쐻����
	createReadCommand(0, &send);
	//�R�}���h�𓊂����X�|���X���擾����
	unsigned char* response = sendCommand(send);
	//���[�U�[��ID���擾���邽�߂̕ϐ���p��
	int userid;
	//���X�|���X�̑O4�o�C�g��ID���i�[���Ă���f�[�^���������R�s�[��ID�擾����
	memcpy(&userid, response, sizeof(int));
	//ID��ԋp����
	return userid;
}


/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
//���̃u���b�N��ǂݍ��ނ��߂̃R�}���h�쐬
SENDCOMM CardRW::createReadCommand(int block, SENDCOMM* sendComm)
{
//��1�E2�Z�N�^�[���΂��ď������邽�߂�8�u���b�N�������ăR�}���h�𑗂�
block += cardRWConstant.adjustBlock;

	//�����̃u���b�N���i�[���ăR�}���h�쐬
	SENDCOMM readComm = { 5, { 0xFF, 0xB0, 0x00, block, 0x00 } };

	sendComm->iLength = 5;
	for (int i = 0; i < 5; i++) {
		sendComm->bCommand[i] = readComm.bCommand[i];
	}

	//�쐬�����R�}���h��ԋp����
	return readComm;
}

/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
SENDCOMM CardRW::createWriteCommand(int block, BYTE * writeData, SENDCOMM* sendComm)
{

	//�u���b�N�̏�]��3(�A�N�Z�X����̃u���b�N�ɏ����������Ƃ��Ă���)
	if (3 == block % 4) {
		//��O�𑗏o����
		throw std::exception("�������ݕs�̃u���b�N�ɏ����������Ƃ��܂����B");
	}


//��1�E2�Z�N�^�[���΂��ď������邽�߂�8�u���b�N�������ăR�}���h�𑗂�
block += cardRWConstant.adjustBlock;

	//�����̃u���b�N��writeData���������߂̃R�}���h���i�[���Ă���
	SENDCOMM writeComm = { 21,{ 0xFF, 0xD6, 0x00, block, 0x10,
		writeData[0], writeData[1], writeData[2],  writeData[3],  writeData[4],  writeData[5],  writeData[6],  writeData[7],
		writeData[8], writeData[9], writeData[10], writeData[11], writeData[12], writeData[13], writeData[14], writeData[15] } };


	sendComm->iLength = 21;
	for (int i = 0; i < 21; i++) {
		sendComm->bCommand[i] = writeComm.bCommand[i];
	}

	//�쐬�����R�}���h��ԋp����
	return writeComm;
}


/*
�֐���:
�T�v:
����:
�ԋp�l:
�쐬��:10��10��(��)
�쐬��:���c�C�V
*/
SENDCOMM CardRW::createAuthenticCommand(int sector, SENDCOMM* sendComm)
{
	//�����̃Z�N�^�[�̉����狖�ɕK�v�ȃu���b�N�̒l������o��
	int authenBlock = sector * 4 + 3;

//��1�E2�Z�N�^�[���΂��ď������邽�߂�8�u���b�N�������ăR�}���h�𑗂�
authenBlock += cardRWConstant.adjustBlock;

	//���̃u���b�N���i�[���ăR�}���h�쐬
	SENDCOMM authenComm = { 10,{ 0xFF, 0x86, 0x00, 0x00, 0x05,
		0x01, 0x00, authenBlock, 0x60, 0x00 } };

	sendComm->iLength = 10;
	for (int i = 0; i < 10; i++) {
		sendComm->bCommand[i] = authenComm.bCommand[i];
	}

	//������R�}���h��ԋp����
	return authenComm;
}

void CardRW::clear()
{
	//�J�[�h���������l�ł͂Ȃ����
	if (0 != cardName) {
		//�J�[�h�Ƃ̐ڑ���؂�
		::SCardDisconnect(cardName, SCARD_LEAVE_CARD);
	}
	//���[�_�[���������l�ł͂Ȃ����
	if (0 != readerName) {
		//���[�_�[�Ƃ̐ڑ���؂�
		::SCardFreeMemory(hContext, readerName);
	}
	//���\�[�X�}�l�[�W���[�Ƃ̐ڑ����Ȃ���Ă����
	if (0 != hContext) {
		//�n���h�����������
		::SCardReleaseContext(hContext);
	}
}
