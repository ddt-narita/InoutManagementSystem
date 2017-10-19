#include "FileRW.h"
#include <fstream>

using namespace std;

FileRW::FileRW()
{
}


FileRW::~FileRW()
{
}

void FileRW::writeData(int id, std::string data)
{
	string filename = to_string(id) + ".txt";
	//出力ストリームを用意
	ofstream ofs;
	//idを文字列に変えてそのIDでファイルを開く
	ofs.open(filename);

	//オープンできなかったとき
	if (!ofs) {
		//メッセージを添えて例外を送出する
		throw exception("データ保持用のファイルが開けませんでした。");
	}
	 
	//ファイルに引数のデータを出力する
	ofs << data;
	//ファイルを閉じる
	ofs.close();
}

/*
関数名:readFileData
概要:ファイルからデータを読み取る
引数:int id  データを取得したい人のID
	vector<string> recvData　取得したデータを格納するための配列　
返却値:無し
作成日:10月18日(水)
作成者:成田修之
*/
vector<string> FileRW::readFileData(int id)
{
	vector<string> recvData;
	//引数のidからファイル名を作製する
	string fileName = to_string(id) + ".txt";
	//ファイルの入力ストリームを生成する
	ifstream ifs;
	//ファイル名でファイルを開く
	ifs.open(fileName);

	//引数の格納先のファイルをクリアしておく
	recvData.clear();
	//一行ごとのデータを格納するためのバッファを取得する
	string buff;
	//一行ごとに読みこむを行う
	while (std::getline(ifs, buff)) {
		//読みこんだ一行のデータを受け取った配列の後ろへと追加していく
		recvData.push_back(buff);
	}
	ifs.close();

	return recvData;
}

bool FileRW::checkId(int id)
{
	//判定用の変数
	int judge = 0;
	//引数のIDを文字列に変換
	string filename = to_string(id) + ".txt";
	//ファイル入力ストリームを生成
	ifstream ifs;
	//ファイルを開く
	ifs.open(filename);

	//判定用の変数
	string check;
	//一行目を読み込む
	getline(ifs,check);

	//文字列が読みこめている
	if ("" != check) {
		//trueを示す値を格納する
		judge = 1;
	}

	//判定を返却する
	return 1 == judge;
}
