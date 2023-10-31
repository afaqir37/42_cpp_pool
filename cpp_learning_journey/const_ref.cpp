// C++ Progam that try to increment a const reference passed by reference
#include <iostream>
using namespace std;

void _increment(const int& a)
{
    //a++;      Error since a is a read-only reference
    int &y = const_cast<int&>(a); // the const_cast operator is used to 
                                // to cast away the constness of the reference
    y++;
}

int main()
{
    int a = 42;
    printf("before a = %d\n", a);
    _increment(a);
    printf("after a = %d\n", a);
}