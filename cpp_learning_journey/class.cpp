#include <iostream>

class MyClass
{
    public:
        int a;

    void func(void)
    {
        std::cout << "Hello World!\n";
    }

    void sync(void) {
        std::cout << "Test\n";
    }
};

int main()
{
    // MyClass object;
    // object.a = 42;
    // std::cout << object.a << std::endl;
    // object.func();
    void (MyClass::*ptr[2])() = {&MyClass::func, &MyClass::sync};
    MyClass obj;

    (obj.*ptr[0])();
    (obj.*ptr[1])();
}