#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    virtual void voice () = 0;
};

class Dog : public Animal {
public:
    virtual void voice () {
        cout << "Bark!\n";
    }
};

class Cat : public Animal {
public:
    virtual void voice () {
        cout << "Meow!\n";
    }
};


void meeting (Animal* a, Animal* b) {
    a->voice() + b-> voice();
}

int main() {
    Animal* a = new Dog();
    Animal* b = new Cat;

    meeting (a, b);
    meeting (a, a);
    meeting (b, a);
    meeting (b, b);
}