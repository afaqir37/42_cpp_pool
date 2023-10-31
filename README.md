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
---
#### <ins>Static Data Members and Static Member Functions</ins>
**Static Data Members**
- Static data members in C++ are not instantiated for each object of a class and instead, only one copy of the data member exists for the entire class.
- A static data member in C++ is declared within a class and is defined outside the class.
- A static data member in C++ can be accessed with the help of the scope resolution operator(::) or a static member function.
- A constant static data member in C++ can be initialized within the same class in which it is defined.
- A Static data member in C++ are not associated with any object and can be accessed even without the creation of any object. Static data members belong to the static **storage class** in C++ and as such have a lifetime equal to the lifetime of the program.
***Example***
```cpp
// Program to show how static data member works
#include <iostream>
using namespace std;

class test {
    public:
        static int x; //declaration of static data member x
};

int test::x = 42; // definition of the static data member

int main()
{
    cout << test::x << endl; // as you see, we can access the static variable without defining an object from the class.
                            // the output will be 42;
}
```
```cpp
// Program to demonstrate static data member
#include <iostream>
using namespace std;

class school {
    public:
        static string name;
};

string school::name = "Random";

int main()
{
    school obj1, obj2;
    obj1.name = "EMI";
    obj2.name = "1337";
    cout << obj1.name << endl; // should prints "1337" since name is static data member
    return 0;
}
```
**Static Member Functions**
- By declaring a function member as static, you make it independent of any particulr object of the class.
- A static member function can be called even if no objects of the class exist.
- A static functions are accessed using only the class name and the scope resolution operator :: .
- A static member function in C++ can access only the static data members.
**Example**
```cpp
// Program that throws error in compile-time
#include <iostream>
using namespace std;

class test {
    public:
        int y = 0;
        static void increment()
        {
            y++; // Error because the static member function increment() try to access a non-static data member 'y'
        }
};

int main()
{
    test obj;
    obj.increment();
    return 0;
}
```
```cpp
// Program that shows how static member function works
#include <iostream>
using namespace std;

class test {
    public:
        static void display()
        {
            cout << "Hi there!" << endl; 
        }
};

int main()
{
    test::display(); // you can use the static member function 'display()' without the existence of an object.

    test obj;
    obj.display(); // or you can create an instance from the test class and access the display() function.
    return 0;
}
```
---
#### <ins>Passing Objects as arguments by Reference and by Pointer</ins>
##### Passing Objects by reference
- It allows a function to modify a variable without having to create a copy of it. We have to declare reference variables. The memory location of the passed variable and parameter is the same and therefore, any change to the parameter reflects in the variable as well.
- A reference is the same object, just with a different name.
- A reference must refer to an object. Since references can't be NULL, they are safer to use.
- A reference cannot be left without initializing it.
- A reference cannot be re-assigned.
- A reference has the same memory address as the item it references.
- A pointer needs to be dereferenced with * to access the memory location it points to, whereas a reference can be used directly.

**Example**
```cpp
// C++ program to swap two numbers using pass by reference
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    int a = 42, b = 92;
    printf("before swap: a = %d | b = %d\n", a, b);

    swap(a, b);

    printf("after swap, a = %d | b = %d\n", a, b);
    return 0;
}
```

```cpp
// C++ program that uses passing by reference with objects.
#include <iostream>
using namespace std;

class complex {
    int real, imag;

    public:
        void getData(int r, int i);
        void addData(complex &obj1, complex &obj2); // pass by reference
        void showData();
};

void complex::getData(int r, int i)
{
    real = r;
    imag = i;
}

void complex::addData(complex &obj1, complex &obj2)
{
    real = obj1.real + obj2.real;
    imag = obj1.imag + obj2.imag;
}

void complex::showData()
{
    cout << real << "+" << imag << "i" << endl;
}

int main()
{
    complex c1, c2, c3;
    c1.getData(4, 5);
    c1.showData();
    c2.getData(1, 2);
    c2.showData();
    c3.addData(c1, c2);
    c3.showData();
}
```
##### Passing Objects by Pointer
- The difference between pass-by-reference and pass-by-pointer is that pointers can be NULL or reassigned whereas references cannot.
- Use pass-by-pointer if NULL is a valid parameter value or if you want to reassign the pointer. Otherwise, use constant or non-constant references to pass arguments.
```cpp
// Passing objects by POINTER
#include <iostream>
using namespace std;

class complex {
    int real, imag;

    public:
        void getData(int r, int i);
        void addData(complex *obj1, complex *obj2); // pass by reference
        void showData();
};

void complex::getData(int r, int i)
{
    real = r;
    imag = i;
}

void complex::addData(complex *obj1, complex *obj2)
{
    real = obj1->real + obj2->real;
    imag = obj1->imag + obj2->imag;
}

void complex::showData()
{
    cout << real << "+" << imag << "i" << endl;
}

int main()
{
    complex c1, c2, c3;
    c1.getData(9, 9);
    c1.showData();
    c2.getData(4, 2);
    c2.showData();
    c3.addData(&c1, &c2);
    c3.showData();
}
```
**More about pass-by-reference**
> Pass-by-reference is more efficient than pass-by-value, because it does not copy the arguments. The formal parameter is an alias for the argument. When the called function read or write the formal parameter, it is actually read or write the argument itself.

