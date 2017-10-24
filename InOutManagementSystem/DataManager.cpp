#include "DataManager.h"
#include <sstream>

using namespace std;
using namespace boost::property_tree;

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
	this->currentInout = 0;
	this->userFirstName = "";
	this->userLastName = "";
	this->address = "";
	this->group = 0;
	this->cast = 0;
	this->chara = 0;
	this->auth = 0;
	this->password = "";
	this->inTime = vector<InoutDay>(31);
	this->outTime = vector<InoutDay>(31);
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


/*
関数名:readFileData
概要:ファイルからデータを読み取ってメンバに適用させる
引数:なし
返却値:なし
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::readFileData()
{
	//ファイルのデータを読み込んでメンバのファイル情報を保管する変数に格納
	file.readFileData(userId, fileData);
	//読みこんだデータをメンバに適用させる
	applyFileData(fileData);
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

//カードへと書き込む
void DataManager::writeCard()
{
	//カードへと書き込むデータを作成して書き込む
	card.writeCard(makeDataForCard());
}

//ファイル用のデータを作成(追加)してファイルへと書き込む
void DataManager::writeFile()
{
	//ファイル用のデータを作成する
	makeDataForFile();
	//作成したデータをファイルへと書き込む
	file.writeData(userId, fileData);
}

/*
関数名:
概要:
引数:なし
返却値:string 
作成日:10月16日(月)
作成者:成田修之
*/
void DataManager::makeDataForFile()
{
	


}

/*
関数名:applyFileData
概要:メンバに取得したファイルのデータをほかのメンバに適用させる
引数:property_tree fileData ファイルからのデータ
返却値:無し
作成日:10月24日(火)
作成者:成田修之
*/
void DataManager::applyFileData(boost::property_tree::ptree fileData)
{
	//ユーザーIDを適用
	userId = fileData.get_value("userId");
	//苗字を適用
	userLastName = fileData.get_value("userLastName");
	//名前を適用
	userFirstName = fileData.get_value("userFirstName");
	//パスワードを適用
	password = fileData.get_value("password");
	//電話番号を適用
	telNo = fileData.get_value("telNo");
	//誕生日を数値に変換して格納する
	birthday = stoi(fileData.get_value("birthday"));
	//人物の値を数値に変えて適用
	chara = stoi(fileData.get_value("character"));
	//権限の値を数値に変えて適用
	auth = stoi(fileData.get_value("auth"));
	//役職の値を数値に変えて適用
	cast = stoi(fileData.get_value("cast"));
	//所属の値を数値に変えて適用
	group = stoi(fileData.get_value("group"));
	//住所を適用
	address = fileData.get_value("address");
	//カレントの入退館日の値を数値に変えて適用
	currentInout = stoi(fileData.get_value("currentInout"));

}

/*
関数名:applyFileInData
概要:メンバに取得したファイルの入館データをメンバに適用させる
引数:property_tree fileData ファイルからのデータ
返却値:無し
作成日:10月24日(火)
作成者:成田修之
*/
void DataManager::applyFileIndata(boost::property_tree::ptree fileData)
{
	ptree inData = fileData.get_child("in");


}

