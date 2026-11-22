#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _database(other._database)
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string BitcoinExchange::trim(const std::string& text)
{
    std::string::size_type first = text.find_first_not_of(" \t");
    if (first == std::string::npos)
        return "";
    std::string::size_type last = text.find_last_not_of(" \t");
    return text.substr(first, last - first + 1);
}

bool BitcoinExchange::isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

bool BitcoinExchange::parseNumber(const std::string& text, double& value)
{
    if (text.empty())
        return false;
    bool digitFound = false;
    bool decimalPointFound = false;
    std::string::size_type i = 0;
    if (text[i] == '+' || text[i] == '-')
        ++i;
    for (; i < text.size(); ++i)
    {
        if (text[i] >= '0' && text[i] <= '9')
            digitFound = true;
        else if (text[i] == '.' && !decimalPointFound)
            decimalPointFound = true;
        else
            return false;
    }
    if (!digitFound)
        return false;
    std::stringstream stream(text);
    stream >> value;
    return !stream.fail() && stream.eof();
}

bool BitcoinExchange::isValidDate(const std::string& date) const
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    for (std::string::size_type i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
        daysInMonth[1] = 29;
    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isValidValue(const std::string& text, double& value) const
{
    if (!parseNumber(text, value))
        return false;
    return value >= 0.0;
}

bool BitcoinExchange::findRate(const std::string& date, double& rate) const
{
    std::map<std::string, double>::const_iterator it = _database.lower_bound(date);
    if (it == _database.end())
    {
        if (_database.empty())
            return false;
        --it;
    }
    else if (it->first != date)
    {
        if (it == _database.begin())
            return false;
        --it;
    }
    rate = it->second;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file)
        throw std::runtime_error("could not open database file");

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string::size_type separator = line.find(',');
        if (separator == std::string::npos)
            continue;
        std::string date = trim(line.substr(0, separator));
        std::string priceText = trim(line.substr(separator + 1));
        double price = 0.0;
        if (isValidDate(date) && parseNumber(priceText, price))
            _database[date] = price;
    }
}

void BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream file(filename.c_str());
    if (!file)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::string::size_type separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = trim(line.substr(0, separator));
        std::string valueText = trim(line.substr(separator + 1));
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = 0.0;
        if (!isValidValue(valueText, value))
        {
            if (valueText.find('-') != std::string::npos)
                std::cerr << "Error: not a positive number." << std::endl;
            else
                std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        double rate = 0.0;
        if (!findRate(date, rate))
        {
            std::cerr << "Error: date is earlier than the database." << std::endl;
            continue;
        }
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }
}