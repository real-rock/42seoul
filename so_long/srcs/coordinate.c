/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:39:28 by jiheo             #+#    #+#             */
/*   Updated: 2022/04/29 18:27:41 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/coordinate.h"

void	set_coord(t_coordinate *co, int row, int col)
{
	co->row = row;
	co->col = col;
}

void	to_right(t_map *map, t_player *player)
{
	int	col;
	int	upper_row;
	int	lower_row;

	col = (player->coord.col + STEP_SIZE + GRID_SIZE) / GRID_SIZE;
	upper_row = player->coord.row / GRID_SIZE;
	lower_row = (player->coord.row + GRID_SIZE) / GRID_SIZE;
	if ((player->coord.col + STEP_SIZE) % GRID_SIZE != 0 && \
				map->map[upper_row][col] == '1')
		return ;
	else if (player->coord.row % GRID_SIZE != 0 && \
				map->map[lower_row][col] == '1')
		return ;
	else
	{
		player->coord.col += STEP_SIZE;
		printf("Player moving count: %llu\n", player->cnt++);
	}
}

void	to_left(t_map *map, t_player *player)
{
	int	col;
	int	upper_row;
	int	lower_row;

	col = (player->coord.col - STEP_SIZE) / GRID_SIZE;
	upper_row = player->coord.row / GRID_SIZE;
	lower_row = (player->coord.row + GRID_SIZE) / GRID_SIZE;
	if (map->map[upper_row][col] == '1')
		return ;
	else if (player->coord.row % GRID_SIZE != 0 && \
				map->map[lower_row][col] == '1')
		return ;
	else
	{
		player->coord.col -= STEP_SIZE;
		printf("Player moving count: %llu\n", player->cnt++);
	}
}

void	to_up(t_map *map, t_player *player)
{
	int	left_col;
	int	right_col;
	int	row;

	left_col = player->coord.col / GRID_SIZE;
	right_col = (player->coord.col + GRID_SIZE) / GRID_SIZE;
	row = (player->coord.row - STEP_SIZE) / GRID_SIZE;
	if (row < 0 || row > map->height)
		gen_err("Error: invalid player coordination");
	if (map->map[row][left_col] == '1')
		return ;
	else if (player->coord.col % GRID_SIZE != 0 && \
				map->map[row][right_col] == '1')
		return ;
	else
	{
		player->coord.row -= STEP_SIZE;
		printf("Player moving count: %llu\n", player->cnt++);
	}
}

void	to_down(t_map *map, t_player *player)
{
	int	left_col;
	int	right_col;
	int	row;

	left_col = player->coord.col / GRID_SIZE;
	right_col = (player->coord.col + GRID_SIZE) / GRID_SIZE;
	row = (player->coord.row + STEP_SIZE + GRID_SIZE) / GRID_SIZE;
	if (row < 0 || row > map->height)
		gen_err("Error: invalid player coordination");
	if ((player->coord.row + STEP_SIZE) % GRID_SIZE != 0 && \
			map->map[row][left_col] == '1')
		return ;
	else if (player->coord.col % GRID_SIZE != 0 && \
				map->map[row][right_col] == '1')
		return ;
	else
	{
		player->coord.row += STEP_SIZE;
		printf("Player moving count: %llu\n", player->cnt++);
	}
}
