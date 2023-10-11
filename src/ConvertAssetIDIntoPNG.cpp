// ConvertAssetIDIntoPNG.cpp
//

#include "ConvertAssetIDIntoPNG.h"

CConvertAssetIDIntoPNG::CConvertAssetIDIntoPNG(
	const IAssetIDLoader& assetIDLoader, 
	const IChecksumGenerator& checksumGenerator) 
	: m_AssetIDLoader(assetIDLoader),
	  m_ChecksumGenerator(checksumGenerator)
{}

CConvertAssetIDIntoPNG::~CConvertAssetIDIntoPNG() {}

bool CConvertAssetIDIntoPNG::LoadAssetIDsFromPlainTextFile(const std::string& assetIDInfoFile)
{
	bool isAssetIDLoaded = false;
	if (nullptr != m_pAssetIDLoader)
	{
		isAssetIDLoaded = m_pAssetIDLoader->loadAssetIDsFromFile(assetIDInfoFile, m_AssetIDs);
	}

	return isAssetIDLoaded;
}

bool CConvertAssetIDIntoPNG::GenerateChecksummedAssetIDCodes()
{
	bool bReturnValue = false;
	if (!m_AssetIDs.empty())
	{
		for (auto& assetID : m_AssetIDs)
		{
			std::vector<char> checksummedAssetIDCode;
			m_ChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetIDCode);
			m_ChecksummedAssetIDs.push_back(checksummedAssetIDCode);
			bReturnValue = true;
		}
	}
	return bReturnValue;
}