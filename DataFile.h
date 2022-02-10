#pragma once
#include"AD_File.h"
class DataFile :  public AD_File
{
	string data;
public:
	DataFile(string file_name,string data);
	virtual bool operator ==(const AD_File& other)const;
	float getSize()const { return data.size()+1; }
	DataFile(const DataFile& other);
	virtual~DataFile();
};

