#pragma once

#include "IChecksumGenerator.h"

class CTwoDigitChecksumGenerator : public IChecksumGenerator
{
public:
	~CTwoDigitChecksumGenerator();

	virtual void setChecksumBase(const unsigned int& checksumBase);
	virtual const unsigned int& getChecksumBase() const;
	virtual void generateChecksum(const std::vector<unsigned int>& reversedAssetIDDigits, unsigned int& checksum) const;
	virtual void getChecksummedCodeInReverseOrder(const std::vector<unsigned int>& reversedAssetIDDigits, std::vector<unsigned int>& reversedChecksummedAssetIDDigits) const;

private:
	const unsigned int m_MAX_TWO_DIGIT_NUMBER = 99;
	unsigned int m_ChecksumBase = m_MAX_TWO_DIGIT_NUMBER; //Defaulted to max two digit number
};