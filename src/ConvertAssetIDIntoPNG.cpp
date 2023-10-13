// ConvertAssetIDIntoPNG.cpp
//

#include "ConvertAssetIDIntoPNG.h"

#include <iostream>

CConvertAssetIDIntoPNG::CConvertAssetIDIntoPNG(
	const IAssetIDLoader& assetIDLoader, 
	const IChecksumGenerator& checksumGenerator,
	const ICharToBitArrayMapper& charToBitArrayMapper,
	const IImageFileCreator& imageFileCreator) :
	m_AssetIDLoader(assetIDLoader),
	m_ChecksumGenerator(checksumGenerator),
	m_CharToBitArrayMapper(charToBitArrayMapper),	
	m_ImageFileCreator(imageFileCreator)
{}

CConvertAssetIDIntoPNG::~CConvertAssetIDIntoPNG() {}

bool CConvertAssetIDIntoPNG::loadAssetIDsAndGenerateChecksummedCodes(const std::string& assetIDInfoFile)
{
	bool bReturnValue = true;
	if (m_AssetIDLoader.loadAssetIDsFromFile(assetIDInfoFile, m_AssetIDs) && !m_AssetIDs.empty())
	{
		m_ChecksummedAssetIDs.clear();

		for (auto& assetID : m_AssetIDs)
		{
			std::vector<char> checksummedAssetIDCode;
			bReturnValue = m_ChecksumGenerator.generateChecksumAndGetDigitsOfTheChecksummedCode(assetID, checksummedAssetIDCode) && bReturnValue;
			m_ChecksummedAssetIDs.push_back(checksummedAssetIDCode);
		}
	}
	return bReturnValue;
}

bool CConvertAssetIDIntoPNG::generateBitArrayOfChecksummedAssetIDs()
{
	bool bReturnValue = false;
	if (!m_ChecksummedAssetIDs.empty())
	{
		m_BitArraysOfChecksummedAssetIDs.clear();

		std::vector<unsigned char> bitArrayForIndividualCharacter;
		std::vector<unsigned char> bitArrayForCompleteAssetID;

		for (const auto& checksummedAssetID : m_ChecksummedAssetIDs)
		{
			bReturnValue = true;
			for (const auto& character : checksummedAssetID)
			{
				if (m_CharToBitArrayMapper.getBitArrayForChar(character, bitArrayForIndividualCharacter))
				{
					bitArrayForCompleteAssetID.insert(bitArrayForCompleteAssetID.end(), bitArrayForIndividualCharacter.begin(), bitArrayForIndividualCharacter.end());
				}
				else
				{
					const std::string checksummedAssetIDText(checksummedAssetID.data(), checksummedAssetID.size());
					std::cout << "Failed to generate bit array for checksummed code - " << checksummedAssetIDText << std::endl;
					bReturnValue = false;
					break;
				}
			}
			if (bReturnValue)
			{
				m_BitArraysOfChecksummedAssetIDs.push_back(bitArrayForCompleteAssetID);
			}
		}

		bReturnValue = !m_BitArraysOfChecksummedAssetIDs.empty();
	}

	return bReturnValue;
}

bool CConvertAssetIDIntoPNG::generateImagesForChecksummedAssetIDs(const std::string& outputDirectory) const
{
	bool bReturnValue = true;

	for (auto i = 0u; (i < m_BitArraysOfChecksummedAssetIDs.size() && i < m_AssetIDs.size()); ++i)
	{
		std::string filename;
		filename.insert(filename.begin(), m_AssetIDs[i].begin(), m_AssetIDs[i].end());

		if (!m_ImageFileCreator.generateAndSaveImageFileToOutputDirectory(
			m_BitArraysOfChecksummedAssetIDs[i], filename, outputDirectory))
		{
			bReturnValue = false;
			std::cout << "Failed to generate image for asset ID - " << filename << std::endl;
		}
	}

	return bReturnValue;
}

bool CConvertAssetIDIntoPNG::generateImagesForLoadedAssetIDs(const std::string& assetIDInfoFile, const std::string& outputDirectory)
{
	auto bReturnValue = true;

	bReturnValue = loadAssetIDsAndGenerateChecksummedCodes(assetIDInfoFile) && bReturnValue;
	bReturnValue = generateBitArrayOfChecksummedAssetIDs() && bReturnValue;
	bReturnValue = generateImagesForChecksummedAssetIDs(outputDirectory);

	return bReturnValue;
}
