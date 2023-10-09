#pragma once

#include <vector>

class IChecksumGenerator
{
public:
	virtual ~IChecksumGenerator() {}

	virtual void setChecksumBase(const unsigned int& checksumBase) = 0;
	virtual const unsigned int& getChecksumBase() const = 0;
	virtual void generateChecksumForNumber(const unsigned int& number, const unsigned int& minimumNumberOfDigits, unsigned int& checksum) const = 0;
	virtual void generateChecksumForDigitsOfNumber(const std::vector<unsigned int>& digitsOfNumber, unsigned int& checksum) const = 0;
	virtual void generateChecksumAndGetDigitsOfTheChecksummedCode(const unsigned int& number, const unsigned int& minimumNumberOfDigits, const unsigned int& minimumNumberOfDigitsInChecksum, std::vector<unsigned int>& digitsOfChecksummedCode) const = 0;
	virtual void generateChecksumAndGetDigitsOfTheChecksummedCode(const std::vector<unsigned int>& digitsOfNumber, const unsigned int& minimumNumberOfDigitsInChecksum, std::vector<unsigned int>& digitsOfChecksummedCode) const = 0;
};