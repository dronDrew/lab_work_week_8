#pragma once
#include"dependies.h"
#include "mystring.h"
class Smart_point_to_my_str {
	str_m* point;
	bool from_object;
public:
	friend class Html_validator;
	Smart_point_to_my_str();
	Smart_point_to_my_str(str_m& a);
	Smart_point_to_my_str(str_m* a);
	~Smart_point_to_my_str();
	Smart_point_to_my_str& operator =(str_m& a);
	Smart_point_to_my_str& operator =(str_m* a);
	str_m& operator *();
};
class Html_validator
{
	Smart_point_to_my_str p;
	str_m path;
public:
	Html_validator();
	void chack_html();
};

