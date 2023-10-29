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
<<<<<<< Updated upstream
#### iostreamm header
=======
###### <ins>iostreamm header</ins>
>>>>>>> Stashed changes
- The standard input and output is performed using header iostream.
- It is a standard library which consists four standard input output objects i.e 'cin', 'cout', 'cerr', 'clog'.
- '<<' is known as insertion operator.
- '>>' is known as extraction operator.
#### Examples
```cpp
// program to print hello world
#include <iostream>
int main()
{
std::cout << "hello world";
return (0);
}

```
```cpp
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
---
#### 👓 Inline functions and default arguments in C++
###### Inline functions
- An inline function is a function that is expanded in line when it is called.
- When a function is declared as 'inline', the compiler may choose to replace function calls with the actual function code at compile time. This is known as "inlining" the function. Inlining reducs the overhead of function call, which includes pushing and popping parameters onto and from the stack, and jumping to the function code.
###### Syntax
```cpp
inline return_type   function_name(parameters)
{
   // function code
}
```
###### Default arguments
- A default argument is a value provided in a function declaration that is automatically assigned by the compiler if the calling function doesn't provide a value for the argument.
- In case any value is passed, the default value is overridden.
***Example***
```cpp
#include <iostream>
void func(int a, int b = 42)
{
   std::cout << a << " " << b << endl;
}
int main(void)
{
   func(5); // the output will be : 5 42
   return (0);
}
```
---
#### <ins>Function Overloading in C++</ins>
- Function overloading is a feature of object-oriented programming where two or more funtions can have the same name but different parameters.
- When a function name is overloaded with different jobs it is called Function Overloading.
- In Function Overloading **Function** name should be the same and the arguments should be different.
- Function Overloading can be considered as an example of a polymorphism feature in C++.
###### Example
```cpp
add(int a, int b)
add(int a, int b, int c)
```
Here, the function add() is overloaded function, one with 2 arguments and another with 3 arguments. So, when  the add() function is called with 2 arguments, the function add(int a, int b) is executed and when the add() function is called with 3 arguments, the function add(int a, int b, int c) is executed.
```cpp
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
```
---
#### <ins>Class definition and Object definition in C++</ins>
###### Class
- When we define a class, we define a blueprint for a data type.
- This doesn't actually define any data, but it does define what the class name means, that is, what an object of the class will consist of and what operations can be performed on such an object.
- A class definition starts with the keyword **class** followed by the **class name** and **class body**, enclosed by a pair of curly braces.

***<ins>Syntax</ins>***
```cpp
    class className
    {
        Access specifier;
        Data members;
        Member Functions(){}
    };
```
###### Object
- A class provides the blueprints for objects, so basically an object is created from a class.
- We declare objects of a class with exactly the same sort of declaration that we declare variables of basic types.
***<ins>Syntax</ins>***
> class_name object_name;
###### Data Member of Class
- Data members are the variables inside the class.
- Data members can be any data type like int, float, char, double etc.
***<ins>Syntax</ins>***
````cpp
    class Demo
    {
        int     member1;
        float   member2;
        char    member3;
    };
````
---
