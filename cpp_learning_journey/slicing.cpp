#include <iostream>

class Base {
public:
    int a;

    Base(int a) : a(a) {}
};

class Derived : public Base {
public:
    int b;

    Derived(int a, int b) : Base(a), b(b) {}
};


void testSlicing(Base & obj) {
    std::cout << obj.b << std::endl;
}

int main() {
    Derived d(1, 2);
    testSlicing(d);
    return 0;
}