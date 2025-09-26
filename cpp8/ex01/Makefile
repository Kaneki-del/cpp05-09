NAME      = Span
CC        = c++
CFLAGS    =  -Wall -Wextra -Werror -std=c++98
RM        = rm -rf
SRCS      = main.cpp Span.cpp
OBJS      = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Span.hpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
