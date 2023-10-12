#pragma once

#include "ICharToBitArrayMapper.h"

#include <string>
#include <map>

class CCharToSevenSegmentBitArrayMapper : public ICharToBitArrayMapper
{
public:
	CCharToSevenSegmentBitArrayMapper(const std::string& mappingFile);
	virtual ~CCharToSevenSegmentBitArrayMapper();

	virtual bool getBitArrayForChar(const unsigned char& character,  std::vector<unsigned char>& bitArray) const;

private:
	void populateCharToBitArrayMap(const std::string& mappingFile);

	std::map<unsigned char, std::vector<unsigned char> > m_CharToBitArrayMap;
};