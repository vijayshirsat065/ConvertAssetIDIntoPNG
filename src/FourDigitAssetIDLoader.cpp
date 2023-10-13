// FourDigitAssetIDLoader.cpp : Loads asset IDs from a plain text file
//

#include "FourDigitAssetIDLoader.h"
#include "core/FileReader.h"

#include <iostream>
#include <filesystem>

namespace
{
    constexpr auto FOUR_DIGITS = 4u;
}

CFourDigitAssetIDLoader::CFourDigitAssetIDLoader()
{
}

CFourDigitAssetIDLoader::~CFourDigitAssetIDLoader() {}

const unsigned int& CFourDigitAssetIDLoader::GetNumberOfDigitsInAssetID() const
{
    return FOUR_DIGITS;
}

bool CFourDigitAssetIDLoader::loadAssetIDsFromFile(
    const std::string& filePath,
    std::vector< std::vector<char> >& assetIDs) const
{
    bool isAssetIDLoaded = false;

    if (std::filesystem::exists(filePath))
    {
        assetIDs.clear();

        try
        {
            CFileReader fileReader(filePath);
            std::string text;

            while (std::getline(fileReader.getFileStreamInstance(), text))
            {
                if (text.size() == GetNumberOfDigitsInAssetID())
                {
                    std::vector<char> assetID;
                    assetID.insert(assetID.begin(), text.begin(), text.end());

                    //read data from file object and put it into string
                    assetIDs.push_back(assetID);
                }
            }

            if (!assetIDs.empty())
            {
                isAssetIDLoaded = true;
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
    return isAssetIDLoaded;
}