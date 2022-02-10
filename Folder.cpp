#include "Folder.h"
string tmp1 = "root";
string tmp2 = "";
Folder* Folder :: root=new Folder(tmp1, tmp2);
Folder::Folder(string folder_name, string path) :AD_File(folder_name), arr_files(nullptr), arr_size(0)
{
	this->path =path+ "\\" + folder_name;
}
Folder* Folder::find_Folder(Folder& currentdir, string path)throw (string)
{
	
	Folder* foldertmp=&currentdir;
	do
	{
		
		bool flag = false;
		if (path.at(0) == '\\')path.erase(0, path.find_first_of('\\'));// for case the path star whit "\"
		int pos = path.find_first_of("\\");
		if (pos == -1)
		{
			for (int i = 0; i < foldertmp->arr_size; i++)
				if (foldertmp->arr_files[i]->get_file_name() == path)
					return(Folder*)foldertmp->arr_files[i];
		}
		string folder_curent=path.substr(0,pos);//find the first folder in path
		for (int i = 0; i < foldertmp->arr_size; i++)
		{
			if (foldertmp->arr_files[i]->get_file_name() == folder_curent)
			{
				foldertmp = (Folder*)foldertmp->arr_files[i];
				flag = true; 
				path.erase(0,path.find("\\")+1);break;
			}
			
		}
		if (!flag)throw EROR_FIND_FOLDER;
	} while (true);

}

bool Folder::name_exsit(string name)
{
	for (int i = 0; i < arr_size; i++)
	{
		if (arr_files[i]->get_file_name() == file_name)
			return true;
	}
	return false;
}



void Folder::addFileToArry(AD_File* add)
{
	AD_File** newarr = new AD_File * [arr_size + 1];
	for (int i = 0; i < arr_size; i++)
	{
		newarr[i] = this->arr_files[i];
	}
	newarr[arr_size++] = add;
	delete[] arr_files;
	arr_files = newarr;
	
}

Folder::Folder(const Folder& other, string path):AD_File(other.file_name)
{
	*this = other;
}

const Folder& Folder::operator=(const Folder& other)
{
	if (*this == other)return other;
	for (int i = 0; i <arr_size; i++)
	{
		delete arr_files[i];
	}
	delete[]arr_files;
	arr_files = new AD_File * [other.arr_size];
	this->arr_size = other.arr_size;
	this->path = other.path;
	for (int i = 0; i < arr_size; i++)
	{
		arr_files[i] = other.arr_files[i];
	}
	return *this;
	
}

void Folder::mkfile(string file_name, string data) throw(string)
{
	if(name_exsit(file_name)) throw ERROR_NAME;
	DataFile* newdata = new DataFile(file_name,data);
	AD_File* tmp = dynamic_cast<AD_File*>(newdata);
	addFileToArry(tmp);
}

void Folder::mkDir(string file_name) throw(string)
{
	if (name_exsit(file_name)) throw ERROR_NAME;
	Folder* newfolder= new Folder(file_name,this->path);
	AD_File* tmp = dynamic_cast<AD_File*>(newfolder);
	addFileToArry(tmp);
}

 Folder* Folder::cd(string path)
{
	Folder* tmp = Folder::root;
	tmp=tmp->find_Folder(*tmp, path);
	if (tmp) return tmp; 
}

bool Folder::operator==(const AD_File& other)
{
	bool x;
	const Folder* tmp = dynamic_cast<const Folder*>(&other);
	if (tmp)
	{
		
			for (int i = 0; i < this->arr_size; i++)
			{
				if (!(AD_File*)this->arr_files[i]->operator==(*tmp->arr_files[i]))return false;
				x=this->arr_files[i]->operator== (*tmp->arr_files[i]);
			}
			return x;
			
	}
	else return false;
	
}

void Folder::dir() const
{
	if (this->arr_size == 0) cout << "Empty directory"<<endl;
	else cout << "Files in directory " << this->file_name << ":" << endl;
	for (int k = 0; k < arr_size; k++)
	{
		if (typeid(*(this->arr_files[k]))== typeid(Folder)) {
		Folder* tmp1 = dynamic_cast<Folder*>(arr_files[k]);
		cout << right <<tmp1->getTime() << "  <DIR>";
	    cout << right << setw(12) << setfill(' ') << tmp1->file_name << endl;
		}
		else
		{
			DataFile* tmp1 = dynamic_cast<DataFile*>(arr_files[k]);
			cout << tmp1->getTime() << right << setw(12) << setfill(' ') << tmp1->getSize()*pow(10,-3) << " KB " << tmp1->get_file_name() << endl;
		}
	}
}
Folder::~Folder()
{
	for (int i = 0; i < root->arr_size; i++)
	{
		delete root->arr_files[i];
	}
	delete root;
}

