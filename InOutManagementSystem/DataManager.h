#pragma once

#include <string>
#include <vector>
#include "CardRW.h"
#include "FileRW.h"


class DataManager
{
public:
	int userId;
	int birthday;
	std::string userName;
	std::string telNo;
	std::string address;
	short group;
	short cast;
	short attr;
	int inoutYM;
	std::vector<int> inoutTime;
	std::string password;

	//
	CardRW card;
	FileRW file;

public:
	DataManager();
	~DataManager();

	//カードリーダーの初期化を行う関数
	void init();
	//IDのチェックを行う
	void checkId();
	//人物のチェックを行う
	void checkCharacter();
	//カードのデータを読み込む
	void readCardData();
	//データをカードとファイルへ書き込む
	void writeData();
	//ファイルのデータを読み込む
	void readFileData();
	//カードのIDのみ読み込む
	void readCardId();
	
	//メンバのデータをファイルに書き込むように変換する
	std::string makeDataForFile();
	//メンバのデータをカードに書き込むコマンドように変換する
	CardData* makeDataForCard();
	BYTE* makeEleDataForCard(BYTE* block);
	BYTE* makeTelDataForCard(BYTE* block);
	BYTE* makeAddDataForCard(BYTE* block);
	SectorData* makeUsernameForCard();
	CardData* makeAddressForCard();
	CardData* makeInoutDataForCard();
	BYTE* makePasswordForCard(BYTE* block);

	//読みこんだデータをメンバに適用する
	void applyData(CardData* carddata);
	//基礎データを反映させる
	void applyElementData(BYTE* element);
	//電話番号
	void applyTelNoData(BYTE* tel);
	//追加情報を適用させる
	void applyAddData(BYTE* addData);
	//ユーザー名
	void applyUserName(SectorData* nameData);
	//住所
	void applyAddressData(CardData* addressData);
	//読みこんだデータを入退館時間の配列に直す
	void applyInout(CardData* inoutData);
	//パスワードを適用させる
	void applyPassword(BYTE* passBlock);

	//属性から権限取得
	int getAuthority();
	//属性から人物取得
	int getCharacter();
	//入退館の年を取得
	int getInoutY();
	//入退館の月を取得
	int getInoutM();

	//受け取ったファイルのデータをメンバに適用させる
	void applyFileData(std::vector<std::string> fileData);
	
	//カードリーダの開放などの後処理
	void clear();
};

