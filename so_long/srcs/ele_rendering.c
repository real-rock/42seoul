/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ele_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:16:45 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 10:37:40 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

void	render_tile(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < info->map->height)
	{
		while (j < info->map->width)
			render_map_ele(info, i, j++, TILE);
		i++;
		j = 0;
	}
}

void	render_wall(t_info *info)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < info->map->height)
	{
		while (++j < info->map->width)
		{
			if (info->map->map[i][j] == '1')
				render_map_ele(info, i, j, WALL);
		}
		j = -1;
	}
}

void	render_ladder(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < info->map->height)
	{
		while (j < info->map->width)
		{
			if (info->map->map[i][j] == 'E')
				render_map_ele(info, i, j, LADDER);
			j++;
		}
		i++;
		j = 0;
	}
}

void	render_ball(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < info->map->height)
	{
		while (j < info->map->width)
		{
			if (info->map->map[i][j] == 'C')
				render_map_ele(info, i, j, BALL);
			j++;
		}
		i++;
		j = 0;
	}
}
