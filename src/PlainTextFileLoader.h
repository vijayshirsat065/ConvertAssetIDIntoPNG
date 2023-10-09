#pragma once

#include "IAssetIDLoader.h"

class CPlainTextFileLoader : public IAssetIDLoader
{
public:
	CPlainTextFileLoader();
	virtual ~CPlainTextFileLoader();

	virtual void loadAssetIDsFromFile(
		const std::string& filePath, 
		const unsigned int& minNumber, 
		const unsigned int& maxNumber,
		std::vector<unsigned int>& assetIDs) const;

private:
};