> The difference between pass-by-reference and pass-by-value is that modifications made to arguments passed in by reference in the called function have effect in the calling function, whereas modifications made to arguments passed in by value in the called function can not affect the calling function. Use pass-by-reference if you want to modify the argument value in the calling function. Otherwise, use pass-by-value to pass arguments.
---
#### <ins>Types of Class Constructors</ins>
###### <ins>Default Constructor</ins>
- The constructor which does not take any arguments is called default constructor.
- It is also called non-parameterized constructor.
- The compiler automatically creates a default constructor without data member or initialization if no constructor is explicitly declared.
**Example**
```cpp
//Program to demonstrate default constructor
#include <iostream>
using namespace std;

class complex {
    int real, imag;

    public:
        complex() // default constructor
        {
            real = 1;
            imag = 5;
        }

        void showNumber()
        {
            cout << "Complex number is " << real << "+" << imag << "i" << endl;
        }
};

int main()
{
    complex c;
    c.showNumber();
    return 0;
}
```
#### <ins>Parameterized Constructor</ins>
- it takes argument while caling the constructor.
- Typically these arguments are used to initialize an object when it is created.

**Example**
```cpp
// Program to demonstrate parameterized constructor
#include <iostream>
using namespace std;

class complex {
    int real, imag;
    public:
        complex(int a, int b) // parameterized constructor
        {
            real = a;
            imag = b;
        }
        void showNumber()
        {
            cout << "Complex number is " << real << "+" << imag << "i" << endl;
        }
};

int main()
{
    // implicit invoke
    complex c1(20, 40);
    c1.showNumber();

    //explicit invoke
    complex c2 = complex(3, 5);
    c2.showNumber();
}
```
###### <ins>Copy Constructor</ins>

- The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously.
- The copy constructor is used to
    * Initialize one object from another of the same type.
    * Copy an object to pass it as an argument ot a function.
    * Copy an object to return it from a function.

**Example**
```cpp
// Program to demonstrate copy constructor
#include <iostream>
using namespace std;

class complex {
    int real, imag;

    public:
        complex(int a, int b)
        {
            real = a;
            imag = b;
        }

        complex(complex &obj) // copy constructor
        {
            real = obj.real;
            imag = obj.imag;
        }

        void showNumber()
        {
            cout << "Complex number is " << real << "+" << imag << "i" << endl;
        }
};

int main()
{
    complex c1(11, 22);
    c1.showNumber();

    complex c2(c1);
    c2.showNumber();
}
```
---
#### <ins>Array of objects</ins>
- An array of objects is a collection of objects of the same class type that are stored in contiguous memory locations.
```cpp
// Program to demonstrate array of objects
#include <iostream>
using namespace std;

class student
{
    string name;
    int id;

public:
    void setData()
    {
        cout << "Enter id and name of student: ";
        cin >> id >> name;
    }

    void getData()
    {
        cout << "Student info..." << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "-----------------------" << endl;
    }
};

int main()
{
    student obj[10];
    int size;
    cout << "Size of student (1-10): ";
    cin >> size;
    while (size <= 0 || size > 10)
    {
        cout << "Size of student (1-10): ";
        cin >> size;
    }

    for (int i = 0; i < size; i++)
    {
        obj[i].setData();
    }
    for (int i = 0; i < size; i++)
    {
        obj[i].getData();
    }
    return 0;
}
```
```
Output:
Size of student (1-10): 4
Enter id and name of student: 1 Messi
Enter id and name of student: 2 Cristiano
Enter id and name of student: 3 Maradona
Enter id and name of student: 4 Pele
Student info...
Id: 1
Name: Messi
-----------------------
Student info...
Id: 2
Name: Cristiano
-----------------------
Student info...
Id: 3
Name: Maradona
-----------------------
Student info...
Id: 4
Name: Pele
-----------------------
```
---
#### <ins>Operator Overloading in C++</ins>
- ___Operator overloding is a compile-time polymorphism___. It is an idea of giving special meaning to an existing operator in C++ without changing its original meaning.
- In C++, we can make operators work for user-defined classes. This means C++ has the ability to provide the operators with a special meaning for a data type, this ability is known as operator overloading. For example, we can overload an operator '+' in a class like String so that we can concatenate two strings by just using +. Other example classes where arithmetic operators may be overloaded are Complex Numbers, Fractional Numbers, Big integers, etc.
##### <ins>What is the difference between operator functions and normal functions?</ins>
Operator functions are the same as normal functions. The only differences are, that the name of an operator function is always the operator keyword followed by the symbol of the operator, and operator functions are called when the corresponding operator is used.

