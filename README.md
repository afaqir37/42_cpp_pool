# 42_cpp_pool

There are six fundamental concepts of OOPs
- Class
- Objects
- Abstraction
- inheritance
- Encapsulation
- Polymorphism
---
- Objects are instance created using class.
- Each object has their own data and function. Each objects can interact with each other with the help of message pass.
- For interacting, they don't need to have the internal knowledge of each other data and code.
---
- Using inheritance, a child class can inherit the data and code or common properties from the base class.
- inheritance provide code reusablity.
---
- Abstraction include hiding the implemenation detail from the world and showing only the relevant detail to the world.
- It includes hiding something into a function or interface.
---
- Encapsulation includes wrapping up of data and functions into a single unit.
- We can hide this data from the outsidei world using access specifier.
- Encapsulation provides data securit and privacy.
---
- Polymorphism simply means having multiple forms of a same instance.
- They are of two types:
    * Overloading
    * Overriding
- Overloading example: a same function can have multiple forms which act and react differently according to situation.
- Overriding example: a child class can implement function from parent class according to its need.
---
###### iostreamm header
- The standard input and output is performed using header iostream.
- It is a standard library which consists four standard input output objects i.e 'cin', 'cout', 'cerr', 'clog'.
- '<<' is known as insertion operator.
- '>>' is known as extraction operator.
###### Examples
```
// program to print hello world
#include <iostream>
int main()
{
std::cout << "hello world";
return (0);
}

```
```
// program to take two numbers and display them
#include <iostream>
using namespace std;
int main()
{
int firstNum, secondNum;
cout << "Enter two numbers:" << endl;
cin >> firstNum >> secondNum;
cout << "First number: " << firstNum << endl;
cout << "Second number: " << secondNum << endl;
return (0);
}
```
