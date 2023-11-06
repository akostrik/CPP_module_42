SRCS  = main.cpp Fixed.hpp Fixed.cpp
OBJS  = $(SRCS:.c=.o)
OBJS := $(addprefix ./objs/, $(OBJS))
FLAGS = -std=c++98 -Wall -Wextra -Werror
CPP   = c++

all: $(OBJS)
	clear
	$(CPP) $(FLAGS) $(SRCS)

./objs/%.o: ./src/%.c
	mkdir ./objs/ 2> /dev/null || true
	$(CPP) -o $@ -c $<

clean:
	rm -f $(OBJ)
	rmdir ./objs/ 2> /dev/null || true

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all, clean, fclean, re, debug