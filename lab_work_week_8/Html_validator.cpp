#include "Html_validator.h"
Smart_point_to_my_str::Smart_point_to_my_str() {
	this->point = nullptr;
}
Smart_point_to_my_str::Smart_point_to_my_str( char* a) {
	this->point->st = a;
	this->point->leng = strlen(a);
}
Smart_point_to_my_str::Smart_point_to_my_str(str_m a) {
	this->point->st = a.st;
	this->point->leng = a.leng;
	a.st = nullptr;
	a.leng = 0;
}
Smart_point_to_my_str::Smart_point_to_my_str(str_m* a) {
	this->point->st = a->st;
	this->point->leng=a->leng;
	a->st = nullptr;
	a->leng = 0;
}
Smart_point_to_my_str::Smart_point_to_my_str(std::string a) {
	this->point->st = a.data();

}
Smart_point_to_my_str::Smart_point_to_my_str(std::string* a) {
	
}
Smart_point_to_my_str::~Smart_point_to_my_str() {
	if (this->point!=nullptr)
	{
		free(this->point);
	}
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =( char*a) {
	if (this->point == nullptr) {
		this->point->st = a;
		this->point->leng = strlen(a);
	}
	else
	{
		delete this->point;
		this->point->st = a;
		this->point->leng = strlen(a);
	}
	return *this;
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(str_m a) {
	
	return *this;
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(str_m* a) {
	
	return *this;
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(std::string a) {
	
	return *this;
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(std::string* a) {
	
	return *this;
}
str_m& Smart_point_to_my_str::operator *() {
	return *this->point;
}