// TwoDigitChecksumGenerator.cpp : Defines the logic for generating a two digit checksum
//

#include "TwoDigitChecksumGenerator.h"
#include "core/NumberConversion.h"

#include <numeric>
#include <cmath>

CTwoDigitChecksumGenerator::CTwoDigitChecksumGenerator(const unsigned int& checksumBase)
{
	// To prevent from using an invalid number
	setChecksumBase(checksumBase);
}

CTwoDigitChecksumGenerator::~CTwoDigitChecksumGenerator() {}

void CTwoDigitChecksumGenerator::setChecksumBase(const unsigned int& checksumBase)
{
	//Ensure the checksum base is not greater than the allowed max digit number and is not less than 1
	m_ChecksumBase = (checksumBase > 1 ? ((checksumBase > m_MAX_TWO_DIGIT_NUMBER) ? m_MAX_TWO_DIGIT_NUMBER : checksumBase) : 1);
}

const unsigned int& CTwoDigitChecksumGenerator::getChecksumBase() const
{
	return m_ChecksumBase;
}
	
void CTwoDigitChecksumGenerator::generateChecksumForNumber(const unsigned int& number, const unsigned int& minimumNumberOfDigits, unsigned int& checksum) const
{
	std::vector<unsigned int> digitsOfNumber;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);

	generateChecksumForDigitsOfNumber(digitsOfNumber, checksum);
}

void CTwoDigitChecksumGenerator::generateChecksumForDigitsOfNumber(const std::vector<unsigned int>& digitsOfNumber, unsigned int& checksum) const
{
	if (digitsOfNumber.size() > 0)
	{
		// Generate checksum
		// Formula for generating checksum: c = (a1 + (10 * a2) + (100 * a3) + (1000 * a4)) mod cb
		// Here 'c' is the checksum, {a1, a2, a3, a4} are the digits of the number and cb is the checksum base
		// In this formula, the original number or asset ID is getting reversed and then a modulus of cb is getting calculated
		// For example, the checksum for the asset ID 1337 can be calculated as follows:
		// (1 + (10 * 3) + (100 * 3) + (1000 * 7)) mod 97 = 7331 mod 97 = 56

		checksum = digitsOfNumber.front();
		for (int i = 1; i < digitsOfNumber.size(); ++i)
		{
			checksum += (digitsOfNumber[i] * (static_cast<unsigned int>(std::pow(10, i))));
		}
		checksum %= m_ChecksumBase;
	}
	else
	{
		checksum = 0;
	}
}

void CTwoDigitChecksumGenerator::generateChecksumAndGetDigitsOfTheChecksummedCode(
	const unsigned int& number, 
	const unsigned int& minimumNumberOfDigitsInNumber,
	const unsigned int& minimumNumberOfDigitsInChecksum,
	std::vector<unsigned int>& digitsOfChecksummedCode) const
{
	// Get the individual digits of the number and store them in a vector
	std::vector<unsigned int> digitsOfNumber;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigitsInNumber, digitsOfNumber);

	generateChecksumAndGetDigitsOfTheChecksummedCode(digitsOfNumber, minimumNumberOfDigitsInChecksum, digitsOfChecksummedCode);
}

void CTwoDigitChecksumGenerator::generateChecksumAndGetDigitsOfTheChecksummedCode(
	const std::vector<unsigned int>& digitsOfNumber, 
	const unsigned int& minimumNumberOfDigitsInChecksum,
	std::vector<unsigned int>& digitsOfChecksummedCode) const
{
	// Generate the checksum
	unsigned int checksum = 0;
	generateChecksumForDigitsOfNumber(digitsOfNumber, checksum);

	// Get the individual digits of the checksum and add them in the output variable
	NumberConversion::getAllDigitsOfTheNumber(checksum, minimumNumberOfDigitsInChecksum, digitsOfChecksummedCode);

	// At this point our output variable contains the digits of the checksum
	// All thats left to do, is to add the digits of the original number
	digitsOfChecksummedCode.insert(digitsOfChecksummedCode.end(), digitsOfNumber.begin(), digitsOfNumber.end());
}
