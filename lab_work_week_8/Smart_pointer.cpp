#include "Smart_pointer.h"
//smart pointer
Smart_pointer::Smart_pointer() {
    this->pointer = nullptr;
}
Smart_pointer::Smart_pointer(std::string* a) {
    this->pointer = a;
}
Smart_pointer::Smart_pointer(const char* a) {
    this->pointer = new std::string(a);
}
Smart_pointer::Smart_pointer(std::string a) {
    this->pointer = &a;
}
Smart_pointer::~Smart_pointer() {
    delete pointer;
}
std::string& Smart_pointer::operator *() {
    return *this->pointer;
}
Smart_pointer& Smart_pointer::operator =(std::string* a) {
    this->pointer = a;
    a = nullptr;
    return *this;
}
Smart_pointer& Smart_pointer::operator =(const char* a) {
    if (this->pointer == nullptr) {
        this->pointer = new std::string(a);
    }
    else {
        delete this->pointer;
        this->pointer = new std::string(a);
    }
    return *this;
}
Smart_pointer& Smart_pointer::operator =(std::string a) {
    this->pointer = &a;
    return *this;
}
//list position
List_position::element::element(int position, int time_coll, int time_change) {
    this->next = nullptr;
    this->position = position;
    this->time_call = time_coll;
    this->time_change = time_change;
}
List_position::List_position() {
    this->Top = nullptr;
}
List_position::~List_position() {
    if (this->Top != nullptr) {
        this->Delete_all();
    }
}
void List_position::Add(int position,int time_call,int time_change) {
    if (this->Top==nullptr)
    {
        Top = new element(position, time_call, time_change);
    }
    else {
        element* temp = this->Top;
        while (temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = new element(position, time_call, time_change);
    }
}
void List_position::Delete_all() {
    while (this->Top!=nullptr)
    {
        if (this->Top->next == nullptr) {
            element *temp = this->Top;
            delete temp;
            temp = nullptr;
            this->Top = temp;
        }
        else
        {
            element* temp = this->Top;
            while (temp->next->next!=nullptr)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;

        }
    }

}
void  List_position::call_to_position(int position) {
    element* temp = this->Top;
    while (temp->position!=position)
    {
        temp = temp->next;
    }
    temp->time_call++;
    std::cout << "You searck row " << position << " " << temp->time_call << " times\n";
}
void  List_position::change_position(int position) {
    element* temp = this->Top;
    while (temp->position != position)
    {
        temp = temp->next;
    }
    temp->time_change++;
    std::cout << "You change row " << position << " " << temp->time_change << " times\n";
}


//program
Program_work::Program_work() {
    this->Menu();
}
bool Program_work::Menu() {
    std::string temp;
    std::cout << "Hi Enter path to file\n";
    std::cin >> temp;
    std::fstream file;
    file.open(temp, std::ios::in | std::ios::out);
    if (!file.is_open())
    {
        std::cout << "Can`t find a file\n";
        return false;

    }
    else
    {
        system("CLS");
        this->path = temp;
        int i = 0;
        std::string data;
        while (true) {
            std::getline(file, data);
            if (file.eof()) {
                break;
            }
            this->statistic.Add(i + 1);
            i++;
        }
        file.close();
        bool run = true;
        while (run)
        {
            std::cout << "________________________Menu________________________\n";
            std::cout << " 1----Press to view all file on screen\n";
            std::cout << " 2----Press to change string in file \n";
            std::cout << " 3----Press to search string in file\n";
            std::cout << " 4----Press to change file backward\n";
            int choice{ 0 };
            std::cin >> choice;
            system("CLS");
            switch (choice) {
            case 1:
                Print();
                Sleep(3000);
                system("CLS");
                break;
            case 2:
                this->change_string();
                Sleep(3000);
                system("CLS");
                break;
            case 3:
                this->Search();
                Sleep(3000);
                system("CLS");
                break;
            case 4:
                this->change_file();
                Sleep(3000);
                system("CLS");
                break;
            default:
                run = false;
                system("CLS");
                std::cout << "Bey!\n";
                break;
            }
        }
    }
    return true;
}
bool Program_work::Print() {
    std::ifstream file;
    file.open(this->path);
    std::string data;
    while (true) {
        std::getline(file, data);
        if (file.eof()) {
            break;
        }
        this->inst = data.data();
        std::cout << *this->inst << "\n";
    }
    file.close();
    return true;
}
bool Program_work::change_string() {
    std::fstream file;
    file.open(this->path, std::ios::in | std::ios::out);
    std::string data;
    int i = 0;
    while (true) {

        std::getline(file, data);
        std::cout << data << std::endl;
        char a;
        std::cout << "Do you want to change this->string?  Y/N";
        std::cin >> a;
        if (a == 'Y' || a == 'y') {
            this->inst = data.data();
            std::cout << "Enter new string\n";
            std::cin.ignore();
            std::getline(std::cin, *this->inst);
            long pos = file.tellp();
            file.seekp(pos - (data.length() + 1));
            file << *this->inst;
            file << "\n";
            this->statistic.change_position(i + 1);
        }
        if (file.eof()) {
            return true;
        }
        i++;
        std::getline(file, data);
        std::cout << data << std::endl;
        std::cout << "Do you want to change this->string?  Y/N";
        std::cin >> a;
        if (a == 'Y' || a == 'y') {
            this->inst = data.data();
            std::cout << "Enter new string\n";
            std::cin.ignore();
            std::getline(std::cin, *this->inst);
            long pos = file.tellp();
            file.seekp(pos - (data.length() + 1));
            file << *this->inst;
            file << "\n";
            this->statistic.change_position(i + 1);


        }
        file.close();
        return true;
    }
}
bool Program_work::Search() {
    std::cout << "Enter string to search\n";
    std::cin.ignore();
    std::string temp;
    std::getline(std::cin, temp);
    this->inst = temp.data();
    std::ifstream file;
    file.open(this->path);
    std::string data;
    long pos{ 0 };
    int i = 0;
    while (*this->inst != data) {
        std::getline(file, data);
        if (file.eof()) {
            break;
        }
        i++;
    }
        this->inst = data.data();
        //std::cout<<*this->inst<<"\n";
        pos = file.tellg();
   

    std::cout << "I fing in position - " << pos<<"\n";
    this->statistic.call_to_position(i);
    file.close();
    return true;
}
bool Program_work::change_file() {
    std::ifstream file;
    file.open(this->path);
    std::string data;
    std::string temp;
    while (true) {
        if (file.eof()) {
            break;
        }

        std::getline(file, temp);
        if (temp == "\0") {
            break;
        }
        data += temp;
        data += '\n';

    }
    file.close();
    std::ofstream file_1;
    file_1.open(this->path);
    int leng = data.length() - 1;
    for (int i = leng; i >= 0; i--) {
        if (data[i] == '\n' | i == 0) {
            for (int j = i; j < leng; j++) {
                if (data[j] != '\n') {
                    file_1.put(data[j]);
                }
            }
            if (i != leng) {
                file_1.put('\n');
            }
            leng = i;
        }
    }
    file_1.close();
    std::cout << "Procesing\n";
    return true;
}
