#include <iostream>
using namespace std;

class test {
    public:
        test()
        {
            cout << "default constructor called" << endl;
        }
        test(int a)
        {
            this->a = a;
            cout << "constructor with one argument called" << endl;
        }
        test(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
            cout << "constructor with 3 argument called" << endl;
        }

    private:
        int a, b ,c;
};

int main()
{
    test obj1;
    test obj2(10);
    test obj3(1, 2, 3);
    return 0;
}