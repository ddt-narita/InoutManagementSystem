#pragma once
#include <vector>
#include "InoutDay.h"
#include "procedureInOut.h"

class ChainData
{
public:
	INOUT inout;	//入退どちらか
	int day;	//日付
	int hour;	//時間
	int minute;	//分

	//上の行へのポインタ
	ChainData* upper;
	//下の行へのポインタ
	ChainData* under;

public:
	//コンストラクタ
	ChainData();
	~ChainData();

	//行のデータを取得する
	ChainData* getRow(int row);
	int getValue(int col);

	//行を挿入する
	ChainData* insertUpper(int row);
	//行を取り除く
	void remove(int row);

	//上下へどちらもお互いのポインタが指すようにする
	void addUpper(ChainData* upper);
	void addUnder(ChainData* under);

	//vectorの情報から行ごとの情報を作成する(入退の時間の配列を適用させる)
	void applyVecData(std::vector<InoutDay> data);
	//vectorのデータを作製する
	void makeDataForVec(std::vector<InoutDay> inoutdays);
};

