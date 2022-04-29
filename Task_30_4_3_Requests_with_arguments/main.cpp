#include <iostream>
#include <string>
#include <cpr/cpr.h>
#include <vector>
using namespace std;

int main() {
    cout << "\n---=== Requests with arguments ===---\n";
    string url = "http://httpbin.org/";
    cpr::Response r;
    vector<cpr::Pair> pairs;
    string answer;

    while (answer != "exit") {
        cout << "\nadd post get exit\n";
        cout << "->";
        cin >> answer;
        if (answer == "add") {
            cpr::Pair pair("", "");
            cout << "Key:";
            cin >> pair.key;
            cout << "Value:";
            cin >> pair.value;
            pairs.push_back(pair);
        } else if (answer == "post") {
            r = cpr::Post(cpr::Url(url + "post"), cpr::Payload(pairs.begin(), pairs.end()));
            cout << r.text << "\n";
            pairs.clear();
        }else if (answer == "get") {
            string args = "?";
            for (auto i = pairs.begin(); i != pairs.end(); i++) {
                args += i->key + '=' + i->value;
                if (i + 1 < pairs.end()) args += '&';
            }
            r = cpr::Get(cpr::Url(url + "get" + args));
            cout << r.text << "\n";
            pairs.clear();
        }
    }
}