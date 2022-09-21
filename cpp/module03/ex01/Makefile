# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 17:31:24 by jiheo             #+#    #+#              #
#    Updated: 2022/09/21 17:44:38 by jiheo            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
FLAG = --std=c++98 -Wall -Wextra -Werror
PROJ = clap_trap
SRCS = main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp
	$(CC) $(FLAG) -c $< -o $@

all: $(OBJS)
	$(CC) $(FLAG) $(OBJS) -o $(PROJ)

$(PROJ): all

clean:
	rm -rf *.o
	rm -rf */*.o

fclean:
	make clean
	rm -rf $(PROJ)

re:
	make fclean
	make all