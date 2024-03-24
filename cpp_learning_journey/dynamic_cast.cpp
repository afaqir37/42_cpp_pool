#include <iostream>

class B {
    public:
        virtual ~B() {}
};

class A : public B {
    public:
        virtual ~A() {}
};

class C : public B {
    public:
        virtual ~C() {}
};


int main() {
    B* base = new A;

    A &obj = dynamic_cast<A&>(*base);
}