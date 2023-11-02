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
cout << setw(10) << left << "test" << endl;
```
---