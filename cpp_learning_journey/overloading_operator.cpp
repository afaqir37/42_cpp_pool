// C++ program to demonstrate how operator overloading works

#include <iostream>
using namespace std;

class complex {
    private:
        int real, imag;

    public:
        complex(int real, int imag);
        void print();
        complex operator+(complex op);
};

complex::complex(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

void complex::print()
{
    cout << real << " + " << imag << "i" << endl;
}

complex complex::operator+ (complex op)
{
    return complex(real + op.real, imag + op.imag);
}

int main(void)
{
    complex c1(2, 5);
    c1.print();
    complex c2(1, 9);
    c2.print();

    complex c3 = c1 + c2;
    c3.print();

    return 0;
}