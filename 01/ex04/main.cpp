#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		{
			std::cout << "Wrong arguments" << std::endl;
			return 1;
		}
  File my_file = File(av[1]);
	my_file.replace(av[2], av[3]);
	return 0;
}