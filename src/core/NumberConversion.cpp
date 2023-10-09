// NumberConversion.cpp : 
//

#include "NumberConversion.h"

void NumberConversion::GetAllDigitsOfTheNumberInReverseOrder(const unsigned int& number, std::vector<unsigned int>& DigitsInNumber)
{
	DigitsInNumber.clear(); // Empty the vector, so the elements can be added from starting position
	AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(number, DigitsInNumber);
}

void NumberConversion::AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(const unsigned int& number, std::vector<unsigned int>& DigitsInNumber)
{
	unsigned int resultingDividend = number;

	while (resultingDividend != 0)
	{
		// Store the digits of the number in the vector in a reverse order
		DigitsInNumber.push_back(resultingDividend % 10); // Get the last digit from the number and add it to the end of the vector
		resultingDividend /= 10; // Reduce the digits in the number one by one
	}
}

void NumberConversion::ReplaceElementsOfVectorWithReversedDigitsOfNumber(const unsigned int& number, std::vector<unsigned int>& DigitsInNumber)
{
	unsigned int resultingDividend = number;
	unsigned int count = 0;
	while (resultingDividend != 0)
	{
		// Store the digits of the number in the vector in a reverse order

		// Check if the vector already has some elements
		if (count < DigitsInNumber.size())
		{
			// Replace existing elements. This is helpful if the vector is prepopulated with placeholder elements.
			DigitsInNumber[count] = (resultingDividend % 10);
		}
		else
		{
			// Add new elements
			DigitsInNumber.push_back(resultingDividend % 10);
		}
		
		resultingDividend /= 10; // Reduce the digits in the number one by one
		++count;
	}
}