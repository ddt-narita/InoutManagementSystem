#include "DataManager.h"
#include <sstream>

using namespace std;

namespace {
	Constants DataMConstants;
};

/*
関数名:コンストラクタ
概要:各メンバを初期化する
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
DataManager::DataManager()
{
	this->userId = "";
	this->birthday = 0;
	this->inoutYM = 0;
	this->userFirstName = "";
	this->userLastName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->chara = 0;
	this->auth = 0;
	this->password = "";
}

/*
関数名:デストラクタ
概要:
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
DataManager::~DataManager()
{
}

/*
関数名:init
概要:初期化処理
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::init()
{
	//カードリーダの初期化を行う
	card.init();
}

/*
関数名:checkId
概要:取得したIDがPC上に存在するかどうかを判定
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::checkId()
{
	//メンバにセットされたIDがPC上にない
	if (!file.checkId(userId)) {
		//メッセージを添えて例外を送出する
		throw exception(DataMConstants.MESSAGE_NO_ID.c_str());
	}
}

/*
関数名:checkCharacter
概要:人物の判定を行う
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::checkCharacter()
{
	//入館拒否者の時
	if (chara == DataMConstants.noInout) {
		//例外でそのことを伝える
		throw exception(DataMConstants.MESSAGE_CHARACTER_REJECT.c_str());
	}
}

/*
関数名:readCardData
概要:カードのデータを読み込む
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::readCardData()
{
	//カードを読み込んで結果を取得する
	CardData* result;
	result = card.readCard();
	//取得したデータからメンバにセット
	applyData(result);
}

/*
関数名:writeData
概要:メンバのデータをカードとファイルへ書き込む
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::writeData()
{
	//カード用にデータを変換してカードに書き込む
	card.writeCard(makeDataForCard());
	//ファイル用にデータを変換してカードに書き込む
	file.writeData(userId, makeDataForFile());
}

/*
関数名:
概要:
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::readFileData()
{
	//ファイルのデータを格納するための変数を用意
	vector<string> filedata;
	//ファイルのデータを読み込んで用意した変数に格納する

	filedata = file.readFileData(userId);

	//読みこんだデータをメンバに適用させる
	applyFileData(filedata);
}

/*
関数名:
概要:
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::readCardId()
{
	//カードからfirstnameのみを取得して格納する
	userId = card.readCardID();
}

/*
関数名:
概要:
引数:なし
返却値:string 
作成日:10月16日(月)
作成者:成田修之
*/
std::string DataManager::makeDataForFile()
{
	//ファイルに書き込むためのストリームを確保
	std::stringstream ss;

	//各情報を格納していく
	ss << userId << endl;			// 1
	ss << userLastName << endl;		// 3
	ss << userFirstName << endl;
	ss << password << endl;			// 10
	ss << telNo << endl;			// 4
	ss << birthday << endl;			// 2
	ss << to_string(group) << endl;	// 6
	ss << to_string(cast) << endl;	// 7
	ss << to_string(chara) << endl;	// 8
	ss << to_string(auth) << endl;

	ss << address << endl;			// 5
	ss << inoutYM << endl;			// 9

	//入退館時刻についても同じく配列部分繰り返して
	for (int i = 0; i < inTime.size(); i++) {
		//その時の配列の値を格納する
		ss << inTime[i] << endl;
	}

	ss << "end intime" << endl;

	for (int i = 0; i < outTime.size(); i++) {
		ss << outTime[i] << endl;
	}

	//ストリームを文字列に変えて返却する
	return ss.str();
}

