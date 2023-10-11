#pragma once

#include "IAssetIDCharToNumberMapper.h"

class CAssetIDDecimalCharToNumberMapper  : public IAssetIDCharToNumberMapper
{
public:
	CAssetIDDecimalCharToNumberMapper();
	virtual ~CAssetIDDecimalCharToNumberMapper();

	virtual unsigned int getNumberForSpecifiedChar(const char& assetIDCharacter) const;
	virtual char getCharForSpecifiedNumber(const unsigned int& number) const;
};