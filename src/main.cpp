// main.cpp : Defines the entry point for the application.
//

#include "ConvertAssetIDIntoPNG.h"

int main()
{
	const auto ASSET_ID_MIN_VALUE = 0u;
	const auto ASSET_ID_MAX_VALUE = 9999u;
	const auto NUMBER_OF_DIGITS_IN_ASSET_ID = 4u;
	const auto NUMBER_OF_DIGITS_IN_CHECKSUM = 2u;
	const auto CHECKSUM_BASE = 97u;
	const std::string ASSET_ID_TEST_FILE = "test.txt";

	/*
	std::vector<unsigned int> assetIDs;

	// Load list of asset IDs from the test file
	CPlainTextFileLoader plainTextFileLoader;
	plainTextFileLoader.loadAssetIDsFromFile(ASSET_ID_TEST_FILE, ASSET_ID_MIN_VALUE, ASSET_ID_MAX_VALUE, assetIDs);

	std::vector<std::vector<unsigned int> > checksummedAssetIDs(assetIDs.size());

	CTwoDigitChecksumGenerator twoDigitChecksumGenerator(CHECKSUM_BASE);
	for (auto i = 0u; i < assetIDs.size(); ++i)
	{
		twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(
			assetIDs[i],
			NUMBER_OF_DIGITS_IN_ASSET_ID,
			NUMBER_OF_DIGITS_IN_CHECKSUM,
			checksummedAssetIDs[i]);
	}*/
	CConvertAssetIDIntoPNG ConvertAssetIDIntoPNG;


	return 0;
}
