#pragma once
#include"DataFile.h"
#include "AD_File.h"
#include<iomanip>
#define ERROR_NAME "error:this name is already exist"
#define EROR_FIND_FOLDER "ERROR folder didn't found"
class Folder : public AD_File
{
	AD_File** arr_files;
	int arr_size;
	string path;
	Folder* find_Folder(Folder& currentdir, string path)throw(string);
	bool name_exsit(string name);
	
public:
	static Folder* root;
	Folder(string folder_name, string path);
	string getFullPath() { return path; }
	void addFileToArry(AD_File* add);
	Folder(const Folder& other, string path);
	const Folder& operator=(const Folder& other);
	void mkfile(string file_name, string data)throw(string);
	void mkDir(string file_name)throw(string);
	static Folder* cd(string path);
	bool operator == (const AD_File & other);
	void dir()const;
	friend bool fc(Folder& currentDir, string source, string dest);
	~Folder();


};

