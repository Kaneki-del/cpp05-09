NAME      = Rpn
CC        = c++
CFLAGS    =  -Wall -Wextra -Werror  -std=c++98
RM        = rm -rf
SRCS      = main.cpp Rpn.cpp
OBJS      = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Rpn.hpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
