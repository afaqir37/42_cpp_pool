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