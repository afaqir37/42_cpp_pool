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
#### iostreamm header
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

<ins>Syntax</ins> 
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

<ins>Syntax</ins> 
```
 class_name object_name;
```
###### Data Member of Class
- Data members are the variables inside the class.
- Data members can be any data type like int, float, char, double etc.

<ins>Syntax</ins>
````cpp
    class Demo
    {
        int     member1;
        float   member2;
        char    member3;
    };
````
---
#### <ins>Data Members, Member Functions and Access Modifiers</ins>
###### Accessing the Data Members of Class
- The public data members of objects of a class can be accessed using the direct member access operator(.)
- Syntax: object.class_member;

###### <ins>Member Function of CLass</ins>
- A member function of a class is a function that has its definition or its prototype within the class definition like any other variable.
- Member functions can be defined within the class definition or separately using scope resolution operator, (::).
- Defining a member function within the class definition declares the function inline, even if we do not use the inline specifier.

###### <ins>Class Access Modifiers</ins>
- Class Access modifiers are keywords that can be used to control the visibility of fields, methods, and constructors in a class.
- The keywords public, private, and protected are called access specifiers

###### <ins>The Public Members</ins>
- A public member is accessible from anywhere outside the class but within a program.

###### <ins>The Private Members</ins>
- A private member variable or function cannot be accessed, or even viewed from outside the class. Only the class and friend functions can access private members. By default all the members of a class would be private.

###### <ins>The Protected Members</ins>
- A protected member variable or function is very similar to a private member they can be accessed in child classes which are called derived classes.

```cpp
// Program to access data members of class
#include <iostream>
using namespace std;

class Student {
    public:             // access specifier
        string name;    // data member
        string sex;     // data member
        int    id;      // data member
};

int main()
{
    Student afaqir;     // afaqir object of class Student
    // accessing data members of class student
    afaqir.id = 1;
    afaqir.name = "Faqir Abdellah";
    afaqir.sex = "Male";
    cout << "Student's details:" << endl;
    cout << "ID: " << afaqir.id << endl;
    cout << "Name: " << afaqir.name << endl;
    cout << "Sex: " << afaqir.sex << endl;
    return 0;
}
```

```cpp
// Program to demonstrate access modifiers
#include <iostream>
using namespace std;

class Student {
    private: // cannot be accessed
        string phone;
    
    public: // can be accessed
        int id;
        string name;
        string faculty;

    protected: // cannot be accessed
        string guardian_phone;
};

int main()
{
    Student abdellah;
    abdellah.phone = "XXX-XXX-XXX"; // not allowed
    abdellah.id = 42;
    abdellah.name = "faqir";
    abdellah.faculty = "CS";
    abdellah.guardian_phone = "YYY-YYY-YYY"; // not allowed
    return 0;
}
```
```cpp
// Program to create member function
#include <iostream>
using namespace std;

class Student {
    public:
        int     id;
        string  name;
        // member function
        void display()
        {
            cout << "Member function running";
        }
};

int main()
{
    Student Abdullah;
    Abdullah.display();
    return 0;
}
```
```cpp
// Program to define member function outside of the class
#include <iostream>
using namespace std;

class Student {
    public:
        int     id;
        string  name;
        void    display();
};

// member function definition outside of class
void Student::display()
{
    cout << "member function outside class" << endl;
}

int main()
{
    Student Abdullah;
    Abdullah.display();
    return 0;
}
```
```cpp
// Program to define a friend function to access a private member inside a class
#include <iostream>
using namespace std;

class student {
    private:
        string secret_code;

    public:
        int     id;
        string  say_hello;

        void setter(int number, string str)
        {
            id = number;
            say_hello = str;
        }
        void getter()
        {
            cout << "Id: " << id << endl;
            cout << "Say Hello: " << say_hello << endl;
            cout << "Secret Code: " << secret_code << endl;
        }
        friend void set_code(student &obj, string code);
        // this function can now access the private members of this class

};

void set_code(student &obj, string code)
{
    obj.secret_code = code;
}

int main()
{
    student Abdullah;
    Abdullah.setter(42, "Hi");
    Abdullah.getter();
    set_code(Abdullah, "1234");
    Abdullah.getter();
    return (0);
}
```
#### <ins>The Class Constructors</ins>
###### <ins>Class Constructors</ins>
- Class constructors are the special member function whose name is same as that of the class.
- Constructors are used to initialize the member of the objects.
- Constructors does not have any return type at all, not even void.
- Constructors are automatically invoked whenever an object is created.

**Example**
```cpp
#include <iostream>
using namespace std;

class student
{
    public:
        int number;
        // constructor
        student(int data = 42)
        {
            number = data;
            cout << "I am a constructor" << endl;
        }
};

int main()
{
    student demo; // gives output: "I am a constructor" and initialize the member data by default with 42
    return 0;
}
```
---
#### <ins>Destructors in C++</ins>
- A Destructor is a special member function of a class which is executed whenever an object of that class goes out of scope.
- A Destructor is created using tilde(~) sign.
- Destructor is created automatically by the compiler and invoked automatically when an object of the class goes out of scope.
- Destructor is used in order to free up the memory or release the memory used by the class objects.

**Syntax**
```cpp
~classname()
{
    //statement
}
```
**Program**
```cpp
// Program to demonstrate the destructor
#include <iostream>
using namespace std;

class Dimensions {
    int length, width;
    public:
        Dimensions(int a, int b)
        {
            length = a;
            width = b;
        }

        void showData()
        {
            cout << "First dimension: " << length << endl << "Second dimension: " << width << endl; 
        }

        ~Dimensions()
        {
            cout << "Destructor is called..." << endl;
        }
};

int main()
{
    Dimensions object(10, 20);
    object.showData();
    return 0;
}

```
