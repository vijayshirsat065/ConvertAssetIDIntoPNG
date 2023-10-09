// NumberConversiontest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "PlainTextFileLoader.h"

using namespace testing;

TEST(PlainTextFileLoaderTest, LoadAssetIDsFromFile)
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
