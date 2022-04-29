#include <iostream>
#include <memory>

using namespace std;

class Toy {
public:
    Toy(string _name) : name(_name) {};
    Toy () : name("SomeToy") {};
private:
    string name;
};

class smart_ptr_toy {
private:
    Toy *obj;
public:
    smart_ptr_toy() {
        obj = new Toy("SomeName");
    }

    smart_ptr_toy(string name) {
        obj = new Toy(name);
    }

    smart_ptr_toy(const smart_ptr_toy &oth) {
        obj = new Toy(*oth.obj);
    }

    smart_ptr_toy& operator = (const smart_ptr_toy& oth) {
        if (this == &oth) return *this;
        if (obj != nullptr) delete obj;
        obj = new Toy(*oth.obj);
        return *this;
    }

    ~smart_ptr_toy() {
        delete obj;
    }
};

class Dog  {

public:
    Dog(string _name, shared_ptr<Toy> toy, int _age) : name(_name), lovelyToy(toy) {
        if (_age >= 0 && _age < 30) {
            age = _age;
        }
    }

    Dog() : Dog ("Snow", make_shared<Toy>("SomeToy"), 0) {};
    Dog(string _name) : Dog(_name,make_shared<Toy>("SomeToy"), 0) {};
    Dog (int _age) : Dog("Snow",make_shared<Toy>("SomeToy"), _age) {};

    void copyLovelyToy(const Dog& oth) {
        lovelyToy = oth.lovelyToy;
    }

    void setBestie (shared_ptr<Dog> _bestie) {
        bestie = _bestie;
    }

private:
    string name;
    int age;
    shared_ptr<Toy> lovelyToy;
    weak_ptr<Dog> bestie;
};


int main() {
    shared_ptr<Toy> ball = make_shared<Toy>("Ball");
    shared_ptr<Toy> bone = make_shared<Toy>("Bone");

    shared_ptr<Dog> a = make_shared<Dog>("Sharik", ball, 10);
    shared_ptr<Dog> b = make_shared<Dog>("Druzhok", ball, 11);
    shared_ptr<Dog> c = make_shared<Dog>("Pushok", ball, 12);

    a->setBestie(b);
    b->setBestie(a);

    Dog* pa = a.get();
    Dog* pb = b.get();

    a.reset();
    b.reset();

    ball.reset();
    bone.reset();
}