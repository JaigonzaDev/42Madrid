#include <iostream>

class Megaphone {
public:
    void shout(int ac, char **av)
    {
        if (ac == 1)
            std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
        {
            for (int i = 1; av[i]; i++)
            {
                for (int j = 0; av[i][j]; j++)
                    std::cout << (char)std::toupper(av[i][j]);
                std::cout << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main (int ac, char **av)
{
    Megaphone megaphone;
    megaphone.shout(ac, av);
    return (0);
}