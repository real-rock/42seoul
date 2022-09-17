/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:13:06 by jiheo             #+#    #+#             */
/*   Updated: 2022/04/29 18:37:19 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static
void	init_player(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	info->player.cnt = 0;
	while (i < info->map->height)
	{
		while (j < info->map->width)
		{
			if (info->map->map[i][j] == 'P')
			{
				set_coord(&info->player.coord, i * GRID_SIZE, j * GRID_SIZE);
				info->player.dir = SOUTH;
				info->player.status = STOP;
				return ;
			}
			else if (info->map->map[i][j] == 'C')
				info->player.cnt++;
			j++;
		}
		j = 0;
		i++;
	}
}

static
void	init_window(t_info *info)
{
	int	win_width;
	int	win_height;

	win_width = info->map->width * GRID_SIZE;
	win_height = info->map->height * GRID_SIZE;
	info->win = mlx_new_window(info->mlx, win_width, win_height, "so_long");
}

void	init_game(t_info *info, char *src)
{
	info->mlx = mlx_init();
	info->map = new_map(src);
	info->ball_count = 0;
	init_window(info);
	init_player(info);
}

/*
		for (int i = 0; i < info->map->height; i++) {
		for (int j = 0; j < info->map->width; j++) {
			printf("%c ", info->map->map[i][j]);
		}
		printf("\n");
	}
*/