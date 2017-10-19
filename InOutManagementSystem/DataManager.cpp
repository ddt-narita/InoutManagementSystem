#include "DataManager.h"
#include <sstream>

using namespace std;

namespace {
	Constants DataMConstants;
};

DataManager::DataManager()
{
	this->userId = 0;
	this->birthday = 0;
	this->inoutYM = 0;
	this->userName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->attr = 0;
	this->password = "";
}


DataManager::~DataManager()
{
}

void DataManager::init()
{
	//カードリーダの初期化を行う
	card.init();
}

void DataManager::checkId()
{
	//メンバにセットされたIDがPC上にない
	if (!file.checkId(userId)) {
		//メッセージを添えて例外を送出する
		throw exception(DataMConstants.MESSAGE_NO_ID.c_str());
	}
}

/*

*/
void DataManager::checkCharacter()
{
	//人物の値を取得する
	int chara = getCharacter();
	//入館拒否者の時
	if (chara == 1) {
		//例外でそのことを伝える
		throw exception(DataMConstants.MESSAGE_CHARACTER_REJECT.c_str());
	}
}

void DataManager::readCardData()
{
	//カードを読み込んで結果を取得する
	CardData* result;
	result = card.readCard();
	//取得したデータからメンバにセット
	applyData(result);
}

void DataManager::writeData()
{
	//カード用にデータを変換してカードに書き込む
	card.writeCard(makeDataForCard());
	//ファイル用にデータを変換してカードに書き込む
	file.writeData(userId, makeDataForFile());
}

void DataManager::readFileData()
{
	//ファイルのデータを格納するための変数を用意
	vector<string> filedata;
	//ファイルのデータを読み込んで用意した変数に格納する
	filedata = file.readFileData(userId);

	//読みこんだデータをメンバに適用させる
	applyFileData(filedata);
}

//IDのみを取得する
void DataManager::readCardId()
{
	//カードからidのみを取得して格納する
	userId = card.readCardID();
}


std::string DataManager::makeDataForFile()
{
	//ファイルに書き込むためのストリームを確保
	std::stringstream ss;

	//各情報を格納していく
	ss << userId << endl;		// 1
	ss << birthday << endl;		// 2
	ss << userName << endl;		// 3
	ss << telNo << endl;		// 4
	ss << address << endl;		// 5
	ss << group << endl;		// 6
	ss << cast << endl;			// 7
	ss << attr << endl;			// 8
	ss << inoutYM << endl;		// 9
	ss << password << endl;		// 10

	//入退館時刻についても同じく配列部分繰り返して
	for (int i = 0; i < inoutTime.size(); i++) {
		//その時の配列の値を格納する
		ss << inoutTime[i] << endl;
	}

	//ストリームを文字列に変えて返却する
	return ss.str();
}


CardData* DataManager::makeDataForCard()
{
	//今回使用する8セクター分のデータを格納するカードデータを用意
	CardData* carddata = new CardData(9);

	//セクター1ブロック1に基礎情報を作って格納する
	makeEleDataForCard(carddata->sector[0]->RWBlock[0]);
	//セクター1ブロック2に電話番号のデータを作成して格納する
	makeTelDataForCard(carddata->sector[0]->RWBlock[1]);
	//セクター1ブロック3に追加情報を作成して格納する
	makeAddDataForCard(carddata->sector[0]->RWBlock[2]);

	//セクター2にユーザー名で作ったデータを格納する
	carddata->sector[1] = makeUsernameForCard();

	//住所のデータを作成して取得
	CardData* address = makeAddressForCard();
	//住所に割り当てられた3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//割り当てられたセクター3から5までに順に格納していく
		carddata->sector[2 + i] = address->sector[i];
	}

	//入退館時間のデータを作成して格納する
	CardData* inout = makeInoutDataForCard();
	//入退館時間に割り当てられた3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//割り当てられた6から8セクターに順に格納していく
		carddata->sector[5 + i] = inout->sector[i];
	}
	//パスワードについても書き込む
	makePasswordForCard(carddata->sector[8]->RWBlock[0]);

	delete address;
	delete inout;

	//作成した書き込みたいカードデータを返却する
	return carddata;
}

