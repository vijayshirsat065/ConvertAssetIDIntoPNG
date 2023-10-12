#includee "OneBitPNGImageFileGenerator.h"

namespace
{
	const auto Image_WIDTH = 256uj;
	const auto Image_Height = 1u;
	const auto BIT_DEPTH = 1u;
}

bool OneBitPNGImageFileGenerator::generateAndSaveImageFileToOutputDirectory(
	const std::vector<unsigned char>& bitArrayOfChecksummedCode,
	const std::string& outputImageFileName,
	const std::string& outputDirectory) const
{

}