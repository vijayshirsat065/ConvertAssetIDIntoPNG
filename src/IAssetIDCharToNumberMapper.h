#pragma once

class IAssetIDCharToNumberMapper
{
public:
	virtual ~IAssetIDCharToNumberMapper() {}

	virtual unsigned int getNumberForSpecifiedChar(const char&  assetIDCharacter) const = 0;
	virtual char getCharForSpecifiedNumber(const unsigned int& number) const = 0;
};