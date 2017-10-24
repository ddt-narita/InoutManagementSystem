#pragma once

#include <string>
#include <vector>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/optional.hpp>


class FileRW
{
public:
	FileRW();
	~FileRW();

	void writeData(std::string id, boost::property_tree::ptree tree);
	void readFileData(std::string id, boost::property_tree::ptree recvTree);
	bool checkId(std::string id);

};

