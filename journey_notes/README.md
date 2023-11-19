# This README is about some details and problems I faced while programming in C++ and I found solutions to solve them,So I thought why not share this solutions and notes :) 

#### <ins>About std::cin and getline</ins>
**The code below has an issue**
```cpp
#include <iostream>
using namespace std;

int main()
{
    string name;
    string line;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a line: ";
    getline(cin, line);
    cout << line << endl;
}
```
```
output:
Enter a name: ahmed
Enter a line:
```
So the issue here is when running the program it never stopped to ask for the line. It just skipped over it.
The problem occurs because when you type ```Ahmed``` and press enter, the input stream contains ```Ahmed/n```and ```Ahmed``` is parsed into the 'name' variable while '\n' is still in the stream. Reading the doc for *getline* function by default it will look in the *istream* until a '\n' is encountered. In this example, since '\n' is in the stream, it looks like it "skipped" it but it worked properly.

Essentially, for std::cin statements you use *ignore* before you do a *getline* call, because when a user inputs something with std::cin, they hit enter and a '\n' char gets into the **cin** buffer. Then if you use *getline*, it gets the newline char instead of the string you want. So you do a ```std::cin.ignore(1000, '\n')``` 

#### <ins>About std::istream::ignore()</ins>
##### source: cplusplus.com
##### <ins>istream& ignore (streamsize n = 1, int delim = EOF);</ins>

Extract characters from the input sequence and discards them, until either n characters have been extracted, or one compares equal to *delim*

The function also stops extracting characters i the end-of-file is reached.

**Parameters**
n: Maximum number of characters to extract (and ignore).
If this is exactly *numeric_limits<streamsize>::max()*, there is no limit: As many characters are extracted as needed until *delim* (or the end-of-file) is found.

**delim**
Delimiting character: The function stops extracting characters as soon as an extracted character compares equal to this.
Note that the delimiting character is extracted, and thus the next input operation will continue on the character that follows it (if any).

**Solution**
```cpp
#include <iostream>
#include <limits>
using namespace std;

int main()
{
    string name;
    string line;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a line: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this line will  skip all the remaining characters in
                                                        //the input buffer until it reaches '\n' or eof.
    getline(cin, line);// the cin buffer now is ready to receive new input
    cout << line << endl;
}
```
```
output:
Enter a name: ahmed
Enter a line: hello world
hello world
```
---
#### <ins>Dealing with Spacing Issues using iomanip</ins>
- A principle aspect of nicely formatted output is that the spacing looks right. There aren't columns of text that are too appropriately aligned. This section deals with ways of spacing output correctly.

**Setting the field width with setw**
- The std::setw function allows you to set the minimum widith of the next output via the insertion operator. setw takes, one argument, the width of the next output (insertion), an integer. If the next output is too short, then spaces will be used for padding. There is no effect if the output is longer than the width --note that the output won't be truncated. The only strange thing about setw is that its return value must be inserted into the stream. The setw function has no effect if it is called without reference to a stream. A simple example is :
```cpp
using namespace std;
cout << setw(10) << "ten" << "four" <<> "four";
```
The output from the above would look like this:
```
ten       fourfour
```
- You might wonder whether it is possible to change the padding character. It turns out that yes, you can, by using the setfill function, which takes a character to use for the padding. note tht setfill should also be sed as a stream manipulator only, so it must be inserted into the stream:
```cpp
cout << setfill('-') << setw(10) << "+" << endl;
```
- The above code sets the padding character to a dash, the width of the next output to be at least 10 characters, and then outputs a dash. This results in the rest of the line being filled with dashs too. The output would look like this:
```
---------+
```
- <ins>Note that the pad character is changed until the next time you call setfill to change it again.</ins>
**Aligning text with iomanip**
- It's possible to specify whether output is left or right aligned by using the manipulator flags that are part of ios_bas. In particular, it is possible to specify that output should be either left or right aligned by passing in the stream manipulators std::left and std::right.
- <ins>Exampe</ins>
```cpp
using namespace std;
cout << setfill('-') << setw(10) << left << "test" << endl;
```
the output:
```
test------
```
```cpp
using namespace std;
cout << setfill('-') << setw(10) << right << "test" << endl;
```
the output:
```
------test
```
---
#### <ins>You can ACCESS PRIVATE DATA MEMBERS -- without -- ANY PUBLIC MEMBER FUNCTION !<ins> ####
- first of all, lets take a look on what is "PADDING and ALIGNMENT" ?
##### PADDING 
- Padding is the technique of adding extra bytes to a structure or class to align its data members to specific boundaries. This is done to ensure that they data members are accessed efficienty by the processor, which typicaly fetche data from memory in chunks of fixed sizes, such as 4 or 8 bytes.

