#include "procedureInOut.h"
#include <stdio.h>
#include <time.h>
#include <exception>

using namespace std;

namespace {
	Constants InoutConstant;
}

procedureInOut::procedureInOut()
{
}

procedureInOut::~procedureInOut()
{
}

/*
関数名:init
概要:カードリーダーの初期化など初期化処理を行う関数
引数:無し
返却値:無し
作成日:10月10日(火)
作成者:成田修之
*/
void procedureInOut::init()
{
	//親クラスDataManagerの初期化関数でカードリーダーを初期化
	DataManager::init();
}

/*
関数名:InOut
概要:入退館処理を行う関数
引数:無し
返却値:無し
作成日:10月10日(火)
作成者:成田修之
*/
void procedureInOut::InOut()
{
	//カードからデータを取り出してメンバに保管
	//DataManager::readCardData();
	
readCardId();
	
	
	//読みこんだカードのIDから判定を行う
	DataManager::checkId();

readFileData();

	//人物のチェックを行う
	DataManager::checkCharacter();
	//入退館に関してのチェック
	inoutCheck();

	//現在時刻を入退館の時間としてセットする
	setInOutTime();

	//メンバのデータを書き込む
	writeData();
}

/*
関数名:setInOutTime
概要:現在時刻を入退館の時間としてセットする
引数:無し
返却値:無し
作成日:10月16日(月)
作成者:成田修之
*/
void procedureInOut::setInOutTime()
{
	//intサイズ分のバイト配列を作成する
	char charArraySizeInt[sizeof(int)];
	//入退館時間としてセットするための値を用意する
	int setNo = 0;
	//現在時刻を取得する
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);

	//セットされている月が読み込まれた日付の月と違う
	if (getInoutM() != pnow->tm_mon + 1) {
		//入退館の時間の配列をクリア
		inoutTime.clear();
		//今月の値をセットする
		inoutYM = (pnow->tm_year + 1900) * 100 + (pnow->tm_mon + 1);
	}

	//1バイト目には入退どちらかを示す値を
	charArraySizeInt[0] = this->inout;
	//2バイト目には日付を
	charArraySizeInt[1] = pnow->tm_mday;
	//3バイト目には時間を
	charArraySizeInt[2] = pnow->tm_hour;
	//4バイト目には分を格納する
	charArraySizeInt[3] = pnow->tm_min;

	//作成した4バイト分の値を用意したintの変数にメモリコピーでセットする
	memcpy(&setNo, charArraySizeInt, 4);

	//作成した値をメンバの入退館時間としてセット
	DataManager::inoutTime.push_back(setNo);
}

void procedureInOut::inoutCheck()
{
	//入退館が初めての時
	if (inoutTime.size() < 1) {
		//退館の時
		if (inout == INOUT::Out) {
			//入館されていないことを警告
			throw exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}
	//初めてではないとき
	else {
		//最後のデータ
		int lastData = inoutTime[inoutTime.size() - 1];
		//intを格納するバイト配列を用意する
		char lastDataByte[sizeof(int)];
		//最後のデータをバイト配列にコピー
		memcpy(lastDataByte, &lastData, sizeof(int));

		//1バイト目の入退どちらかを表す値が今から行おうとしている処理(入/退どちらか)が同じになってしまうとき(入退同じこと連続でやろうとしたとき)
		if (lastDataByte[0] == inout) {
			//そのやろうとしている動作にあわせた例外のメッセージを作製
			std::string message = (inout == INOUT::In) ? InoutConstant.MESSAGE_IN_ERROR : InoutConstant.MESSAGE_OUT_ERROR;
			//メッセージを添えて例外を送出する
			throw std::exception(message.c_str());
		}
	}
}
