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
	//リソースマネージャーのハンドル
	SCARDCONTEXT hContext;
	//カードリーダー名
	LPTSTR readerName;
	//カード名
	SCARDHANDLE cardName;
	//
	DWORD activeProtocol;

public:
	CardRW();
	~CardRW();

	//初期化関数
	void init();
	//カードへの書き込み
	void writeCard(CardData* data);
	//カードの読み込み
	CardData* readCard();
	//カードからidのみを取得する
	int readCardID();

	//変化があるまで待つ
	void getStatusChange(int tout);
	//カードへ接続する
	void connectCard();
	//コマンドを送信し、その結果を引数のバッファに格納する
	BYTE* sendCommand(SENDCOMM cmd);

	SENDCOMM createReadCommand(int block, SENDCOMM* sendComm);

	SENDCOMM createWriteCommand(int block, BYTE* data, SENDCOMM* sendComm);

	SENDCOMM createAuthenticCommand(int sector, SENDCOMM* sendComm);

	void clear();
};

