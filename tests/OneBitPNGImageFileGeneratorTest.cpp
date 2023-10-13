// PlainTextFileLoaderTest.cpp : 

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "OneBitPNGImageFileGenerator.h"
#include "dependencies/lodepng/lodepng.h"

#include <filesystem>

using namespace testing;

TEST(OneBitPNGImageFileGeneratorTest, generateAndSaveImageFileToOutputDirectory)
{
    const std::string encodedPNGFileName = "1337.png";
    const IImageFileCreator& imageFileCreator = COneBitPNGImageFileGenerator();

    std::vector<unsigned char> bitArrayOfChecksummedCode = { '1', '1', '0', '1', '0', '1', '0', '1' , 
    '1', '1', '1', '1', '0', '1', '0', '1',
    '0', '1', '0', '0', '0', '0', '1', '0',
    '1', '1', '0', '1', '0', '1', '1', '0',
    '1', '1', '0', '1', '0', '1', '1', '0',
    '0', '1', '0', '0', '0', '1', '1', '0' };

    EXPECT_TRUE(imageFileCreator.generateAndSaveImageFileToOutputDirectory(bitArrayOfChecksummedCode, encodedPNGFileName, "testDataOut"));

    std::string filename = "testData/1337_Orig.png";
    std::vector<unsigned char> png;
    std::vector<unsigned char> image; //the raw pixels
    unsigned width, height;

    //load and decode
    unsigned error = lodepng::load_file(png, filename);
    if (!error) error = lodepng::decode(image, width, height, png);
    //if there's an error, display it
    if (error) std::cout << "decoder error " << error << ": " << lodepng_error_text(error) << std::endl;
    auto sizeOfVector = image.size();
}
