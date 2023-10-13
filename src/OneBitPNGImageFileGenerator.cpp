#include "OneBitPNGImageFileGenerator.h"
#include "dependencies/lodepng/lodepng.h"

#include <algorithm>
#include <iostream>

namespace
{
	constexpr auto IMAGE_WIDTH = 256u;
	constexpr auto IMAGE_HEIGHT = 1u;
	constexpr auto BIT_DEPTH = 1u;
	constexpr auto IMAGE_FILE_EXTENSION = ".png";
	constexpr auto IMAGE_BITS_DEFAULT_CHAR = '0';
	constexpr auto ASSET_ID_INFO_START_POS_IN_IMAGE_ARRAY = 8u;
}

bool COneBitPNGImageFileGenerator::generateAndSaveImageFileToOutputDirectory(
	const std::vector<unsigned char>& bitArrayOfChecksummedCode,
	const std::string& outputImageFileName,
	const std::string& outputDirectory) const
{
	bool bReturnValue = false;
	
	std::vector<unsigned char> imageBitArray(IMAGE_WIDTH, IMAGE_BITS_DEFAULT_CHAR);
	std::vector<unsigned char> testVector(IMAGE_WIDTH, IMAGE_BITS_DEFAULT_CHAR);
	// Create character array for encoding in the image file
	// Check if there is enough space in the character array
	if ((imageBitArray.size() > (ASSET_ID_INFO_START_POS_IN_IMAGE_ARRAY + bitArrayOfChecksummedCode.size())) &&
		(imageBitArray.end() != std::copy(bitArrayOfChecksummedCode.begin(), bitArrayOfChecksummedCode.end(), imageBitArray.begin() + ASSET_ID_INFO_START_POS_IN_IMAGE_ARRAY)))
	{
		if (0u == lodepng_encode_file(
			outputImageFileName.c_str(),
			imageBitArray.data(),
			IMAGE_WIDTH,
			IMAGE_HEIGHT,
			LodePNGColorType::LCT_GREY,
			BIT_DEPTH))
		{
			bReturnValue = true;
		}
	}

	return bReturnValue;
}