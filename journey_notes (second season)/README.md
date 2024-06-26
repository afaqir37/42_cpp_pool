# Second Pool 42 CPP

This README.md file is for the second pool 42 CPP project. It contains notes and solutions I found during my journey through the project.

# Function Templates in C++

In C++, function templates are a way to write functions that can operate on data of any type. When you define a function template, you provide a placeholder for a type (like `T`), but you don't specify what that type is. When you use the function template, you need to tell the compiler what type to use for the template parameter.


## Using Function Templates with Other Templates

Function templates can also be used as arguments to other templates. For example, consider a function template `iter` that takes an array and a function, and calls the function on each element of the array:

```cpp
template <typename T, typename Func>
void iter(T* array, size_t length, Func func) {
    for (size_t i = 0; i < length; ++i) {
        func(array[i]);
    }
}
```

To use `iter` with an array of `int` and the `printElem` function template, you would write `iter(arr, 5, printElem<int>)`:

```cpp
int arr[] = {1, 2, 3, 4, 5};
iter(arr, 5, printElem<int>);
```

In this case, `printElem<int>` tells the compiler to use the version of `printElem` that takes an `int` as the `func` parameter to `iter`.

# Writing to a File After Reading in C++

In C++, when you read from a file using functions like `std::getline`, the file's "get" pointer, which marks where the next read will occur, moves through the file. After reading the last line, the "get" pointer is at the end of the file.

If you then try to write to the file, the write operation happens where the "get" pointer currently is, which is at the end of the file. However, because the end-of-file (EOF) flag is set when you reach the end of the file during reading, any attempt to write to the file after that will fail, unless you clear the EOF flag.

Here's an example that demonstrates this issue:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::fstream file("data.csv");

    std::string name;

    while (getline(file, name)) {
        std::cout << name << std::endl;
    }

    file << "append this text"; // This will fail because the EOF flag is set
    file.close();
}
```

Sure, here's a `README.md` that explains this issue:

```markdown
# Writing to a File After Reading in C++

In C++, when you read from a file using functions like `std::getline`, the file's "get" pointer, which marks where the next read will occur, moves through the file. After reading the last line, the "get" pointer is at the end of the file.

If you then try to write to the file, the write operation happens where the "get" pointer currently is, which is at the end of the file. However, because the end-of-file (EOF) flag is set when you reach the end of the file during reading, any attempt to write to the file after that will fail, unless you clear the EOF flag.

Here's an example that demonstrates this issue:

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::fstream file("data.csv");

    std::string name;

    while (getline(file, name)) {
        std::cout << name << std::endl;
    }

    file << "append this text"; // This will fail because the EOF flag is set
    file.close();
}
```

In this code, the `while` loop reads lines from the file until it reaches the end. Then it tries to write "append this text" to the file. However, because the EOF flag is set, this write operation fails.

To fix this, you can clear the EOF flag using `file.clear()` before writing to the file:

```cpp
while (getline(file, name)) {
    std::cout << name << std::endl;
}

file.clear(); // Clear EOF flag
file << "append this text"; // This will now succeed
file.close();
```

This will allow the write operation to succeed even if you've read to the end of the file.
```

# Understanding std::map::upper_bound and std::map::lower_bound

`std::map` is a sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the comparison function `Compare`.

## std::map::upper_bound

The function `std::map::upper_bound` returns an iterator pointing to the first element that is considered to go after the key. In other words, it returns an iterator to the first element in the container whose key is considered to go after k.

Example:

```cpp
std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

auto it = m.upper_bound(2);

// it now points to the pair {3, "three"}

Sure, here's a `README.md` file content that explains `std::map::upper_bound`, `std::map::lower_bound`, and the automatic sorting of keys in `std::map`.

```markdown
# Understanding std::map::upper_bound and std::map::lower_bound

`std::map` is a sorted associative container that contains key-value pairs with unique keys. Keys are sorted by using the comparison function `Compare`.

## std::map::upper_bound

The function `std::map::upper_bound` returns an iterator pointing to the first element that is considered to go after the key. In other words, it returns an iterator to the first element in the container whose key is considered to go after k.

Example:

```cpp
std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

auto it = m.upper_bound(2);

// it now points to the pair {3, "three"}
```

## std::map::lower_bound

The function `std::map::lower_bound` returns an iterator pointing to the first element that is not considered to go before the key. In other words, it returns an iterator to the first element in the container whose key is considered to not go before k.

Example:

```cpp
std::map<int, std::string> m = {{1, "one"}, {2, "two"}, {3, "three"}};

auto it = m.lower_bound(2);

// it now points to the pair {2, "two"}
```

## Sorting in std::map

`std::map` automatically sorts its keys in ascending order. This is a built-in feature of `std::map`.

Example:

```cpp
std::map<int, std::string> m;

m[3] = "three";
m[1] = "one";
m[2] = "two";

for (const auto& pair : m) {
    std::cout << "key: " << pair.first << " value: " << pair.second << std::endl;
}

// Output:
// key: 1 value: one
// key: 2 value: two
// key: 3 value: three
```

In this example, even though the elements were inserted into the map in the order 3, 1, 2, they are printed in the order 1, 2, 3. This shows that `std::map` automatically sorts its keys in ascending order.

