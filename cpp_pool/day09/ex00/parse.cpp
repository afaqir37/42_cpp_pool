#include <iostream>

#include <fstream>
#include <map>
#include <sstream>

int main() {
    std::fstream file("data.csv");

    std::string name;
    std::map<std::string, float> data;

    float exchange_rate;
    std::istringstream ss("2033.3.1");
    if (getline(ss, name, ',') && ss >> exchange_rate)
        data[name] = exchange_rate;
    else
        std::cout << "tnakt\n";

    for (auto it: data)
        std::cout << "key: " << it.first << " value: " << it.second << '\n';
    // while (getline(file, name)) {
    //     std::istringstream ss(name);
    //     float exchange_rate;
    //     std::string date;

    //     if (std::getline(ss, date, ',') && ss >> exchange_rate)
    //         data[date] = exchange_rate;
    // }

    
    file.close();
}