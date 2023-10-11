#pragma once

#include "IAssetIDLoader.h"
#include "IChecksumGenerator.h"

#include <memory>

class CConvertAssetIDIntoPNG
{
public:
	CConvertAssetIDIntoPNG(const IAssetIDLoader& assetIDLoader, const IChecksumGenerator& checksumGenerator);
	~CConvertAssetIDIntoPNG();

	bool LoadAssetIDsFromPlainTextFile(const std::string& assetIDInfoFile);

	bool GenerateChecksummedAssetIDCodes();

private:
	std::vector< std::vector<char> > m_AssetIDs;
	std::vector< std::vector<char> > m_ChecksummedAssetIDs;
	const IAssetIDLoader& m_AssetIDLoader;
	const IChecksumGenerator& m_ChecksumGenerator;
};