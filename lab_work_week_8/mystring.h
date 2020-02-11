#pragma once
#include"dependies.h"
class str_m
{
private:
	char* st;
	int leng;
	static int count;
public:
	str_m();
	str_m(const str_m& a);
	str_m(str_m&& a);
	str_m(int length);
	str_m(const char* b);
	~str_m();
	void print();
	void init();
	void push(char a, int i);
	static int Get_count();
	str_m& operator=(const str_m& a);
	str_m& operator=(const char*& a);
	str_m& operator+=(std::string& a);
	str_m& operator+=(const str_m& a);
	str_m operator*(str_m& b);
	str_m operator/(str_m& b);
	bool operator==(const str_m& a);
	bool operator!=(const str_m& a);
	bool operator<(const str_m& a);
	bool operator>(const str_m& a);
	bool operator<=(const str_m& a);
	bool operator>=(const str_m& a);
	char& operator[](int& a);
	int operator()(char& a);
	operator int();
	operator char* ();
	operator double();
	friend class Smart_point_to_my_str;
};
