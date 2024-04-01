#include <iostream>

#include <fstream>
#include <map>
#include <iostream>
#include <sstream>

int main() {
    std::map<std::string, float> data;

    data["2024-02-03"] = 30;
    data["2024-01-10"] = 10;
    data["2024-04-11"] = 40;
    data["2024-01-20"] = 20;

    std::map<std::string, float>::iterator it = data.upper_bound("2024-04-12");
    if (it == data.begin()) {
       std::cout << "element not found\n";
    } else {
        --it;
    std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    }
    std::cout << "------\n";

    for (std::map<std::string, float>::iterator it = data.begin(); it != data.end(); it++) {
        std::cout << "key: " << it->first << " value: " << it->second << std::endl;
    }

   // else
      //  std::cout << "Element not found\n";
}