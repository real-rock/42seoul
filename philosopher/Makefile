# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 09:59:04 by jiheo             #+#    #+#              #
#    Updated: 2022/05/17 14:44:26 by jiheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_NAME = philo
CC = gcc
FLAG = -WALL -WEXTRA -WERROR -I.

SRCS = main.c error.c utils.c
OBJS = $(SRCS:.c=.o)

LIB = -lpthread

%.o: %.c
	$(CC) $(FLAG) $(LIB) -c $< -o $@

$(PROJECT_NAME): $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(PROJECT_NAME)

all: $(PROJECT_NAME)

clean:
	rm -rf *.o **/*.o

fclean: clean
	rm $(PROJECT_NAME)

re: fclean
	all

PHONY: all clean fclean re
