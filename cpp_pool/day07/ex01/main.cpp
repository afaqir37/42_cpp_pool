#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printElem<int>);

    int array[] = {'a', 'b', 'c', 'd', 'e'};
    iter(array, 5, printElem<char>);
}