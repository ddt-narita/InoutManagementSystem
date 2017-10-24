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

class Constants {
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
	const std::string MESSAGE_INOUT_OVER_ERROR = "入退館の管理日数が31日を超えました\n管理者に報告してください";

	//パラメータの値
	const static int general = 0x00;
	
	const static int noInout = 0x01;
	const static int cautionNeed = 0x02;

	const static int admin = 0x01;

	const static int parttime = 0x01;
	const static int butyou = 0x02;

	const static int group1 = 0x01;
	const static int group2 = 0x02;
	const static int group3 = 0x04;

	const static int eigyou = 0x01;
	const static int soumu = 0x02;
	const static int kaihatu = 0x04;


	//ユーザーIDのセクターとブロックと始まりのバイト
	const static int userIdSectorNum = 0;
	const static int userIdBlockNum = 0;
	const static int userIdStartByteNum = 0;

	//苗字のセクターとブロックと始まりのバイト
	const static int lastNameSectorNum = 0;
	const int lastNameBlockNum = 1;
	const static int lastNameStartByteNum = 0;

	//名前のセクターとブロックと始まりのバイト
	const static int firstNameSectorNum = 0;
	const static int firstNameBlockNum = 2;
	const static int firstNameStartByteNum = 0;

	//パスワードのセクターとブロックと始まりのバイト
	const static int passSectorNum = 1;
	const static int passBlockNum = 0;
	const static int passStartByteNum = 0;

	//電話番号のセクターとブロックと始まりのバイト
	const static int tellSectorNum = 1;
	const static int tellBlockNum = 1;
	const static int tellStartByteNum = 0;

	//生年月日のセクターとブロックと始まりのバイト
	const static int birthdaySectorNum = 1;
	const static int birthdayBlockNum = 2;
	const static int birthdayStartByteNum = 0;

	//パラメータのセクターとブロックと始まりのバイト
	const static int parameterSectorNum = 1;
	const static int parameterBlockNum = 2;
	const static int parameterStartByteNum = 4;

	//住所のセクターとブロックと始まりのバイト
	const static int addressSectorNum = 2;
	const static int addressBlockNum = 0;
	const static int addressStartByteNum = 0;

	//入退館の年月のセクターとブロックと始まりのバイト
	const static int inoutTimeSectorNum = 4;
	const static int inoutTimeBlockNum = 0;
	const static int inoutTimeStartByteNum = 0;

	//入館のセクターとブロックと始まりのバイト
	const static int inTimeSectorNum = 4;
	const static int inTimeBlockNum = 0;
	const static int inTimeStartByteNum = 2;

	//退館のセクターとブロックと始まりのバイト
	const static int outTimeSectorNum = 6;
	const static int outTimeBlockNum = 0;
	const static int outTimeStartByteNum = 2;


	//第1・2セクターが使用不可のため、8ブロック分ずらして処理を行うための調整変数
	const static int adjustBlock = 8;

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