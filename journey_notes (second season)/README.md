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


