# need to fix: makefile shoud not relink

SRCS    = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
HEADERS =          ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS    = $(SRCS:.cpp=.o)
OBJS   := $(addprefix ./objs/, $(OBJS))
FLAGS   = -std=c++98 -Wall -Wextra -Werror
CPP     = c++

all: $(OBJS) $(HEADER)
	clear
	$(CPP) $(FLAGS) $(SRCS)

./objs/%.o: %.cpp
	mkdir ./objs/ 2> /dev/null || true
	$(CPP) -o $@ -c $<

clean:
	rm -f $(OBJS)
	rmdir ./objs/ 2> /dev/null || true

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all, clean, fclean, re, debug
