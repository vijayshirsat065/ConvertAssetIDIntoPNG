// NumberConversion.cpp : 
//

#include "NumberConversion.h"

#include <algorithm>

void NumberConversion::getAllDigitsOfTheNumber(
	const unsigned int& number, 
	std::vector<unsigned int>& digitsInNumber)
{
	digitsInNumber.clear(); // Make sure DigitsInNumber doesn't contain any garbage values

	unsigned int resultingDividend = number;
	while (resultingDividend != 0)
	{
		// Store the digits of the number in the vector in a reverse order
		digitsInNumber.push_back(resultingDividend % 10);
		resultingDividend /= 10; // Reduce the digits in the number one by one
	}

	// Correct the order of the elements in the vector by reversing it
	std::reverse(digitsInNumber.begin(), digitsInNumber.end());
}

void NumberConversion::getAllDigitsOfTheNumber(
	const unsigned int& number,
	const unsigned int& minimumNumberOfDigits,
	std::vector<unsigned int>& digitsInNumber)
{
	// Get the digits
	getAllDigitsOfTheNumber(number, digitsInNumber);
	
	// Check if the minimum number of digits are present
	if (digitsInNumber.size() < minimumNumberOfDigits)
	{
		// Get the number of missing digits
		unsigned int count = static_cast<unsigned int>(minimumNumberOfDigits - digitsInNumber.size()); 

		// Backfill the missing digits with zeroes
		while (count > 0)
		{
			digitsInNumber.insert(digitsInNumber.begin(), 0u);
			--count;
		}
	}
}
