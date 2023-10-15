// FileReader.cpp : 
//

#include "FileWriter.h"


CFileWriter::CFileWriter(const std::string& filePath)
	: m_FileWriter(filePath)
{
	
}

CFileWriter::~CFileWriter()
{
	if (m_FileWriter.is_open())
	{
		m_FileWriter.close();
	}
}

std::ofstream& CFileWriter::getFileStreamInstance()
{
	return m_FileWriter;
}