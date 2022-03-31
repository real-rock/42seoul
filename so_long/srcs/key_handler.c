/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:10:24 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/27 13:40:05 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/handler.h"

int	close_window(t_info *info)
{
	printf("ESC key pressd! Window will be closed...\n");
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

int	key_handler(int keycode, t_info *info)
{
	if (keycode == KEY_ESC)
		close_window(info);
	else
		key_pressed_handler(info, keycode);
	return (0);
}

void	key_pressed_handler(t_info *info, int keycode)
{
	if (keycode == KEY_A)
		move_player(info, WEST);
	if (keycode == KEY_S)
		move_player(info, SOUTH);
	if (keycode == KEY_W)
		move_player(info, NORTH);
	if (keycode == KEY_D)
		move_player(info, EAST);
}

int	key_released_handler(int keycode, t_info *info)
{
	info->player.status = STOP;
	return (0);
}
