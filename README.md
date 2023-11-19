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
    obj.dislay();

    return 0;
}
```
```
output:
Hello from the parent class
Hello from the child class
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
    obj.dislay();
    obj.parent::display();
    return 0;
}
```
```
output:
Hello from the child class
Hello from the parent class
```
---
#### <ins>About Namespaces</ins>
- Basically, a namespace is a way to group together related functions, classes, variables, and other symbols. Most of the symbols of the standard library are defined inside a namespace called std. This means that if you are outside this namespace (which is always the case unless you are developing or extending the standard library itself), you need to prepend std:: to be able to access these symbols, for example, std::cout.

- As a convenience, the using keyword allows you to import some or all of these symbols and later not have to specify their namespace. For example, if you write using std::cout, then you can later simply write cout instead of std::cout. If you write using namespace std, it imports all the symbols inside std, which is considered bad practice especially in header files, because it imports so many symbols that it increases the risks of collisions with your own symbols, or with the symbols of any compilation unit that includes the header.

- The problem with using namespace std; is that it doesn't just "pull in" cout. It pulls in EVERYTHING in the std:: namespace. Things you've probably never heard of and may never use in your career are now available by a short name.
- So as you're writing your own code you might be intending to call a function that you wrote, but actually end up calling some function in the std:: namespace without knowing it, just because they have the same name. Or you might see warnings or errors having to do with picking a name that's already taken.
- That's why it's recommended to either not do using namespace std; at all (and just put std:: in front of everything that needs it) OR go with the lesser-known-but-in-my-opinion-much-better option, using std::cout;.
- If you go with using std::cout; that will let you just use cout directly like you want, but it won't pull everything from std:: into the namespace. You can very specifically and individually include just the things you want to pull in (cin, cout, string, etc) with none of the downsides.
---
### <ins>Default Constructors in C++<ins>
- A default constructor is a constructor that either has no parameters, or if it has parameters, all the parameters have default values.
- If no user-defined constructor exits for a class A and one is needed, the compiler implicity declares a default parameterless constructor A::A().
- This constructor is an inline public member of its class. The compiler will implicity *define* A::A() when the compiler uses thei constructor to create an object of type A. The constructor will have on constructor initializer and a null body.
---
### <ins>Pointer to function && Pointer to member function in C++</ins>
- in C++, a pointer to a function refers to the memory address where the function's code starts. It can be used to call the function indirectly. Here's a basic example : 
```cpp
#include <iostream>

void myFunction() {
    std::cout << "Hello, World!";
}

int main() {
    // Declare a function pointer
    void (*ptr)();

    // Point it to myFunction
    ptr = myFunction;

    // Call the function through the pointer
    ptr();  // Outputs: Hello, World!

    return 0;
}
```
- in this example, ptr is a pointer to a function that takes no arguments and returns void. We assign it the address of *myFunction*, and then we use ptr to call *myFunction*.
- When it comes to member functions of a class, the syntax is a bit different. You need to use the class name and the scope resolution operator (::). Here's an example:
```cpp
class MyClass {
public:
    void myMethod() {
        std::cout << "Hello, World!";
    }
};

int main() {
    // Declare a pointer to a member function of MyClass
    void (MyClass::*ptr)();

    // Point it to myMethod
    ptr = &MyClass::myMethod;

    // Create an object of MyClass
    MyClass obj;

    // Call the method through the pointer
    (obj.*ptr)();  // Correct

    // obj.ptr();  // Incorrect

    return 0;
}
```
- in this example, *ptr* is a pointer to a member function of *MyClass* that takes no arguments and returns void. We assign it the address of *myMethod*, nad then we use *ptr* to call *myMethod* on an object of *MyClass*.

---
### <ins>Copy Constructor in C++</ins>
- A copy constructor in C++ is a special constructor that initializes a new object as a copy of an existing object. The copy constructor is used whenever an object is initialized from another of the same type, unless move semantics are involved.
- The copy constructor is called in several situations, including:
* When an object is initialized with another object of the same type: Fixed a = b;
* When an object is passed by value to a function.
* When an object is returned by value from a function.
- If you don't define a copy constructor, the C++ compiler will automatically generate one for you. This default copy constructor performs a shallow copy, which might not be appropriate for classes that manage dynamic memory or other resources.
- The default copy constructor performs a shallow copy of the object. This means that for each non-static data member of the object, the value is copied from the source object to the destionation object.
```cpp
#include <cstring>
#include <iostream>

