#include "InoutDay.h"



InoutDay::InoutDay()
{
	//�S�����o��0�ŏ���������
	day = 0;
	hour = 0;
	minute = 0;
}


InoutDay::~InoutDay()
{
}

short InoutDay::toSHRT()
{
	//���ɂ������ׂĕ��ɒ��������ɂ��Ċi�[����
	short dayToMinute;
	//���A���Ԃ𕪂ɒ����đ���
	dayToMinute += minute + (hour * 60) + (day * 60 * 24);
	//���̒l��ԋp����
	return dayToMinute;
}

void InoutDay::apply(short shrt)
{
	//�����̕��̒l������ɂ����镪�Ŋ����Ă��̓��ɂ����擾����
	day = shrt / 24 / 60;
	//���Ԃ���̕����������l����v�Z����
	hour = (shrt - day * 24 * 60) / 60;
	//���͓��Ǝ��Ԃł���������������������
	minute = shrt - (day * 24 * 60) - (hour * 60);
}
