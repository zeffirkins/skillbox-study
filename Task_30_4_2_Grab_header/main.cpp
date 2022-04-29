#include <iostream>
#include <cpr/cpr.h>
using namespace std;


int main() {
    cpr::Response res = cpr::Get(cpr::Url("http://httpbin.org/html"),
                                 cpr::Header({{"accept", "text/html"}}));
    int start = res.text.find("<h1>") + 4;
    int finish = res.text.find("</h1>");
    cout << "\n" << res.text.substr(start, finish - start) << "\n";
}