/*
関数名:makeDataForCard
概要:メンバからカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
CardData* DataManager::makeDataForCard()
{
	//今回使用する8セクター分のデータを格納するカードデータを用意
	CardData* carddata = new CardData(9);

	makeIdDataForCard(carddata);
	makeNameDataForCard(carddata);
	makePassDataForCard(carddata);
	makeTellDataForCard(carddata);
	makeBirthDataForCard(carddata);
	makeParameterDataForCard(carddata);
	makeAddressDataForCard(carddata);
	makeInTimeDataForCard(carddata);
	makeOutTimeDataForCard(carddata);

	//作成した書き込みたいカードデータを返却する
	return carddata;
}

/*
関数名:makeIdDataForCard
概要:ユーザーIDからカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeIdDataForCard(CardData * card)
{
	//ユーザーのIDを文字列で
	const char* id = userId.c_str();
	int len = strlen(id);
	//ユーザーIDをカードへセットする
	setDataForCardData(card, DataMConstants.userIdSectorNum, DataMConstants.userIdBlockNum, DataMConstants.userIdStartByteNum, (BYTE*)id, len);
}

/*
関数名:makeNameDataForCard
概要:名前からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeNameDataForCard(CardData * card)
{
	//苗字をバイト配列に直す
	const char* firstname = userFirstName.c_str();
	int len = strlen(firstname);
	//苗字をカードのデータへセットする
	setDataForCardData(card, DataMConstants.firstNameSectorNum, DataMConstants.firstNameBlockNum, DataMConstants.firstNameStartByteNum, (BYTE*)firstname, len);
	//
	const char* lastname = userLastName.c_str();
	len = strlen(lastname);
	//
	setDataForCardData(card, DataMConstants.lastNameSectorNum, DataMConstants.lastNameBlockNum, DataMConstants.lastNameStartByteNum, (BYTE*)lastname, len);
}

/*
関数名:makePassDataForCard
概要:パスワードからカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makePassDataForCard(CardData * card)
{
	const char* pass = password.c_str();
	int len = strlen(pass);

	setDataForCardData(card, DataMConstants.passSectorNum, DataMConstants.passBlockNum, DataMConstants.passStartByteNum, (BYTE*)pass, len);
}

/*
関数名:makeTellDataForCard
概要:電話番号からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeTellDataForCard(CardData * card)
{
	const char* tel = telNo.c_str();
	int len = strlen(tel);

	setDataForCardData(card, DataMConstants.tellSectorNum, DataMConstants.tellBlockNum, DataMConstants.tellStartByteNum, (BYTE*)tel, len);
}

/*
関数名:makeBirthdayDataForCard
概要:生年月日からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeBirthDataForCard(CardData * card)
{
	char birth[4];
	memcpy(birth, &birthday, sizeof(int));

	setDataForCardData(card, DataMConstants.birthdaySectorNum, DataMConstants.birthdayBlockNum, DataMConstants.birthdayStartByteNum, (BYTE*)birth, sizeof(int));
}

/*
関数名:makeParameterDataForCard
概要:メンバからカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeParameterDataForCard(CardData * card)
{
	char para[4];
	para[0] = chara;
	para[1] = auth;
	para[2] = cast;
	para[3] = group;

	setDataForCardData(card, DataMConstants.parameterSectorNum, DataMConstants.parameterBlockNum, DataMConstants.parameterStartByteNum, (BYTE*)para, sizeof(int));
}

/*
関数名:makeAddressDataForCard
概要:住所からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeAddressDataForCard(CardData * card)
{
	const char* addr = address.c_str();
	int len = strlen(addr);

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k++) {
				if (len > i * 48 + j * 16 + k) {
					card->sector[2 + i]->RWBlock[j][k] = addr[i * 48 + j * 16 + k];
				}
				else {
					card->sector[2 + i]->RWBlock[j][k] = '\0';
				}
			}
		}
	}

}

/*
関数名:makeInTimeDataForCard
概要:入館時間からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeInTimeDataForCard(CardData * card)
{
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &inoutYM, sizeof(short));
	setDataForCardData(card, 4, 0, 0, (BYTE*)tempbuf, sizeof(short));

	int len = this->inTime.size();
	for (int i = 1; i < len + 1; i++) {
		short temp = inTime[i - 1];
		memcpy(tempbuf, &temp, sizeof(short));

		setDataForCardData(card, i / 24 + 4, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}


}

/*
関数名:makeOutTimeDataForCard
概要:退館時間からカードに書き込むデータを作成する
引数:無し
返却値:CardData
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::makeOutTimeDataForCard(CardData * card)
{

	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &inoutYM, sizeof(short));
	setDataForCardData(card, 6, 0, 0, (BYTE*)tempbuf, sizeof(short));

	int len = this->outTime.size();
	for (int i = 1; i < len + 1; i++) {
		short temp = outTime[i - 1];
		memcpy(tempbuf, &temp, sizeof(short));

		setDataForCardData(card, i / 24 + 6, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}
}

/*
関数名
引数:CardData* card カード
	:int sector　セクター
	:int block　ブロック
	:int fromByte　何バイト目からか
	:Byte* data　格納したいデータ
	:int len 何バイト分か
*/
void DataManager::setDataForCardData(CardData * card, int sector, int block, int fromByte, BYTE * data, int dataLen)
{
	//引数のバイトから
	for (int i = 0; i < dataLen; i++) {
		//
		card->sector[sector]->RWBlock[block][fromByte + i] = data[i];
	}
}

