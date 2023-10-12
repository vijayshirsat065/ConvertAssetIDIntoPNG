// PlainTextFileLoaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "CharToSevenSegmentBitArrayMapper.h"

using namespace testing;

TEST(CharToSevenSegmentBitArrayMapperTest, CharToBitArrayMapper)
{
    const std::string CONFIG_FILE = "testData/SevenSegmentDisplayCharacterToBitArrayMapping.txt";
    const ICharToBitArrayMapper& charToBitArrayMapper = CCharToSevenSegmentBitArrayMapper(CONFIG_FILE);

    std::vector<unsigned char> bitArray;

    charToBitArrayMapper.getBitArrayForChar('0', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('0', '1', '1', '1', '0', '1', '1', '1'));

    charToBitArrayMapper.getBitArrayForChar('1', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('0', '1', '0', '0', '0', '0', '1', '0'));

    charToBitArrayMapper.getBitArrayForChar('2', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '0', '1', '1', '0', '1', '1', '0'));

    charToBitArrayMapper.getBitArrayForChar('3', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '0', '1', '0', '1', '1', '0'));

    charToBitArrayMapper.getBitArrayForChar('4', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '0', '0', '0', '0', '1', '1'));

    charToBitArrayMapper.getBitArrayForChar('5', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '0', '1', '0', '1', '0', '1'));

    charToBitArrayMapper.getBitArrayForChar('6', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '1', '1', '0', '1', '0', '1'));

    charToBitArrayMapper.getBitArrayForChar('7', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('0', '1', '0', '0', '0', '1', '1', '0'));

    charToBitArrayMapper.getBitArrayForChar('8', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '1', '1', '0', '1', '1', '1'));

    charToBitArrayMapper.getBitArrayForChar('9', bitArray);
    EXPECT_THAT(bitArray, ElementsAre('1', '1', '0', '1', '0', '1', '1', '1'));
}
