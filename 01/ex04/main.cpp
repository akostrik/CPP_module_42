#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		{
			std::cout << "Wrong arguments" << std::endl;
			return 0;
		}
  File f = File(av[1]);
	f.replace(av[2], av[3]);
	return 0;
}