/*
関数名:applyData
概要:カードから読み取ったデータを適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyData(CardData * carddata)
{
	applyUserID(carddata);
	applyUserName(carddata);
	////パスワードを適用させる
	applyPassword(carddata);
	///電話番号
	applyTelNoData(carddata);
	applyBirthday(carddata);
	applyParameter(carddata);
	////住所
	applyAddressData(carddata);
	////読みこんだデータを入退館時間の配列に直す
	applyInoutYM(carddata);
	applyInTime(carddata);
	applyOutTime(carddata);
}


/*
関数名:applyUserID
概要:カードから読み取ったユーザーID適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyUserID(CardData * carddata)
{
	userId = (char*)carddata->sector[0]->RWBlock[0];
}

/*
関数名:applyUserName
概要:カードから読み取ったユーザー名を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyUserName(CardData * carddata)
{
	userLastName = (char*)carddata->sector[0]->RWBlock[1];
	userFirstName = (char*)carddata->sector[0]->RWBlock[2];
}

/*
関数名:applyPassword
概要:カードから読み取ったパスワードを適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyPassword(CardData * carddata)
{
	password = (char*)carddata->sector[1]->RWBlock[0];
}

/*
関数名:applyTelNoData
概要:カードから読み取ったパスワードを適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyTelNoData(CardData * carddata)
{
	telNo = (char*)carddata->sector[1]->RWBlock[1];
}

/*
関数名:applyBirthday
概要:カードから読み取った生年月日を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyBirthday(CardData * carddata)
{
	char temp[sizeof(int)];
	for (int i = 0; i < sizeof(int); i++) {
		temp[i] = carddata->sector[1]->RWBlock[2][i];
	}
	memcpy(&birthday, temp, sizeof(int));
}

/*
関数名:applyParameter
概要:カードから読み取ったパラメータを適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyParameter(CardData * carddata)
{
	char temp[4];
	for (int i = 0; i < 4; i++) {
		temp[i] = carddata->sector[1]->RWBlock[2][i + 4];
	}

	chara = temp[0];
	auth = temp[1];
	cast = temp[2];
	group = temp[3];
}

/*
関数名:applyAddressData
概要:カードから読み取った住所を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyAddressData(CardData * carddata)
{
	char addr[96] = { 0x00 };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			if ('\0' != carddata->sector[i]->RWBlock[j]) {
				for (int k = 0; k < 16; k++) {
					addr[i * 48 + j * 16 + k] = (char)carddata->sector[i + 2]->RWBlock[j][k];
				}
			}
		}
	}
	address = addr;
}

/*
関数名:applyInoutYM
概要:カードから読み取った入館の年月を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyInoutYM(CardData * carddata)
{
	char temp[sizeof(short)];
	temp[0] = carddata->sector[4]->RWBlock[0][0];
	temp[1] = carddata->sector[4]->RWBlock[0][1];

	memcpy(&inoutYM, temp, sizeof(short));
}

/*
関数名:applyInTime
概要:カードから読み取った入館情報を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyInTime(CardData * carddata)
{
	char temp[sizeof(short)];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k += 2) {
				if (i != 0 || j != 0 || k != 0) {
					temp[0] = carddata->sector[i + 4]->RWBlock[j][k];
					temp[1] = carddata->sector[i + 4]->RWBlock[j][k + 1];
					if (temp[0] != '\0' && temp[1] != '\0') {
						short dayintime;
						memcpy(&dayintime, temp, sizeof(short));

						inTime.push_back(dayintime);
					}
					else {
						return;
					}
				}
			}
		}
	}
}

/*
関数名:applyOutTime
概要:カードから読み取った退館時間を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyOutTime(CardData * carddata)
{
	char temp[sizeof(short)];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 16; k+=2) {
				if (i != 0 || j != 0 || k != 0) {
					temp[0] = carddata->sector[i + 6]->RWBlock[j][k];
					temp[1] = carddata->sector[i + 6]->RWBlock[j][k+1];

					if (temp[0] != '\0' && temp[1] != '\0') {
						short dayouttime;
						memcpy(&dayouttime, temp, sizeof(short));

						outTime.push_back(dayouttime);
					}
					else {
						return;
					}
				}
			}
		}
	}
}

/*
関数名:set
概要:人物のパラメータをコンボボックスの選ばれたインデックスでセットする
引数:int select
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::setChara(int select)
{
	if (select > 0) {
		chara = (0x01 << (select - 1));
	}
}

/*
関数名:set
概要:人物のパラメータをコンボボックスの選ばれたインデックスでセットする
引数:int select
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::setAuth(int select)
{
	if (select > 0) {
		auth = (0x01 << (select - 1));
	}
}

/*
関数名:set
概要:人物のパラメータをコンボボックスの選ばれたインデックスでセットする
引数:int select
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::setCast(int select)
{
	if (select > 0) {
		cast = (0x01 << (select - 1));
	}
}

/*
関数名:set
概要:人物のパラメータをコンボボックスの選ばれたインデックスでセットする
引数:int select
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::setAffli(int select)
{
	group |= (0x01 << select);
}

/*
関数名:set
概要:人物のパラメータをコンボボックスの選ばれたインデックスでセットする
引数:int select
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::setGroup(int select)
{
	group |= (0x01 << (select + 4));
}

/*
関数名:getSelected
概要:人物のパラメータのコンボボックスの選ばれたインデックスを返す
引数:無し
返却値:int インデックス
作成日:10月19日(木)
作成者:成田修之
*/
int DataManager::getSelectedChara()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (chara & (0x01 << i)) {
			retval = i + 1;
		}
	}
	return retval;
}