Consider the following example:
```cpp
class Example {
    char c;
    int i;
    short s;
};
```
since size of char is 1-byte, int 4-byte and short 2-byte (32 bit machine), you might think that size of Example class is 7 bytes, but believe me it's NOT. <br>

**This is because of padding added to satisfy alignment constraints.**
Data structure alignment is the way data is arranged and accessed in computer memory. It consists of three separate but related issues: <ins>data alignment, data structure padding, and packing</ins> <br>
The CPU in modern computer hardware performs reads and writes to memory most efficienty when the data is *naturally aligned*, which generally means that **data's memory address is a multiple of the data size**.For instance, in a 32-bit architecture, the data may be aligned if the data is stored in four consecutive bytes and the first byte lies on a 4-byte boundary. <br>

Padding bytes are added for efficient memory access. When CPU reads or writes a 2-byte word on an even address through a 16-bit bus the transfer can be done in one cycle. However if 2-byte data is located at an odd address, it occupies a 'lower' half of one een-addressed word and an 'upper' half of another even-addresse word in memory. CPU the must perform two bus cycles: one for each memory word occupied by your data, each time utilizing only half the bus  width for actual tarnsfer. <br>

<ins> Example </ins> <br>
```cpp
class Example {
    char c;
    int i;
    short s;
};
```

Without padding, the data member of the class will be aligned as follows: <br>
```
-----------------------------
| c | i | i | i | i | s | s |  size = 7 bytes
-----------------------------
 0x0 0x1 0x2 0x3 0x4 0x5 0x6

```
in the case where the CPU need to retrieve the value of i, it needs to *TWO CPU CYCLE* or * TWO WORD * <br>
(WORD = 4 bytes in 32-bit machine | WORD = 8 bytes in 64-bit machine) <br>
The padding is typically used to ensure proper alignment of data elements to improve memory access efficiency. When data is correctly aligned, modern CPUs can read or write data more quickly, reducing the time it  takes to access data from memory. <br>
With padding, the data member will be aligned as follow : 
```
-------------------------------------------------
| c | - | - | - | i | i | i | i | s | s | - | - |  size = 12 bytes
-------------------------------------------------
 0x0 0x1 0x2 0x3 0x4 0x5 0x6 0x7 0x8 0x9 0xA 0xB

```
With padding now, whenever the CPU needs to retrieve a value, it will only perform *one CPU cycle or one word*, which <ins>improve memory access speed, as modern CPUs can read or write aligned data more efficiently. </ins> <br>

