#include "Smart_pointer.h"
Smart_pointer::Smart_pointer() {
	this->pointer = nullptr;
}
Smart_pointer::Smart_pointer(std::string*a) {
	this->pointer = a;
}
Smart_pointer::Smart_pointer(const char*a) {
	this->pointer = new std::string(a);
}
Smart_pointer::Smart_pointer(std::string a) {
	this->pointer = &a;
}
Smart_pointer::~Smart_pointer() {
	if (this->pointer!=nullptr)
	{
		delete this->pointer;
	}
}
std::string& Smart_pointer::operator *() {
	return *this->pointer;
}