BYTE * DataManager::makeEleDataForCard(BYTE* block)
{
	//各データをメモリでコピーするためのバイト配列用意
	unsigned char temp[sizeof(int)];
	//ユーザIDをバイト配列に変換
	memcpy(temp, &userId, sizeof(int));
	//intの大きさ分繰り返す
	for (int i = 0; i < sizeof(int); i++) {
		//受け取った配列の前4つに格納
		block[i] = temp[i];
	}
	//生年月日をバイト配列に変換
	memcpy(temp, &birthday, sizeof(int));
	//intの大きさ分繰り返す
	for (int i = 0; i < sizeof(int); i++) {
		//引数の配列のその後ろの4つに格納
		block[4 + i] = temp[i];
	}
	//入退館の年月をバイト配列に変換
	memcpy(temp, &inoutYM, sizeof(int));
	//intの大きさ分繰り返す
	for (int i = 0; i < sizeof(int); i++) {
		//引数の配列の最後の4つに格納
		block[8 + i] = temp[i];
	}

	return block;
}

BYTE * DataManager::makeTelDataForCard(BYTE* block)
{
	//電話番号の文字列をchar*のバイト配列に直す
	const char* chTel = telNo.c_str();
	//文字列の長さを取得する
	int tellen = strlen(chTel);

	//ブロック内のバイト数分繰り返す
	for (int i = 0; i < BLOCK_BYTE; i++) {
		//カレントが電話番号の長さより小さいとき
		if (tellen > i) {
			//電話番号の値を返却するバイト配列に格納する
			block[i] = chTel[i];
		}
		//それより大きいとき
		else {
			//終端文字を格納する
			block[i] = '\0';
		}
	}

	//作成したブロックのバイト配列を返却する
	return block;
}

BYTE * DataManager::makeAddDataForCard(BYTE* block)
{
	//各データをメモリでコピーするためのバイト配列用意
	unsigned char temp[sizeof(short)];

	//所属をバイト配列に変換
	memcpy(temp, &group, sizeof(short));
	//shortの大きさ分繰り返す
	for (int i = 0; i < sizeof(short); i++) {
		//受け取った配列の前4つに格納
		block[0 + i] = temp[i];
	}
	//役職をバイト配列に変換
	memcpy(temp, &cast, sizeof(short));
	//shortの大きさ分繰り返す
	for (int i = 0; i < sizeof(short); i++) {
		//受け取った配列のその後ろの4つに格納
		block[2 + i] = temp[i];
	}
	//属性をバイト配列に変換
	memcpy(temp, &attr, sizeof(short));
	//shortの大きさ分繰り返す
	for (int i = 0; i < sizeof(short); i++) {
		//受け取った配列の最後の4つに格納
		block[4 + i] = temp[i];
	}
	return block;
}

SectorData* DataManager::makeUsernameForCard()
{
	//名前に当てられた一つのセクターを確保
	SectorData* userNameData = new SectorData();
	//ユーザー名の長さを取得
	int len = strlen(userName.c_str());
	//ユーザー名をバイト配列にしておく
	const unsigned char* username = (unsigned char*)userName.c_str();
	//ブロック分繰り返す
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//バイト数分だけ繰り返す
		for (int j = 0; j < BLOCK_BYTE; j++) {
			//終端でなければ
			if ((i * 16 + j) < len) {
				//その文字を格納していく
				userNameData->RWBlock[i][j] = username[i * 16 + j];
			}
			//そうなら
			else {
				//終端文字を格納する
				userNameData->RWBlock[i][j] = '\0';
			}
		}
	}
	//作成した配列を返却する
	return userNameData;
}

