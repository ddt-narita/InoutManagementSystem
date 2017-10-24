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
	//入館状況のチェックを行う
	inoutCheck();
	//現在時刻を入退館の時間としてセットする
	setInOutTime();
	//
	writeFile();
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
	//現在時刻を取得する		
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);

	//カレントの日付をセットする
	currentInout = pnow->tm_year * 10000 + (pnow->tm_mon + 1) * 100 + pnow->tm_mday;

	//入館の時
	if (inout == INOUT::In) {
		//入館のその日のデータに日時分を格納する
		inTime[pnow->tm_mday].day = pnow->tm_mday;
		inTime[pnow->tm_mday].hour = pnow->tm_hour;
		inTime[pnow->tm_mday].minute = pnow->tm_min;
	}
	//退館の時
	else {
		//退館のその日のデータに日時分を格納する
		outTime[pnow->tm_mday].day = pnow->tm_mday;
		outTime[pnow->tm_mday].hour = pnow->tm_hour;
		outTime[pnow->tm_mday].minute = pnow->tm_min;
	}

}

void procedureInOut::inoutCheck()
{


}

