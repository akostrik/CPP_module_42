#include "File.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
		{
			std::cout << "Wrong arguments" << std::endl;
			return 0;
		}
	std::cout << "main call constructor(" << av[1] << ")" << std::endl;
  File my_in_file = File(av[1]);
	std::cout << "main        name    = " << my_in_file.name_as_arr << std::endl;
	my_in_file.func();
	my_in_file.func2("dd");
	//my_in_file.replace(av[2], av[3]);
	(void)my_in_file;
	return 0;
}