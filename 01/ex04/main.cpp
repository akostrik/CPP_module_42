#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4 || !av[1][0])
		{
			std::cout << "Wrong arguments" << std::endl;
			return 0;
		}
	if(!av[2][0])
		return 0;

	return File(av[1]).replace(av[2], av[3]);
}