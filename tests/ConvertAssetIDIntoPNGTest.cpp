// ConvertAssetIDIntoPNGTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "FourDigitAssetIDLoader.h"
#include "AssetIDDecimalCharToNumberMapper.h"
#include "TwoDigitChecksumGeneratorFromFourDigitAssetID.h"
#include "CharToSevenSegmentBitArrayMapper.h"
#include "OneBitPNGImageFileGenerator.h"
#include "ConvertAssetIDIntoPNG.h"

using namespace testing;

TEST(ConvertAssetIDIntoPNGTest, loadAssetIDsAndGenerateChecksummedCodes)
{
	const IAssetIDLoader& assetIDLoader = CFourDigitAssetIDLoader();

	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();

	const auto CHECKSUM_BASE = 68u;
	const IChecksumGenerator& twoDigitChecksumGenerator = CTwoDigitChecksumGeneratorFromFourDigitAssetID(CHECKSUM_BASE, assetIDCharToNumberMapper);

	const auto CONFIG_FILE = "testData/SevenSegmentDisplayCharacterToBitArrayMapping.txt";
	const ICharToBitArrayMapper& charToBitArrayMapper = CCharToSevenSegmentBitArrayMapper(CONFIG_FILE);

	const IImageFileCreator& imageFileCreator = COneBitPNGImageFileGenerator();

	CConvertAssetIDIntoPNG convertAssetIDIntoPNG(assetIDLoader, twoDigitChecksumGenerator, charToBitArrayMapper, imageFileCreator);

}
