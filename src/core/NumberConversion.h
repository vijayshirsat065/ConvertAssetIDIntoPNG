// NumberConversion.h : 

#pragma once

#include <vector>

namespace NumberConversion
{
	void getAllDigitsOfTheNumber(const unsigned int& number, std::vector<unsigned int>& DigitsInNumber);
	void getAllDigitsOfTheNumber(const unsigned int& number, 
		const unsigned int& minimumNumberOfDigits, 
		std::vector<unsigned int>& DigitsInNumber);
}