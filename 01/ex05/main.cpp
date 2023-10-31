#include "Harl.hpp"

int	main()
{
  Harl h = Harl(av[1]);

	h.complain("DEBUG");
	h.complain("INFO");
	h.complain("WARNING");
	h.complain("ERRO");

	return 0;
}