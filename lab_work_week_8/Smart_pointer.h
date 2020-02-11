#pragma once
#include "dependies.h"
class List_position {
    struct element
    {
        int position;
        int time_call;
        int time_change;
        element* next;
        element(int position, int time_coll,int time_change);//done
    };
    element *Top;
public:
    List_position();//done
    void Add(int position,int time_call=0,int time_change=0);//done
    void Delete_all();//done
    void call_to_position(int position);
    void change_position(int position);
    void Show_statistic(int position);
    ~List_position();//done
};
class Smart_pointer
{
    std::string* pointer;
public:
    Smart_pointer();
    Smart_pointer(std::string*);
    Smart_pointer(const char*);
    Smart_pointer(std::string);
    Smart_pointer& operator =(std::string*);
    Smart_pointer& operator =(const char*);
    Smart_pointer& operator =(std::string);
    ~Smart_pointer();
    std::string& operator *();
};

class Program_work {
    Smart_pointer inst;
    List_position statistic;
    std::string path;
public:
    Program_work();
    bool Menu();//done
    bool Search();//done
    bool Print();//done
    bool change_string();//done
    bool change_file();//done
};