class test {
    public:
        char *s;
        
};

int main(void)
{
   test obj;
   obj.s = (char *)malloc(10);
   strcpy(obj.s, "bye");

   std::cout << "str: " << obj.s << '\n';
   test obj2(obj);
   std::cout << "second str: " << obj2.s << '\n';
}
```
- In the above code, s is a pointer to a dynamically array. When the default copy constructor performs a shallow copy,it copies the pointer s, not the actual array that *s* points to. This means that both *obj* and *obj2* end up pointing to the same array. If you modify the array through one object, the change will be visible when you access the array through the other object. Also, if one objet is destroyed and its destructor frees the array, the other object will be left with a dangling pointer.

---
### <ins>Overloading increment and decrement operators in C++</ins>
```cpp
class Test {
public:
    int a;

    Test() : a(0) {}

    // Pre-increment overload
    Test& operator++() {
        ++a;
        return *this;
    }

    // Post-increment overload
    Test operator++(int) {
        Test temp = *this;
        ++(*this);
        return temp;
    }
};

int main() {
    Test t;
    ++t; // Pre-increment
    t++; // Post-increment
    return 0;
}
```
- In this example, the pre-increment operator(++t) increments t.a and then returns t. The post-increment operator(t++) creates a temporary copy of t, increments t.a, and then returns the temporary copy. This is why the post-increment operator is often considered less efficient than the pref-increment operator.
**Why post-increment operator overload function takes an *int* paramater?**
- The *int* parameter in the post-increment operator overload function is a dummy parameter used to differentiate between the pre-increment and post-increment operator overloads. It doesn't have any actual use in the function body, and you don't pass any value to it when you use the post-increment operator.
- The compiler uses the *int* argument ot distinguish between the prefix and postfix increment operators. For implicit calls, the default value is zero.
---
### <ins>Constructors and Destructors in C++</ins>
- The process of creating and deleting objects in C++ is not a trivial task. Every time an instance of a class is created the constructor method is called. The constructor has the same name as the class and it doesn't return any type, while the destructor's name it's defined in the same way, but with a '~' in front.
- Even if a class is not equipped with a  constructor, the compiler will generate code for one, called the implicit default constructor. This will typically call the default constructors for all class members.
- THe construction order of the members is the order in which they are defined, and for this reason the same order should be preserved in the initialization list to avoid confusion.
- Some problems arise when we are dealing with class hierarchies. Let's take a look at the following example where class ```child``` is inherited from class ```test``` :
```cpp
#include <iostream>

class test {
public:
    int a;
    test(int value) : a(value) {}
   virtual ~test() {
        std::cout << "test destructor called\n";
    }
};

class child : public test {
public:
    int b; 
    child(int value) : b(value) { }
    ~child() {
        std::cout << "child destructor called\n";
    }
};

