#pragma once

#include <vector>

class ICharToBitArrayMapper
{
public:
	virtual ~ICharToBitArrayMapper() {}

	virtual bool getBitArrayForChar(const unsigned char& character, std::vector<unsigned char>& bitArray) const = 0;
};