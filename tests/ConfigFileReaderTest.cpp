// ConfigFileReaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <filesystem>

#include "core/ConfigFileReader.h"

using namespace testing;

TEST(ConfigFileReaderTest, LoadSevenSegmentDisplayCharacterToBitArrayMapping)
{
    std::vector<unsigned int> assetIDs;

    CConfigFileReader configFileReader;
    std::map<std::string, std::string> configFileDataMap;
    configFileReader.readConfigFile("testData/SevenSegmentDisplayCharacterToBitArrayMapping.txt", configFileDataMap);

    EXPECT_THAT(configFileDataMap, ElementsAre(Pair("0", "01110111"), 
        Pair("1", "01000010"),
        Pair("2", "10110110"),
        Pair("3", "11010110"),
        Pair("4", "11000011"),
        Pair("5", "11010101"),
        Pair("6", "11110101"),
        Pair("7", "01000110"),
        Pair("8", "11110111"),
        Pair("9", "11010111")));
}
