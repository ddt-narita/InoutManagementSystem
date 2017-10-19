#pragma once

#include <windows.h>

//セクター内のブロック数
#define SECTOR_BLOCK_NUM (3)
//ブロック内のバイト数
#define BLOCK_BYTE (16)

//セクター後のデータを保持しておくためのクラス
class SectorData {
public:
	//読み書きに使用するブロック(セクター内には3つ)
	BYTE* RWBlock[SECTOR_BLOCK_NUM];
	//アクセス制御を行うブロック(セクター内の4つ目のブロック)
	BYTE* acsessBlock;

public:
	SectorData();
	~SectorData();

	//代入演算子
	SectorData& operator=(SectorData& sector);
};