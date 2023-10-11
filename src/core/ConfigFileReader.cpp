// ConfigFileReader.cpp : 
//

#include "ConfigFileReader.h"
#include "FileReader.h"

#include <filesystem>
#include <iostream>
#include <sstream>
#include <regex>

namespace 
{
	void trimWhitespaces(std::string& value)
	{
		value = std::regex_replace(value, std::regex("^ +| +$|( ) +"), "$1");
	}
}

CConfigFileReader::CConfigFileReader()
{
}

CConfigFileReader::~CConfigFileReader()
{
}

void CConfigFileReader::readConfigFile(const std::string& configFile, std::map<std::string, std::string>& configFileDataMap) const
{
	// Make sure the output variable doesn't contain any garbage values
	configFileDataMap.clear();

	if (std::filesystem::exists(configFile))
	{
		CFileReader fileReader(configFile);

		std::string line;
		std::string key;
		std::string value;
		while (std::getline(fileReader.getFileStreamInstance(), line))
		{
			key.clear();
			value.clear();
			std::istringstream is_line(line);

			try 
			{
				if (std::getline(is_line, key, '='))
				{
					if (!key.empty())
					{
						trimWhitespaces(key);
						if (std::getline(is_line, value))
						{
							if (!value.empty())
							{
								trimWhitespaces(value);
								configFileDataMap.emplace(key, value);
							}
						}
					}
				}
			}
			catch (const std::exception& e) 
			{
				std::cout << "Caught exception while reading file \"" << configFile << "\" - " << e.what() << "\"\n";
			}
		}
	}
	else
	{
		std::cout << "Failed to find config file '" << configFile << "'" << std::endl;
	}

}