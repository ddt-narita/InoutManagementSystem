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


	//第1・2セクターが使用不可のため、8ブロック分ずらして処理を行うための調整変数
	const int adjustBlock = 8;



	void fileout(char* a) {
		std::stringstream ss;
		int len = strlen(a);
		for (int i = 0; i < len; i++) {

			ss << std::setw(2) << std::hex <<  a[i] << std::endl;

			if ((i + 1) >= len) {
				ss <<("\n");
			}
			else {
				ss << (" ");
			}

		}
		std::string filename = "debug.txt";
		std::ofstream ofs;
		ofs.open(filename, std::ios::app);
		ofs << ss.str();
		ofs.close();
	}


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