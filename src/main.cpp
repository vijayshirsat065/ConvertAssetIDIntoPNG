// main.cpp : Defines the entry point for the application.
//

#include "FourDigitAssetIDLoader.h"
#include "AssetIDDecimalCharToNumberMapper.h"
#include "TwoDigitChecksumGeneratorFromFourDigitAssetID.h"
#include "ConvertAssetIDIntoPNG.h"

int main()
{
	const auto CHECKSUM_BASE = 97u;
	const std::string ASSET_ID_TEST_FILE = "test.txt";

	CFourDigitAssetIDLoader fourDigitAssetIDLoader;
	CAssetIDDecimalCharToNumberMapper assetIDCharToNumberMapper;
	CTwoDigitChecksumGeneratorFromFourDigitAssetID twoDigitChecksumGeneratorFromFourDigitAssetID(CHECKSUM_BASE, assetIDCharToNumberMapper);
	CConvertAssetIDIntoPNG convertAssetIDIntoPNG(fourDigitAssetIDLoader, twoDigitChecksumGeneratorFromFourDigitAssetID);


	return 0;
}
