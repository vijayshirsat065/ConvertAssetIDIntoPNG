// TwoDigitChecksumGenerator.cpp : Defines the logic for generating a two digit checksum
//

#include "TwoDigitChecksumGeneratorFromFourDigitAssetID.h"

#include <iostream>
#include <numeric>
#include <cmath>

namespace
{
	constexpr auto MAX_TWO_DIGIT_NUMBER = 99u;
	constexpr auto NUMBER_OF_DIGITS_IN_CHECKSUM = 2u;
	constexpr auto NUMBER_OF_DIGITS_IN_ASSET_ID = 4u;
}

CTwoDigitChecksumGeneratorFromFourDigitAssetID::CTwoDigitChecksumGeneratorFromFourDigitAssetID(
	const unsigned int& checksumBase, 
	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper)
	: m_AssetIDCharToNumberMapper(assetIDCharToNumberMapper)
{
	// To prevent from using an invalid number
	setChecksumBase(checksumBase);
}

CTwoDigitChecksumGeneratorFromFourDigitAssetID::~CTwoDigitChecksumGeneratorFromFourDigitAssetID() {}

void CTwoDigitChecksumGeneratorFromFourDigitAssetID::setChecksumBase(const unsigned int& checksumBase)
{
	//Ensure the checksum base is not greater than the allowed max digit number and is not less than 1
	m_ChecksumBase = (checksumBase > 1 ? ((checksumBase > MAX_TWO_DIGIT_NUMBER) ? MAX_TWO_DIGIT_NUMBER : checksumBase) : 1);
}

const unsigned int& CTwoDigitChecksumGeneratorFromFourDigitAssetID::getChecksumBase() const
{
	return m_ChecksumBase;
}

void CTwoDigitChecksumGeneratorFromFourDigitAssetID::generateChecksumForDigitsOfNumber(const std::vector<unsigned int>& digitsOfNumber, unsigned int& checksum) const
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

bool CTwoDigitChecksumGeneratorFromFourDigitAssetID::generateChecksumAndGetDigitsOfTheChecksummedCode(
	const std::vector<char>& assetID, 
	std::vector<char>& checksummedAssetIDCode) const
{
	bool bReturnValue = false;
	checksummedAssetIDCode.clear();

	if (!assetID.empty() && (assetID.size() == NUMBER_OF_DIGITS_IN_ASSET_ID))
	{
		// Convert character to number
		std::vector<unsigned int> assetIDDigits;
		for (auto& character : assetID)
		{
			assetIDDigits.push_back(m_AssetIDCharToNumberMapper.getNumberForSpecifiedChar(character));
		}

		// Generate checksum
		auto checksumNumber = 0u;
		generateChecksumForDigitsOfNumber(assetIDDigits, checksumNumber);

		// Convert the checksum number into a char array
		std::vector<char> checksumCharacters(NUMBER_OF_DIGITS_IN_CHECKSUM, '0');
		auto count = NUMBER_OF_DIGITS_IN_CHECKSUM-1;
		while (count >= 0 && count < checksumCharacters.size())
		{
			// Take last digit of the checksum value and add it to the vector
			checksumCharacters[count] = m_AssetIDCharToNumberMapper.getCharForSpecifiedNumber(checksumNumber % 10);
			checksumNumber /= 10; // Remove the last digit of checksum value
			--count;
		}

		// Add the checksum char array and the original asset ID char array to get the checksummed asset ID code
		checksummedAssetIDCode.insert(checksummedAssetIDCode.begin(), checksumCharacters.begin(), checksumCharacters.end());
		checksummedAssetIDCode.insert(checksummedAssetIDCode.end(), assetID.begin(), assetID.end());

		bReturnValue = true;
	}
	return bReturnValue;
}
