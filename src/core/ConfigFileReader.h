#pragma once

#include <string>
#include <map>

class CConfigFileReader
{
public:
	CConfigFileReader();
	~CConfigFileReader();

	void readConfigFile(const std::string& configFile, std::map<std::string, std::string>& configFileDataMap) const;
};
