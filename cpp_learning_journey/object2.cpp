// Passing objects by POINTER
#include <iostream>
using namespace std;

class complex {
    int real, imag;

    public:
        void getData(int r, int i);
        void addData(complex *obj1, complex *obj2); // pass by reference
        void showData();
};

void complex::getData(int r, int i)
{
    real = r;
    imag = i;
}

void complex::addData(complex *obj1, complex *obj2)
{
    real = obj1->real + obj2->real;
    imag = obj1->imag + obj2->imag;
}

void complex::showData()
{
    cout << real << "+" << imag << "i" << endl;
}

int main()
{
    complex c1, c2, c3;
    c1.getData(9, 9);
    c1.showData();
    c2.getData(4, 2);
    c2.showData();
    c3.addData(&c1, &c2);
    c3.showData();
}