int main()
{
    child obj(42);
}
```
- When we create an object of type ```child```, the ```test``` part of the ```child``` object must be initialized and since we provide a constructor for class ```test```, the compiler will not create an implicit default constructor. This code will fail to compile because there is no default constructor for class ```test``` to be called. To fix this we could provide a default constructor in class ```test``` or expilicty call the existing constructor of ```test``` in the initialization list of the ```child```'s constructor:
```cpp
class child : public test {
public:
    int b; 
    child(int value) : b(value), test(42) { } // test constructor added
    ~child() {
        std::cout << "child destructor called\n";
    }
};
```
- Notice that we needed to call the constructor of ```test``` before doing any initialization in ```child```, since the order of construction starts with the base class and ends with the most derived class. For example, the following code also will fail to compile:
```cpp
class child : public test {
public:
    int b; 
    child(int value) : b(value) { 
        test(42);
        } // test constructor added
    ~child() {
        std::cout << "child destructor called\n";
    }
};
```
- this is because you can't initialize the child object before initializing the test object.

### <ins>Virtual Destructors</ins>
- To build an object the constructor must be of the same type a the object and because of this a constructor cannot be a virtual function.
- Constructor is a special member function of a class that is used to intialize objects of its class type. When a constructor is called, it has to construct an object of a specific type, so there's no need for the dynamic dispatch provided by virtual functions.
- But the same thing does not apply to destructors. A destructor can be defined as virtual or even pure virtual. You would use a virtual destructor if you ever expect a derived class to be destroyed through a pointer to the base class. This will ensure that the destructor of the most derived classes will get called.
---
**<ins>Virtual Inheritance</ins>**
- in C++, a clas can inherit from multiple classes which is commonly referred as multiple inheritance. But this can cause problems sometimes, as you can have multiple instances of the base class.
- To tackle this problem, C++ uses a technique whicih ensures only one instance of a base class is present. That technique is referred as virtual inheritance.
**Example of When Virtual Inheritance is Useful**
- Let's look at an example and then explain what's happening:
```cpp
#include <iostream>

class parent {
public:
    int a;
    parent() : a(42) {}
};

class child1 : public parent {
public: 
    int b;
    child1() : b(1) {}
};

class child2 : public parent {
public:
    int c;
    child2() : c(2) {}
};

class child3 : public child1, public child2 {
public:
    int d;
    child3() : d(3) {}
};

int main()
{
    child3 obj;
    std::cout << obj.a << '\n';
}
```
- First, we have a class ```parent``` which is being inherited by two class ```child1``` and ```chil2```. Both of these classes are then inherited by another class ```child3```.
- Inside our main function, we create a new instance (object) of the class ```child3```. We then simply tried to print the value of a to the console.
- It might look to access the value of ```a``` here, because class ```child3``` is inherited from both class ```child1``` and ```child2``` which are ultimately inherited from the class ```parent```.
- But when you try to compile the above progra, you get the following error: 
```
test.cpp: In function ‘int main()’:
test.cpp:30:22: error: request for member ‘a’ is ambiguous
   30 |     std::cout << obj.a << '\n';
      |                      ^
test.cpp:5:9: note: candidates are: ‘int parent::a’
    5 |     int a;
      |         ^
test.cpp:5:9: note:                 ‘int parent::a’
```
- The error is pretty clear: ```error: request for member 'a' is ambiguous```, if we draw the hierarchical class structure, it should become pretty clear:
```
        parent              parent
          |                   |
          |                   |
        child1              child2
            \                 /
             \               /
              \             /
                   child3
```
- We can see that we have multiple instances of the class ```parent```. So the request to the variable ```a``` becomes ambiguous because the compiler doesn't know which instance we are referring to - is it through ```child1``` or through ```child2```? That's the real problem.<br>
**One Way to Solve this Problem**
- One way to tackle the problem is to use the ```scope-resolution operator (::)``` with which we can directly specify which instance of ```parent``` we want.
```cpp
int main()
{
    child3 obj;
    std::cout << obj.child1::a << '\n';
}
```
- Using the ```scope-resolution operator``` we explicity told the compiler which instance of ```parent``` we referred to.
- The main problem with this approach is that it doesn't solve our problem - because our main probelm is having multiple instancesof class ```parent```, and we still have that. SO we need to look around for some other solutions.

**Another way to solve this issue: Virtual Inheritance**
- To inherit virtually we simply add a keyword ```virtual``` before our base class name in the derived class declaration like this:
```cpp
class child1 : virtual public parent {
public: 
    int b;
    child1() : b(1) {}
};

