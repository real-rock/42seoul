# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:40:02 by jiheo             #+#    #+#              #
#    Updated: 2022/09/14 19:41:49 by jiheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAG = --std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)
PROJ_NAME = ex00

%.o: %.cpp
	$(CC) -c $(FLAG) $< -o $@

all: $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(PROJ_NAME)

$(PROJ_NAME): all

clean:
	rm -rf *.o **/*.o

fclean:
	make clean
	rm -rf $(PROJ_NAME)

re:
	make fclean
	make all