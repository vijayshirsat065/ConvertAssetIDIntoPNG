#pragma once

#include "IChecksumGenerator.h"
#include "IAssetIDCharToNumberMapper.h"

class CTwoDigitChecksumGeneratorFromFourDigitAssetID : public IChecksumGenerator
{
public:
	CTwoDigitChecksumGeneratorFromFourDigitAssetID(const unsigned int& checksumBase, const IAssetIDCharToNumberMapper& assetIDCharToNumberMapper);
	virtual ~CTwoDigitChecksumGeneratorFromFourDigitAssetID();

	virtual void setChecksumBase(const unsigned int& checksumBase);
	virtual const unsigned int& getChecksumBase() const;
	virtual bool generateChecksumAndGetDigitsOfTheChecksummedCode(const std::vector<char>& assetID, std::vector<char>& checksummedAssetIDCode) const;

private:
	void generateChecksumForDigitsOfNumber(const std::vector<unsigned int>& digitsOfNumber, unsigned int& checksum) const;

	unsigned int m_ChecksumBase = 1;
	const IAssetIDCharToNumberMapper& m_AssetIDCharToNumberMapper;
};