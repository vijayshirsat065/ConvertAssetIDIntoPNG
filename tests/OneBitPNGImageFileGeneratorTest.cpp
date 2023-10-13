// PlainTextFileLoaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "OneBitPNGImageFileGenerator.h"
#include "dependencies/lodepng/lodepng.h"

#include <filesystem>

using namespace testing;

TEST(OneBitPNGImageFileGeneratorTest, generateAndSaveImageFileToOutputDirectory)
{
    const IImageFileCreator& imageFileCreator = COneBitPNGImageFileGenerator();

    std::vector<unsigned char> bitArrayOfChecksummedCode = { '1', '1', '0', '1', '0', '1', '0', '1' , 
    '1', '1', '1', '1', '0', '1', '0', '1',
    '0', '1', '0', '0', '0', '0', '1', '0',
    '1', '1', '0', '1', '0', '1', '1', '0',
    '1', '1', '0', '1', '0', '1', '1', '0',
    '0', '1', '0', '0', '0', '1', '1', '0' };

    EXPECT_TRUE(imageFileCreator.generateAndSaveImageFileToOutputDirectory(bitArrayOfChecksummedCode, "1337.png", "testDataOut"));
}
