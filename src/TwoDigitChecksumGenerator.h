#pragma once

#include "IChecksumGenerator.h"

class CTwoDigitChecksumGenerator : public IChecksumGenerator
{
public:
	CTwoDigitChecksumGenerator(const unsigned int& checksumBase);
	virtual ~CTwoDigitChecksumGenerator();

	virtual void setChecksumBase(const unsigned int& checksumBase);
	virtual const unsigned int& getChecksumBase() const;
	virtual void generateChecksumForNumber(const unsigned int& number, const unsigned int& minimumNumberOfDigits, unsigned int& checksum) const;
	virtual void generateChecksumForDigitsOfNumber(const std::vector<unsigned int>& digitsOfNumber, unsigned int& checksum) const;
	virtual void generateChecksumAndGetDigitsOfTheChecksummedCode(const unsigned int& number, const unsigned int& minimumNumberOfDigits, const unsigned int& minimumNumberOfDigitsInChecksum, std::vector<unsigned int>& digitsOfChecksummedCode) const;
	virtual void generateChecksumAndGetDigitsOfTheChecksummedCode(const std::vector<unsigned int>& digitsOfNumber, const unsigned int& minimumNumberOfDigitsInChecksum, std::vector<unsigned int>& digitsOfChecksummedCode) const;

private:
	const unsigned int m_MAX_TWO_DIGIT_NUMBER = 99;
	unsigned int m_ChecksumBase = m_MAX_TWO_DIGIT_NUMBER; //Defaulted to max two digit number
};