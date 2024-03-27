#include <iostream>

int main(void)
{
    int *a = new int[0];
    *a = 1;
    std::cout << *a << std::endl;
}