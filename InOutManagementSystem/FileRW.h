#pragma once

#include <string>
#include <vector>

class FileRW
{
public:
	FileRW();
	~FileRW();

	void writeData(int id, std::string data);
	std::vector<std::string> readFileData(int id);
	bool checkId(int id);

};

