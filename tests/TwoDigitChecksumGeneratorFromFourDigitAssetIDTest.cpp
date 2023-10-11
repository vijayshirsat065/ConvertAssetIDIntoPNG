// TwoDigitChecksumGeneratorTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "TwoDigitChecksumGeneratorFromFourDigitAssetID.h"
#include "AssetIDDecimalCharToNumberMapper.h"

using namespace testing;

TEST(TwoDigitChecksumGeneratorFromFourDigitAssetIDTest, ChecksumBase)
{
	unsigned int checksumBase = 68;

	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();
	CTwoDigitChecksumGeneratorFromFourDigitAssetID TwoDigitChecksumGeneratorFromFourDigitAssetID(checksumBase, assetIDCharToNumberMapper);
	IChecksumGenerator& twoDigitChecksumGenerator = TwoDigitChecksumGeneratorFromFourDigitAssetID;

	EXPECT_EQ(checksumBase, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 0;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_NE(0, twoDigitChecksumGenerator.getChecksumBase());
	EXPECT_EQ(1u, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 99;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(checksumBase, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 100;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(99u, twoDigitChecksumGenerator.getChecksumBase());

	checksumBase = 1267;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);
	EXPECT_EQ(99u, twoDigitChecksumGenerator.getChecksumBase());
}

TEST(TwoDigitChecksumGeneratorFromFourDigitAssetIDTest, generateChecksummedCode)
{
	auto checksumBase = 97u;

	const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();
	CTwoDigitChecksumGeneratorFromFourDigitAssetID TwoDigitChecksumGeneratorFromFourDigitAssetID(checksumBase, assetIDCharToNumberMapper);
	IChecksumGenerator& twoDigitChecksumGenerator = TwoDigitChecksumGeneratorFromFourDigitAssetID;

	std::vector<char> assetID = {'1', '3', '3', '7'};
	std::vector<char> checksummedAssetID;

	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('5', '6', '1', '3', '3', '7'));

	assetID = { '1' };
	EXPECT_FALSE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));

	assetID = { '0', '0', '0', '1' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('3', '0', '0', '0', '0', '1'));

	assetID = { '0', '0', '2', '7' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('2', '2', '0', '0', '2', '7'));

	assetID = { '0', '3', '8', '9' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('3', '3', '0', '3', '8', '9'));

	assetID = { '2', '0', '0', '0' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('0', '2', '2', '0', '0', '0'));

	checksumBase = 65;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);

	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('0', '2', '2', '0', '0', '0'));

	assetID = { '0', '3', '8', '9' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('1', '5', '0', '3', '8', '9'));

	checksumBase = 97;
	twoDigitChecksumGenerator.setChecksumBase(checksumBase);

	assetID = { '0', '0', '1', '1' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('3', '3', '0', '0', '1', '1'));

	assetID = { '0', '2', '0', '1' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('5', '0', '0', '2', '0', '1'));

	assetID = { '1', '2', '2', '2' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('8', '7', '1', '2', '2', '2'));
	
	assetID = { '1', '9', '2', '7' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('1', '6', '1', '9', '2', '7'));

	assetID = { '2', '6', '7', '4' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('0', '9', '2', '6', '7', '4'));

	assetID = { '4', '4', '3', '4' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('7', '6', '4', '4', '3', '4'));

	assetID = { '5', '6', '5', '7' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('9', '6', '5', '6', '5', '7'));

	assetID = { '6', '8', '7', '2' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('7', '0', '6', '8', '7', '2'));

	assetID = { '7', '2', '8', '8' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('0', '0', '7', '2', '8', '8'));

	assetID = { '9', '4', '4', '3' };
	EXPECT_TRUE(twoDigitChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetID));
	EXPECT_THAT(checksummedAssetID, ElementsAre('5', '4', '9', '4', '4', '3'));
}