/*
関数名:applyFileData
概要:メンバに取得したファイルの退館データをメンバに適用させる
引数:property_tree fileData ファイルからのデータ
返却値:無し
作成日:10月24日(火)
作成者:成田修之
*/
void DataManager::applyFileOutdata(boost::property_tree::ptree fileData)
{
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

	//idをカードのデータへ格納する
	makeIdDataForCard(carddata);
	//名前をカードのデータへ格納する
	makeNameDataForCard(carddata);
	//パスワードをカードのデータへ格納する
	makePassDataForCard(carddata);
	//電話番号をカードのデータへ格納する
	makeTellDataForCard(carddata);
	//誕生日をカードのデータへ格納する
	makeBirthDataForCard(carddata);
	//パラメータをカードのデータへ格納する
	makeParameterDataForCard(carddata);
	//住所をカードのデータへ格納する
	makeAddressDataForCard(carddata);
	//入館時間をカードのデータへ格納する
	makeInTimeDataForCard(carddata);
	//退館時間をカードのデータへ格納する
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
	//名前をバイト配列に直す
	const char* lastname = userLastName.c_str();
	len = strlen(lastname);
	//名前をカードのデータをセットする
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
	//パスワードをバイト配列に直す
	const char* pass = password.c_str();
	int len = strlen(pass);
	//パスワードをカードのデータにセットする
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
	//電話番号をバイト配列に
	const char* tel = telNo.c_str();
	int len = strlen(tel);
	//電話番号をカードのデータにセットする
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
	//誕生日をバイト配列に
	char birth[4];
	memcpy(birth, &birthday, sizeof(int));
	//誕生日をカードのデータにセットする
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
	//パラメータを一つにまとめてバイト配列に
	char para[4];
	para[0] = chara;
	para[1] = auth;
	para[2] = cast;
	para[3] = group;
	//パラメータをカードのデータにセットする
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
	//住所をバイト配列に直す
	const char* addr = address.c_str();
	int len = strlen(addr);

	//住所に割り当てられた2セクター分繰り返す
	for (int i = 0; i < 2; i++) {
		//セクター内のブロック数だけ繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			///ブロック内のバイト数分だけ繰り返す
			for (int k = 0; k < BLOCK_BYTE; k++) {
				//その位置が取得した住所の長さより短ければ
				if (len > i * SECTOR_BLOCK_NUM * BLOCK_BYTE + j * BLOCK_BYTE + k) {
					//その時のバイト配列の値を格納する
					card->sector[DataMConstants.addressSectorNum + i]->RWBlock[j][k] = addr[i * SECTOR_BLOCK_NUM* BLOCK_BYTE + j * BLOCK_BYTE + k];
				}
				//長い時
				else {
					//終端文字を格納する
					card->sector[DataMConstants.addressSectorNum + i]->RWBlock[j][k] = '\0';
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
	//入退館の年月をバイト配列へ直す
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &currentInout, sizeof(short));
	//カードのデータに
	setDataForCardData(card, DataMConstants.inTimeSectorNum, DataMConstants.inTimeBlockNum, DataMConstants.inTimeStartByteNum, (BYTE*)tempbuf, sizeof(short));

	//入館時間のデータの長さを取得する
	int len = this->inTime.size();
	//その長さ分だけ繰り返す
	for (int i = 1; i < len + 1; i++) {
		//上から順にその時間を取得する
		short temp = inTime[i - 1].toSHRT();
		//用意したバイト配列に直す
		memcpy(tempbuf, &temp, sizeof(short));
		//入退時間のバイト配列をセットする(処理は最初の2バイト分は入退館の年月のため)
		setDataForCardData(card, i / 24 + DataMConstants.inTimeSectorNum, (i / 8) % SECTOR_BLOCK_NUM, i * 2 % BLOCK_BYTE, (BYTE*)tempbuf, sizeof(short));
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
	//バイト配列を用意して入退館の年月をそのバイト配列に格納する
	char tempbuf[sizeof(short)];
	memcpy(tempbuf, &currentInout, sizeof(short));
	//そのデータを格納する
	setDataForCardData(card, DataMConstants.inoutTimeSectorNum, DataMConstants.inoutTimeBlockNum, DataMConstants.inoutTimeStartByteNum, (BYTE*)tempbuf, sizeof(short));

	//退館時間の長さを取得する
	int len = this->outTime.size();
	//退館時間の長さ分だけ繰り返す
	for (int i = 1; i < len + 1; i++) {
		//その位置の退館時間を取得する
		short temp = outTime[i - 1].toSHRT();
		memcpy(tempbuf, &temp, sizeof(short));
		//そのデータをカードのデータに格納する
		setDataForCardData(card, i / 24 + DataMConstants.outTimeSectorNum, (i / 8) % 3, i * 2 % 16, (BYTE*)tempbuf, sizeof(short));
	}
}

/*
関数名:setDataForCardData
概要:第一引数に受け取ったカードのデータの引数の位置にデータを格納する
引数:CardData* card カード
	:int sector　セクター
	:int block　ブロック
	:int fromByte　何バイト目からか
	:Byte* data　格納したいデータ
	:int len 何バイト分か
返却値:なし
作成日:10月20日(金)
作成者:成田修之
*/
void DataManager::setDataForCardData(CardData * card, int sector, int block, int fromByte, BYTE * data, int dataLen)
{
	//引数のバイトから
	for (int i = 0; i < dataLen; i++) {
		//引数番目のセクター内で、引数のブロックの中の引数の値の位置から始まる位置にデータを格納していく
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
	//ユーザーidを指定の格納された箇所から取得
	char temp[17] = { 0x00 };
	//苗字を指定の位置から取得する
	strncpy(temp, (char*)carddata->sector[DataMConstants.userIdSectorNum]->RWBlock[DataMConstants.userIdBlockNum], 16);
	userId = temp;
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
	char temp[17] = {0x00};
	//苗字を指定の位置から取得する
	strncpy(temp, (char*)carddata->sector[DataMConstants.lastNameSectorNum]->RWBlock[DataMConstants.lastNameBlockNum], 16);
	userLastName = temp;

	//名前も同じく指定の位置から取得する
	strncpy(temp, (char*)carddata->sector[DataMConstants.firstNameSectorNum]->RWBlock[DataMConstants.firstNameBlockNum], 16);
	userFirstName = temp;
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
	char temp[17] = { 0x00 };
	//パスワードを指定の位置から取得する
	strncpy(temp, (char*)carddata->sector[DataMConstants.passSectorNum]->RWBlock[DataMConstants.passBlockNum], 16);
	password = temp;
}

/*
関数名:applyTelNoData
概要:カードから読み取った電話番号を適用させる
引数:CardData カードのデータ
返却値:無し
作成日:10月19日(木)
作成者:成田修之
*/
void DataManager::applyTelNoData(CardData * carddata)
{
	//電話番号を指定の位置から取得して格納する
	telNo = (char*)carddata->sector[DataMConstants.tellSectorNum]->RWBlock[DataMConstants.tellSectorNum];
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
	//誕生日を取得するバッファを用意する
	char temp[sizeof(int)];
	//intのサイズ分だけ繰り返す
	for (int i = 0; i < sizeof(int); i++) {
		//格納された位置から取得していく
		temp[i] = carddata->sector[DataMConstants.birthdaySectorNum]->RWBlock[DataMConstants.birthdayBlockNum][i];
	}
	//誕生日に取得したバイト配列を格納する
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
	//パラメータを格納するバイト配列をパラメータ数の4バイト分用意する
	char temp[4];
	//パラメータの数だけ繰り返す
	for (int i = 0; i < 4; i++) {
		//指定の位置から順に取得していく
		temp[i] = carddata->sector[DataMConstants.parameterSectorNum]->RWBlock[DataMConstants.parameterBlockNum][i + DataMConstants.parameterStartByteNum];
	}

	//位置バイト目の人物を取得する
	chara = temp[0];
	//2バイト目の権限を取得する
	auth = temp[1];
	//3バイト目の役職を取得する
	cast = temp[2];
	//4バイト目の所属を取得する
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
	//2セクター分のバイト配列を用意する
	char addr[SECTOR_BLOCK_NUM * BLOCK_BYTE * 2 + 1] = { 0x00 };

	//セクター数分だけ繰り返す
	for (int i = 0; i < 2; i++) {
		//セクター内のブロック数だけ繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//先頭が終端を示していなければ
			if ('\0' != carddata->sector[i]->RWBlock[j]) {
				//
				for (int k = 0; k < BLOCK_BYTE; k++) {
					//
					addr[i * 48 + j * 16 + k] = (char)carddata->sector[i + 2]->RWBlock[j][k];
				}
			}
			//
			else {
				break;
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

	memcpy(&currentInout, temp, sizeof(short));
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
	//short型の2バイト分を格納する変数を用意
	char temp[sizeof(short)];

	//入館に与えられた2セクター分繰り返す
	for (int i = 0; i < 2; i++) {
		//セクター内の3ブロック分繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロック内のバイト数分繰り返す
			for (int k = 0; k < BLOCK_BYTE; k += 2) {
				//一番最初でなければ(最初はカレントの年月が格納されている)
				if (i != 0 || j != 0 || k != 0) {
					//1バイト目を取得する
					temp[0] = carddata->sector[i + 4]->RWBlock[j][k];
					//2バイト目を取得する
					temp[1] = carddata->sector[i + 4]->RWBlock[j][k + 1];
					//どちらでも格納されている値が存在する
					if (temp[0] != '\0' && temp[1] != '\0') {
						//short型にする変数を用意
						short dayintime;
						//格納した2バイトをshort型変数にコピー
						memcpy(&dayintime, temp, sizeof(short));
						//short型の値を格納する
						inTime[i * 24 + j * 8 + k].apply(dayintime);
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
	//short型の2バイト分を格納する変数を用意
	char temp[sizeof(short)];

	//退館に与えられた2セクター分繰り返す
	for (int i = 0; i < 2; i++) {
		//セクター内の3ブロック分繰り返す
		for (int j = 0; j < SECTOR_BLOCK_NUM; j++) {
			//ブロック内のバイト数分繰り返す
			for (int k = 0; k < BLOCK_BYTE; k += 2) {
				//一番最初でなければ(最初はカレントの年月が格納されている)
				if (i != 0 || j != 0 || k != 0) {
					//1バイト目を取得する
					temp[0] = carddata->sector[i + DataMConstants.outTimeSectorNum]->RWBlock[j][k];
					//2バイト目を取得する
					temp[1] = carddata->sector[i + DataMConstants.outTimeSectorNum]->RWBlock[j][k + 1];
					//どちらでも格納されている値が存在する
					if (temp[0] != '\0' && temp[1] != '\0') {
						//short型にする変数を用意
						short dayintime;
						//格納した2バイトをshort型変数にコピー
						memcpy(&dayintime, temp, sizeof(short));
						//short型の値を格納する
						outTime[i * 24 + j * 8 + k].apply(dayintime);
					}
				}
			}
		}
	}
}

/*
関数名:setChara
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
	return currentInout / 12;
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
	int month = currentInout % 12;
	if (month == 0) {
		month = 12;
	}

	//
	return month;
}


void DataManager::clear()
{
	card.clear();
}

