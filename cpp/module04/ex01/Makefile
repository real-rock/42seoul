# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiheo <jiheo@student.42.kr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 19:40:02 by jiheo             #+#    #+#              #
#    Updated: 2022/09/26 08:04:29 by jiheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAG = --std=c++98 -Wall -Wextra -Werror
SRCS = main.cpp Dog.cpp Animal.cpp Cat.cpp Brain.cpp WrongAnimal.cpp WrongCat.cpp
OBJS = $(SRCS:.cpp=.o)
PROJ_NAME = ex01

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