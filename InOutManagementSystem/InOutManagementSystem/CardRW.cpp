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
関数名:init
概要:初期化関数
引数:なし
返却値:なし
作成日:10月10日(火)
作成者:成田修之
*/
void CardRW::init()
{
	//カードリーダ等との接続の結果を格納するための変数
	LONG lResult;
	//リソースマネージャーに接続しそのハンドルをメンバにセットする
	lResult = SCardEstablishContext(SCARD_SCOPE_USER, NULL, NULL, &hContext);
	//成功出ないなら
	if (lResult != SCARD_S_SUCCESS) {
		//リソースマネージャーがないとき
		if (lResult == SCARD_E_NO_SERVICE) {
			throw exception(cardRWConstant.MESSAGE_RESOURSE_NO_SERVICE.c_str());
		}
		//それ以外の場合
		else {
			stringstream message;
			message << ("ErrorCode %08X\n", lResult);

			throw exception((cardRWConstant.MESSAGE_RESOUSE_ERROR + '\n' + message.str()).c_str());
		}
	}
	//
	DWORD	dwAutoAllocate = SCARD_AUTOALLOCATE;

	//カードリーダへ接続を行い、リーダーの名前をメンバに格納する
	lResult = ::SCardListReaders(hContext, NULL, (LPTSTR)&readerName, &dwAutoAllocate);
	//成功でないなら
	if (lResult != SCARD_S_SUCCESS) {
		//使用可能なリーダが見つからなかったとき
		if (lResult == SCARD_E_NO_READERS_AVAILABLE) {
			//
			throw exception(cardRWConstant.MESSAGE_NO_READER.c_str());
		}
		//それ以外の原因
		else {
			//
			throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
		}
	}

}

/*
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
void CardRW::getStatusChange(int tout)
{
	//カードリーダの状態を取得するための変数を用意
	SCARD_READERSTATE readerState;
	//用意した変数にリーダーの名前を書くのする
	readerState.szReader = readerName;
	//状態がわからないことを示す値を格納する
	readerState.dwCurrentState = SCARD_STATE_UNAWARE;

	//現在の状態を取得する
	LONG lResult = SCardGetStatusChange(hContext, 0, &readerState, 1);

	//状態の取得に失敗(リーダーとの接続に失敗)
	if (lResult != SCARD_S_SUCCESS) {
		//例外を送出する
		throw exception(cardRWConstant.MESSAGE_NO_READER.c_str());
	}
	//セットされていないとき
	if (readerState.dwEventState & SCARD_STATE_EMPTY) {
		//現在の状態を格納する
		readerState.dwCurrentState = readerState.dwEventState;
		//引数のタイムアウト時間でカードがかざされるのを待つ
		lResult = SCardGetStatusChange(hContext, tout, &readerState, 1);
		//カードがかざされた時
		if (readerState.dwEventState & SCARD_STATE_PRESENT) {
			//何もしない、次の処理へ移行
		}
		//カードが見つからないとき
		else if (readerState.dwEventState & SCARD_STATE_UNAVAILABLE) {
			//例外を送出
			throw exception(cardRWConstant.MESSAGE_NO_CARD.c_str());
		}
		//それ以外で成功しなかったとき
		else {
			//例外を送出する
			throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
		}
	}
	//すでにセットされているとき
	else if (readerState.dwEventState & SCARD_STATE_PRESENT) {
		//何もしない、次に処理へ移行

		int n;
	}
	//その他でエラーがある時
	else {
		//例外を送出する
		throw exception(cardRWConstant.MESSAGE_READER_ACCESS_ERROR.c_str());
	}
}


/*
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
void CardRW::connectCard()
{
	//カードに接続して使用可能なカード名とプロトコルを取得
	LONG lResult = SCardConnect(hContext, readerName, SCARD_SHARE_SHARED, SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1, &cardName, &activeProtocol);
	//通信が成功ではない
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
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
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
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
BYTE * CardRW::sendCommand(SENDCOMM cmd)
{
	//レスポンスの長さを格納する変数
	//@0ではなくきちんとバッファのサイズ渡さなければきちんとレスポンスが取得できない
	DWORD recvBufSize = PCSC_RECV_BUFF_LEN;
	//今回は18バイト以上はありえない
	BYTE retbuf[PCSC_RECV_BUFF_LEN] = {0x00};
	//受け取ったコマンドでコマンド送信
	LONG lResult = SCardTransmit(cardName, CardProtocol2PCI(activeProtocol),
		cmd.bCommand, cmd.iLength, NULL, retbuf, &recvBufSize);

	//結果が成功でなければ
	if (lResult != SCARD_S_SUCCESS) {
		//メッセージを添えて例外を送出する
		throw std::exception("コマンドの送信に失敗しました。");
	}

	unsigned char* retRecvdata = new unsigned char[recvBufSize];
	for (int i = 0; i < recvBufSize; i++) {
		retRecvdata[i] = retbuf[i];
	}

	//
	return retRecvdata;
}


/*
関数名:writeCard
概要:カードに書き込む関数
引数:vector<BYTE*>作成したデータ群
返却値:なし
作成日:10月10日(火)
作成者:成田修之
*/
void CardRW::writeCard(CardData* data)
{
	//カードがかざされるまで待つ
	getStatusChange(2000);
	//カードがあることを確認したらカードに接続する
	connectCard();

	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	sendCommand(se);

	SENDCOMM send = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	//今回使うセクター分繰り返す
	for (int i = 0; i < 9; i++) {
		createAuthenticCommand(i, &send);
		//そのセクターへの読み書き許可のコマンドを作成して送信する
		sendCommand(send);
		//セクター内のブロック数(3)だけ繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロックに書き込むコマンドを格納させる（ブロックはセクター*4+その時のセクター内のブロック番目
			createWriteCommand(i * 4 + j, data->sector[i]->RWBlock[j], &send);
			//その位置のデータをブロックを計算して書き込みのコマンドを作成して送信する
			sendCommand(send);
		}
	}
}

