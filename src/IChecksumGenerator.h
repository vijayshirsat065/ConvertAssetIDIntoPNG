#pragma once

#include <vector>

class IChecksumGenerator
{
public:
	virtual ~IChecksumGenerator() {}

	virtual void setChecksumBase(const unsigned int& checksumBase) = 0;
	virtual const unsigned int& getChecksumBase() const = 0;
	virtual bool generateChecksumAndGetDigitsOfTheChecksummedCode(const std::vector<char>& assetID, std::vector<char>& checksummedAssetIDCode) const = 0;
};