CardData* DataManager::makeAddressForCard()
{
	//住所に割り当てられた3セクター分のデータを格納する変数を用意
	CardData* addressData = new CardData(3);
	//住所の文字列をバイト後の配列に直す
	const char* chAddress = address.c_str();
	//住所の文字列の長さを取得する
	int addrlen = strlen(chAddress);
	//住所に割り当てられた3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター内のブロックの数繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロック内のバイト数分繰り返す
			for (int k = 0; k < BLOCK_BYTE; k++) {
				//住所の文字列の長さのほうが長いとき
				if (addrlen > i * 48 + j * 16 + k) {
					//その位置のバイトごとの値を格納する
					addressData->sector[i]->RWBlock[j][k] = chAddress[i * 48 + j * 16 + k];
				}
				//小さいとき(すでに終わっているとき)
				else {
					//終端文字を格納する
					addressData->sector[i]->RWBlock[j][k] = '\0';
				}
			}
		}
	}
	//作成した配列を返却する
	return addressData;
}

CardData* DataManager::makeInoutDataForCard()
{
	//入退館時間に当てられた3セクター分のデータを格納する変数を用意する
	CardData* inoutData = new CardData(3);
	//intをメモリでコピーしてバイト配列にするための変数を用意する
	char tempbuf[sizeof(int)];
	//メンバの入退館時間の配列の長さを取得
	int veclen = inoutTime.size();

	//割り当てられた3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター内のブロックの数分繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロック内のバイト数分繰り返す
			for (int k = 0; k < BLOCK_BYTE / sizeof(int); k++) {
				//その位置が配列の長さより小さい(まだカードに書かなければならない値が残っている)
				if (veclen > i * 12 + j * 4 + k) {
					//その位置の配列の要素のintをメモリでコピーしてバイト配列にする
					memcpy(tempbuf, &inoutTime[i * 12 + j * 4 + k], sizeof(int));
					//intの長さ分だけ繰り返す
					for (int m = 0; m < sizeof(int); m++) {
						//できたバイト配列の要素を一つ一つ格納していく
						inoutData->sector[i]->RWBlock[j][4 * k + m] = tempbuf[m];
					}
				}
				//もうカードに書き込むべき値がない
				else {
					//intの長さ分だけ繰り返す
					for (int m = 0; m < sizeof(int); m++) {
						//その位置の書き込むデータに無効な値を格納しておく
						inoutData->sector[i]->RWBlock[j][4 * k + m] = 0xff;
					}
				}
			}
		}
	}
	//3セクター分のデータを返却する
	return inoutData;
}

BYTE * DataManager::makePasswordForCard(BYTE * block)
{
	const char* pass = password.c_str();
	
	int len = strlen(pass);
	for (int i = 0; i <	len; i++) {
		block[i] = pass[i];
	}
	
	return block;
}




