#include "InoutDay.h"



InoutDay::InoutDay()
{
	//全メンバを0で初期化する
	day = 0;
	hour = 0;
	minute = 0;
}


InoutDay::~InoutDay()
{
}

short InoutDay::toSHRT()
{
	//日にちをすべて分に直したいにして格納する
	short dayToMinute;
	//日、時間を分に直して足す
	dayToMinute += minute + (hour * 60) + (day * 60 * 24);
	//その値を返却する
	return dayToMinute;
}

void InoutDay::apply(short shrt)
{
	//引数の分の値を一日にかかる分で割ってその日にちを取得する
	day = shrt / 24 / 60;
	//時間を日の分を引いた値から計算する
	hour = (shrt - day * 24 * 60) / 60;
	//分は日と時間でかかった分を引いたもの
	minute = shrt - (day * 24 * 60) - (hour * 60);
}
