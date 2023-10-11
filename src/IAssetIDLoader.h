#pragma once

#include <vector>
#include <string>

class IAssetIDLoader
{
public:
	virtual ~IAssetIDLoader() {}

	virtual const unsigned int& GetNumberOfDigitsInAssetID() const = 0;

	virtual bool loadAssetIDsFromFile(
		const std::string& filePath,
		std::vector< std::vector<char> >& assetIDs) const = 0;
};