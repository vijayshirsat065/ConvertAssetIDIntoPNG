// PlainTextFileLoaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <filesystem>

#include "PlainTextFileLoader.h"

using namespace testing;

TEST(PlainTextFileLoaderTest, LoadAssetIDsFromFile)
{
    std::vector<unsigned int> assetIDs;

    CPlainTextFileLoader PlainTextFileLoader;
    PlainTextFileLoader.LoadAssetIDsFromFile("testData/assetIDsTestFile.txt", 0, 9999, assetIDs);
    EXPECT_THAT(assetIDs, ElementsAre(11, 201, 1222, 1927, 2674, 4434, 5657, 6872, 7288, 9443));

    PlainTextFileLoader.LoadAssetIDsFromFile("testData/assetIDsTestFile2.txt", 0, 9999, assetIDs);
    EXPECT_THAT(assetIDs, ElementsAre(3, 201, 1222, 1927));
}
