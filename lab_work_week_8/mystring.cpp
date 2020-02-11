#include "mystring.h"
int str_m::count = 0;
str_m::str_m() {
	leng = 80;
	st = nullptr;
	count++;
}
str_m::str_m(const str_m& a) {
	this->st = new char[a.leng];
	this->leng = a.leng;
	for (int i = 0; i < this->leng - 1; i++)
	{
		this->st[i] = a.st[i];
	}
	this->st[leng - 1] = '\0';
}
str_m::str_m(str_m&& a) {
	this->count = a.count;
	this->leng = a.leng;
	this->st = a.st;
	a.st = nullptr;
}
str_m::str_m(int length) :str_m() {
	leng = length;
	st = nullptr;
}
str_m::str_m(const char* b) : str_m() {
	if (this->leng > strlen(b)) {
		st = new char[leng];
		for (int j = 0; j < strlen(b); j++)
		{
			st[j] = b[j];
		}
		st[strlen(b)] = '\0';
	}
	else
	{
		st = new char[strlen(b) + 1];
		this->leng = strlen(b) + 1;
		for (int j = 0; j < this->leng - 1; j++)
		{
			st[j] = b[j];
		}
		st[leng - 1] = '\0';
	}
}
str_m::~str_m() {
	delete[]this->st;
}
void str_m::print() {
	std::cout << this->st;
	std::cout << std::endl;
}
void str_m::init() {
	if (st == nullptr) {
		st = new char[this->leng];
		int i = 0;
		while (i < leng - 1)
		{
			if ((st[i] = getchar()) == 13) {
				st[i] = '\0';
				std::cout << '\n';
				break;
			}
			else
			{
				std::cout << st[i];
				i++;
			}

		}
		st[leng - 1] = '\0';
		std::cout << std::endl;
	}
	else
	{
		int i = 0;
		while (st[i] != '\0')
		{
			++i;
		}
		while (i < leng - 1)
		{
			if ((st[i] = getchar()) == 13) {
				st[i] = '\0';
				std::cout << '\n';
				break;
			}
			else
			{
				std::cout << st[i];
				i++;
			}

		}
		st[leng - 1] = '\0';
		std::cout << std::endl;
	}
}
int str_m::Get_count() {
	return count;
}
void str_m::push(char a, int i) {
	if (this->st == nullptr) {
		st = new char[this->leng];
		st[i] = a;
	}
	else {
		st[i] = a;
	}
}
str_m& str_m::operator=(const str_m& a) {
	this->st = new char[a.leng];
	this->leng = a.leng;
	for (int i = 0; i < this->leng - 1; i++)
	{
		this->st[i] = a.st[i];
	}
	this->st[leng - 1] = '\0';
	return *this;
}
str_m& str_m::operator=(const char*& a) {
	this->st = new char[strlen(a) + 1];
	this->leng = strlen(a) + 1;
	for (int i = 0; i < this->leng - 1; i++)
	{
		this->st[i] = a[i];
	}
	this->st[leng - 1] = '\0';
	return *this;
}
str_m str_m::operator*(str_m& b) {
	str_m ner;
	int k = 0;
	for (int i = 0; i < this->leng; i++) {
		for (int j = 0; j < b.leng; j++) {
			if (this->st[i] == '\0' || b.st[j] == '\0') {
				break;
			}
			if (this->st[i] == b.st[j]) {
				char a = this->st[i];
				ner.push(a, k);
				k++;
			}

		}
	}
	ner.push('\0', k);
	return ner;
}
str_m str_m::operator/(str_m& b) {
	str_m ner;
	int k = 0;
	bool same{ false };
	for (int i = 0; i < this->leng; i++) {
		for (int j = 0; j < b.leng; j++) {
			if (this->st[i] == b.st[j]) {
				same = true;
			}
		}
		if (!same) {
			char a = this->st[i];
			ner.push(a, k);
			k++;
		}
		same = false;
	}
	ner.push('\0', k);
	return ner;
}
str_m& str_m::operator+=(std::string& a) {
	int i{ 0 };
	while (this->st[i] != '\0') {
		i++;
	}
	for (int j = i, k = 0; j < this->leng; j++) {
		if (k == a.length()) {
			this->st[j] = '\0';
			break;
		}
		else {
			this->st[j] = a[k];
			k++;
		}
	}
	return *this;
}
str_m& str_m::operator+=(const str_m& a) {
	int i{ 0 };
	while (this->st[i] != '\0') {
		i++;
	}for (int j = i, k = 0; j < this->leng; j++) {
		if (k == a.leng) {
			this->st[j] = '\0';
			break;
		}
		else {
			this->st[j] = a.st[k];
			k++;
		}
	}
	return *this;
}
bool str_m::operator==(const str_m& a) {
	if (this->leng != a.leng) {
		return false;
	}
	else {
		for (int i = 0; i < this->leng; i++) {
			if (this->st[i] != a.st[i]) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}
bool str_m::operator!=(const str_m& a) {
	return !(*this == a);
}
bool str_m::operator<(const str_m& a) {
	int q{ 0 }, z{ 0 };
	while (this->st[z] != '\0')
	{
		z++;
	}
	while (a.st[q] != '\0')
	{
		q++;
	}
	return z < q;
}
bool str_m::operator>(const str_m& a) {
	return !(*this < a);
}
bool str_m::operator<=(const str_m& a) {
	int q{ 0 }, z{ 0 };
	bool break_point{ false };
	for (int i = 0; i < this->leng; i++)
	{
		if (this->st[i] == '\0' || break_point) {
			break_point = true;
			break;
		}
		else
		{
			z++;
		}
	}
	break_point = false;
	for (int i = 0; i < a.leng; i++)
	{
		if (a.st[i] == '\0' || break_point) {
			break_point = true;
			break;
		}
		else
		{
			q++;
		}
	}
	return z <= q;
}
bool str_m::operator>=(const str_m& a) {
	return !(*this <= a);
}
str_m::operator int() {
	int res{ 0 };
	for (int i = 0; i < this->leng; i++)
	{
		if (st[i] == '\0') {
			break;
		}
		res++;
	}
	return res;
}
str_m::operator char* () {
	int count{ 0 };
	while (this->st[count] != '\0') {
		count++;
	}
	char* res = new char[count + 1];
	for (int i = 0; i < count; i++)
	{
		res[i] = this->st[i];
	}
	res[count] = '\0';
	return res;
}
str_m::operator double() {
	double res{ 0 };
	bool finish{ false };
	for (int i = 0; i < this->leng; i++)
	{
		if (st[i] == '\0') {
			finish = true;
		}
		if (!finish) {
			res += static_cast<double>(this->st[i]);
		}
	}
	return res;
}
char& str_m::operator[](int& a) {
	return this->st[a];
}
int str_m::operator()(char& a) {
	for (int i = 0; i < this->leng; i++) {
		if (st[i] == a) {
			return i;
		}
	}
	return -1;
}
