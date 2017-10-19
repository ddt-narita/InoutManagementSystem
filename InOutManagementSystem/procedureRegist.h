#pragma once

#include "DataManager.h"

class procedureRegist
	:public DataManager
{
public:
	procedureRegist();
	~procedureRegist();

	void init();
	void registData();
	
};

