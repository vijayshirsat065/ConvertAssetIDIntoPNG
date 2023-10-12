// ConvertAssetIDIntoPNG.cpp
//

#include "ConvertAssetIDIntoPNG.h"

#include <iostream>

CConvertAssetIDIntoPNG::CConvertAssetIDIntoPNG(
	const IAssetIDLoader& assetIDLoader, 
	const IChecksumGenerator& checksumGenerator,
	const ICharToBitArrayMapper& charToBitArrayMapper)
	: m_AssetIDLoader(assetIDLoader),
	  m_ChecksumGenerator(checksumGenerator),
	 m_CharToBitArrayMapper(charToBitArrayMapper)
{}

CConvertAssetIDIntoPNG::~CConvertAssetIDIntoPNG() {}

bool CConvertAssetIDIntoPNG::loadAssetIDsAndGenerateChecksummedCodes(const std::string& assetIDInfoFile)
{
	bool bReturnValue = false;
	if (m_AssetIDLoader.loadAssetIDsFromFile(assetIDInfoFile, m_AssetIDs) && !m_AssetIDs.empty())
	{
		m_ChecksummedAssetIDs.clear();

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
					std::cout << "Failed to generate bit array for checksummed code - " << checksummedAssetID.data() << std::endl;
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