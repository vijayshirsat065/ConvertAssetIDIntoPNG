// main.cpp : Defines the entry point for the application.
//

#include "TwoDigitChecksumGenerator.h"
#include "PlainTextFileLoader.h"
#include <iostream>

int main()
{
	const auto ASSET_ID_MIN_VALUE = 0u;
	const auto ASSET_ID_MAX_VALUE = 9999u;
	const auto NUMBER_OF_DIGITS_IN_ASSET_ID = 4u;
	const auto NUMBER_OF_DIGITS_IN_CHECKSUM = 2u;
	const std::string ASSET_ID_TEST_FILE = "test.txt";

	std::vector<unsigned int> assetIDs;

	// Load list of asset IDs from the test file
	CPlainTextFileLoader plainTextFileLoader;
	plainTextFileLoader.loadAssetIDsFromFile(ASSET_ID_TEST_FILE, ASSET_ID_MIN_VALUE, ASSET_ID_MAX_VALUE, assetIDs);

	std::vector<std::vector<unsigned int> > checksummedAssetIDs;

	return 0;
}