class child2 : virtual public parent {
public:
    int c;
    child2() : c(2) {}
};
```
- The addition of the ```virtual``` keyword indicates that we want to inherit from ```parent``` virtually.
- Inheriting virtually guarantees that there will be only one isntance of the base class among the derived classes that virtually inherited it. After the changes, our hierarchical class structure becomes:

```
            parent
               |
              /\
             /  \
            /    \
           /      \
          /        \
         /          \
       child1      child2
         |           |
          \         /
           \       /
             child3    

```
- So now if we try to compile the following code, it will successfully compile:
```cpp
#include <iostream>

class parent {
public:
    int a;
    parent() : a(42) {}
};

class child1 : virtual public parent {
public: 
    int b;
    child1() : b(1) {}
};

class child2 : virtual public parent {
public:
    int c;
    child2() : c(2) {}
};

class child3 : public child1, public child2 {
public:
    int d;
    child3() : d(3) {}
};

int main()
{
    child3 obj;
    std::cout << obj.a << '\n';
}
```
- So with the introduction of ```virtual``` inheritance we are able to remove the ambiguities we had earlier.
---
### <ins>What is a VTABLE</ins>
- A vtable is basically the most common implementation of polymorphism in C++. When vtables are used, every polymorphic class has a vtable somewhere in the program; you can think of it as a (hidden) static data member of the class. Every object of a polymorphic class is associated with the vtable for its most-derived class. By checking this association, the program can work its polymorphic magic. Important caveat: a vtable is an implementation detail. It is not mandated by the C++ standard, even though most (all?) C++ compilers use vtables to implement polymorphic behavior.
- The name "vtable" comes from "virtual function table". It is a table that stores pointers to (virtual) functions. A compiler chooses its convention for how the table is laid out; a simple approach is to go through the virtual functions in the order they are declared within class definitions. When a virtual function is called, the program follows the object's pointer to a vtable, goes to the entry associated with the desired function, then uses the stored function pointer to invoke the correct function.

##### <ins>Virtual and Pure Virtual Functions in C++</ins>
- Unlike a non-virtual function, when a virtual function is overridden the most-derived version is used at all levels of the class hierarchy, rather than just the level at which it was created. Therefore if one method of the base class calls a virtual method, the version defined in the derived class will be used instead of the version defined in the base class.
- This is in contrast to non-virtual functions, which can still be overridden in a derived class, but the "new" version will only be used by the derived class and below, but will not change the functionality of the base class at all.
- What virtual does is to give you polymorphism, that is, the ability to select at run-time the most-derived override of a method.
- When a pure virtual method exists, the class is "abstract" and can not be instantiated on its own. Instead, a derived class that implements the pure-virtual method(s) must be used. A pure-virtual isn't defined in the base-class at all, so a derived class must define it, or that derived class is also abstract, and can not be instantiated. Only a class that has no abstract methods can be instantiated.
- Pure Virtual Functions are mostly used to define:<br>
 1. abstract classes

 These are base classes where you have to derive from them and then implement the pure virtual functions.
 2. interfaces

 These are 'empty' classes where all functions are pure virtual and hence you have to derive and then implement all of the functions.




---
### <ins>Const member function in C++</ins>
- Constant member functions are those functions that are denied permission to change the values of the data members of their class. To make a member function constant, the keyword const is appended to the function prototype and also to the function definition header.
- Like member functions and member function arguments, the objects of a class can also be declared as const. An object declared as const cannot be modified and hence, can invoke only const member functions as these functions ensure not to modify the object. A const object can be created by prefixing the const keyword to the object declaration. Any attempt to change the data member of const objects results in a compile-time error.<br>
**Syntax**
- The const member function can be defined in three ways:
    1. For function declaration within a class. <br>
    ```
    return_type function_name() **const** 
    ```<br>
    * Example:<br>
    ```
    int get_data() const;
    ```
    2. For function definition within the class declaration.<br>
    ```
    return_type function_name() const
    {
            //function body
    }
    ```
    3. For function definition outside the class.
    ```
    return_type class_name::function_name() const
    {
            //function body
    }
    ```

    