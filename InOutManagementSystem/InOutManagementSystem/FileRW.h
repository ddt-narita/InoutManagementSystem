#pragma once

#include <string>
#include <vector>

class FileRW
{
public:
	FileRW();
	~FileRW();

	void writeData(std::string id, std::string data);
	std::vector<std::string> readFileData(std::string id);
	bool checkId(std::string id);

};

