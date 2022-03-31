/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 08:30:57 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/30 08:36:11 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static
bool	is_done(t_info *info)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
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
