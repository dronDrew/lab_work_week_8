#pragma once
#include"dependies.h"
#include "mystring.h"
class Dictionary_on_map
{
	std::map<str_m, str_m> dictionary_angl;
	std::map<str_m, str_m> dictionary_rus;
	str_m path_to_file;
public:
	Dictionary_on_map();
	bool Load_from_file();
	bool Save_to_file();

};

