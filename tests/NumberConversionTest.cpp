// NumberConversiontest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core/NumberConversion.h"

using namespace testing;

TEST(NumberConversiontest, getAllDigitsOfTheNumber)
{
	unsigned int number = 1256;
	std::vector<unsigned int> digitsOfNumber;

	NumberConversion::getAllDigitsOfTheNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(1, 2, 5, 6));

	number = 324;
	NumberConversion::getAllDigitsOfTheNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3, 2, 4));

	number = 41;
	NumberConversion::getAllDigitsOfTheNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 1));

	number = 372849;
	NumberConversion::getAllDigitsOfTheNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3, 7, 2, 8, 4, 9));

	number = 3;
	NumberConversion::getAllDigitsOfTheNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3));
}

TEST(NumberConversiontest, getAllDigitsOfTheNumberWithMinimumElementCount)
{
	const auto minimumNumberOfDigits = 4;
	unsigned int number = 1256;
	std::vector<unsigned int> digitsOfNumber;

	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(1, 2, 5, 6));

	number = 324;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(0, 3, 2, 4));

	number = 41;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(0, 0, 4, 1));

	number = 372849;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3, 7, 2, 8, 4, 9));

	number = 3;
	NumberConversion::getAllDigitsOfTheNumber(number, minimumNumberOfDigits, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(0, 0, 0, 3));
}
