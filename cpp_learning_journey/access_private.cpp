// Program that access private data member of a class without using any member function
#include <iostream>
using namespace std;

class test
{
private:
    char a;
    int b;
    char c;

public: 
    void display(void)
    {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
    }
    void init(char a, int b, char c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    test obj;
    obj.init('x', 20, 'z');
    obj.display();

    char *ptr = (char *)&obj;

    // to use the below commented lines of code, we need to set the data member of the class as public.
    // we need this commented lines in case we don't know how the data members are aligned in memory so we can access to them successfully,
    // but in case we know this info, we can skip them :)
    // cout << "offsetof a: " << offsetof(test, a) << " "
    //      << "offsetof b: " << offsetof(test, b) << "offsetof c: " << offsetof(test, c) << endl;

    char num = *ptr;
    int num2 = *(int *)(ptr + 4);
    char num3 = *(char *)(ptr + 8);

    cout << "num = " << num << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3: " << num3 << endl;

    *ptr = '!';
    *(int *)(ptr + 4) = 99;
    *(char *)(ptr + 8) = '?';

    cout << "after overwiting" << endl;
    obj.display();
}