/*
関数名:applyData
概要:読み取ったデータをメンバに適用させる
引数:CardData carddata 読み取ったカードのデータ
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyData(CardData* carddata)
{
	//セクター1ブロック1の基礎データを適用
	applyElementData(carddata->sector[0]->RWBlock[0]);
	//セクター1ブロック2の電話番号データをメンバに適用
	applyTelNoData(carddata->sector[0]->RWBlock[1]);
	//セクター1ブロック３の追加データをメンバに適用
	applyAddData(carddata->sector[0]->RWBlock[2]);

	//セクター2の名前を適用
	applyUserName(carddata->sector[1]);
	//住所を取得するためのカードデータ用意
	CardData* address = new CardData(3);
	//3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター3から5の住所データを格納して
		address->sector[i] = carddata->sector[2 + i];
	}
	//取得した住所データで適用させる
	applyAddressData(address);

	//入退館時刻のデータを取得するためのカードデータを用意
	CardData* inout = new CardData(3);
	//3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター6から8の入退館時刻データを格納して
		inout->sector[i] = carddata->sector[5 + i];
	}
	//取得した入退館時刻データをメンバに適用させる
	applyInout(inout);

	//パスワードをメンバに適用させる
	applyPassword(carddata->sector[8]->RWBlock[0]);

}


/*
関数名:applyElementData
概要:基礎情報をメンバに適用させる
引数:BYTE* element　基礎情報の入ったブロックの情報
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyElementData(BYTE * element)
{
	int intlen = sizeof(int);

	//4バイト分のcharのバイト配列を用意する
	char tempbuf[sizeof(int)];
	//4バイト(int)分繰り返す
	for (int i = 0; i < intlen; i++) {
		//最初の4つを格納する
		tempbuf[i] = element[0 + i];
	}
	//ユーザIDにメモリーコピーしてセット
	memcpy(&userId, tempbuf, intlen);

	//4バイト(int)分繰り返す
	for (int i = 0; i < intlen; i++) {
		//その次の4つを格納する
		tempbuf[i] = element[4 + i];
	}
	//誕生日にメモリーコピーしてセット
	memcpy(&birthday, tempbuf, intlen);

	//4バイト(int)分繰り返す
	for (int i = 0; i < intlen; i++) {
		//その次の4つを格納する
		tempbuf[i] = element[8 + i];
	}
	//入退の年月にコピーしてセット
	memcpy(&inoutYM, tempbuf, intlen);
}

/*
関数名:applyTelNoData
概要:電話番号をメンバに適用させる
引数:BYTE* tel　読み取った電話番号のデータ
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyTelNoData(BYTE * tel)
{
	//長さを取得する
	int len = strlen((char*)tel);
	//長さが16以下なら
	if (len <= 16) {
		//ユーザー名に格納する
		telNo = (char*)tel;
	}
	//16より大きいなら
	else {
		//例外を送出する
		throw std::exception("データが無効です");
	}
}

/*
関数名:applyAddData
概要:追加情報をメンバに適用させる
引数:BYTE*　block 追加情報のブロック
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyAddData(BYTE * addData)
{
	int shortlen = sizeof(short);

	//2バイトの配列を用意する
	char tempbuf[sizeof(short)];

	//2バイト分繰り返す
	for (int i = 0; i < shortlen; i++) {
		//初めの2つを格納する
		tempbuf[i] = addData[0 + i];
	}
	//所属にメモリーコピーしてセット
	memcpy(&group, tempbuf, shortlen);

	//2バイト分繰り返す
	for (int i = 0; i < shortlen; i++) {
		//初めの2つを格納する
		tempbuf[i] = addData[2 + i];
	}
	//役職にメモリーコピーしてセット
	memcpy(&cast, tempbuf, shortlen);

	//2バイト分繰り返す
	for (int i = 0; i < 2; i++) {
		//初めの2つを格納する
		tempbuf[i] = addData[4 + i];
	}
	//属性にメモリーコピーしてセット
	memcpy(&attr, tempbuf, sizeof(short));
}


/*
関数名:applyUserName
概要:ユーザ名をメンバに適用させる
引数:SectorData* nameData 名前の格納されたセクターのデータ
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyUserName(SectorData * nameData)
{
	//名前を格納する変数を用意する
	string name;
	//セクター内のブロックの数(3)だけ繰り返す
	for (int i = 0; i < SECTOR_BLOCK_NUM; i++) {
		//先頭の文字列が終端文字ではなければ
		if ('\0' != nameData->RWBlock[i]) {
			//用意した変数に追加する
			name += (char*)nameData->RWBlock[i];
		}
	}
	//名前をメンバに適用する
	userName = name;
}

/*
関数名:applyAddressData
概要:住所をメンバに適用させる
引数:CardData addressData 住所の格納された3セクター分のカードデータ
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyAddressData(CardData* addressData)
{
	//住所の文字列を格納するための変数を用意
	char* addr = new char[144];
	//住所に割り当てられた3セクター分繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター内のブロックの数分繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロックの先頭の文字が終端を示すものではないなら
			if ('\0' != addressData->sector[i]->RWBlock[j]) {

				for (int k = 0; k < 16; k++) {
					addr[i * 48 + j * 16 + k] = addressData->sector[i]->RWBlock[j][k];
				}
			}
		}
	}
	//できた住所をメンバに格納する
	address = addr;

}

/*
関数名:applyInout
概要:入退館時間のデータをメンバに適用させる
引数:CardData inoutData 入退館情報の格納された3セクター分のカードデータ
返却値:無し
作成日:10月11日
作成者:成田修之
*/
void DataManager::applyInout(CardData* inoutData)
{
	//バイト配列intにから変換するための変数を用意
	char tempbuf[sizeof(int)];
	//入退館時刻データに割り当てられた3セクター分だけ繰り返す
	for (int i = 0; i < 3; i++) {
		//セクター内のブロック数(3)だけ繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロック内の16バイトの中の4バイト(int)ずつ行う
			for (int k = 0; k < sizeof(int); k++) {
				//その4バイトずつの先頭が無効な値でないなら
				if (0xff != inoutData->sector[i]->RWBlock[j][k * 4]) {
					//そのintの4バイト分を繰り返す
					for (int m = 0; m < sizeof(int); m++) {
						//その位置のブロックの4k番目からの4つを書くの数r
						tempbuf[m] = inoutData->sector[i]->RWBlock[j][k * 4 + m];
					}
					//メモリコピーのためのint型変数を用意
					int tempint;
					//作成した4バイトごとの配列をメモリコピーする
					memcpy(&tempint, tempbuf, sizeof(int));
					//メンバの入退時間に追加していく
					inoutTime.push_back(tempint);
				}
				//先頭が無効な値の時
				else {
					//そのあとにはないとしてループを抜ける
					break;
				}
			}
		}
	}
}

