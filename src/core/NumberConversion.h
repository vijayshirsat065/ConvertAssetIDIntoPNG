// NumberConversion.h : 

#pragma once

#include <vector>

namespace NumberConversion
{
	void GetAllDigitsOfTheNumberInReverseOrder(const unsigned int& assetID, std::vector<unsigned int>& DigitsInNumber);
	void AddAllDigitsOfTheNumberInReverseOrderToEndOfVector(const unsigned int& assetID, std::vector<unsigned int>& DigitsInNumber);
	void ReplaceElementsOfVectorWithReversedDigitsOfNumber(const unsigned int& assetID, std::vector<unsigned int>& DigitsInNumber);
}