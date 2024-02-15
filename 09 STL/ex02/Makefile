NAME    = a.out
SRCS    = main.cpp PmergeMe.cpp
OBJS    = $(addprefix ./objs/, $(SRCS:.cpp=.o))
FLAGS   = -std=c++98 -Wall -Wextra -Werror
CPP     = c++

all: $(OBJS) $(HEADER)
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