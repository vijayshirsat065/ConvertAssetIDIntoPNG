#pragma once

#include <vector>
#include <string>

class IImageFileCreator
{
public:
	virtual ~IImageFileCreator() {}

	virtual bool generateAndSaveImageFileToOutputDirectory(
		const std::vector<unsigned char> bitArrayOfChecksummedCode,
		const std::string& outputImageFileName,
		const std::string& outputDirectory) const = 0;
};