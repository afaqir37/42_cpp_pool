#include <iostream>
using namespace std;

int sum(int, int);
int sum(int, int, int);

int sum(int a, int b)
{
   return a + b;
}
int sum(int a, int b, int c)
{
    return a + b + c;
}

int main()
{
    cout << "Passing 1 and 2 arguments: " << sum(1, 2) << endl;
    cout << "Passing 1, 2 and 3 arguments: " << sum(1, 2, 3) << endl;
    return (0);
}