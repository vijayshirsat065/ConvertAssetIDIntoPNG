// NumberConversiontest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "core/NumberConversion.h"

using namespace testing;

TEST(NumberConversiontest, GetAllDigitsOfTheNumberInReverseOrder)
{
	unsigned int number = 1256;
	std::vector<unsigned int> digitsOfNumber;

	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(6, 5, 2, 1));

	number = 324;
	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 2, 3));

	number = 41;
	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(1, 4));

	number = 372849;
	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(9, 4, 8, 2, 7, 3));

	number = 3;
	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3));
}

TEST(NumberConversiontest, AddAllDigitsOfTheNumberInReverseOrderToEndOfVector)
{
	unsigned int number = 1256;
	std::vector<unsigned int> digitsOfNumber(3, 0);

	NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(0, 0, 0, 6, 5, 2, 1));

	number = 37;
	NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(0, 0, 0, 6, 5, 2, 1, 7, 3));
	digitsOfNumber.clear();

	number = 44;
	NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 4));

	number = 3728;
	NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 4, 8, 2, 7, 3));
	digitsOfNumber.clear();

	number = 3;
	NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3));
}

TEST(NumberConversiontest, ReplaceElementsOfVectorWithReversedDigitsOfNumber)
{
	unsigned int number = 16;
	std::vector<unsigned int> digitsOfNumber(4, 0);

	NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(6, 1, 0, 0));

	number = 3724;
	NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 2, 7, 3));
	digitsOfNumber.clear();

	number = 44;
	NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(4, 4));

	number = 5397;
	NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(7, 9, 3, 5));

	digitsOfNumber = {0, 0, 0, 0};
	number = 3;
	NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(number, digitsOfNumber);
	EXPECT_THAT(digitsOfNumber, ElementsAre(3, 0, 0, 0));
}