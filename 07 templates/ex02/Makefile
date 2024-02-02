SRCS    = *.cpp
HEADERS = *.hpp
OBJS    = $(SRCS:.cpp=.o)
OBJS   := $(addprefix ./objs/, $(OBJS))
FLAGS   = -std=c++98 -Wall -Wextra -Werror
CPP     = c++

all: $(OBJS) $(HEADER)
	$(CPP) $(FLAGS) $(SRCS)

./objs/%.o: %.cpp
	clear
	mkdir ./objs/ 2> /dev/null || true
	$(CPP) -O0 -g -o $@ -c $<

clean:
	rm -f $(OBJS)
	rmdir ./objs/ 2> /dev/null || true

fclean: clean
	rm -f a.out

re: fclean all

.PHONY: all, clean, fclean, re, debug
