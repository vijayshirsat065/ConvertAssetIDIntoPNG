#pragma once

#include "IImageFileCreator.h"

#include <vector>
#include <string>

class COneBitPNGImageFileGenerator : public IImageFileCreator
{
public:
	virtual ~COneBitPNGImageFileGenerator() {}

	virtual bool generateAndSaveImageFileToOutputDirectory(
		const std::vector<unsigned char>& bitArrayOfChecksummedCode,
		const std::string& outputImageFileName,
		const std::string& outputDirectory) const;	
};