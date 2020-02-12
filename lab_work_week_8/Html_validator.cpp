#include "Html_validator.h"
Smart_point_to_my_str::Smart_point_to_my_str() {
	this->point = nullptr;
	this->from_object = false;
}
Smart_point_to_my_str::Smart_point_to_my_str(str_m& a) {
	this->point = &a;
	this->from_object = true;
	
}
Smart_point_to_my_str::Smart_point_to_my_str(str_m* a) {
	this->point->st = a->st;
	this->point->leng=a->leng;
	a->st = nullptr;
	a->leng = 0;
	this->from_object = false;
}
Smart_point_to_my_str::~Smart_point_to_my_str() {
	if (this->from_object==false)
	{
		free(this->point);
	}
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(str_m& a) {
	this->point = &a;
	this->from_object = true;
	return *this;
}
Smart_point_to_my_str& Smart_point_to_my_str::operator =(str_m* a) {
	if (this->point != nullptr) {
		delete[]this->point;
		this->point->st = a->st;
		this->point->leng = a->leng;
		a->st = nullptr;
		a->leng = 0;
		this->from_object = false;
	}
	else
	{
		this->point->st = a->st;
		this->point->leng = a->leng;
		a->st = nullptr;
		a->leng = 0;
		this->from_object = false;
	}
	return *this;
}
str_m& Smart_point_to_my_str::operator *() {
	return *this->point;
}
Html_validator::Html_validator() {
	this->path.st = nullptr;
	std::cout << "Enter path to file\n";
	char* temp = new char[500];
	std::cin >> temp;
	std::ifstream file;
	file.open(temp);
	if (!file.is_open()) {
		std::cout << "File not found\n";
	}
	else
	{
		std::cout << "File load\n";
		this->path = temp;
	}
	delete[]temp;
	file.close();
}
void Html_validator::chack_html() {
	if (this->path.st == nullptr)
	{
		exit(0);
	}
	std::ifstream file;
	file.open(this->path);
	int j{ 0 };
	str_m temp;
	while (!file.eof())
	{
		getline(file, temp, '<', '>');
		if (temp=="3") {
			std::cout << "Problem in place :\n";
			std::cout << j+1 << std::endl;
			exit(0);
		}
		if (temp != "2")
		{
			j += temp.Get_lenght();
			this->p = temp;
			char opened = 0;
			char closed = 0;
			for (int i = 0; i < temp.leng; i++)
			{
				if (p.point->st[i] == '<') {
					opened = p.point->st[i];
				}
				if (p.point->st[i] == '>') {
					closed = p.point->st[i];
				}
			}
			if (opened == '<' && closed != '>')
			{
				std::cout << "Problem in file in row in TEG :\n";
				p.point->print();
				exit(0);
			}
			else if (opened != '<' && closed == '>')
			{
				std::cout << "Problem in file in row in TEG :\n";
				p.point->print();

			}
			j++;
		}
	}
	std::cout << "File is valid " << std::endl;
}