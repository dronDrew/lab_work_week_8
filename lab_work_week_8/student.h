#pragma once
#include "dependies.h"
class person {
protected:
    char* name;
    char* sername;
public:
    person();//done
    person(const char* name, const char* surname);//done
    virtual ~person();//done
    char* Getname();//done
    char* Getsurname();//done
    void Set_name(const char* name);//done
    void Set_surname(const char* surname);//done
    virtual void Save_txt();//done
    virtual void Load_from_txt();//done
    friend std::ostream& operator <<(std::ostream& os, person& a);//done
    friend std::istream& operator >>(std::istream& is, person& a);//done
    friend void Save_binary(person& a);//done
    friend void Load_binary(person& a);//done
};

class student :public person
{
    std::string group;
public:
    student();//done
    student(const char* name, const char* surname, const char* group);//done
    std::string Getgroup();//done
    void  Set_group(const char* group);//done
    void Save_txt()override;//done
    void Load_from_txt()override;//done
    friend std::ostream& operator <<(std::ostream& os, student& a);//done
    friend std::istream& operator >>(std::istream& is, student& a);//done
    friend void Save_binary(student& a);//done
    friend void Load_binary(student& a);//done

};