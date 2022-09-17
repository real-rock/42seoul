/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:24:15 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 11:42:48 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

static
char	*_get_stop_player_src(t_direction dir)
{
	if (dir == EAST)
		return (PLAYER_E00);
	else if (dir == SOUTH)
		return (PLAYER_S00);
	else if (dir == NORTH)
		return (PLAYER_N00);
	else
		return (PLAYER_W00);
}

static
char	*_get_right_player_src(t_direction dir)
{
	if (dir == EAST)
		return (PLAYER_E01);
	else if (dir == SOUTH)
		return (PLAYER_S01);
	else if (dir == NORTH)
		return (PLAYER_N01);
	else
		return (PLAYER_W01);
}

static
char	*_get_left_player_src(t_direction dir)
{
	if (dir == EAST)
		return (PLAYER_E02);
	else if (dir == SOUTH)
		return (PLAYER_S02);
	else if (dir == NORTH)
		return (PLAYER_N02);
	else
		return (PLAYER_W02);
}

static
char	*_get_player_src(t_info *info)
{
	if (info->player.status == STOP)
		return (_get_stop_player_src(info->player.dir));
	else if (info->player.status == RIGHT)
		return (_get_right_player_src(info->player.dir));
	else
		return (_get_left_player_src(info->player.dir));
}

void	update_player(t_info *info)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(info->mlx, \
			_get_player_src(info), &width, &height);
	mlx_put_image_to_window(info->mlx, info->win, img, \
		info->player.coord.col, info->player.coord.row - GRID_SIZE);
}
