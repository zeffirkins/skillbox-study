#include <iostream>
using namespace std;

class Toy {
public:
    Toy(string _name) : name(_name) {};
    Toy () : name("SomeToy") {};

    string getName() const {
        return name;
    }
private:
    string name;
};


class shared_ptr_toy {
private:
    Toy* obj = nullptr;
    int* countRef = nullptr;

    void initiation() {
        countRef = new int(1);
    }

    void lower() {
        if(--*countRef == 0) {
            cerr << "Toy with name " << obj->getName() << " was deleting.\n";
            delete obj;
            delete countRef;
        }
    }

public:
    shared_ptr_toy() {
        obj = new Toy("SomeName");
        initiation();
    }

    shared_ptr_toy(string _name) {
        obj = new Toy(_name);
        initiation();
    }

    shared_ptr_toy(const shared_ptr_toy &oth) {
        obj = new Toy(*oth.obj);
        initiation();
    }


    shared_ptr_toy& operator = (const shared_ptr_toy& oth) {
        if (countRef != oth.countRef) {
            lower();
            obj = oth.obj;
            countRef = oth.countRef;
            ++*countRef;
        }
        return *this;
    }

    Toy* operator->() const{
        return obj;
    }

    ~shared_ptr_toy() {
        lower();
    }
};

template<typename ... Args>
shared_ptr_toy make_shared_toy(Args&&... args) {
    return shared_ptr_toy(forward<Args>(args)...);
}

int main() {
    shared_ptr_toy a;
    shared_ptr_toy b = a;

    shared_ptr_toy c = make_shared_toy("Bone");

    cout << a->getName() << "\n";
    cout << b->getName() << "\n";
    cout << c->getName() << "\n";
}