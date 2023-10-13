#include "CharToSevenSegmentBitArrayMapper.h"
#include "core/ConfigFileReader.h"

#include <filesystem>

namespace 
{
	constexpr auto CONFIG_FILE = "SevenSegmentDisplayCharacterToBitArrayMapping.txt";
	constexpr auto NUMBER_OF_BITS_IN_7_SEGMENT_DU = 8u;
}

CCharToSevenSegmentBitArrayMapper::CCharToSevenSegmentBitArrayMapper(const std::string& mappingFile)
{
	populateCharToBitArrayMap(mappingFile);
}

CCharToSevenSegmentBitArrayMapper::~CCharToSevenSegmentBitArrayMapper() {}

void CCharToSevenSegmentBitArrayMapper::populateCharToBitArrayMap(const std::string& mappingFile)
{
	if (!mappingFile.empty() && std::filesystem::exists(mappingFile))
	{
		CConfigFileReader configFileReader;
		std::map<std::string, std::string> bitPositionKeysDataMap;
		configFileReader.readConfigFile(mappingFile, bitPositionKeysDataMap);

		for (const auto& [key, value] : bitPositionKeysDataMap)
		{
			if (!key.empty() && (key.size() == sizeof(char)) &&
				!value.empty() && (value.size() == NUMBER_OF_BITS_IN_7_SEGMENT_DU))
			{
				std::vector<unsigned char> bitArray;
				bitArray.insert(bitArray.begin(), value.begin(), value.end());

				m_CharToBitArrayMap[key.front()] = bitArray;
			}
		}
	}
}

bool CCharToSevenSegmentBitArrayMapper::getBitArrayForChar(const unsigned char& character, std::vector<unsigned char>& bitArray) const
{
	bool bReturnValue = false;
	bitArray.clear(); 

	auto pDataIterator = m_CharToBitArrayMap.find(character);
	if (pDataIterator != m_CharToBitArrayMap.end())
	{
		bitArray = pDataIterator->second;
		bReturnValue = true;
	}
	return bReturnValue;
}