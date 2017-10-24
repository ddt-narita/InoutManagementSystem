#pragma once
class InoutDay
{
public:
	int day;
	int hour;
	int minute;

public:
	InoutDay();
	~InoutDay();

	short toSHRT();
	void apply(short shrt);
};

