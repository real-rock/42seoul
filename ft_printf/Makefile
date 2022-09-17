CC = gcc
CFLAG = -Wall -Wextra -Werror -I./headers
NAME = libftprintf.a
RAW_HEADERS = ft_printf ft_types ft_output
RAW_SRCS = ft_printf ft_put_char ft_put_dec ft_put_int ft_put_lower_hex ft_put_pointer ft_put_str ft_put_unsignedint ft_put_upper_hex ft_get_len
HEADERS = $(addsuffix .h, $(addprefix headers/, $(RAW_HEADERS)))
SRCS = $(addsuffix .c, $(addprefix srcs/, $(RAW_SRCS)))
OBJECTS = $(addsuffix .o, $(RAW_SRCS))

all : $(NAME)

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS) : $(SRCS)
	$(CC) $(CFLAG) -c $(SRCS)

clean:
	find . -name "*.o" -delete

fclean : clean
	rm -f $(NAME)

re : fclean all

test : all
	$(CC) $(CFLAG) main.c $(NAME)
	./a.out

.PHONY: all bonus clean fclean re