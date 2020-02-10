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
Program_work::Program_work() {
	this->Menu();
}
bool Program_work::Menu() {
	std::string temp;
	std::cout << "Hi Enter path to file\n";
	std::cin >> temp;
	std::fstream file;
	file.open(temp,std::ios::in|std::ios::out);
	if (!file.is_open())
	{
		return false;

	}
	else
	{
		this->path = temp;
		std::string helper;
		std::getline(file,helper);
	}
}