/*
関数名:getSelected
概要:人物のパラメータのコンボボックスの選ばれたインデックスを返す
引数:無し
返却値:int インデックス
作成日:10月19日(木)
作成者:成田修之
*/
int DataManager::getSelectedAuth()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (auth & (0x01 << i)) {
			retval = i + 1;
		}
	}

	return retval;
}

/*
関数名:getSelected
概要:人物のパラメータのコンボボックスの選ばれたインデックスを返す
引数:無し
返却値:int インデックス
作成日:10月19日(木)
作成者:成田修之
*/
int DataManager::getSelectedCast()
{
	int retval = 0;

	for (int i = 0; i < 8; i++) {
		if (cast & (0x01 << i)) {
			retval = i + 1;
		}
	}
	return retval;
}

/*
関数名:getSelected
概要:人物のパラメータのコンボボックスの選ばれたインデックスを返す
引数:無し
返却値:int インデックス
作成日:10月19日(木)
作成者:成田修之
*/
int DataManager::getSelectedAffli()
{
	int retval = 0;

	for (int i = 0; i < 4; i++) {
		if (group & (0x01 << i)) {
			retval = i;
		}
	}

	return retval;
}

/*
関数名:getSelected
概要:人物のパラメータのコンボボックスの選ばれたインデックスを返す
引数:無し
返却値:int インデックス
作成日:10月19日(木)
作成者:成田修之
*/
int DataManager::getSelectedGroup()
{
	int retval = 0;

	for (int i = 4; i < 8; i++) {
		if (group & (0x01 << i)) {
			retval = i - 4;
		}
	}


	return retval;
}

/*
関数名:getInoutY
概要:入退館の
引数:int 入退館の年
返却値:無し
作成日:10月20日(金)
作成者:成田修之
*/
int DataManager::getInoutY()
{
	//
	return inoutYM / 12;
}

/*
関数名:getInoutY
概要:入退館の
引数:int 入退館の年
返却値:無し
作成日:10月20日(金)
作成者:成田修之
*/
int DataManager::getInoutM()
{
	int month = inoutYM % 12;
	if (month == 0) {
		month = 12;
	}

	//
	return month;
}

void DataManager::applyFileData(vector<string> fileData)
{
	//1行目をユーザーIDに
	userId = fileData[0];
	//2行目を誕生日に
	userFirstName = fileData[1];
	//3行目を名前に
	userLastName = fileData[2];
	//4行目を電話に
	password = fileData[3];
	//5行目を住所に
	telNo = fileData[4];
	//6行目を所属に
	birthday = stoi(fileData[5]);
	//7行目を役職に
	group = stoi(fileData[6]);
	//8行目を属性に
	cast = stoi(fileData[7]);
	//9行目を入退の年月に
	chara = stoi(fileData[8]);
	//10行目をパスワードに
	auth = stoi(fileData[9]);
	//住所を適用
	address = fileData[10];
	//入退館の年月を適用
	inoutYM = stoi(fileData[11]);

	int i;

	//10行目から先をすべて
	for (i = 12; i < fileData.size(); i++) {
		if (fileData[i] == "end intime") {
			i++;
			break;
		}
		//メンバに後ろから追加していく
		inTime.push_back(stoi(fileData[i]));
	}

	for (; i < fileData.size(); i++) {
		outTime.push_back(stoi(fileData[i]));
	}


}

void DataManager::clear()
{
	card.clear();
}

