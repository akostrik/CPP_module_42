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
CPPFLAGS  = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	$(CPP) $(CPPFLAGS) -I $(HEADERS) $(OBJS) -o $(NAME)

main.o:
	g++ -MM $(<:.o=.cpp) -MT main.o > main.d && g++ -c -Os $(<:.o=.cpp) -o main.o

Span.o:
	g++ -MM $(<:.o=.cpp) -MT Span.o > Span.d && g++ -c -Os $(<:.o=.cpp) -o Span.o

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
