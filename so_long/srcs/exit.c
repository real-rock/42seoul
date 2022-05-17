/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:30:57 by jiheo             #+#    #+#             */
/*   Updated: 2022/05/16 12:04:10 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static
bool	is_done(t_info *info)
{
	int	i;
	int	j;
    const t_coordinate p_coord = info->player.coord;

	i = -1;
	j = -1;
    if (info->map->map[p_coord.row][p_coord.col] != 'E')
        return (false);
	while (++i < info->map->height)
	{
		while (++j < info->map->width)
		{
			if (info->map->map[i][j] == 'C')
				return (false);
		}
	}
	return (true);
}

void	check_and_exit_game(t_info *info)
{
	if (is_done(info))
	{
		printf("Successfully done!\n");
		exit(EXIT_SUCCESS);
	}
}
