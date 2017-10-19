#pragma once

#include <vector>
#include "SectorData.h"

class CardData {
public:
	//セクターごとのデータの配列
	std::vector<SectorData*> sector;
	
public:
	//コンストラクタ
	CardData(int sectorN) {
		//引数の数のセクタ配列に
		sector = std::vector<SectorData*>(sectorN);
		//引数分繰り返す
		for (int i = 0; i < sectorN; i++) {
			//セクタごとに作成する
			sector[i] = new SectorData();
		}
	}
	//デストラクタ
	~CardData() {
		//セクタの数分だけ繰り返す
		for (int i = 0; i < sector.size(); i++) {
			//セクタを破棄する
			//delete sector[i];
		}
	}
};