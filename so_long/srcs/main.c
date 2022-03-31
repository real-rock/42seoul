/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 10:06:03 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 10:41:25 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	start_game(t_info *info)
{
	update_map(info);
	update_player(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_map	*m;

	if (argc != 2)
		gen_err("Error");
	init_game(&info, argv[1]);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 1L << 0, &close_window, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L << 0, &key_handler, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, \
			1L << 1, &key_released_handler, &info);
	mlx_loop_hook(info.mlx, &start_game, &info);
	mlx_loop(info.mlx);
	rm_map(m);
	return (0);
}
