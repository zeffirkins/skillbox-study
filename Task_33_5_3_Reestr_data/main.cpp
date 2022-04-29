#include <iostream>
#include <map>
using namespace std;

template <typename T>
T enter_data () {
    T value;
    cin >> value;
    return value;
}

template <typename Key, typename Value>
class Registry {
public:
    void add() {
        cout << "Enter key: ";
        Key key = enter_data<Key>();
        cout << "Enter value: ";
        Value value = enter_data<Value>();
        registry.insert(make_pair(key, value));
        cout << "\n===============\n";
    };

    void remove() {
        cout << "Enter key: ";
        Key key = enter_data<Key>();

        auto itf = registry.find(key);
        if (itf != registry.end()) {
            registry.erase(key);
            cout << "~ Key \"" << key << "\" was deleted\n";
        } else {
            cout << "~ Key \"" << key << "\" doesn't find\n";
        }

        cout << "\n===============\n";
    };

    void print() {
        for (const auto& key : registry) {
            cout << "Key: "  << key.first << "\n";
            cout << "Value: " << key.second << "\n";
        }
        cout << "\n===============\n";
    };

    void find() {
        cout << "Enter key: ";
        Key key = enter_data<Key>();

        auto itf = registry.equal_range(key);

        cout << "Key: " << key << "\n";
        cout << "Value: ";
        while (itf.first != itf.second) {
            std::cout << itf.first->second << ' ';
            ++itf.first;
            cout << "\n";
        }
        cout << "\n===============\n";
    };

private:
    multimap <Key, Value> registry;
};

int main() {
    Registry<string, string> myRegistry;
    bool exit = false;
    while (!exit) {
        string action;
        cout << "Enter you command:\n";
        cout << "1) add\n";
        cout << "2) remove\n";
        cout << "3) print\n";
        cout << "4) find\n";
        cout << "5) exit\n";
        cout << "=>";
        cin >> action;

        if (action == "add") myRegistry.add();
        else if (action == "remove") myRegistry.remove();
        else if (action == "print") myRegistry.print();
        else if (action == "find") myRegistry.find();
        else if (action == "exit") exit = true;
    }
    cout << "Goodbye.\n";
}