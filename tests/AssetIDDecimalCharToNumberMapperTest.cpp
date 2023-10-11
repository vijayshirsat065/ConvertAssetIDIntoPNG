// ConfigFileReaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "AssetIDDecimalCharToNumberMapper.h"

using namespace testing;

TEST(AssetIDDecimalCharToNumberMapperTest, NumberToCharConverter)
{
    std::vector<unsigned int> assetIDs;

    const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();

    EXPECT_EQ('0', assetIDCharToNumberMapper.getCharForSpecifiedNumber(0));
    EXPECT_EQ('1', assetIDCharToNumberMapper.getCharForSpecifiedNumber(1));
    EXPECT_EQ('2', assetIDCharToNumberMapper.getCharForSpecifiedNumber(2));
    EXPECT_EQ('3', assetIDCharToNumberMapper.getCharForSpecifiedNumber(3));
    EXPECT_EQ('4', assetIDCharToNumberMapper.getCharForSpecifiedNumber(4));
    EXPECT_EQ('5', assetIDCharToNumberMapper.getCharForSpecifiedNumber(5));
    EXPECT_EQ('6', assetIDCharToNumberMapper.getCharForSpecifiedNumber(6));
    EXPECT_EQ('7', assetIDCharToNumberMapper.getCharForSpecifiedNumber(7));
    EXPECT_EQ('8', assetIDCharToNumberMapper.getCharForSpecifiedNumber(8));
    EXPECT_EQ('9', assetIDCharToNumberMapper.getCharForSpecifiedNumber(9));
}

TEST(AssetIDDecimalCharToNumberMapperTest, CharToNumberConverter)
{
    std::vector<unsigned int> assetIDs;

    const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper = CAssetIDDecimalCharToNumberMapper();

    EXPECT_EQ(0, assetIDCharToNumberMapper.getNumberForSpecifiedChar('0'));
    EXPECT_EQ(1, assetIDCharToNumberMapper.getNumberForSpecifiedChar('1'));
    EXPECT_EQ(2, assetIDCharToNumberMapper.getNumberForSpecifiedChar('2')); 
    EXPECT_EQ(3, assetIDCharToNumberMapper.getNumberForSpecifiedChar('3'));
    EXPECT_EQ(4, assetIDCharToNumberMapper.getNumberForSpecifiedChar('4'));
    EXPECT_EQ(5, assetIDCharToNumberMapper.getNumberForSpecifiedChar('5'));
    EXPECT_EQ(6, assetIDCharToNumberMapper.getNumberForSpecifiedChar('6'));
    EXPECT_EQ(7, assetIDCharToNumberMapper.getNumberForSpecifiedChar('7'));
    EXPECT_EQ(8, assetIDCharToNumberMapper.getNumberForSpecifiedChar('8'));
    EXPECT_EQ(9, assetIDCharToNumberMapper.getNumberForSpecifiedChar('9'));
}