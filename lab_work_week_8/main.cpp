#include"dependies.h"
#include"student.h"
#include "fraction.h"
#include "Smart_pointer.h"
#include "Html_validator.h"
#include "Rail_way_station_info.h"
#include "Dictionary_on_map.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");
	//Program_work k;
	//str_m b = "helllo";
	//Smart_point_to_my_str a(b);
	//Html_validator k;
	//k.chack_html();
	/*Rail_way_station_info a;
	a.Add_train(1345,13,14,"Lviv");
	a.Add_train(1346, 15, 14, "Kyiv");
	a.Add_train(1348, 18, 14, "Odessa");
	a.Print_all_Trains();
	std::cout << "---------------------------------------------------------\n";
	pair<int,int> j(13, 14);
	a.Search_train(j);
	str_m q("Odessa");
	a.Search_train(q);*/
	Dictionary_on_map a;
	a.Add_word("circle", "����");
	a.Add_word("squer", "�������");
	a.Add_word("�����������", "triangle");
	a.Save_to_file();
	std::string temp= "cake";
	a.Search_word(temp);
	temp = "�������";
	a.Search_word(temp);
	a.Edit_translation("sister", "�����");
	a.Delete_word("sister");
	return 0;
}