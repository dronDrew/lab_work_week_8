#include "Dictionary_on_map.h"
Dictionary_on_map::Dictionary_on_map() {
	char a{ 0 };
	std::string temp;
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
bool Dictionary_on_map::Load_from_file(){
	if (this->path_to_file==""|| this->path_to_file == "\n"|| this->path_to_file == "\0")
	{
		std::cout << "Your pass is empty\n";
		exit(0);
	}
	else
	{
		std::ifstream file;
		file.open(this->path_to_file);
		std::string temp1, temp2;
		
		while (true)
		{
			file >> temp1;
			char b = temp1[0];
			if (file.eof()) {
				break;
			}
			if (b<0)
			{
				file >> temp2;
				std::pair<std::string, std::string> a(temp1, temp2);
				this->dictionary_rus.insert(a);
			}
			else
			{
				file >> temp2;
				std::pair<std::string, std::string> a(temp1, temp2);
				this->dictionary_angl.insert(a);
			}
				
				
		}
	}
}