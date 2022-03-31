/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiheo <jiheo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 08:59:47 by jiheo             #+#    #+#             */
/*   Updated: 2022/03/29 09:19:33 by jiheo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/render.h"

char	*get_render_src(t_map_ele me)
{
	if (me == TILE)
		return (MAP_TILE_00);
	else if (me == WALL)
		return (MAP_STONE);
	else if (me == BALL)
		return (MAP_BALL);
	else if (me == LADDER)
		return (MAP_LADDER);
	else
		return (NULL);
}

void	render_map_ele(t_info *info, int i, int j, t_map_ele me)
{
	void			*img;
	int				width;
	int				height;
	char			c;

	c = info->map->map[i][j];
	img = mlx_xpm_file_to_image(info->mlx, get_render_src(me), &width, &height);
	if (img == NULL)
		gen_err("[ERROR] Invalid map: unexpected element");
	mlx_put_image_to_window(info->mlx, info->win, \
			img, j * GRID_SIZE, i * GRID_SIZE);
}
