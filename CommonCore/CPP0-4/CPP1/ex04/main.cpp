#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

std::string ft_replace(std::string str, std::string key, std::string replace)
{
    static std::size_t found = 0;
    static std::size_t init = 0;
    static int first = 1;

    if (found == std::string::npos) 
        return ("");
    if (!first)
        init = found + key.length();
    first = 0;
    found = str.find(key, init);
    if (found != std::string::npos)
        return (str.substr(init, found - init).append(replace));
    else
        return (str.substr(init, str.length()));
}

int main (int ac, char **av)
{
    if (ac != 4)
        std::cout << "Format: File - String1 - String 2" << std::endl;
    std::string path = av[1];
    std::string key = av[2];
    std::string replace = av[3];
    std::ifstream stream(path);
    std::ofstream file(path.append(".replace"));
    std::stringstream buffer;
    std::string status;

    if (stream.is_open())
    {
        buffer << stream.rdbuf();
    while (!(status = ft_replace(buffer.str(), key, replace)).empty()) 
        file << status;
    file.close();
    }
    else
    {
        std::cout << "Can't open the file" << std::endl;
        return (1);
    }
    return (0);
}