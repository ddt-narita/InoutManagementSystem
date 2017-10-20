#pragma once

#include <windows.h>
#include <winscard.h>
#include <stdio.h>
#include <tchar.h>
#include <assert.h>
#include <string>
#include <vector>
#include "CardData.h"
#include "Constants.h"


#define PCSC_TRANS_BUFF_LEN	(262)
#define PCSC_RECV_BUFF_LEN	(262)

typedef struct {
	INT		iLength;
	BYTE	bCommand[PCSC_TRANS_BUFF_LEN];
} SENDCOMM;

class CardRW
{
private:
	//���\�[�X�}�l�[�W���[�̃n���h��
	SCARDCONTEXT hContext;
	//�J�[�h���[�_�[��
	LPTSTR readerName;
	//�J�[�h��
	SCARDHANDLE cardName;
	//
	DWORD activeProtocol;

public:
	CardRW();
	~CardRW();

	//�������֐�
	void init();
	//�J�[�h�ւ̏�������
	void writeCard(CardData* data);
	//�J�[�h�̓ǂݍ���
	CardData* readCard();
	//�J�[�h����id�݂̂��擾����
	int readCardID();

	//�ω�������܂ő҂�
	void getStatusChange(int tout);
	//�J�[�h�֐ڑ�����
	void connectCard();
	//�R�}���h�𑗐M���A���̌��ʂ������̃o�b�t�@�Ɋi�[����
	BYTE* sendCommand(SENDCOMM cmd);

	SENDCOMM createReadCommand(int block, SENDCOMM* sendComm);

	SENDCOMM createWriteCommand(int block, BYTE* data, SENDCOMM* sendComm);

	SENDCOMM createAuthenticCommand(int sector, SENDCOMM* sendComm);

	void clear();
};

