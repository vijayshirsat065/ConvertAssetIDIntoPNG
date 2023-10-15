#pragma once

#include <iostream>
#include <fstream>

class CFileWriter
{
public:
	CFileWriter(const std::string& filePath);
	~CFileWriter();

	std::ofstream& getFileStreamInstance();

private:
	std::ofstream m_FileWriter;
};
