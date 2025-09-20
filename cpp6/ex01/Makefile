NAME      = Serializer
CC        = c++
CFLAGS    =  -Wall -Wextra -Werror -std=c++98  -g
RM        = rm -rf
SRCS      = Serializer.cpp  main.cpp 
OBJS      = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp Serializer.hpp Data.hpp
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
