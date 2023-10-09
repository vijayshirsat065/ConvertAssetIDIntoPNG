// TwoDigitChecksumGenerator.cpp : Defines the logic for generating a two digit checksum
//

#include "TwoDigitChecksumGenerator.h"
#include "core/NumberConversion.h"

#include <numeric>
#include <cmath>

CTwoDigitChecksumGenerator::~CTwoDigitChecksumGenerator() {}

void CTwoDigitChecksumGenerator::setChecksumBase(const unsigned int& checksumBase)
{
	//Ensure the checksum base is not greater than the allowed max digit number
	m_ChecksumBase = ((checksumBase > m_MAX_TWO_DIGIT_NUMBER) ? m_MAX_TWO_DIGIT_NUMBER : checksumBase);
}

const unsigned int& CTwoDigitChecksumGenerator::getChecksumBase() const
{
	return m_ChecksumBase;
}

void CTwoDigitChecksumGenerator::generateChecksum(const std::vector<unsigned int>& reversedAssetIDDigits, unsigned int& checksum) const
{
	if (reversedAssetIDDigits.size() > 0)
	{
		// Generate checksum
		// Formula for generating checsum: c = (a1 + (10 * a2) + (100 * a3) + (1000 * a4)) mod 97
		// Here 'c' is the checksum, {a1, a2, a3, a4} are the digits of the number and 97 is the checksum base
		// In this formula, the original number or asset ID is getting reversed and then a modulus of 97 is getting calculated
		checksum = reversedAssetIDDigits.front();
		for (int i = 1; i < reversedAssetIDDigits.size(); ++i)
		{
			checksum += (reversedAssetIDDigits[i] * (static_cast<unsigned int>(std::pow(10, i))));
		}
		checksum %= m_ChecksumBase;
	}
	else
	{
		checksum = 0;
	}
}

void CTwoDigitChecksumGenerator::getChecksummedCodeInReverseOrder(const std::vector<unsigned int>& reversedAssetIDDigits, std::vector<unsigned int>& reversedChecksummedAssetIDDigits) const
{
	//This function expects the assetID in reversed order, so the output checksummedAssetIDDigits variable also has the digits of the result in reverse order
	//For example, if the assetID is 1234, then the reversedAssetIDDigits contains [4, 3, 2, 1]

	//Generate the checksum
	unsigned int checksum = 0;
	generateChecksum(reversedAssetIDDigits, checksum);

	//Copy the assetID digits into the checksummed vector
	reversedChecksummedAssetIDDigits = reversedAssetIDDigits;

	//Add the digits from checksum into the output variable
	NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(checksum, reversedChecksummedAssetIDDigits);
}
