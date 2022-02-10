#include "AD_File.h"


AD_File::AD_File(const string file_name)
{
	set_time();
	set_file_name(file_name);
}

AD_File::AD_File(const AD_File& other)
{
	file_name = other.file_name;
	this->lastUpadateTime = other.lastUpadateTime;
}

void AD_File::set_file_name(const string name)
{
	file_name = name;
}

void AD_File::set_time()
{
	// current date/time based on current system
	time_t now = time(0);
	lastUpadateTime = localtime(&now);
}

string AD_File::getTime()const
{
	char buf[80];
	strftime(buf, sizeof(buf), "%d/%m/%Y %X", lastUpadateTime);
	string time = buf;
	return time;

}

bool AD_File::operator==(const AD_File& other)const
{
	return this->file_name == other.file_name;
}

AD_File::~AD_File()
{
}



