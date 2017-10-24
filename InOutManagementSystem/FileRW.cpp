#include "FileRW.h"
#include <fstream>

using namespace std;
using namespace boost::property_tree;

FileRW::FileRW()
{
}


FileRW::~FileRW()
{
}

void FileRW::writeData(std::string id, boost::property_tree::ptree tree)
{
	//json書き込みのtry catch
	try {
		//IDからファイル名を作成する
		string filename = id + ".txt";
		//作成したファイル名のファイルに受け取ったjsonデータを書き込む
		write_json(filename, tree);
	}
	//書き込みで例外が発生したとき
	catch (...) {
		//書き込みに失敗したことを例外で通知
		throw exception("ファイルへのデータ書き込みができませんでした。");
	}

}

void FileRW::readFileData(std::string id, boost::property_tree::ptree recvTree)
{
	//json読み込みのtry catch
	try {
		//引数のIDからファイル名を作成する
		string filename = id + ".txt";
		//ファイル名のファイルのjsonデータを引数のjsonオブジェクトで受け取る
		read_json(filename, recvTree);
	}
	//json読み込みのtry catch
	catch (...) {
		//idのファイル読み込みができなかったことを通知
		throw exception(("PC上のid: "+ id +"\nのファイルのデータが読み取れませんでした。").c_str());
	}
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
vector<string> FileRW::readFileData(string id)
{
	vector<string> recvData;
	//引数のidからファイル名を作製する
	string fileName = id + ".txt";
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

bool FileRW::checkId(string id)
{
	//判定用の変数
	int judge = 0;
	//引数のIDを文字列に変換
	string filename = id + ".txt";
	//ファイル入力ストリームを生成
	ifstream ifs;
	//ファイルを開く
	ifs.open(filename);

	if (!ifs) {
		judge = 0;
		return false;
	}

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
