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
	DataManager::readCardData();
	//読みこんだカードのIDから判定を行う
	DataManager::checkId();
	//人物のチェックを行う
	DataManager::checkCharacter();
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
		inTime.clear();
		outTime.clear();
		//今月の値をセットする
		inoutYM = (pnow->tm_year + 1900) * 12 + (pnow->tm_mon) + 1;
	}
	//設定する時刻をセット
	setNo = (pnow->tm_mday * 24 * 60) + (pnow->tm_hour * 60) + pnow->tm_min;
	
	//
	if (inout == INOUT::In) {
		//
		DataManager::inTime.push_back(setNo);
	}
	else {
		DataManager::outTime.push_back(setNo);
	}


}

void procedureInOut::inoutCheck()
{
	//退館日数が31日を超えているとき
	if (outTime.size() >= 31) {
		//例外を送出して管理者に報告するように警告
		throw std::exception(InoutConstant.MESSAGE_INOUT_OVER_ERROR.c_str());
	}
	//登録後初めての時
	if (inTime.size() == 0) {
		//退館しようとしている
		if (inout == INOUT::Out) {
			//退館エラーを通知
			throw std::exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}

	//入退どちらの
	if (inTime.size() == outTime.size()) {
		//
		if (inout == INOUT::Out) {
			//
			throw exception(InoutConstant.MESSAGE_OUT_ERROR.c_str());
		}
	}
	//
	else if(inTime.size() > outTime.size()) {
		//
		if (inout == INOUT::In) {
			//
			throw exception(InoutConstant.MESSAGE_IN_ERROR.c_str());
		}
	}

}

