#include <iostream>
#include <cpr/cpr.h>
#include <vector>
using namespace std;

vector <string> list = {"get", "post", "put", "delete", "patch"};

void showCommand (vector<string> list) {
    cout << "What is you action?\n";
    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << " ";
    }
}


class Command {
public:

    void Get () {
        cpr::Response res = cpr::Get(cpr::Url("http://httpbin.org/get"));
        cout << res.text << "\n";
    }

    void Post () {
        cpr::Response res = cpr::Post(cpr::Url("http://httpbin.org/post"));
        cout << res.text << "\n";
    }

    void Put () {
        cpr::Response res = cpr::Put(cpr::Url("http://httpbin.org/put"));
        cout << res.text << "\n";
    }

    void Delete () {
        cpr::Response res = cpr::Delete(cpr::Url("http://httpbin.org/delete"));
        cout << res.text << "\n";
    }

    void Patch () {
        cpr::Response res = cpr::Patch(cpr::Url("http://httpbin.org/patch"));
        cout << res.text << "\n";
    }

    void selectCommand (string action) {
        if (action == "get") Get();
        else if (action == "post") Post();
        else if (action == "put") Put();
        else if (action == "delete") Delete();
        else if (action == "patch") Patch();
        else cout << "Incorrect action!\n";
    }
};


int main() {
    cout << "\n---=== Custom Requests ===---\n";
    Command myCommand;
    string action;
    while (action != "exit") {
        showCommand(list);
        cout << "->";
        cin >> action;
        myCommand.selectCommand(action);
    }
    cout << "\nGoodbye!\n";
}