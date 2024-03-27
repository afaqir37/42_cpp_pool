#include "iter.hpp"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, printElem<int>);

    char array[] = {'a', 'b', 'c', 'd', 'e'};
    iter(array, 5, printElem<char>);

    std::string array2[] = {"a0", "b1", "c2", "d3", "e4"};
    iter(array2, 5, printElem<std::string>);
}

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }


// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, printElem<const int> );
//   iter( tab2, 5, printElem<Awesome> );

//   return 0;
// }