/*
関数名:readCard
概要:カードから情報を読み込む関数
引数:なし
返却値:vector<BYTE*>　読み取ったデータ
作成日:10月10日(火)
作成者:成田修之
*/
CardData* CardRW::readCard()
{
	//9セクター分のカードのデータを作成する
	CardData* readResult = new CardData(9);

	//カードがかざされるまで待つ
	getStatusChange(10000);
	//カードに接続する
	connectCard();

	SENDCOMM send;

	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	sendCommand(se);

	//使用中のセクター分だけ繰り返す
	for (int i = 0; i < 9; i++) {
		//
		createAuthenticCommand(i, &send);
		//そのセクターに接続するためのコマンドを作成して送出
		unsigned char* authresult  = sendCommand(send);
		delete authresult;

		//セクター内のブロック数分だけ繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//セクター内のブロックに読み込みのコマンドを投げレスポンスを取得
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

			//受け取ったレスポンスの16バイト分(1ブロックの値)だけ用意したカードのデータにコピー
			for (int k = 0; k < 16; k++) {
				readResult->sector[i]->RWBlock[j][k] = result[k];
			}

			delete result;
		}
	}
	//格納した結果を返却する
	return readResult;
}

int CardRW::readCardID()
{
	//カードがかざされるまで待つ
	getStatusChange(10000);
	//カードに接続する
	connectCard();
	//カード指定のコマンドを作製
	SENDCOMM se = { 11,{ 0xFF, 0x82, 0x00, 0x00, 0x06,
		0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } };
	//コマンドを送信
	sendCommand(se);
	//コマンドを取得するための構造体を用意
	SENDCOMM send;
	//IDの入ったセクターへの読み書き許可のコマンドを作製
	createAuthenticCommand(0, &send);
	//コマンドを送信
	sendCommand(send);
	//IDの入ったブロックへの読み込みコマンドを作製する
	createReadCommand(0, &send);
	//コマンドを投げレスポンスを取得する
	unsigned char* response = sendCommand(send);
	//ユーザーのIDを取得するための変数を用意
	int userid;
	//レスポンスの前4バイトのIDを格納してあるデータをメモリコピーでID取得する
	memcpy(&userid, response, sizeof(int));
	//IDを返却する
	return userid;
}


/*
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
//そのブロックを読み込むためのコマンド作成
SENDCOMM CardRW::createReadCommand(int block, SENDCOMM* sendComm)
{
//第1・2セクターを飛ばして処理するために8ブロック分足してコマンドを送る
block += cardRWConstant.adjustBlock;

	//引数のブロックを格納してコマンド作成
	SENDCOMM readComm = { 5, { 0xFF, 0xB0, 0x00, block, 0x00 } };

	sendComm->iLength = 5;
	for (int i = 0; i < 5; i++) {
		sendComm->bCommand[i] = readComm.bCommand[i];
	}

	//作成したコマンドを返却する
	return readComm;
}

/*
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
SENDCOMM CardRW::createWriteCommand(int block, BYTE * writeData, SENDCOMM* sendComm)
{

	//ブロックの剰余が3(アクセス制御のブロックに書き込もうとしている)
	if (3 == block % 4) {
		//例外を送出する
		throw std::exception("書き込み不可のブロックに書き込もうとしました。");
	}


//第1・2セクターを飛ばして処理するために8ブロック分足してコマンドを送る
block += cardRWConstant.adjustBlock;

	//引数のブロックにwriteDataを書くためのコマンドを格納していく
	SENDCOMM writeComm = { 21,{ 0xFF, 0xD6, 0x00, block, 0x10,
		writeData[0], writeData[1], writeData[2],  writeData[3],  writeData[4],  writeData[5],  writeData[6],  writeData[7],
		writeData[8], writeData[9], writeData[10], writeData[11], writeData[12], writeData[13], writeData[14], writeData[15] } };


	sendComm->iLength = 21;
	for (int i = 0; i < 21; i++) {
		sendComm->bCommand[i] = writeComm.bCommand[i];
	}

	//作成したコマンドを返却する
	return writeComm;
}


/*
関数名:
概要:
引数:
返却値:
作成日:10月10日(火)
作成者:成田修之
*/
SENDCOMM CardRW::createAuthenticCommand(int sector, SENDCOMM* sendComm)
{
	//引数のセクターの価から許可に必要なブロックの値を割り出す
	int authenBlock = sector * 4 + 3;

//第1・2セクターを飛ばして処理するために8ブロック分足してコマンドを送る
authenBlock += cardRWConstant.adjustBlock;

	//そのブロックを格納してコマンド作成
	SENDCOMM authenComm = { 10,{ 0xFF, 0x86, 0x00, 0x00, 0x05,
		0x01, 0x00, authenBlock, 0x60, 0x00 } };

	sendComm->iLength = 10;
	for (int i = 0; i < 10; i++) {
		sendComm->bCommand[i] = authenComm.bCommand[i];
	}

	//作ったコマンドを返却する
	return authenComm;
}

void CardRW::clear()
{
	//カード名が初期値ではなければ
	if (0 != cardName) {
		//カードとの接続を切る
		::SCardDisconnect(cardName, SCARD_LEAVE_CARD);
	}
	//リーダー名が初期値ではなければ
	if (0 != readerName) {
		//リーダーとの接続を切る
		::SCardFreeMemory(hContext, readerName);
	}
	//リソースマネージャーとの接続がなされていれば
	if (0 != hContext) {
		//ハンドルを解放する
		::SCardReleaseContext(hContext);
	}
}
