NAME = push_swap
CC = gcc
FLAG = -Wall -Wextra -Werror -I./includes

RAW_LIST = list list_adv_operator list_base_operator
RAW_SRCS = ft_errors base_operation helper quick_sort simple_sort simple_sort_1 operation_1 operation_2 operation_3 push_swap main

LIST_SRCS = $(addprefix ./list/, $(addsuffix .c, $(RAW_LIST)))
SRCS = $(addprefix ./srcs/, $(addsuffix .c, $(RAW_SRCS)))

LIST_OBJS = $(addprefix ./list/, $(addsuffix .o, $(RAW_LIST)))
OBJS = $(addprefix ./srcs/, $(addsuffix .o, $(RAW_SRCS)))

all: $(NAME)

$(NAME): $(SRCS) $(LIST_SRCS)
	cd ./libft && make all
	$(CC) $(FLAG) -L ./libft -lft $(SRCS) $(LIST_SRCS) -o $(NAME)

re: fclean all

clean:
	find . -name "*.o" -delete

fclean: clean
	rm -f $(NAME)
	rm -f ./libft/libft.a

.PHONY: all clean fclean re