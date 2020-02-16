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
	return true;
}
bool Dictionary_on_map::Save_to_file() {
	auto iter = this->dictionary_angl.begin();
	std::ofstream file;
	file.open(this->path_to_file);
	for (;iter  != this->dictionary_angl.end(); iter++)
	{
		std::pair < std::string, std::string > a= *iter;
		file << a.first << " " << a.second << "\n";
	}
	iter = this->dictionary_rus.begin();
	for (; iter!=this->dictionary_rus.end(); iter++)
	{
		std::pair < std::string, std::string > a = *iter;
		file << a.first << " " << a.second << "\n";
	}
	file.close();
	return true;
}
bool Dictionary_on_map::Add_word(std::string word, std::string trans) {
	std::pair<std::string, std::string> a(word, trans);
	if (word[0] < 0) {
		this->dictionary_rus.insert(a);
	}
	else
	{
		this->dictionary_angl.insert(a);
	}
	return true;
}
bool Dictionary_on_map::Search_word(std::string& a) {
	if (a[0]<0)
	{
		auto iter =this->dictionary_rus.find(a);
		if (iter==this->dictionary_rus.end())
		{
			std::cout << " No word in dictionary\n";
			return false;
		}
		else {
			std::pair < std::string, std::string>a = *iter;
			std::cout << "Word : " << a.first << " Translation :" << a.second << "\n";
		}
		return true;
	}
	else {
		auto iter =this->dictionary_angl.find(a);
		if (iter == this->dictionary_angl.end())
		{
			std::cout << " No word in dictionary\n";
			return false;
		}
		else {
			std::pair < std::string, std::string>a = *iter;
			std::cout << "Word : " << a.first << " Translation :" << a.second << "\n";
		}
		return true;
	}
}
bool Dictionary_on_map::Edit_translation(std::string word, std::string new_translation) {
	try
	{
		if (word[0]<0)
		{
			this->dictionary_rus.at(word) = new_translation;
			return true;
		}
		else {
			this->dictionary_angl.at(word) = new_translation;
			return true;
		}
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
		return false;
	}
}
bool Dictionary_on_map::Delete_word(std::string word) {
	if (word[0] < 0) {
		this->dictionary_rus.erase(word);
		return true;
	
	}
	else
	{
		this->dictionary_angl.erase(word);
		return true;
	}
}