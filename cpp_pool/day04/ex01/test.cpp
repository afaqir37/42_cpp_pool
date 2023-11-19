#include <iostream>

int main()
{
    std::string str[100];
    str[0] = "po";
    str[1] = "k";
    str[2] = "";
    str[3] = "d";
    str[9] = "";
    str[10] = "ok";
    for (int i = 0; i < 100; i++)
    {
        // if (str[i] == "")
        //     break;
        // else
            std::cout << "str: " << str[i] << '\n';
    }
}