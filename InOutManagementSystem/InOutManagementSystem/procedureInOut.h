#pragma once
#include "DataManager.h"

enum INOUT
{
	In = 0,
	Out = 1,
};

class procedureInOut :
	public DataManager
{
public:
	//入退どちらなのか格納する変数
	INOUT inout;

public:
	procedureInOut();
	~procedureInOut();

	//カードリーダー等の初期化処理を行う関数
	void init();
	//入退館処理
	void InOut();

	//現在時刻を入退時間のメンバにセットする(入退館時刻として記録する)
	void setInOutTime();
	//入退の不整合をチェックする
	void inoutCheck();
};