- that's why the size of the above class is 12 bytes and not 7 bytes :)
In case we don't need to perform the padding (which is rare !), we can use ```pragma``` directive as follow :
```cpp
// some directives
#pragma pack(1) // Pack the data structure with no padding
class Example {
    char c;
    int i;
    short s;
};
```
#### <ins>Now let's pass to how we can access private data members without member function :O</ins>
When we create an instance of a class with two int type attributes, a total of 8 bytes are allocated on the stack to hold two 4 butes int. And it happens that when we initialize an instance we get the memory block which holds these two integers.
```cpp
// Program that access private data member of a class without using any member function
#include <iostream>
using namespace std;

class test
{
private:
    char a;
    int b;
    char c;

public: 
    void display(void)
    {
        cout << "a: " << a << endl;
        cout << "b: " << b << endl;
        cout << "c: " << c << endl;
    }
    void init(char a, int b, char c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int main()
{
    test obj;
    obj.init('x', 20, 'z');
    obj.display();

    char *ptr = (char *)&obj;

    // to use the below commented lines of code, we need to set the data member of the class as public.
    // we need this commented lines in case we don't know how the data members are aligned in memory so we can access to them successfully,
    // but in case we know this info, we can skip them :)
    // cout << "offsetof a: " << offsetof(test, a) << " "
    //      << "offsetof b: " << offsetof(test, b) << "offsetof c: " << offsetof(test, c) << endl;

    char num = *ptr;
    int num2 = *(int *)(ptr + 4);
    char num3 = *(char *)(ptr + 8);

    cout << "num = " << num << endl;
    cout << "num2 = " << num2 << endl;
    cout << "num3: " << num3 << endl;

    // we can overwrite those private data member also ;)
    *ptr = '!';
    *(int *)(ptr + 4) = 99;
    *(char *)(ptr + 8) = '?';

    cout << "after overwiting" << endl;
    obj.display();
}


```
In order to access the private attributes of the instance we can convert the class instance to a poitner type, then modify the offset to read or write at a specific location. <br>
In line 209, the test object is converted to char pointer. Convertin to char pointer lets us perform arithmetic operations on the pointer with a least count of increment and decrement of 1 bytes. If we convert the pointer to int pointer, then ```pointer++``` will result in a 4 bytes increment. <br>
In line 214, the pointer is dereferenced to get the char at that location, and in line 215 we are incrementing the pointer by 4, i.e moving 4 bytes forward to access the next element. Why we are incrementing it by 4 ? because we know the compiler will perform a padding operation by adding 3 empty bytes to the *char a* and then it will put the *int i* next to it, after that it will put *char c* immediately after the int var, with an extra 3 empty bytes to this char. <br>

### Make sure of the offset you use when you increment the pointer pointed to the object. Use offsetof() func to make sure of the offset you will use  ###

---
#### <ins>Difference between std::endl and '\n'</ins>

- The only difference is that std::endl flushes the output buffer, and '\n' doesn't. If you don't want the buffer flushed frequently, use '\n'. If you (for example, if you want to get all the output, and the program is unstable), use ```std::endl```.
 **importante note from cppreference.com : ** <br>
 >In many implementations, standard output is line-buffered, and writing '\n' causes flush anyway, unless
 >```std::ios::sync_with_stdio(false)``` was executed.

 ### <ins>MORE ABOUT OUTPUT BUFFER AND FLUSHING BUFFER</ins>
 - Consider writing to a file. This is an expensive operation. If in your code your write one byte at a time, then each write of a byte is giong to be very costly. So a common way to improve performance is to store the data that you are writing in a temprary buffer. Only when there is a lot of data is the buffer written to the file. By postponing the writes, and wriing a large block in one go, performance is improved.

---
#### <ins>What is the role of c_str()<ins>
- c_str() returns a const char * that points to a null-terminated string (i.e., a C-styel string). It is useful when you want to pass the "contents" of an std::string to a function that expects to work with a C-style string.
- in C++, you define your strings as: ```std::string MyString;``` instead of ```char MyString[20]```. While writing C++ code, you encounter some C functions which require C string as parameter like ```int checkString(const char *)```.
- Now this is a problem. You are working with C++ and you are using ```std::string``` string variables. But this C function is asking for a C string. How do you convert your std::string to a standard C string? <br>
Like this: <br>
```cpp
std::string MyString;
MyString = "hello world;
int res = checkString(MyString.c_str());
```

---
### <ins>Why should I use new instead of malloc()</ins>
- Each has there own advantage but let's see some scenarios where we need to use the new operator instead of malloc(): <br>
**Constructors/Destructors**
The class constructor is invoked by the new operator but not by the malloc. Similarly, destructor invoked by delete, not by the free.
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Constructed\n";
    }
    ~Animal() {
        cout << "Deconstructed\n";
    }
};

