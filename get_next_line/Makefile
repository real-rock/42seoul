CC = gcc
CFLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I./
NAME = gnl
SRCS = get_next_line_utils.c get_next_line.c main.c
BONUS = get_next_line_utils_bonus.c get_next_line_bonus.c main.c
OBJECTS = $(SRCS:%.c=%.o)
BONUSOBJ = $(BONUS:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJECTS)
	$(CC) -o $(NAME) $(OBJECTS)
	./$(NAME)

bonus : $(BONUSOBJ)
	$(CC) -o $(NAME) $(BONUSOBJ)
	./$(NAME)

clean:
	find . -name "*.o" -delete

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re