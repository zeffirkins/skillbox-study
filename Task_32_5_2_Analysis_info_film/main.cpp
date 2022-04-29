#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
using namespace std;


int main() {
    cout << "Enter Actor name =>";
    string name;
    getline(cin, name);

    ifstream file ("film_5.json");
    if (!file.is_open ()) {
        cerr << "File is not not found!\n";
    } else {
        nlohmann::json dict;
        file >> dict;
        file.close();

        bool found = false;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            auto actor = it.value().at("Actors");
            auto role   = actor.find(name);
            if (role != actor.end()) {
                cout << it.key() << " as " << *role << "\n";
                found = true;
            }
        }

        if (!found){
            cout << "This actor is not present in these films.\n";
        }
    }
}