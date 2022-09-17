CC = gcc
CFLAG = -Wall -Wextra -Werror -I./
SERVER_RAW = server ft_putnbr ft_putstr ft_utils ft_strlen ft_initializer
SERVER_SRCS = $(addsuffix .c, $(SERVER_RAW))

CLIENT_RAW = client ft_atoi ft_putstr ft_strlen ft_utils ft_sender ft_initializer
CLIENT_SRCS = $(addsuffix .c, $(CLIENT_RAW))

all: server client

server: $(SERVER_SRCS)
	$(CC) $(CFLAG) $(SERVER_SRCS) -o server

client: $(CLIENT_SRCS)
	$(CC) $(CFLAG) $(CLIENT_SRCS) -o client

clean:
	rm client server

fclean: clean

re : clean all