#include <iostream>

class MyClass
{
    public:
        int a;

    void func(void)
    {
        std::cout << "Hello World!\n";
    }
};

int main()
{
    MyClass object;
    object.a = 42;
    std::cout << object.a << std::endl;
    object.func();
}