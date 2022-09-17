/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:50:46 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/16 11:29:42 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# define GRID_SIZE 64
# define KEY_W 13
# define KEY_D 2
# define KEY_A 0
# define KEY_S 1
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17
# define X_EVENT_KEY_RELEASE 3
# define KEY_ESC 53

# define MAP_TILE_00 "./assets/images/map/tile00.xpm"
# define MAP_TILE_01 "./assets/images/map/tile01.xpm"
# define MAP_STONE "./assets/images/map/stone.xpm"

# define MAP_LADDER "./assets/images/common/ladder.xpm"

# define MAP_BALL "./assets/images/map/ball.xpm"

# define PLAYER_E00 "./assets/images/player/player_E00.xpm"
# define PLAYER_E01 "./assets/images/player/player_E01.xpm"
# define PLAYER_E02 "./assets/images/player/player_E02.xpm"
# define PLAYER_N00 "./assets/images/player/player_N00.xpm"
# define PLAYER_N01 "./assets/images/player/player_N01.xpm"
# define PLAYER_N02 "./assets/images/player/player_N02.xpm"
# define PLAYER_S00 "./assets/images/player/player_S00.xpm"
# define PLAYER_S01 "./assets/images/player/player_S01.xpm"
# define PLAYER_S02 "./assets/images/player/player_S02.xpm"
# define PLAYER_W00 "./assets/images/player/player_W00.xpm"
# define PLAYER_W01 "./assets/images/player/player_W01.xpm"
# define PLAYER_W02 "./assets/images/player/player_W02.xpm"

# define ENEMY_E00 "./assets/images/enemy/rocket_E00.xpm"
# define ENEMY_N00 "./assets/images/enemy/rocket_N00.xpm"
# define ENEMY_S00 "./assets/images/enemy/rocket_S00.xpm"
# define ENEMY_W00 "./assets/images/enemy/rocket_W00.xpm"

# define STEP_SIZE 32

# include <stdbool.h>
# include "../mlx_opengl/mlx.h"

typedef enum e_direction
{
	EAST = 0,
	WEST = 1,
	SOUTH = 2,
	NORTH = 3,
}			t_direction;

typedef enum e_player_status
{
	STOP = 0,
	RIGHT = 1,
	LEFT = 2,
}			t_player_status;

typedef enum e_map_ele
{
	TILE = 0,
	WALL = 1,
	BALL = 2,
	LADDER = 3,
}			t_map_ele;

typedef struct s_coordinate
{
	int	row;
	int	col;
}			t_coordinate;

typedef struct s_map
{
	int		fd;
	char	*src;
	char	**map;
	int		width;
	int		height;
}			t_map;

typedef struct s_player
{
	t_coordinate		coord;
	t_direction			dir;
	t_player_status		status;
	unsigned long long	cnt;
}			t_player;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_player		player;
	unsigned int	ball_count;
}			t_info;

#endif