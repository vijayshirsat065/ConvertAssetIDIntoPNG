#pragma once

#include "IAssetIDLoader.h"

class CFourDigitAssetIDLoader : public IAssetIDLoader
{
public:
	CFourDigitAssetIDLoader();
	virtual ~CFourDigitAssetIDLoader();

	const unsigned int& GetNumberOfDigitsInAssetID() const;

	virtual bool loadAssetIDsFromFile(
		const std::string& filePath,
		std::vector< std::vector<char> >& assetIDs) const;
};