#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

bool valid_name (string name) {
    for (int i = 0; i < name.size(); i++) {
        if (!isalpha (name[i])) return false;
    }
    return true;
}

bool valid_date (string date) {
    if (date.size() == 10) {
        int day, month, year;
        day = std::stoi(date.substr(0, 2));
        month = std::stoi(date.substr(3, 2));
        year = std::stoi(date.substr(6, 4));

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

bool valid_money (string money) {
    for (int i = 0; i < money.size(); i ++) {
        if (!isdigit (money[i])) return false;
    }
}

bool validation (string data) {
    int space = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == ' ') space++;
    }
    if (space != 3) return false;

    stringstream str (data);
    string firstname, lastname, date, money;
    str >> firstname >> lastname >> date >> money;

    if (!valid_name (firstname)) return false;
    if (!valid_name (lastname)) return false;
    if (!valid_date (date)) return false;
    if (!valid_money(money)) return false;

    return true;
}

int main() {
   string data;
   cout << "Enter First Name, Last Name, Date (DD.MM.YYYY) and Sum RUB:";
   getline(cin, data);

   if (validation(data)) {
       ofstream file("C:\\Skillbox\\vedomost.txt", ios::app);
       if(!file.is_open()){
           std::cerr<<"Error! File not open or not found.\n";
           exit(0);
       }

       file << "\n" << data << " RUB\n";
       file.close();
       cout << "Excellent! Data added to file.";
   }else {
       cout << "Data is not correct! Check them and try again.";
   }
}