/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 20:48:24 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 11:37:28 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/player.h"

t_coordinate	get_player_coord(t_info *info)
{
	return (info->player.coord);
}

static
void	_update_ball(t_info *info)
{
	t_coordinate	p;
	const int		diff = 10;

	p = get_player_coord(info);
	if (info->map->map[p.row / GRID_SIZE][p.col / GRID_SIZE] == 'C')
		info->map->map[p.row / GRID_SIZE][p.col / GRID_SIZE] = '0';
}

void	turn_player(t_info *info, t_direction dir)
{
	info->player.dir = dir;
}

static
void	_move_to_dir(t_info *info, t_direction dir)
{
	if (dir == NORTH)
		to_up(info->map, &info->player.coord);
	else if (dir == SOUTH)
		to_down(info->map, &info->player.coord);
	else if (dir == EAST)
		to_right(info->map, &info->player.coord);
	else
		to_left(info->map, &info->player.coord);
	_update_ball(info);
}

void	move_player(t_info *info, t_direction dir)
{
	if (info->player.dir == dir)
	{
		if (info->player.status != RIGHT)
			info->player.status = RIGHT;
		else
			info->player.status = LEFT;
		_move_to_dir(info, dir);
	}
	else
		turn_player(info, dir);
}
