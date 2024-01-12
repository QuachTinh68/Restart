#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "Base()\n";
    }
    ~Base() {
        cout << "~Base()\n";
    }
};

class Derived : public Base {
public:
    Derived() {
        cout << "Derived()\n";
    }
    ~Derived() {
        cout << "~Derived()\n";
    }
};

int main() {
    Derived d;
    Base b;
}
