#include "SectorData.h"

//コンストラクタ
SectorData::SectorData()
{
	//セクター内ブロック数分だけ繰り返す
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//各ブロックに16バイトの領域確保
		RWBlock[i] = new BYTE[BLOCK_BYTE];
		//確保したメモリの初期化を行う
		memset(RWBlock[i], 0x00, BLOCK_BYTE);
	}
	//アクセス制御のブロックにも16バイトの領域確保
	acsessBlock = new BYTE[BLOCK_BYTE];
	//確保したメモリの初期化
	memset(acsessBlock, 0x00, BLOCK_BYTE);
}

//デストラクタ
SectorData::~SectorData()
{
	//セクター内のブロック数分だけ繰り返す
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//各ブロックの確保された領域を解放する
		delete RWBlock[i];
	}
	//アクセス制御のブロックを解放する
	delete acsessBlock;
}

SectorData& SectorData::operator=(SectorData& sector)
{
	//読み書き用ブロック数だけ繰り返す
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//各ブロックのメモリをそのブロック内のバイト数分コピーする
		memcpy(this->RWBlock[i], sector.RWBlock[i], BLOCK_BYTE);
	}
	//アクセス制御のブロックもバイト数分コピーする
	memcpy(this->acsessBlock, sector.acsessBlock, BLOCK_BYTE);

	//自身を返す
	return *this;
}
