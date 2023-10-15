#include "OneBitPNGImageFileGenerator.h"
#include "dependencies/lodepng/lodepng.h"
#include "core/FileWriter.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <filesystem>

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
	bool bReturnValue = true;
	
	std::vector<unsigned char> imageBitArray(IMAGE_WIDTH, IMAGE_BITS_DEFAULT_CHAR);
	std::vector<unsigned char> testVector(IMAGE_WIDTH, IMAGE_BITS_DEFAULT_CHAR);
	// Create character array for encoding in the image file
	// Check if there is enough space in the character array
	if ((imageBitArray.size() > (ASSET_ID_INFO_START_POS_IN_IMAGE_ARRAY + bitArrayOfChecksummedCode.size())) &&
		(imageBitArray.end() != std::copy(bitArrayOfChecksummedCode.begin(), bitArrayOfChecksummedCode.end(), imageBitArray.begin() + ASSET_ID_INFO_START_POS_IN_IMAGE_ARRAY)))
	{
		std::string imageFilePath = outputImageFileName + IMAGE_FILE_EXTENSION;

		if (!outputDirectory.empty())
		{
			imageFilePath = (outputDirectory + "/" + outputImageFileName + IMAGE_FILE_EXTENSION);
			std::filesystem::create_directory(outputDirectory);
		}

		// Creating pbm file to check if the image data is correct
		CFileWriter fileWriter((outputDirectory + "/" + outputImageFileName + ".pbm"));
		auto& fileInstance = fileWriter.getFileStreamInstance();
		
		fileInstance << "P1" << std::endl;
		fileInstance << IMAGE_WIDTH << " " << IMAGE_HEIGHT << std::endl;
		for (auto& character : imageBitArray)
		{
			fileInstance << character << " ";
		}
		fileInstance << std::endl;
		fileInstance.close();
		// File closed

		// Generating png file
		imageBitArray.push_back('\0');
		unsigned error = lodepng_encode_file(
			imageFilePath.c_str(),
			imageBitArray.data(),
			IMAGE_WIDTH,
			IMAGE_HEIGHT,
			LodePNGColorType::LCT_GREY,
			BIT_DEPTH);

		if (error)
		{
			std::cout << "image (" << imageFilePath.c_str() << ") encoding error " << error << ": " << lodepng_error_text(error) << std::endl;
			bReturnValue = false;
		}
	}

	return bReturnValue;
}