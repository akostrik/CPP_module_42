#include <cctype>
#include <string>
#include <iostream>
#include <cstring>

void	megaphone(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
        for (int j = 0; j < (int)strlen(argv[i]); j++)
            std::cout << (char)toupper(argv[i][j]);
    std::cout << std::endl;
}

int	main(int argc, char *argv[])
{
    if (argc > 1)
        megaphone(argc, argv);
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}