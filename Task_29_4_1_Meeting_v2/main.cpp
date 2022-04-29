#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual string voice () = 0;
};

class Dog : public Animal {
public:
    virtual string voice () {
        return "Bark ";
    }
};

class Cat : public Animal {
public:
    virtual string voice () {
        return "Meow ";
    }
};

void meeting (Animal* a, Animal* b) {
    string buffer = a->voice() + b->voice();
    if (buffer == "Bark Bark ") cout << "Woof Woof ";
    else if (buffer == "Meow Meow ") cout << "Purr Purr ";
    else cout << buffer;
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat();

    cout << a->voice() << "\n";
    cout << b->voice() << "\n";

    meeting (a, b);
    meeting (b, a);
    meeting (a, a);
    meeting (b, b);
}