int main()
{
    Animal* ptr = new Animal();

    delete ptr;
    return 0;
}
```
```
output:
Constructed
Deconstructed
```
**Type Safety**
The malloc() returns a ```void*``` which is not type-safe. ```new T``` returns a pointer to T.

### <ins>Exception handling of the new operator</ins>
- When the new operator request for the memory then if there is a free memory is available then it returns a valid address, either it throws bad_alloc exception.

- Let's see an example where we will catch the bad_alloc exception through a try-catch block.
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Constructed\n";
    }
    ~Animal() {
        cout << "Deconstructed\n";
    }
};

int main()
{
    int *ptr = nullptr;
    try {
        ptr = new int[999999999999999];
    }
    catch(...)
    {
        cout << "allocation failed!\n";
        return -1;
    }
    delete[] ptr;
}
```
```
output:
allocation failed!
```
- To avoid the exception throw we can use "nothrow" with the new operator. When we are used "nothrow" with the new operator, it returns a valid address if it is available otherwise it returns a null pointer.
```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    Animal() {
        cout << "Constructed\n";
    }
    ~Animal() {
        cout << "Deconstructed\n";
    }
};

int main()
{
    int *ptr = nullptr;
    ptr = new(nothrow) int[999999999999999];
    if (!ptr)
    {
        cout << "Quitting\n";
        return -1;
    }
    delete[] ptr;
}
```
```
output:
Quitting
```
---
### <ins>Some points about Overloading the '<<' operator</ins>
- To overload the `<<` operator for your `test` class, you can add a friend function in your class definition. Here's how you can do it:

```cpp
#include <cstring>
#include <iostream>

class test {
    public:
        int a;
        test(const test& other)
        {
            std::cout << "copy constructed\n";
            a = other.a;
        }
        test() 
        {
            std::cout << "constructed\n";
        }

        friend std::ostream& operator<<(std::ostream& os, const test& t)
        {
            os << "test object: " << t.a;
            return os;
        }
};

int main(void)
{
    test t;
    t.a = 5;
    std::cout << t << std::endl;
}
```

- In this code, the `operator<<` function is a friend of the `test` class, so it can access the private and protected members of `test`. It takes an `std::ostream` object and a `test` object as parameters, and it returns an `std::ostream` object. Inside the function, it outputs the `test` object to the `std::ostream` object in a specific format, and then returns the `std::ostream` object.
- The `std::ostream` class is part of the C++ Standard Library and provides functions for outputting data to output streams, such as the console or a file. 

- When you overload the `<<` operator for a custom class, you typically want to allow instances of that class to be outputted using `std::cout`, which is an instance of `std::ostream`. 

- By defining the overloaded `<<` operator to take an `std::ostream` reference as its first parameter and a reference to your custom class as its second parameter, you enable the use of `std::cout << yourObject` syntax. 

- The function returns a reference to the `std::ostream` to allow chaining of output operations. For example, `std::cout << obj1 << obj2;`. 

- Here's how you can add the overloaded `<<` operator to your `test` class:

```cpp
friend std::ostream& operator<<(std::ostream& os, const test& t)
{
    os << "test object: " << t.a;
    return os;
}
```

- This function can now be used to output a `test` object to any output stream, not just `std::cout`. For example, you could also output to an `std::ofstream` to write the object to a file.
- The `operator<<` function returns a reference to an `std::ostream` object to allow for chaining of output operations. 

- When you write something like `std::cout << obj1 << obj2;`, what's actually happening is that `operator<<(std::cout, obj1)` is called first, which returns a reference to `std::cout`. Then `operator<<(std::cout, obj2)` is called on that returned reference.

- If the `operator<<` function didn't return a reference to the `std::ostream` object, you wouldn't be able to chain output operations like this. Instead, you would have to write each output operation on a separate line:

```cpp
std::cout << obj1;
std::cout << obj2;
```

- By returning a reference to the `std::ostream` object, the `operator<<` function allows for more concise and readable code.
#### **<ins>As an aside**</ins>
- When the compiler compiles a function, it performs name mangling, which means the compiled name of the function is altered (“mangled”) based on various criteria, such as the number and type of parameters, so that the linker has unique names to work with.

