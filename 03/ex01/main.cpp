#include <iostream>
#include "ClapTrap.hpp"

int main( void ) {
  ClapTrap loup("Loup");
	ClapTrap chat;

	chat = ClapTrap("Chat");

  chat.attack("Loup");
  chat.attack("Loup");
  loup.takeDamage(2);
  loup.beRepaired(1);
  loup.takeDamage(2);
  loup.beRepaired(1);

  return 0;
}