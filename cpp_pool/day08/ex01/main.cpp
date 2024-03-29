#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;
return 0;
}

// int main() {
//     Span sp = Span(5);

//     try {
//         sp.addNumber(4);
//         sp.addNumber(5);
//         sp.addNumber(6);
//         sp.addNumber(7);
//         sp.addNumber(8);
//         sp.addNumber(9);
//     } catch (std::exception& e)
//         {
//             std::cout << "Exception [max size exceeded]" << std::endl;
//         }

//     Span sp2 = Span(5);

//     try {
//         std::cout << sp2.shortestSpan() << std::endl;
//     } catch (std::exception& e)
//         {
//             std::cout << "Exception [shortestSpan on empty vector]" << std::endl;
//         }

//     try {
//         std::cout << sp2.longestSpan() << std::endl;
//     } catch (std::exception& e)
//         {
//             std::cout << "Exception [longestSpan on empty vector]" << std::endl;
//         }
    
//     std::vector<int> tmp;

//     for (int i = 0; i < 10000; i++)
//         tmp.push_back(i);

//     Span sp3 = Span(tmp.size());
//     try {
//         sp3.addRange(tmp.begin(), tmp.end());
//     } catch (std::exception& e)
//         {
//             std::cout << "Exception [max size exceeded]" << std::endl;
//     }

//     sp3.printArr();


// }