```cpp
// C++ program to demonstrate how operator overloading works

#include <iostream>
using namespace std;

class complex {
    private:
        int real, imag;

    public:
        complex(int real, int imag);
        void print();
        complex operator+(complex op);
};

complex::complex(int real, int imag)
{
    this->real = real;
    this->imag = imag;
}

void complex::print()
{
    cout << real << " + " << imag << "i" << endl;
}

complex complex::operator+ (complex op)
{
    return complex(real + op.real, imag + op.imag);
}

int main(void)
{
    complex c1(2, 5);
    c1.print();
    complex c2(1, 9);
    c2.print();

    complex c3 = c1 + c2;
    c3.print();

    return 0;
}
```
- Now, if the user wants to make the operator "+" add two class objects, the user has to redefine the meaning of the "+" operator such that it adds two class objets. This is done by using the concept of "Operator overloading". So the main idea behind "Operator overloading" is to use C++ operators with class objects. Redefining the meaning of operators really does not change their original meaning; instead, they have been given additional meaning along with their existence ones.

- The statement complex c3 = c1 + c2; is internally translated as complex c3 = c1.operator+ (c2); in order to invoke the operator function. The argument c1 is implicitly passed using the '.' operator. The next statement also makes use of the dot operator to access the member function 'print' and pass c3 as an argument.

##### <ins>Can we overload all operators?</ins>
Almost all operators can be overloaded except a few. Following is the list of operators that cannot be overloaded.
- sizeof
- typeid
- Scope resolution (::)
- Class member access operator (.(dot), .* (pointer to member operator))
- ternary or conditional (?:)
---
#### <ins>Function Overriding in C++</ins>
**Function overriding is where a derived class can override the function of its parent class, with its own implementation. This is an important part of polymorphism and OOPs concept in C++ programming.**

- Function overriding is a feature that allows a derived class to provide a new implementation for a function that is already defined in its base class. This is essential for building hierarchical relationships between classes, where derived classes inherit characteristics and behavior from their base classes but can also customize or extend those behaviors as needed.

```cpp
#include <iostream>
using namespace std;

class parent {
    public:
        // overridden function
        void display()
        {
            cout << "Hello from the parent class" << endl;
        }
};

class child : public parent {
    public:
        // overriding function
        void dislay()
        {
            cout << "Hello from the child class" << endl;
        }
};

int main()
{
    child obj;
    obj.dislay(); // the output will be :"Hello from the child class" 

    return 0;
}
```

```cpp
// Program to call the overridden function in the derived class
#include <iostream>
using namespace std;

class parent {
    public:
        // overridden function
        void display()
        {
            cout << "Hello from the parent class" << endl;
        }
};

class child : public parent {
    public:
        // overriding function
        void dislay()
        {
            parent::display(); // overridden function called
            cout << "Hello from the child class" << endl;
        }
};

int main()
{
    child obj;
    obj.dislay(); // the output will be :"Hello from the child class" 

    return 0;
}
```
```cpp
// Program to access overridden function by object of derived class
#include <iostream>
using namespace std;

class parent {
    public:
        // overridden function
        void display()
        {
            cout << "Hello from the parent class" << endl;
        }
};

class child : public parent {
    public:
        // overriding function
        void dislay()
        {
            cout << "Hello from the child class" << endl;
        }
};

int main()
{
    child obj;
    obj.dislay(); // the output will be :"Hello from the child class" 
    obj.parent::display();
    return 0;
}
```
---