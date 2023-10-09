#pragma once

#include <iostream>
#include <fstream>

class CFileReader
{
public:
	CFileReader(const std::string& filePath);
	~CFileReader();

	std::ifstream& GetFileStreamInstance();

private:
	std::ifstream m_FileReader;
};
