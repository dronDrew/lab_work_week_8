#pragma once
#include "dependies.h"
class Smart_pointer
{
	std::string* pointer;
public:
	Smart_pointer();
	Smart_pointer(std::string *);
	Smart_pointer(const char*);
	Smart_pointer(std::string);
	~Smart_pointer();
	std::string& operator *();
};

class Program_work {
	Smart_pointer inst;
	std::string path;
public:
	bool Menu();
	bool Search();
	bool Print();
	bool change_string();
	bool change_file();
};