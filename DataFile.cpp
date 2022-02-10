#include "DataFile.h"

DataFile::DataFile(string file_name,string data):AD_File(file_name),data(data)
{}
bool DataFile::operator==(const AD_File& other)const
{
	if (!AD_File::operator==(other)) return false;
	const DataFile* tmp = dynamic_cast<const DataFile*>(&other);
	return this->data == tmp->data;
}

DataFile::DataFile(const DataFile& other):AD_File(other)
{
	this->data = other.data;
}

DataFile::~DataFile()
{	
	
}


