#pragma once
#include <ctime>
#include<iostream>
#include <string>
#include <typeinfo>
using namespace std;

class AD_File
{
protected:
	string file_name;
	tm* lastUpadateTime;
public:
	AD_File(const string file_name);
	AD_File(const AD_File& other);
	void set_file_name(const string name);
	string get_file_name() const{ return file_name; }
	void set_time();
	string getTime()const;
	virtual bool operator ==(const AD_File& other)const;
	virtual ~AD_File();
};