- For example, some function with prototype int fcn() might compile to name __fcn_v, whereas int fcn(int) might compile to name __fcn_i. So while in the source code, two overloaded functions share a name, in compiled code, the names are actually unique.

- There is no standardization on how names should be mangled, so different compilers will produce different mangled names.
---
### <ins>IMPORTANT POINT ABOUT CONVERTING FROM FLOATING POINT NUMBER TO FIXED POINT NUMBER</ins>
- In the context of the conversion operation `fixedPoint = static_cast<int>(roundf(num * (1 << fracBits)));`, the floating-point number `num` is treated as a decimal number, not as its IEEE 754 binary representation.

- When you perform arithmetic operations on floating-point numbers in C++, the numbers are automatically converted from their IEEE 754 binary representation to decimal. The arithmetic operations are then performed on the decimal numbers, and the results are converted back to IEEE 754 binary representation for storage.

- So, when you write `num * (1 << fracBits)`, you're scaling the decimal number `num` by a power of two. This corresponds to shifting the binary point in the binary representation of `num` to the right by `fracBits` positions. 

- The `roundf` function then rounds this number to the nearest integer, and the `static_cast<int>` converts the result to an integer. This integer is the fixed-point representation of the original floating-point number `num`.

### <ins>You CAN'T bind a non-const lvalue reference to an rvalue in C++<ins>
- let's take the following senario: 
```cpp
int main()
{
    int a = 24;
    int &ref = 99;
    std::cout << ref << '\n';
}
```
```
the compiler throws the following error:
test.cpp:67:16: error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
   67 |     int &ref = 99;
      |                ^~
```
- the line ```int &ref = 99;``` will cause a compiler error because you're trying to bind a non-const lvalue reference to an rvalue. In C++, you cannot bind a non-const lvalue reference to an rvalue.
- In this case, ```99``` is an rvalue because it's a temporary object (a literal). You're trying to bind this rivalue to ```ref```, which is a non-const lvalue reference.
- To fix this, you can make ```ref``` a const lvalue reference:
```cpp
const int &ref = 99;
```
- This code is valid because you can bind a const lvalue reference to an rvalue in C++. The ```const``` qualifier prevents you from modifying the referred object, which is necessary because rvalues like ```99``` cannot be modified.
---
### <ins>Why Is it important for the *Copy assignment operator* to return a REFERENCE to the object</ins>
- If the copy assignment operator doesn't return a reference to the object, you won't be able to chain assignment operations.
```
For example, if you have:
Fixed a, b, c;
// Initialize a, b, and c
a = b = c; // chaining assignment operations
``` 
- This code won't compile if your copy assignment operator doesn't return a reference to ```Fixed```. ```a = b = c``` is equivalent to ```a.operator=(b.operator=(c))```, so the ```b = c``` which is ```b.operator=(c)``` will return ```void```, and you can't assign ```void``` to ```a```.
- So, while it's technically possible to have a copy assignment operator that doesn't return a reference to the object, it's not recommended because it would limit the usuability of your class and go against the conventions of C++.
- The standard convention in C++ is for the copy assignment operator to return a reference to the object it's assigning, to allow for assignment chaining.
#### <ins>In case the copy assignment operator doesn't return a reference, will a = b; still work ? </ins>
- Answer: Yes, if the copy assignment operator doesn't return a reference, the statement ```a = b;``` will still work. This is because ```a = b;``` doesn't require the result of the assignment operation.
---
### <ins>Most Vexing Parse in C++</ins>
- The most vexing parse is a specific form of syntactic ambiguity resolution in the C++ programming language. The term was used by <ins>Scott Meyers in Effective STL</ins>. It is formally defined in section 8.2 of the C++ language standard. It means that whatever that can be interpreted as a function declaration will be interpreted as a function declaration. It also means long minutes sitting in front of a failed compilation trying to figure out what the heck is going on.
- Take the following example:
```cpp
std::string foo();
```
- Probably this is the simplest form of the most vexing parse. The unsuspecting coder might think that we just declared a string called food and called its default constructor, so initialized it as an empty string.
- Then, for example, when we try to call ```empty()``` on it, and we have the following error message (with gcc):
```
main.cpp:18:5: error: request for member 'empty' in 'foo', which is of non-class type 'std::string()' {aka 'std::__cxx11::basic_string<char>()'

```
- What happened is that the above line of code was interpreted as a function declaration. We just declared a function called foo, taking no parameeters and returning a string. Whereas we only wanted to call the default constructor.
- This can give a kind of headache to debug eve nif you know about the most vexing parse. Mostly because you see the compiler error on a different line, not where you declared your (variable) function, but where you try to use it.
- This can be fixed very easily. You don't need to use parentheses at all to declare a variable calling its default constructor. But since C++11, if you want you can also use the {}- initialization. Both examples are going to work just fine:
```cpp
std::string foo;
std::string bar{};
```
---
### <ins>You can pass an object as argument to a function without creating it outside of the function</ins>
**Example**
```cpp
#include <iostream>

class point2D {

    public:        
        int a;
        int b;
        point2D(int a, int b) : a(a), b(b) {
            std::cout << "object created\n";
        }
        point2D() {
            std::cout << "default constructor called\n";
        }
};

void display(const point2D& obj)
{
    std::cout << obj.a << " " << obj.b << '\n';
}


int main()

{
    display({}); // will print garbage value for both 'a' and 'b'
    display({42, -42}); // will call the parameterized constructor 
}
```
```
output:
default constructor called
-197636560 32764
object created
42 -42
```
---
### <ins>What if you want to initialize a base's data member inside the child's constructor since child class is inherited from base class ?</ins>

