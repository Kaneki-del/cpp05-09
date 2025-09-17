NAME      = Bureaucrat
CC        = c++
CFLAGS    =  -Wall -Wextra -Werror -std=c++98  -g
RM        = rm -rf
SRCS      = ScalarConverter.cpp  main.cpp ScalarConverterHelper.cpp
OBJS      = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp ScalarConverter.hpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
