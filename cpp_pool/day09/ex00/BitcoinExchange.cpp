#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename, std::string dataBasePath) : _filename(filename)
{
    parse();
    parseDataBase(dataBasePath);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    _filename = other._filename;
    _data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool BitcoinExchange::isLeapYear(int year)
{
    if (year % 4 != 0)
        return false;
    else if (year % 100 != 0)
        return true;
    else if (year % 400 != 0)
        return false;
    else
        return true;
}

std::string BitcoinExchange::trim(const std::string &str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}

void BitcoinExchange::processLine(std::string &line, int line_number)
{
    int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    size_t pos = line.find(" | ");
    if (pos != std::string::npos)
    {
        std::string date_str = trim(line.substr(0, pos));
        std::string value_str = trim(line.substr(pos + 3));

        size_t dash1 = date_str.find("-");
        size_t dash2 = date_str.rfind("-");

        if (dash1 != std::string::npos && dash2 != std::string::npos && dash1 != dash2)
        {
            std::string year_str = date_str.substr(0, dash1);
            std::string month_str = date_str.substr(dash1 + 1, dash2 - dash1 - 1);
            std::string day_str = date_str.substr(dash2 + 1);

            int year = atoi(year_str.c_str());
            int month = atoi(month_str.c_str());
            int day = atoi(day_str.c_str());

            if (year > 0 && month > 0 && day > 0 && month <= 12 && day <= 31)
            {
                if ((month == 2 && isLeapYear(year) && day <= 29) || (day <= daysInMonth[month - 1]))
                {
                        std::istringstream ss(value_str);
                        float value;
                        if (!(ss >> value))
                            std::cout << "Error: Invalid value on line: " << line_number << " : " << value_str << std::endl;
                        else if (value < 0 || value > 1000)
                            std::cout << "Error: value out of range on line: " << line_number << " : " << value_str << std::endl;
                        else
                            _data[date_str] = value;
                    
                }
                else {
                    std:: cout << "Error: bad input on line: " << line_number << " => " << date_str << std::endl;
                }
            }
            else
            {
                std::cout << "Error: bad input on line: " << line_number << " => " << date_str << std::endl;
            }
        }
        else
        {
            std::cout << "Error: Invalid date format on line: " << line_number << " : " << date_str << std::endl;
        }
    }
    else
    {
        std::cout << "Error: Invalid format on line: " << line_number << std::endl;
    }
}

void BitcoinExchange::parse()
{
    std::fstream file(_filename.c_str());
    if (!file.is_open())
    {
        std::cout << "Error: Could not open file" << std::endl;
        return;
    }

    std::string line;
    int line_number = 0;

    if (getline(file, line))
    {
        ++line_number;
        size_t pos = line.find("|");
        if (pos != std::string::npos)
        {
            std::string date_str = trim(line.substr(0, pos));
            std::string value_str = trim(line.substr(pos + 1));

            if (!(date_str == "date" && value_str == "value"))
                processLine(line, 1);
        }
        else
        {
            std::cout << "Error: Invalid format on line: " << line_number << std::endl;
        }
    }

    while (getline(file, line))
    {
        ++line_number;
        processLine(line, line_number);
    }

    file.close();
}

void BitcoinExchange::parseDataBase(std::string& filename) {
    std::ifstream input(filename.c_str());

    if (!input.is_open()) {
        std::cout << "Error: cannot open the file" << std::endl;
        return ;
    }

    std::string line;
    std::string name;
    float exchange_rate;
    std::getline(input, line);

    while (std::getline(input, line)) {
        std::istringstream ss(line);
        if (std::getline(ss, name, ',') && ss >> exchange_rate)
            dataBase[name] = exchange_rate;
        else
            std::cout << "Error" << std::endl;
    }
}


void BitcoinExchange::print()
{
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it)
        std::cout << "key: " << it->first << " value: " << it->second << '\n';
}

void BitcoinExchange::printDataBase() {
    for (std::map<std::string, float>::iterator it = dataBase.begin(); it != dataBase.end(); ++it)
        std::cout << "key: " << it->first << " value: " << it->second << '\n';
}