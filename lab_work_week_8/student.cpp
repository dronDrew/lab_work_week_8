#include "student.h"
person::person() {
    this->name = nullptr;
    this->sername = nullptr;
}
person::person(const char* name, const char* surname) {
    try {
        this->name = new char[(strlen(name)+1)];
        for (int i = 0; i < strlen(name); i++) {
            this->name[i] = name[i];
        }
        this->name[strlen(name)] = '\0';
        this->sername = new char[(strlen(surname)+1)];
        for (int i = 0; i < strlen(surname); i++) {
            this->sername[i] = surname[i];
        }
        this->sername[strlen(surname)] = '\0';

    }
    catch (std::bad_alloc & ex) {
        std::cout << ex.what() << std::endl;
        exit(0);
    }
}
person:: ~person() {
    if (this->name != nullptr) {
        delete[] this->name;
    }
    if (this->sername != nullptr) {
        delete[]this->sername;
    }
}
char* person::Getname() {
    try
    {
        if (this->name == nullptr) {
            throw 1;
        }
        return this->name;
    }
    catch (int)
    {
        std::cout << "name unset\n";
        exit(0);
    }
}
char* person::Getsurname() {
    try
    {
        if (this->sername == nullptr) {
            throw 1;
        }
        return this->sername;
    }
    catch (int)
    {
        std::cout << "surname unset\n";
        exit(0);
    }
}
void person::Set_name(const char* name) {
    if (this->name == nullptr) {
        try {
            this->name = new char[(strlen(name) + 1)];
            for (int i = 0; i < strlen(name); i++) {
                this->name[i] = name[i];
            }
            this->name[strlen(name)] = '\0';
        }
        catch (std::bad_alloc & ex) {
            std::cout << ex.what() << std::endl;
            exit(0);
        }
    }
    else {
        delete[] this->name;
        try {
            this->name = new char[(strlen(name) + 1)];
            for (int i = 0; i < strlen(name); i++) {
                this->name[i] = name[i];
            }
            this->name[strlen(name)] = '\0';
        }
        catch (std::bad_alloc & ex) {
            std::cout << ex.what() << std::endl;
            exit(0);
        }
    }
}
void person::Set_surname(const char* surname) {
    if (this->sername == nullptr) {
        try {
            this->sername = new char[(strlen(surname)+1)];
            for (int i = 0; i < strlen(surname); i++) {
                this->sername[i] = surname[i];
            }
            this->sername[strlen(surname)] = '\0';

        }
        catch (std::bad_alloc & ex) {
            std::cout << ex.what() << std::endl;
            exit(0);
        }
    }
    else {
        try {
            delete[] this->sername;
            this->sername = new char[(strlen(surname)+1)];
            for (int i = 0; i < strlen(surname); i++) {
                this->sername[i] = surname[i];
            }
            this->sername[strlen(surname)] = '\0';

        }
        catch (std::bad_alloc & ex) {
            std::cout << ex.what() << std::endl;
            exit(0);
        }
    }

}
void person::Save_txt() {
    std::ofstream file;
    file.open("test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        file << "Name" << " " << this->name << "\n";
        file << "Surname" << " " << this->sername << "\n";
    }
    file.close();
}
void person::Load_from_txt() {
    std::ifstream file;
    file.open("test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        std::string temp;
        std::getline(file, temp);
        int lenght = (temp.length() - 4);
        char* temp_name = new char[lenght];
        int i = 0;
        for (int j = 5; j < temp.length(); i++, j++) {
            temp_name[i] = temp[j];
        }
        temp_name[i] = '\0';
        this->Set_name(temp_name);
        delete[] temp_name;
        std::getline(file, temp);
        lenght = (temp.length() - 7);
        char* temp_surname = new char[lenght];
        i = 0;
        for (int j = 8; j < temp.length(); i++, j++) {
            temp_surname[i] = temp[j];
        }
        temp_surname[i] = '\0';
        this->Set_surname(temp_surname);
        delete[] temp_surname;
        file.close();
    }
}
std::ostream& operator <<(std::ostream& os, person& a) {
    os << a.name << "\n";
    os << a.sername;
    return os;
}
std::istream& operator >>(std::istream& is, person& a) {
    char* temp = new char[256];
    is >> temp;
    a.Set_name(temp);
    is >> temp;
    a.Set_surname(temp);
    delete[]temp;
    return is;
}
void Save_binary(person& a) {
    std::ofstream file;
    file.open("binary_test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        auto size = static_cast<int>(strlen(a.name));
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<char*>(&a.name[i]), sizeof(char));
        }
        size = static_cast<int>(strlen(a.sername));
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<char*>(&a.sername[i]), sizeof(char));
        }
        file.close();
    }
}
void Load_binary(person& a) {
    std::ifstream file;
    file.open("binary_test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        auto size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        a.name = new char[size + 1];
        for (int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char*>(&a.name[i]), sizeof(char));
        }
        a.name[size] = '\0';
        size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        a.sername = new char[size + 1];
        for (int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char*>(&a.sername[i]), sizeof(char));
        }
        a.sername[size] = '\0';
        file.close();
    }

}
//student
student::student() :person()
{
}
student::student(const char* name, const char* surname, const char* group) : person(name, surname) {
    for (int i = 0; i < strlen(group); i++) {
        this->group += group[i];
    }
}
std::string student::Getgroup() {
    return this->group;
}
void  student::Set_group(const char* group) {
    for (int i = 0; i < strlen(group); i++) {
        this->group += group[i];
    }
}
void student::Save_txt() {
    std::ofstream file;
    file.open("test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        file << "Name" << " " << this->name << "\n";
        file << "Surname" << " " << this->sername << "\n";
        file << "Group" << " " << this->group << "\n";
        file.close();
    }
}
void student::Load_from_txt() {
    std::ifstream file;
    file.open("test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        std::string temp;
        std::getline(file, temp);
        int lenght = (temp.length() - 4);
        char* temp_name = new char[lenght];
        int i = 0;
        for (int j = 5; j < temp.length(); i++, j++) {
            temp_name[i] = temp[j];
        }
        temp_name[i] = '\0';
        this->Set_name(temp_name);
        delete[] temp_name;
        std::getline(file, temp);
        lenght = (temp.length() - 7);
        char* temp_surname = new char[lenght];
        i = 0;
        for (int j = 8; j < temp.length(); i++, j++) {
            temp_surname[i] = temp[j];
        }
        temp_surname[i] = '\0';
        this->Set_surname(temp_surname);
        delete[] temp_surname;
        std::getline(file, temp);
        for (int j = 6; j < temp.length(); i++, j++) {
            this->group += temp[j];
        }
        file.close();
    }
}
std::ostream& operator <<(std::ostream& os, student& a) {
    os << a.name << "\n";
    os << a.sername << "\n";
    os << a.group;
    return os;
}
std::istream& operator >>(std::istream& is, student& a) {
    char* temp=new char[256];
    is >> temp;
    a.Set_name(temp);
    is >> temp;
    a.Set_surname(temp);
    is >> a.group;
    delete[]temp;
    return is;
}
void Save_binary(student& a) {
    std::ofstream file;
    file.open("binary_test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        auto size = static_cast<int>(strlen(a.name));
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<char*>(&a.name[i]), sizeof(char));
        }
        size = static_cast<int>(strlen(a.sername));
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        for (int i = 0; i < size; i++) {
            file.write(reinterpret_cast<char*>(&a.sername[i]), sizeof(char));
        }
        size = static_cast<int>(a.group.size());
        file.write(reinterpret_cast<char*>(&size), sizeof(size));
        file.write(a.group.data(), a.group.length());
        file.close();
    }
}
void Load_binary(student& a) {
    std::ifstream file;
    file.open("binary_test.txt");
    if (!file.is_open()) {
        std::cout << "Can`t find file\n";
    }
    else {
        auto size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        a.name = new char[size + 1];
        for (int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char*>(&a.name[i]), sizeof(char));
        }
        a.name[size] = '\0';
        size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        a.sername = new char[size + 1];
        for (int i = 0; i < size; i++) {
            file.read(reinterpret_cast<char*>(&a.sername[i]), sizeof(char));
        }
        a.sername[size] = '\0';
        size = 0;
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        a.group.resize(size);
        file.read(reinterpret_cast<char*>(&a.group.front()), size);
        file.close();
    }
}

