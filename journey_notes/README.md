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
The problem occurs because when you type ==Ahmed== and press enter, the input stream contains ==Ahmed/n== and ==Ahmed== is parsed into the 'name' variable while '\n' is still in the stream. Reading the doc for *getline* function by default it will look in the *istream* until a '\n' is encountered. In this example, since '\n' is in the stream, it looks like it "skipped" it but it worked properly.

Essentially, for std::cin statements you use *ignore* before you do a *getline* call, because when a user inputs something with std::cin, they hit enter and a '\n' char gets into the **cin** buffer. Then if you use *getline*, it gets the newline char instead of the string you want. So you do a ```std::cin.ignore(1000, '\n')``` 

<ins>About std::istream::ignore()</ins>
*source: cplusplus.com*
**istream& ignore (streamsize n = 1, int delim = EOF);**
```
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
using namespace std;

int main()
{
    string name;
    string line;
    cout << "Enter a name: ";
    cin >> name;
    cout << "Enter a line: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // this line will  skip all the remaining characters in the input buffer until it reaches '\n' of eof
    getline(cin, line);// the cin buffer now is ready to receive new input
    cout << line << endl;
}
```
