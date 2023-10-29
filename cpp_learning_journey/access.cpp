#include <iostream>
using namespace std;

class newClass
{
private:
    int a, b;
public:
    void setter(int aa = 1, int ba = 2)
    {
        a = aa;
        b = ba;
    }
    void getter()
    {
        cout << "value of a: " << a << endl;
        cout << "value of b: " << b << endl;
    }
};

int main()
{
    newClass obj;
    obj.setter(44, 88);
    obj.getter();
    return 0;
}