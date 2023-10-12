#pragma once

#include "IAssetIDLoader.h"
#include "IChecksumGenerator.h"
#include "ICharToBitArrayMapper.h"

#include <memory>

class CConvertAssetIDIntoPNG
{
public:
	CConvertAssetIDIntoPNG(
		const IAssetIDLoader& assetIDLoader, 
		const IChecksumGenerator& checksumGenerator,
		const ICharToBitArrayMapper& charToBitArrayMapper);
	~CConvertAssetIDIntoPNG();

	bool loadAssetIDsAndGenerateChecksummedCodes(const std::string& assetIDInfoFile);

	bool generateBitArrayOfChecksummedAssetIDs();

private:
	std::vector< std::vector<char> > m_AssetIDs;
	std::vector< std::vector<char> > m_ChecksummedAssetIDs;
	std::vector< std::vector<unsigned char> > m_BitArraysOfChecksummedAssetIDs;
	const IAssetIDLoader& m_AssetIDLoader;
	const IChecksumGenerator& m_ChecksumGenerator;
	const ICharToBitArrayMapper& m_CharToBitArrayMapper;
};