#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

struct Vedomost{
    std::string firstname;
    std::string lastname;
    std::string date;
    int money;
};

bool valid_date (string date) {
    if (date.size() == 10) {
        int day, month, year;
        day = stoi(date.substr(0, 2));
        month = stoi(date.substr(3, 2));
        year = stoi(date.substr(6, 4));

        bool leap = ((year % 4 == 0) && (year % 100 == 0 && year % 400 == 0)) ? true : false;

        if ((month == 1 || month == 3 || month == 5 || month == 7
             || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31) {
            return true;
        }else if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 1 && day <= 30) {
            return true;
        }else if (month == 2 && leap && day >= 1 && day <= 29) {
            return true;
        }else if (month == 2 && !leap && day >= 1 && day <= 28) {
            return true;
        }else return false;

    } else return false;
}

bool Verefianswer(const string &answer, Vedomost &ved){
    stringstream pars(answer);
    int count = 0;
    for(int i = 0; i<answer.size(); ++i){ // correct 3 ' '
        if(answer[i] == ' ')
            ++count;
    }

    if(count != 3){
        cerr<<"Incorrect input, not enough arguments!\n";
        return false;
    }

    string firstname, lastname, date;
    int rub;
    pars >> firstname >> lastname >> date >> rub;

    for(int i =0; i < firstname.size(); ++i){
        if(!isalpha(firstname[i])){
            cerr<<"Error first name!\n";
            return false;
        }
    }
    ved.firstname = firstname;

    for(int i =0; i < lastname.size(); ++i){
        if(!isalpha(lastname[i])){
            cerr<<"Error lastname name!\n";
            return false;
        }
    }
    ved.lastname = lastname;

    if(!valid_date(date)){
        cerr << "Incorrect date!\n";
        return false;
    }
    ved.date = date;
    ved.money = rub;
    return true;
}

bool Save(ofstream &file, Vedomost &ved){
    if(!file.is_open()){
        cerr << "Error write file" << "\n";
        return false;
    }
    int size = ved.firstname.length();
    file.write((char *)&size, sizeof(size));
    file.write(ved.firstname.c_str(), size);
    size = ved.lastname.length();
    file.write((char *)&size, sizeof(size));
    file.write(ved.lastname.c_str(), size);
    size = ved.date.length();
    file.write((char *)&size, sizeof(size));
    file.write(ved.date.c_str(), size);
    file.write((char *)&ved.money, sizeof(ved.money));
    return true;
}

bool Read(ifstream &file, Vedomost &ved){
    if(!file.is_open()){
        cerr<< "Error read file" << "\n";
        return false;
    }

    int size = 0;
    file.read((char *)&size, sizeof(size));
    if(size == 0){
        return false;
    }
    ved.firstname.resize(size);
    file.read((char*)ved.firstname.c_str(), size);

    file.read((char *)&size, sizeof(size));
    ved.lastname.resize(size);
    file.read((char *)ved.lastname.c_str(), size);

    file.read((char *)&size, sizeof(size));
    ved.date.resize(size);
    file.read((char *)ved.date.c_str(), size);

    file.read((char *)&ved.money, sizeof(ved.money));
    return true;
}

int main() {
    string answer;
    Vedomost ved;
    cout<< "Input 'add' or 'list' :" << "\n";
    getline(std::cin,answer);
    if(answer == "add"){
        cout << "Input First name, Last name, date and RUB:\n";
        getline(std::cin, answer);
        if(Verefianswer(answer, ved)){
            ofstream file("C:\\Skillbox\\vedomost.bin", ios::binary | ios::app);
            Save(file, ved);
        }
    }else if(answer == "list"){
        ifstream file("C:\\Skillbox\\vedomost.bin", ios::binary);
        int i = 1;
        while(Read(file, ved)){
            cout << i <<") " << ved.firstname << " ";
            cout << ved.lastname <<" ";
            cout << ved.date <<" ";
            cout << ved.money << "\n";
            ++i;
        }
    }else{
        cout << "Incorrect input." << "\n";
    }
}