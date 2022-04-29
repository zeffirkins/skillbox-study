#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

vector <string> menu = {"pizza", "soup", "steak", "sushi", "salt"};
vector <thread> orders;
vector <string> available;
mutex kitchen_access;
mutex order_access;

void createOrder() {
    order_access.lock();
    srand (time(nullptr));
    this_thread::sleep_for(chrono::seconds(rand() % 5 + 5));
    string order = menu[rand() % menu.size()];
    cout << "New order: " << order << "\n";
    order_access.unlock();
    kitchen_access.lock();
    this_thread::sleep_for(chrono::seconds(rand() % 10 + 5));
    cout << order << " is ready!" << "\n";
    available.push_back(order);
    kitchen_access.unlock();
}

int main() {
    cout << "\n---=== Online_restaurant ===---\n";
    for (int i = 0; i < 10; i++) {
        orders.emplace_back(createOrder);
        orders[i].detach();
    }
    int countDelivery = 0;
    while (countDelivery < 9) {
        this_thread::sleep_for(chrono::seconds(30));
        cout << "Courier is come. He will pick-up:\n";
        for (int i = 0; i < available.size();i++) {
            cout << available[i] << "\n";
        }
        countDelivery += available.size();
        available.clear();
    }
    cout << "Well done! Restaurant is close.\n";
}