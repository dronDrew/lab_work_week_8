#pragma once
#include "dependies.h"
#include"mystring.h"
class Time_depart {
	int hour;
	int minute;
public:
	Time_depart();//done
	Time_depart(int hour, int minute);//done
	void Set_hour(int hour);//done
	void Set_minute(int minute);//done
	std::pair<int, int>Get_time();//done
	void Print_time();//done
};
//////////////////////////////////////////////////////////////////////////////
class Train {
	int number_of_train;
	Time_depart time;
	str_m end_station;
public:
	Train();
	Train(int number_of_train, int hour_depart, int minute_depart, const char* a);//done
	~Train();//done
	void Show_info();//done
	int Get_number_of_train();//done
	std::pair<int, int> Get_time_of_departure();//done
	str_m Get_and_station();//done
	friend std::ostream& operator<<(std::ostream& out, Train& a);//done
	Train& operator =(Train& a);//done
};
//////////////////////////////////////////////////////////////////////////////
class Rail_way_station_info
{
	std::vector<Train>rain;
public:
	void Add_train(int number_of_train, int hour_depart, int minute_depart, const char* a);//done
	void Print_all_Trains();//done
	void Search_train(int Number_of_train);//done
	void Search_train(int hour_depart, int minute_depart);//done
	void Search_train(std::pair<int,int>& Time_depature);//done
	void Search_train(const char* a);//done
	void Search_train(str_m& a);//done
};

