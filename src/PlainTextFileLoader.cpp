// TwoDigitChecksumGenerator.cpp : Defines the logic for generating a two digit checksum
//

#include "PlainTextFileLoader.h"
#include "core/NumberConversion.h"
#include "core/FileReader.h"

#include <iostream>
#include <filesystem>

CPlainTextFileLoader::CPlainTextFileLoader()
{
}

CPlainTextFileLoader::~CPlainTextFileLoader() {}

void CPlainTextFileLoader::loadAssetIDsFromFile(
    const std::string& filePath,
    const unsigned int& minNumber,
    const unsigned int& maxNumber,
    std::vector<unsigned int>& assetIDs) const
{
    if (std::filesystem::exists(filePath))
    {
        assetIDs.clear();

        CFileReader FileReader(filePath);

        std::string text;
        auto assetID = 0;
        try
        {
            while (std::getline(FileReader.GetFileStreamInstance(), text))
            {
                //read data from file object and put it into string
                //convert string to number
                assetID = std::stoi(text);
                if ((static_cast<int>(minNumber) <= assetID) && (static_cast<int>(maxNumber) >= assetID))
                {
                    assetIDs.push_back(assetID);
                }
            }
        }
        catch (std::invalid_argument const& ex)
        {
            std::cout << "std::invalid_argument::what(): " << ex.what() << '\n';
        }
    }
    else
    {
        std::cout << "File doesn't exist : " << filePath << std::endl;
    }
}