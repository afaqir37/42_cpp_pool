#include <iostream>
using namespace std;
void display(void);

class newClass
{
private:
    int a, b;
public:
    void setter(int num1 = 1, int num2 = 2)
    {
        a = num1;
        b = num2;
    }
    void getter()
    {
        cout << "value of a: " << a << endl;
        cout << "value of b: " << b << endl;
    }
protected:
    void display(void);
};

void newClass::display(void)
{
    cout << "this a protected function!" << endl;
}

class subClass : public newClass {
    int a;
    string name;
public:
    void setter(int num1, string str)
    {
        a = num1;
        name = str;
    }
    void display_child(void)
    {
        display();
        cout << "value of a: " << a << endl << "value of name: " << name << endl;
    }
};

class newSubClass : private subClass
{
public:
    void display_new(void)
    {
        display();
    }
};

int main()
{
    newClass obj;
    obj.setter(44, 88);
    obj.getter();
    subClass obj2;
    obj2.setter(55, "hello");
    obj2.display_child();
    cout << "--------------" << endl;
    newSubClass obj3;
    obj3.display_new();

    return 0;
}