#include "Rail_way_station_info.h"
//time
Time_depart::Time_depart() {
	this->hour = 0;
	this->minute = 0;
}
Time_depart::Time_depart(int hour, int minute) {
	this->hour = hour;
	this->minute = minute;
}
void Time_depart::Set_hour(int hour) {
	this->hour = hour;
}
void Time_depart::Set_minute(int minute) {
	this->minute = minute;
}
std::pair<int, int>Time_depart::Get_time() {
	std::pair<int, int>res(this->hour, this->minute);
	return res;
}
void Time_depart::Print_time() {
	std::cout << this->hour << ":" << this->minute << std::endl;
}
//train
Train::Train() {
	this->time.Set_hour(0);
	this->time.Set_minute(0);
	this->number_of_train = 0;
}
Train::Train(int number_of_train, int hour_depart, int minute_depart, const char* a) {
	this->number_of_train = number_of_train;
	this->time.Set_hour(hour_depart);
	this->time.Set_minute(minute_depart);
	this->end_station = a;
}
Train::~Train() {
	
}
void Train::Show_info() {
	std::cout << "Number of Train : " << this->number_of_train << std::endl;
	std::cout << "Time of departure :";
	this->time.Print_time();
	std::cout << "End station : ";
	this->end_station.print();
}
int Train::Get_number_of_train() {
	return this->number_of_train;
}
std::pair<int, int> Train::Get_time_of_departure() {
	return this->time.Get_time();
}
str_m Train::Get_and_station() {
	return this->end_station;
}
std::ostream& operator<<(std::ostream& out, Train& a) {
	a.Show_info();
	return out;
}
Train& Train::operator =(Train& a) {
	this->number_of_train = a.number_of_train;
	this->time = a.time;
	this->end_station = a.end_station;
	return *this;
}
//Rail_way;
void Rail_way_station_info::Add_train(int number_of_train, int hour_depart, int minute_depart, const char* a) {
	Train  temp(number_of_train, hour_depart, minute_depart, a);
	this->rain.push_back(temp);
}
void Rail_way_station_info::Print_all_Trains() {
	auto iter = this->rain.begin();
	for (;iter!=this->rain.end(); ++iter)
	{
		std::cout<<*iter;
	}
}
void Rail_way_station_info::Search_train(int Number_of_train) {
	auto iter = this->rain.begin();
	for (; iter != this->rain.end(); ++iter)
	{
		Train temp;
		temp = *iter;
		if (Number_of_train == temp.Get_number_of_train()) {
			std::cout << temp;
			break;
		}
	}

}
void  Rail_way_station_info::Search_train(int hour_depart, int minute_depart) {
	auto iter = this->rain.begin();
	std::pair<int, int> temp_time(hour_depart, minute_depart);
	for (; iter != this->rain.end(); ++iter)
	{
		Train temp;
		temp = *iter;
		if ( temp_time==temp.Get_time_of_departure() ) {
			std::cout << temp;
			break;
		}
	}
}
void  Rail_way_station_info::Search_train(std::pair<int, int>& Time_depature) {
	auto iter = this->rain.begin();
	for (; iter != this->rain.end(); ++iter)
	{
		Train temp;
		temp = *iter;
		if (Time_depature == temp.Get_time_of_departure()) {
			std::cout << temp;
			break;
		}
	}
}
void  Rail_way_station_info::Search_train(const char* a) {
	str_m point = a;
	auto iter = this->rain.begin();
	for (; iter != this->rain.end(); ++iter)
	{
		Train temp;
		temp = *iter;
		if (temp.Get_and_station()==point) {
			std::cout << temp;
			break;
		}
		
	}
}
void  Rail_way_station_info::Search_train(str_m& a) {
	auto iter = this->rain.begin();
	for (; iter != this->rain.end(); ++iter)
	{
		Train temp;
		temp = *iter;
		if (temp.Get_and_station() == a) {
			std::cout << temp;
			break;
		}

	}
}