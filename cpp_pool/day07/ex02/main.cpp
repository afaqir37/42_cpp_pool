#include "Array.hpp"

//#define MAX_VAL 750
int main(int, char**)
{
    Array<int> array(5);

    for (unsigned int i = 0; i < array.size(); i++)
        array[i] = i;

    for (unsigned int i = 0; i < array.size(); i++)
        std::cout << array[i] << std::endl;

    try {
        array[array.size()] = 5;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Array<char> array2(5);
    array2[0] = 'a';
    array2[1] = 'b';
    array2[2] = 'c';
    array2[3] = 'd';
    array2[4] = 'e';

    for (unsigned int i = 0 ; i < array2.size(); i++)
        std::cout << array2[i] << std::endl;

    Array<std::string> array3(5);
    array3[0] = "a0";
    array3[1] = "b1";
    array3[2] = "c2";
    array3[3] = "d3";
    array3[4] = "e4";

    for (unsigned int i = 0; i < array3.size(); i++)
        std::cout << array3[i] << std::endl;

    return 0;
    // Array<int> numbers(MAX_VAL);
    // int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     const int value = rand();
    //     numbers[i] = value;
    //     mirror[i] = value;
    // }
    // //SCOPE
    // {
    //     Array<int> tmp = numbers;
    //     Array<int> test(tmp);
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {
    //     if (mirror[i] != numbers[i])
    //     {
    //         std::cerr << "didn't save the same value!!" << std::endl;
    //         return 1;
    //     }
    // }
    // try
    // {
    //     numbers[-2] = 0;
    // }
    // catch(const std::exception& e)
    // {
      
    //     std::cerr << e.what() << '\n';
    // }
    // try
    // {
    //     numbers[MAX_VAL] = 0;
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // for (int i = 0; i < MAX_VAL; i++)
    // {

    //     numbers[i] = rand();
    // }
    // delete [] mirror;//
    // return 0;
}