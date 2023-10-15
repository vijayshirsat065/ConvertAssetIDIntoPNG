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

TEST(ConvertAssetIDIntoPNGTest, generateImagesForLoadedAssetIDs)
{
	const IAssetIDLoader& assetIDLoader = CFourDigitAssetIDLoader();

	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();

	const auto CHECKSUM_BASE = 97u;
	const IChecksumGenerator& twoDigitChecksumGenerator = CTwoDigitChecksumGeneratorFromFourDigitAssetID(CHECKSUM_BASE, assetIDCharToNumberMapper);

	const auto CONFIG_FILE = "testData/SevenSegmentDisplayCharacterToBitArrayMapping.txt";
	const ICharToBitArrayMapper& charToBitArrayMapper = CCharToSevenSegmentBitArrayMapper(CONFIG_FILE);

	const IImageFileCreator& imageFileCreator = COneBitPNGImageFileGenerator();

	CConvertAssetIDIntoPNG convertAssetIDIntoPNG(assetIDLoader, twoDigitChecksumGenerator, charToBitArrayMapper, imageFileCreator);
	
	EXPECT_TRUE(convertAssetIDIntoPNG.generateImagesForLoadedAssetIDs("testData/assetIDsTestFile.txt", "testOutput"));

	const auto& assetIDs = convertAssetIDIntoPNG.getAssetIDs();
	// Check all asset IDs where correctly loaded
	EXPECT_THAT(assetIDs[0], ElementsAre('0', '0', '1', '1'));
	EXPECT_THAT(assetIDs[1], ElementsAre('0', '2', '0', '1'));
	EXPECT_THAT(assetIDs[2], ElementsAre('1', '2', '2', '2'));
	EXPECT_THAT(assetIDs[3], ElementsAre('1', '9', '2', '7'));
	EXPECT_THAT(assetIDs[4], ElementsAre('2', '6', '7', '4'));
	EXPECT_THAT(assetIDs[5], ElementsAre('4', '4', '3', '4'));
	EXPECT_THAT(assetIDs[6], ElementsAre('5', '6', '5', '7'));
	EXPECT_THAT(assetIDs[7], ElementsAre('6', '8', '7', '2'));
	EXPECT_THAT(assetIDs[8], ElementsAre('7', '2', '8', '8'));
	EXPECT_THAT(assetIDs[9], ElementsAre('9', '4', '4', '3'));
	EXPECT_THAT(assetIDs[10], ElementsAre('1', '3', '3', '7'));

	// Check if the checksummed IDs were correctly generated
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[0], ElementsAre('3', '3', '0', '0', '1', '1'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[1], ElementsAre('5', '0', '0', '2', '0', '1'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[2], ElementsAre('8', '7', '1', '2', '2', '2'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[3], ElementsAre('1', '6', '1', '9', '2', '7'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[4], ElementsAre('0', '9', '2', '6', '7', '4'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[5], ElementsAre('7', '6', '4', '4', '3', '4'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[6], ElementsAre('9', '6', '5', '6', '5', '7'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[7], ElementsAre('7', '0', '6', '8', '7', '2'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[8], ElementsAre('0', '0', '7', '2', '8', '8'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[9], ElementsAre('5', '4', '9', '4', '4', '3'));
	EXPECT_THAT(convertAssetIDIntoPNG.getChecksummedAssetIDs()[10], ElementsAre('5', '6', '1', '3', '3', '7'));

	// Check if the bit array for the checksummed asset IDs was correctly generated
	EXPECT_THAT(convertAssetIDIntoPNG.getBitArraysOfChecksummedAssetIDs()[0], ElementsAre('1', '1','0','1','0','1','1','0','1','1','0','1','0','1','1','0','0','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','0','0','0','0','1','0','0','1','0','0','0','0','1','0'));
	EXPECT_THAT(convertAssetIDIntoPNG.getBitArraysOfChecksummedAssetIDs()[1], ElementsAre('1', '1','0','1','0','1','0','1','0','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','0','1','1','0','0','1','1','1','0','1','1','1','0','1','0','0','0','0','1','0'));
	EXPECT_THAT(convertAssetIDIntoPNG.getBitArraysOfChecksummedAssetIDs()[2], ElementsAre('1', '1','1','1','0','1','1','1','0','1','0','0','0','1','1','0','0','1','0','0','0','0','1','0','1','0','1','1','0','1','1','0','1','0','1','1','0','1','1','0','1','0','1','1','0','1','1','0'));
}
