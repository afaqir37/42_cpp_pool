#ifndef _BITCOINEXCHANGE_HPP_
#define _BITCOINEXCHANGE_HPP_

#include <iostream>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
    public:
        BitcoinExchange(std::string filename);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();


        void processLine(std::string& line, int line_number);
        void parse();
        std::string trim(const std::string &str);
        void print();
    private:
        std::string _filename;
        std::map<std::string, float> _data;
};


#endif