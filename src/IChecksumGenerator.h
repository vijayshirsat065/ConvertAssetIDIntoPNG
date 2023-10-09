#pragma once

#include <vector>

class IChecksumGenerator
{
public:
	virtual ~IChecksumGenerator() {}

	virtual void setChecksumBase(const unsigned int& checksumBase) = 0;
	virtual const unsigned int& getChecksumBase() const = 0;
	virtual void generateChecksum(const std::vector<unsigned int>& reversedAssetIDDigits, unsigned int& checksum) const = 0;
	virtual void getChecksummedCodeInReverseOrder(const std::vector<unsigned int>& reversedAssetIDDigits, std::vector<unsigned int>& reversedChecksummedAssetIDDigits) const = 0;
};