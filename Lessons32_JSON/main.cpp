#include <iostream>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;

struct Record {
    string name;
    string family;
    int age;
    bool married;
};


int main() {
    Record record;
    ifstream file("record.json");
    nlohmann::json dict;
    file >> dict;
    record.name = dict["name"];
    record.family = dict["family"];
    record.age = dict["age"];
    record.married = dict["married"];
    cout << record.name << " " << record.family << " " << record.age << " " << record.married;
}
