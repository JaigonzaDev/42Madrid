#include "ScalarConverter.hpp"

#include <cerrno>
#include <cfloat>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>

bool isSpecial(const std::string& literal)
{
    return literal == "-inf" || literal == "+inf" || literal == "nan"
        || literal == "-inff" || literal == "+inff" || literal == "nanf";
}

bool isCharLiteral(const std::string& literal)
{
    return literal.length() == 3 && literal[0] == '\''
        && literal[2] == '\'';
}

bool isIntegerLiteral(const std::string& literal, int& value)
{
    char* end;
    long parsed;

    if (literal.empty())
        return false;
    errno = 0;
    parsed = std::strtol(literal.c_str(), &end, 10);
    if (*end != '\0' || errno == ERANGE
        || parsed < std::numeric_limits<int>::min()
        || parsed > std::numeric_limits<int>::max())
        return false;
    value = static_cast<int>(parsed);
    return true;
}

    bool isFloatLiteral(const std::string& literal, float& value)
    {
        char* end;
        std::string number;

        if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
            return false;
        number = literal.substr(0, literal.length() - 1);
        errno = 0;
        value = std::strtof(number.c_str(), &end);
        if (*end != '\0' || errno == ERANGE)
            return false;
        return number.find('.') != std::string::npos;
    }

    bool isDoubleLiteral(const std::string& literal, double& value)
    {
        char* end;

        if (literal.find('.') == std::string::npos)
            return false;
        errno = 0;
        value = std::strtod(literal.c_str(), &end);
        if (*end != '\0' || errno == ERANGE)
            return false;
        return true;
    }

    bool isNaN(double value)
    {
        return value != value;
    }

    bool isInfinite(double value)
    {
        return value == std::numeric_limits<double>::infinity()
            || value == -std::numeric_limits<double>::infinity();
    }

void printConversions(double value)
{
    bool special = isNaN(value) || isInfinite(value);

    if (special)
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (isNaN(value))
            std::cout << "float: nanf" << std::endl;
        else if (value < 0)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: +inff" << std::endl;
        if (isNaN(value))
            std::cout << "double: nan" << std::endl;
        else if (value < 0)
            std::cout << "double: -inf" << std::endl;
        else
            std::cout << "double: +inf" << std::endl;
        return;
    }

    if (value < 0 || value > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    if (value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    if (value < -std::numeric_limits<float>::max()
        || value > std::numeric_limits<float>::max())
        std::cout << "float: impossible" << std::endl;
    else
    {
        std::cout << "float: " << std::fixed << std::setprecision(1)
                  << static_cast<float>(value) << "f" << std::endl;
    }
    std::cout << "double: " << std::fixed << std::setprecision(1)
              << value << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (isSpecial(literal))
    {
        if (literal == "nan" || literal == "nanf")
            printConversions(std::numeric_limits<double>::quiet_NaN());
        else if (literal[0] == '-')
            printConversions(-std::numeric_limits<double>::infinity());
        else
            printConversions(std::numeric_limits<double>::infinity());
    }
    else if (isCharLiteral(literal))
    {
        printConversions(static_cast<double>(literal[1]));
    }
    else
    {
        int integer;
        float floating;
        double decimal;

        if (isFloatLiteral(literal, floating))
            printConversions(static_cast<double>(floating));
        else if (isDoubleLiteral(literal, decimal))
            printConversions(decimal);
        else if (isIntegerLiteral(literal, integer))
            printConversions(static_cast<double>(integer));
        else
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
        }
    }
}