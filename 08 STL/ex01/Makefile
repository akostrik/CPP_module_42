# $<
# $^ .o
# $@ executable
# FLAGS preprocessor flags


NAME      = a.out
SRCS      = main.cpp Span.cpp
HEADERS   =          Span.hpp
OBJS      = $(SRCS:.cpp=.o)
DEPENDS   = $(OBJS:.o=.d)
CPP      = c++ 
#CPP       = g++ -MM $(1).cpp -MT $(1).o > $(1).d && g++ -c -Os $(1).cpp -o $(1).o
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(CPPFLAGS) -I $(HEADERS) $(OBJS) -o $(NAME)

main.o:
	g++ -MM main.cpp -MT main.o > main.d && g++ -c -Os main.cpp -o main.o

Span.o:
	g++ -MM Span.cpp -MT Span.o > Span.d && g++ -c -Os Span.cpp -o Span.o

-include *.d

# .cpp.o:
# %.o: %.cpp %.hpp
# 	$(CPP) -MM $< -MT $^ > Span.d && g++ -c -Os $< -o $^
#	$(CPP) $(CPPFLAGS) -I $(HEADERS) -c $< -o $(<:.cpp=.o) 
# 	$(CPP) $(CPPFLAGS) $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm $(NAME)

re: fclean all


.PHONY: all clean fclean re
