#include "Dictionary_on_map.h"
Dictionary_on_map::Dictionary_on_map() {
	char a{ 0 };
	str_m temp;
	std::fstream file;
	std::cout << "Do you want load file from file?\t Y/N\n< ";
	std::cin >> a;
	switch (a)
	{
	case 'y':
		std::cout << "Enter path to file\n";
		std::cin >> temp;
		file.open(temp, std::ios::in | std::ios::out);
		if (!file.is_open())
		{
			std::cout << "File not foundet or wrong path\n";
		}
		else
		{
			this->path_to_file = temp;
			this->Load_from_file();
		}
		file.close();
		break;
	case 'Y':
		std::cout << "Enter path to file\n";
		std::cin >> temp;
		file.open(temp, std::ios::in | std::ios::out);
		if (!file.is_open())
		{
			std::cout << "File not foundet or wrong path\n";
		}
		else
		{
			this->path_to_file = temp;
		}
		file.close();
		break;
	}
}
void Dictionary_on_map::Load_from_file() {
	if (this->path_to_file==nullptr)
	{

	}
}