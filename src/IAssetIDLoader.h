#pragma once

#include <vector>
#include <string>

class IAssetIDLoader
{
public:
	virtual ~IAssetIDLoader() {}

	virtual void loadAssetIDsFromFile(
		const std::string& filePath,
		const unsigned int& minNumber,
		const unsigned int& maxNumber,
		std::vector<unsigned int>& assetIDs) const = 0;
};