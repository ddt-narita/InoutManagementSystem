#include <exception>
#include "ChainData.h"

using namespace std;

/*
関数名:コンストラクタ
概要:初期化を行う
引数:無し
返却値:なし
作成日:10月17日(火)
作成者:成田修之
*/
ChainData::ChainData()
{
	//各情報を初期化
	this->inout = INOUT::In;
	this->day = 0;
	this->hour = 0;
	this->minute = 0;

	//兄弟(上と下の行)へのポインタをナルにする
	this->upper = nullptr;
	this->under = nullptr;
}

/*
関数名:デストラクタ
概要:下にまだ行があれば削除する
引数:無し
返却値:無し
作成日:10月17日(火)
作成者:成田修之
*/
ChainData::~ChainData()
{
	//下にまだ行があれば
	if (nullptr != under) {
		//下の行を削除する
		delete under;
	}
}


/*
関数名:
概要:
引数:
返却値:
作成日:10月17日(火)
作成者:成田修之
*/
ChainData * ChainData::getRow(int row)
{
	////兄弟の数を取得する
	//int broNum  ;
	////引数が兄弟の数より多ければ
	//if (broNum < row + 1) {
	//	//例外を送出する
	//	throw exception();
	//}

	//自身をカレントとして格納する
	ChainData* current = this;
	//引数分繰り返す
	for (int i = 0; i <= row; i++) {
		//下の兄弟へ移動する
		current = current->under;
	}

	//目的の行を返却する
	return current;
}

int ChainData::getValue(int col)
{
	//値を格納する変数を用意
	int val = 0;
	//引数の列数によって分岐
	switch (col)
	{
	//1列目
	case 0:
		//入退どちらなのかを返す
		val = this->inout;
		break;
	//2列目
	case 1:
		//入退の日付を返す
		val = this->day;
		break;
	//3列目
	case 2:
		//時間を返す
		val = this->hour;
		break;
	//4列目
	case 3:
		//分を返す
		val = this->minute;
		break;
	default:
		break;
	}

	//分岐によって格納された値を返却する
	return val;
}

//挿入
ChainData * ChainData::insertUpper(int row)
{
	//新しく挿入する行を作成する
	ChainData* insertRow = new ChainData();
	
	//選択された行を取得する
	ChainData* selected = getRow(row);
	//選択された行の上の行を取得する
	ChainData* upper = selected->upper;

	//選択された行の上に追加する
	selected->addUpper(insertRow);
	//挿入する行の上に上の行を追加する
	insertRow->addUpper(upper);

	//挿入した行の情報を返す
	return insertRow;
}

//削除
void ChainData::remove(int row)
{
	//選択された行を取得
	ChainData* selected = getRow(row);
	//上の行を取得する
	ChainData* upper = selected->upper;
	//下がナルではないとき
	if (nullptr != selected->under) {
		//下を取得して
		ChainData* under = selected->under;
		//上の下に下を格納する
		upper->addUnder(under);
		//削除するセルの下へのポインタにナルを格納する(デストラクタで下も一緒に破棄されてしまうため)
		selected->under = nullptr;
	}
	//下がナルの時
	else {
		//上のセルの下へのポインタ(選択されていた行を指していたもの)をナルに
		upper->under = nullptr;
	}

	//選択された行を削除する
	delete selected;
}

//上に追加する
void ChainData::addUpper(ChainData * upper)
{
	this->upper = upper;
	upper->under = this;
}

//下に追加する
void ChainData::addUnder(ChainData * under)
{
	this->under = under;
	under->upper = this;
}

//配列のデータから行の情報を作製する
void ChainData::applyVecData(std::vector<short> data)
{
	ChainData* current = this;

	for (int i = 0; i < data.size(); i++) {
		current->addUnder(new ChainData());
		current = current->under;



		current->day = data[i] / 24 / 60;;
		current->hour = (data[i] - (current->day *(24 * 60))) /60 ;
		current->minute = (data[i]  - (current->day * 24 * 60) - (current->hour * 60));
	}
}

//配列の情報を作製する
std::vector<int> ChainData::makeDataForVec()
{
	//返却する入退のデータ
	vector<int> inoutData;
	//日ごと(行ごと)のデータ
	int dayData;
	//int分のデータをコピーするためのバイトの配列を用意
	char tempbuf[sizeof(int)];

	//下をカレントとする
	ChainData* current = this->under;

	//カレントの行がナルになるまで繰り返す
	while (nullptr != current) {
		//1バイト目に入退どちらなのか
		tempbuf[0] = current->inout;
		//2バイト目には日付
		tempbuf[1] = current->day;
		//3バイト目には時
		tempbuf[2] = current->hour;
		//4バイト目には分を格納する
		tempbuf[3] = current->minute;

		//格納した4バイト分でintにメモリコピーしてintにする
		memcpy(&dayData, tempbuf, sizeof(int));
		//その値を配列の後ろへと追加していく
		inoutData.push_back(dayData);
	}
	//
	return inoutData;
}
