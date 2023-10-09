// FileReader.cpp : 
//

#include "FileReader.h"


CFileReader::CFileReader(const std::string& filePath)
	: m_FileReader(filePath)
{
	
}

CFileReader::~CFileReader()
{
	if (m_FileReader.is_open())
	{
		m_FileReader.close();
	}
}

std::ifstream& CFileReader::GetFileStreamInstance()
{
	return m_FileReader;
}