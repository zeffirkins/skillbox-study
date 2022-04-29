#include <iostream>
#include <map>
#include <exception>
using namespace std;

class not_amount : public exception {
    const char* what() const noexcept override {
        return "Not many";
    }
};

class not_article : public exception {
    const char* what() const noexcept override {
        return "Not article";
    }
};

void add_for_basket (map<int, int> &store, map<int, int> &basket, int article, int count) {
    map<int, int>::iterator it = store.find(article);
    if (it == store.end()) {
        throw not_article();
    }else if (it->second < count) {
        throw not_amount();
    }else {
        it->second -= count;
        map<int, int>::iterator itr = basket.find(article);
        if (itr == basket.end()) {
            basket.insert(pair<int, int> (article, count));
        }else {
            itr->second += count;
        }
    }
}

void remove_from_basket(map<int, int> &basket, map<int, int> &store, int article, int count) {
    map<int, int>::iterator it = basket.find(article);
    if (it == basket.end()) {
        throw not_article();
    }else if (it->second < count) {
        throw not_amount();
    }else {
        it->second -= count;
        map<int, int>::iterator itr = store.find(article);
        if (itr == store.end()) {
            basket.insert(pair<int, int> (article, count));
        }else {
            itr->second += count;
        }
    }
}

int main() {
    cout << "\n---=== Product Basket ===---\n";
    int article = 1, count = 1;
    map<int, int> store;
    map<int, int> basket;

    while (article != 0 && count != 0) {
        cout << "Enter article and count product. For ending enter '0' and '0'.\n";
        cin >> article >> count;
        store.insert(pair<int, int> (article, count));
    }
    cout << "Data is load. Begin shopping!\n";

    string answer;
    while (answer != "0") {
        cout << "Enter 'add' for add product in you basket\n";
        cout << "Enter 'remove' for delete product rom basket\n";
        cout << "Enter '0' for exit from shopping\n";
        cin >> answer;
        if (answer == "add") {
            cin >> article >> count;
            try {
                add_for_basket(store, basket, article, count);
            } catch (const exception &x) {
                cerr << "Exception: " << x.what() << "\n";
            }
        }else if (answer == "remove") {
            cin >> article >> count;
            try {
                remove_from_basket(basket, store, article, count);
            } catch (const exception &x) {
                cerr << "Exception: " << x.what() << "\n";
            }
        }else if (answer == "0") break;
    }
    cout << "Goodbye!\n";
}