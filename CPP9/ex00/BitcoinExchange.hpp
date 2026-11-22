#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
private:
    std::map<std::string, double> _database;

    static std::string trim(const std::string& text);
    static bool isLeapYear(int year);
    static bool parseNumber(const std::string& text, double& value);

    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& text, double& value) const;
    bool findRate(const std::string& date, double& rate) const;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();

    void loadDatabase(const std::string& filename);
    void processInput(const std::string& filename) const;
};

#endif