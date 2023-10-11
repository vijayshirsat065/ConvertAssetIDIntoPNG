#pragma once

#include <iostream>
#include <fstream>

class CFileReader
{
public:
	CFileReader(const std::string& filePath);
	~CFileReader();

	std::ifstream& getFileStreamInstance();

private:
	std::ifstream m_FileReader;
};
