#pragma once

#include <vector>
#include <string>

class COneBitPNGImageFileGenerator
{
public:
	virtual ~COneBitPNGImageFileGenerator() {}

	virtual bool generateAndSaveImageFileToOutputDirectory(
		const std::vector<unsigned char> bitArrayOfChecksummedCode,
		const std::string& outputImageFileName,
		const std::string& outputDirectory) const;
};