NAME      = Bureaucrat
CC        = c++
CFLAGS    =  -Wall -Wextra -Werror -std=c++98 
RM        = rm -rf

SRCS      = Bureaucrat.cpp main.cpp
OBJS      = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

clean:
	$(RM) $(OBJS) $(OBJS:.o=.d)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
