#pragma once

#include <string>
#include <vector>
#include "InoutDay.h"
#include "CardRW.h"
#include "FileRW.h"


class DataManager
{
public:
	std::string userId;
	std::string userFirstName;
	std::string userLastName;
	std::string password;
	std::string telNo;
	int birthday;
	byte group;
	byte cast;
	byte chara;
	byte auth;
	std::string address;
	int currentInout;
	std::vector<InoutDay> inTime;
	std::vector<InoutDay> outTime;
	
	boost::property_tree::ptree fileData;

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

	//ファイルのデータを読み込む
	void readFileData();
	//カードのIDのみ読み込む
	void readCardId();

	//カードへ前回までのデータの書き込みを行う
	void writeCard();
	//ファイルへ入退館のの処理まで終えた後メンバのデータを書き込む
	void writeFile();

	

	
	//メンバのデータをカードに書き込むコマンドように変換する
	CardData* makeDataForCard();
	void makeIdDataForCard(CardData* card);
	void makeNameDataForCard(CardData* card);
	void makePassDataForCard(CardData* card);
	void makeTellDataForCard(CardData* card);
	void makeBirthDataForCard(CardData* card);
	void makeParameterDataForCard(CardData* card);
	void makeAddressDataForCard(CardData* card);
	void makeInTimeDataForCard(CardData* card);
	void makeOutTimeDataForCard(CardData* card);


	//セクターとブロック、ブロック内の何バイト目からかを決め、データの長さ分を格納する
	void setDataForCardData(CardData* card, int sector, int block, int fromByte, BYTE* data, int dataLen);

	////読みこんだデータをメンバに適用する
	void applyData(CardData* carddata);
	////基礎データを反映させる
	void applyUserID(CardData* carddata);
	void applyUserName(CardData* carddata);
	////パスワードを適用させる
	void applyPassword(CardData* carddata);
	////電話番号
	void applyTelNoData(CardData* carddata);
	void applyBirthday(CardData* carddata);
	void applyParameter(CardData* carddata);
	////住所
	void applyAddressData(CardData* carddata);
	void applyInoutYM(CardData* carddata);
	////読みこんだデータを入退館時間の配列に直す
	void applyInTime(CardData* carddata);
	void applyOutTime(CardData* carddata);
	
	void setChara(int select);
	void setAuth(int select);
	void setCast(int select);
	void setAffli(int select);
	void setGroup(int select);

	int getSelectedChara();
	int getSelectedAuth();
	int getSelectedCast();
	int getSelectedAffli();
	int getSelectedGroup();



	//入退館の年を取得
	int getInoutY();
	//入退館の月を取得
	int getInoutM();

	//メンバのデータをファイルに書き込むように変換する
	void makeDataForFile();
	//受け取ったファイルのデータをメンバに適用させる
	void applyFileData(boost::property_tree::ptree fileData);
	//ファイルの入館のデータをメンバに適用させる
	void applyFileIndata(boost::property_tree::ptree fileData);
	//ファイルの退館のデータをメンバに適用させる
	void applyFileOutdata(boost::property_tree::ptree fileData);

	//カードリーダの開放などの後処理
	void clear();
};

