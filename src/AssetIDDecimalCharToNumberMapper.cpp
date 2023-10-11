#pragma once

#include "AssetIDDecimalCharToNumberMapper.h"

CAssetIDDecimalCharToNumberMapper::CAssetIDDecimalCharToNumberMapper() {}

CAssetIDDecimalCharToNumberMapper::~CAssetIDDecimalCharToNumberMapper() {}

unsigned int CAssetIDDecimalCharToNumberMapper::getNumberForSpecifiedChar(const char& assetIDCharacter) const
{
	auto number = 0u;
	switch (assetIDCharacter)
	{
	case '0':
		number = 0u;
		break;
	case '1':
		number = 1u;
		break;
	case '2':
		number = 2u;
		break;
	case '3':
		number = 3u;
		break;
	case '4':
		number = 4u;
		break;
	case '5':
		number = 5u;
		break;
	case '6':
		number = 6u;
		break;
	case '7':
		number = 7u;
		break;
	case '8':
		number = 8u;
		break;
	case '9':
		number = 9u;
		break;
	default:
		break;
	}
	return number;
}

char CAssetIDDecimalCharToNumberMapper::getCharForSpecifiedNumber(const unsigned int& number) const
{
	auto character = '0';
	switch (number)
	{
	case 0:
		character = '0';
		break;
	case 1:
		character = '1';
		break;
	case 2:
		character = '2';
		break;
	case 3:
		character = '3';
		break;
	case 4:
		character = '4';
		break;
	case 5:
		character = '5';
		break;
	case 6:
		character = '6';
		break;
	case 7:
		character = '7';
		break;
	case 8:
		character = '8';
		break;
	case 9:
		character = '9';
		break;
	default:
		break;
	}
	return character;
}
