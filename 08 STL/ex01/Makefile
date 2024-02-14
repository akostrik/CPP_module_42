NAME      = a.out
SRCS      = main.cpp Span.cpp
OBJS      = $(SRCS:.cpp=.o)
CGPP      = c++ -MM $(1).cpp -MT $(1).o > $(1).d && c++ -c -Os $(1).cpp -o $(1).o

all: $(NAME)

$(NAME): $(OBJS)
	@echo NAME $(OBJS)
	c++ $(OBJS) -o $(NAME)

main.o:
	@echo CGPP
	$(call CGPP,main)

Span.o:
	$(call CGPP,Span)

clean:
	rm -f $(OBJS)
	rm -f *.d *.o

-include *.d

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


# $<
# $^
# $@ arg

# OBJS      = $(SRCS:.cpp=.o)
# CPP       = c++ 
# CPPFLAGS  = -Wall -Wextra -Werror -std=c++98 # preprocessor flags

# all: $(NAME)

# $(NAME): $(OBJS)
# 	c++ $(OBJS)
# #	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)

# main.o:
# 	c++ -MM main.cpp -MT main.o > main.d && c++ -c -Os main.cpp -o main.o

# Span.o:
# 	c++ -MM Span.cpp -MT Span.o > Span.d && c++ -c -Os Span.cpp -o Span.o

# -include *.d

# # .cpp.o:
# # %.o: %.cpp %.hpp
# # 	$(CPP) -MM $< -MT $^ > Span.d && g++ -c -Os $< -o $^
# #	$(CPP) $(CPPFLAGS) -I $(HEADERS) -c $< -o $(<:.cpp=.o) 
# # 	$(CPP) $(CPPFLAGS) $< -o $@

