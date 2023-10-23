#include <cctype>
#include <string>
#include <iostream>
#include <cstring>
#include "Contact.h"
#include "PhoneBook.h"
#include "Contact.h"

enum Cmd { ADD = 1, SEARCH, EXIT };

Contact    add(PhoneBook phb)
{
    char *firstName;
    char *lastName;
    char *nickname;

    scanf("%[^\n]s", firstName);
    scanf("%[^\n]s", lastName);
    scanf("%[^\n]s", nickname);
    phb.add(Contact(firstName, lastName, nickname));

}

Contact    search(PhoneBook phb)
{

}

int exit_()
{
    return (0);
}

int	main()
{
    PhoneBook   phb = PhoneBook();
    Cmd cmd;

    // using namespace std;
    while (1)
    {
        printf("Tape a command (ADD / SEARCH / EXIT)"); 
        scanf("%[^\n]s", &cmd);
        if (cmd == ADD)
            add(phb);
        else if (cmd == SEARCH)
            search(phb);
        else if (cmd == EXIT)
            exit_();
    }
    return (0);
}