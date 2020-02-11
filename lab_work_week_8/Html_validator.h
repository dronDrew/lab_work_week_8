#pragma once
#include"dependies.h"
#include "mystring.h"
class Smart_point_to_my_str {
	str_m* point;
public:
	Smart_point_to_my_str();
	Smart_point_to_my_str( char*);
	Smart_point_to_my_str(str_m a);
	Smart_point_to_my_str(str_m* a);
	Smart_point_to_my_str(std::string a);
	Smart_point_to_my_str(std::string* a);
	~Smart_point_to_my_str();
	Smart_point_to_my_str& operator =( char*);
	Smart_point_to_my_str& operator =(str_m a);
	Smart_point_to_my_str& operator =(str_m* a);
	Smart_point_to_my_str& operator =(std::string a);
	Smart_point_to_my_str& operator =(std::string* a);
	str_m& operator *();
};
class Html_validator
{
	str_m path;
};

