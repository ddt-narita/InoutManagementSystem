#pragma once

#ifndef __Constants
#define __Constants


#include <sstream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <assert.h>
#include <fstream>
#include <iomanip>

const static class Constants {
public:
	//
	const std::string MESSAGE_RESOURSE_NO_SERVICE = "Smart Cardサービスが起動されていません";
	const std::string MESSAGE_RESOUSE_ERROR = "Smart Cardサービスとの接続に失敗しました。";
	const std::string MESSAGE_NO_READER = "カードリーダーが接続されていません";
	const std::string MESSAGE_READER_ACCESS_ERROR = "カードリーダーとの接続に失敗しました。";
	const std::string MESSAGE_NO_CARD = "カードがセットされていません";
	const std::string MESSAGE_CARD_ACCESS_ERROR = "カードとの接続に失敗しました。";
	const std::string MESSAGE_CARD_REMOVE = "カードが取り外されました。";
	const std::string MESSAGE_FAILED_SEND_COMMAND = "コマンドの送信に失敗しました。";
	const std::string MESSAGE_WARNING_WRITE_ACCESS_BLOCK = "アクセス制御のブロックに書き込むことはできません。";
	const std::string MESSAGE_NO_SUCH_ID = "存在しないIDです";
	const std::string MESSAGE_CANNOT_OPEN_ID_FILE = "IDのファイルのファイルを開けませんでした。";

	const std::string MESSAGE_NO_ID = "IDが認証できません";
	const std::string MESSAGE_CHARACTER_REJECT = "入館拒否者です。";
	const std::string MESSAGE_CHARACTER_CAUTION_NEED = "要注意人物です。";

	const std::string MESSAGE_IN_ERROR = "退館していません";
	const std::string MESSAGE_OUT_ERROR = "入館していません";

	//パラメータの値
	const int general = 0x00;
	
	const int noInout = 0x01;
	const int cautionNeed = 0x02;

	const int admin = 0x01;

	const int parttime = 0x01;
	const int butyou = 0x02;

	const int group1 = 0x01;
	const int group2 = 0x02;
	const int group3 = 0x04;

	const int eigyou = 0x01;
	const int soumu = 0x02;
	const int kaihatu = 0x04;


	//ユーザーIDのセクターとブロックと始まりのバイト
	const int userIdSectorNum = 0;
	const int userIdBlockNum = 0;
	const int userIdStartByteNum = 0;

	//苗字のセクターとブロックと始まりのバイト
	const int lastNameSectorNum = 0;
	const int lastNameBlockNum = 1;
	const int lastNameStartByteNum = 0;

	//名前のセクターとブロックと始まりのバイト
	const int firstNameSectorNum = 0;
	const int firstNameBlockNum = 2;
	const int firstNameStartByteNum = 0;

	//パスワードのセクターとブロックと始まりのバイト
	const int passSectorNum = 1;
	const int passBlockNum = 0;
	const int passStartByteNum = 0;

	//電話番号のセクターとブロックと始まりのバイト
	const int tellSectorNum = 1;
	const int tellBlockNum = 1;
	const int tellStartByteNum = 0;

	//生年月日のセクターとブロックと始まりのバイト
	const int birthdaySectorNum = 1;
	const int birthdayBlockNum = 2;
	const int birthdayStartByteNum = 0;

	//パラメータのセクターとブロックと始まりのバイト
	const int parameterSectorNum = 1;
	const int parameterBlockNum = 2;
	const int parameterStartByteNum = 4;

	//住所のセクターとブロックと始まりのバイト
	const int addressSectorNum = 2;
	const int addressBlockNum = 0;
	const int addressStartByteNum = 0;

	//入退館の年月のセクターとブロックと始まりのバイト
	const int inTimeSectorNum = 4;
	const int inTimeBlockNum = 0;
	const int inTimeStartByteNum = 0;

	//入館のセクターとブロックと始まりのバイト
	const int inTimeSectorNum = 4;
	const int inTimeBlockNum = 0;
	const int inTimeStartByteNum = 2;

	//退館のセクターとブロックと始まりのバイト
	const int outTimeSectorNum = 6;
	const int outTimeBlockNum = 0;
	const int outTimeStartByteNum = 2;


	//第1・2セクターが使用不可のため、8ブロック分ずらして処理を行うための調整変数
	const int adjustBlock = 8;

	/*
	関数名:StrToC_str
	概要:System::String^からstd::stringに変換して返す関数
	引数:String^ 変換元
	返却値:string 変換後の文字列
	作成日:9月15日(金)
	作成者:成田修之
	*/
	std::string StrToc_str(System::String^ temp) {
		return (char*)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(temp).ToPointer();
	}
};

//Constants constants;


#endif // !__Constants