CC = gcc
FLAG = -Wall -Wextra -Werror
MLX_MMS_DIR = ./mlx_mms
MLX_OPENGL_DIR = ./mlx_opengl
PROJECT = so_long
SRCS_DIR = srcs/
INCLUDE_DIR = include/

SRC_RAW = main.c utils.c errors.c \
			map.c io.c map_rendering.c coordinate.c \
			player.c player_rendering.c key_handler.c \
			init.c ele_rendering.c rendering.c \
			exit.c
SRCS		=	$(addprefix $(SRCS_DIR), $(SRC_RAW))
OBJS		=	$(SRCS:.c=.o)

$.o:%.c
	$(CC) $(FLAG) -I${INCLUDE_DIR} -c $< -o $@

$(PROJECT): $(OBJS)
	$(CC) $(OBJS) -L$(MLX_OPENGL_DIR) -lmlx -L$(MLX_MMS_DIR) -lmlx -framework OpenGL -framework AppKit -o $(PROJECT)

all: $(PROJECT)

clean:
	rm -rf *.o **/*.o

fclean: clean
	rm $(PROJECT)

re: fclean all

run: all
	./so_long assets/map/map_sl.ber

PHONY : all clean fclean re