#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
public:
        BitcoinExchange(std::string filename, std::string dataBasePath);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        bool isLeapYear(int year);
        void processLine(std::string& line, int line_number);
        std::string trim(const std::string &str);
        void print();
        void printDataBase();
        float exchangeBtc(std::string& date);
        void parse();
        void parseDataBase(std::string& filename);
private:
        std::string _filename;
        std::map<std::string, float> _data;
        std::map<std::string, float> dataBase;
};


#endif