- Let's take the two following classes :
```cpp
class base {
    public:
        int a;
        base (int a = 9) : a(a) {}
};

class child : public base {
    public:
        int b;
        child(int a, int b) : a(a), b(b) {}
};
```
- The idea is we want to initialize the data member ```a``` from the base class inside the ```child``` class's constructor, since *logically* the ```child``` class inherit the data members of ```base``` class. the following code fails to compile:
```cpp
#include <iostream>

class base {
    public:
        int a;
        base (int a = 9) : a(a) {}
};

class child : public base {
    public:
        int b;
        child(int a, int b) : a(a), b(b) {}
};

int main()
{
    child obj(5, 6);
    std::cout << obj.a << " " << obj.b << '\n';
}
```
```
output:
test.cpp:12:31: error: class ‘child’ does not have any field named ‘a’
   12 |         child(int a, int b) : a(a), b(b) {}
      |  
```
- However, C++ prevents classes from initializing inherited member variables in the member initializer list of a constructor. In other words, the value of a member variable can only be set in a member initializer list of a constructor belonging to the same class as the variable.
- Why does C++ do this? The answer has to do with const and reference variables. Consider what would happen if m_id were const. Because const variables must be initialized with a value at the time of creation, the base class constructor must set its value when the variable is created. However, when the base class constructor finishes, the derived class constructor’s member initializer lists are then executed. Each derived class would then have the opportunity to initialize that variable, potentially changing its value! By restricting the initialization of variables to the constructor of the class those variables belong to, C++ ensures that all variables are initialized only once.
---
#### <ins>If we allocate memory in the heap for child class object, does the base object of the child object get allocated in the heap also ?</ins>
- Yes, when you allocate memory on the heap for an object of a derived class, the memory for the entire object, including the base class part, is allocated on the heap.

When a derived class object is created, it includes within it a subobject for each base class it has. So, in your case, a `child` object includes a `base` subobject. If you allocate a `child` object on the heap, the `base` subobject is part of that heap allocation.

Here's an example of how you can allocate a `child` object on the heap:

```cpp
child* ptr = new child(10);
```

In this code, `new child(10)` allocates memory on the heap for a `child` object and calls the `child` constructor. The `base` constructor is called as part of the `child` constructor, so the `base` subobject is constructed in the same heap allocation. The `new` expression returns a pointer to the `child` object, which is stored in `ptr`.
---