void DataManager::applyPassword(BYTE * passBlock)
{
	//文字列の配列を用意
	char* pass = new char[16];
	//ブロック中のバイト数分繰り返す
	for (int i = 0; i < BLOCK_BYTE; i++) {
		//渡された配列をコピーしていく
		pass[i] = passBlock[i];
	}

	//パスワードに格納する
	password = pass;
	//用意した配列を削除
	delete pass;
}

int DataManager::getAuthority()
{
	//権限を格納する変数
	int authority = 0;
	//1バイト分だけ繰り返す
	for (int i = 0; i < 8; i++) {
		//属性の値の何番
		if (attr & (1 << (15 - i))) {
			//
			authority = i;
			//
			break;
		}
	}
	//
	return authority;
}

int DataManager::getCharacter()
{
	int chara = 0;
	for (int i = 0; i < 8; i++) {
		if (attr & (1 << (7 - i))) {
			chara = i;
			break;
		}
	}

	return chara;
}

/*
関数名:
概要:
引数:
返却値:
作成日:
作成者:
*/
int DataManager::getInoutY()
{
	//
	return inoutYM / 100;
}

/*

*/
int DataManager::getInoutM()
{
	//
	return inoutYM - getInoutY() * 100;
}

void DataManager::applyFileData(vector<string> fileData)
{
	//1行目をユーザーIDに
	userId = stoi(fileData[0]);
	//2行目を誕生日に
	birthday = stoi(fileData[1]);
	//3行目を名前に
	userName = fileData[2];
	//4行目を電話に
	telNo = fileData[3];
	//5行目を住所に
	address = fileData[4];
	//6行目を所属に
	group = stoi(fileData[5]);
	//7行目を役職に
	cast = stoi(fileData[6]);
	//8行目を属性に
	attr = stoi(fileData[7]);
	//9行目を入退の年月に
	inoutYM = stoi(fileData[8]);
	//10行目をパスワードに
	password = fileData[9];

	//10行目から先をすべて
	for (int i = 10; i < fileData.size(); i++) {
		//メンバに後ろから追加していく
		inoutTime.push_back(stoi(fileData[i]));
	}
}

void DataManager::clear()
{
	card.clear();
}

