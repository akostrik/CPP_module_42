#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4 || !av[1][0] || !av[2][0] || !av[3][0])
		{
			std::cout << "Wrong arguments" << std::endl;
			return 0;
		}

  File(av[1]).replace(av[2], av[3]);
	return 0;
}