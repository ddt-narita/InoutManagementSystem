#include "procedureRegist.h"



procedureRegist::procedureRegist()
{
}


procedureRegist::~procedureRegist()
{
}

void procedureRegist::init()
{
	//親クラスDataManagerの初期化関数でカードリーダの初期化を行う
	DataManager::init();
}

void procedureRegist::registData()
{
	//ファイルとカードへ書き込む
	writeData();
}
