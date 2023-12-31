﻿// main.cpp : Defines the entry point for the application.
//

#include "FourDigitAssetIDLoader.h"
#include "AssetIDDecimalCharToNumberMapper.h"
#include "TwoDigitChecksumGeneratorFromFourDigitAssetID.h"
#include "CharToSevenSegmentBitArrayMapper.h"
#include "OneBitPNGImageFileGenerator.h"
#include "ConvertAssetIDIntoPNG.h"

int main()
{
	const auto CHECKSUM_BASE = 97u;
	const std::string ASSET_ID_TEST_FILE = "test.txt";
	const std::string OUTPUT_DIRECTORY = "OutputImageFiles";

	const IAssetIDLoader& assetIDLoader = CFourDigitAssetIDLoader();

	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();
	const IChecksumGenerator& twoDigitChecksumGenerator = CTwoDigitChecksumGeneratorFromFourDigitAssetID(CHECKSUM_BASE, assetIDCharToNumberMapper);
	
	const std::string CONFIG_FILE = "SevenSegmentDisplayCharacterToBitArrayMapping.txt";
	const ICharToBitArrayMapper& charToBitArrayMapper = CCharToSevenSegmentBitArrayMapper(CONFIG_FILE);
		
	const IImageFileCreator& imageFileCreator = COneBitPNGImageFileGenerator();

	CConvertAssetIDIntoPNG convertAssetIDIntoPNG(assetIDLoader, twoDigitChecksumGenerator, charToBitArrayMapper, imageFileCreator);

	convertAssetIDIntoPNG.generateImagesForLoadedAssetIDs(ASSET_ID_TEST_FILE, OUTPUT_DIRECTORY);


	return 0;
}
