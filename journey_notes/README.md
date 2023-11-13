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