NAME      = a.out
SRCS      = main.cpp Span.cpp
OBJS      = $(SRCS:.cpp=.o)
C         = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS)
	$(C) $(OBJS) -o $(NAME)

.cpp.o:
	$(C) -c $< -o $(<:.cpp=.o)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
