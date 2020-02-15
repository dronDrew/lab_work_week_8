#pragma once
#include"dependies.h"
#include "mystring.h"
class Dictionary_on_map
{
	std::map<std::string, std::string> dictionary_angl;
	std::map <std::string, std::string > dictionary_rus;
    std::string path_to_file;
public:
	Dictionary_on_map();
	bool Load_from_file();
	bool Save_to_file();
	bool Search_word(std::string& a);

};

