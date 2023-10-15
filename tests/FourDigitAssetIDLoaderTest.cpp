// PlainTextFileLoaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <filesystem>

#include "FourDigitAssetIDLoader.h"

using namespace testing;

TEST(FourDigitAssetIDLoaderTest, LoadAssetIDsFromFile)
{
    std::vector< std::vector<char> > assetIDs;

    const IAssetIDLoader& assetIDLoader = CFourDigitAssetIDLoader();
    assetIDLoader.loadAssetIDsFromFile("testData/assetIDsTestFile.txt", assetIDs);
    EXPECT_THAT(assetIDs[0], ElementsAre( '0', '0', '1', '1' ));
    EXPECT_THAT(assetIDs[1], ElementsAre( '0', '2', '0', '1' ));
    EXPECT_THAT(assetIDs[2], ElementsAre( '1', '2', '2', '2' ));
    EXPECT_THAT(assetIDs[3], ElementsAre( '1', '9', '2', '7' ));
    EXPECT_THAT(assetIDs[4], ElementsAre( '2', '6', '7', '4' ));
    EXPECT_THAT(assetIDs[5], ElementsAre( '4', '4', '3', '4' ));
    EXPECT_THAT(assetIDs[6], ElementsAre( '5', '6', '5', '7' ));
    EXPECT_THAT(assetIDs[7], ElementsAre( '6', '8', '7', '2' ));
    EXPECT_THAT(assetIDs[8], ElementsAre( '7', '2', '8', '8' ));
    EXPECT_THAT(assetIDs[9], ElementsAre( '9', '4', '4', '3' ));
    EXPECT_THAT(assetIDs[10], ElementsAre('1', '3', '3', '7'));
}
    